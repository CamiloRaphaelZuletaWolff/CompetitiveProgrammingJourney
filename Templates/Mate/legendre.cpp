#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 lll; // para multiplicaciones sin overflow

// ============================================================
//  Utilidades
// ============================================================

// b^e mod m con exponenciacion rapida
ll modpow(ll b, ll e, ll m) {
    ll r = 1 % m;
    b %= m;
    while (e > 0) {
        if (e & 1) r = (lll)r * b % m;
        b = (lll)b * b % m;
        e >>= 1;
    }
    return r;
}

// Euclides extendido: a*x + b*y = gcd(a, b)
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Inverso de a mod m (requiere gcd(a, m) = 1; m NO necesita ser primo)
ll inverso(ll a, ll m) {
    ll x, y;
    extgcd(((a % m) + m) % m, m, x, y);
    return ((x % m) + m) % m;
}

// Criba de Eratostenes: primos <= n
vector<ll> criba(ll n) {
    vector<bool> compuesto(n + 1, false);
    vector<ll> primos;
    for (ll i = 2; i <= n; i++) {
        if (compuesto[i]) continue;
        primos.push_back(i);
        for (ll j = i * i; j <= n; j += i) compuesto[j] = true;
    }
    return primos;
}

// Factorizacion por division de prueba: pares (primo, exponente)
vector<pair<ll, ll>> factorizar(ll m) {
    vector<pair<ll, ll>> f;
    for (ll p = 2; p * p <= m; p++) {
        if (m % p) continue;
        ll a = 0;
        while (m % p == 0) { m /= p; a++; }
        f.push_back({p, a});
    }
    if (m > 1) f.push_back({m, 1});
    return f;
}

// ============================================================
//  Caso 1: formula de Legendre   v_p(n!) = sum floor(n / p^i)
// ============================================================
ll legendre(ll n, ll p) {
    ll e = 0;
    while (n) { n /= p; e += n; }
    return e;
}

// ============================================================
//  Caso 2: ceros finales de n! en base 10 (CSES Trailing Zeros)
// ============================================================
ll cerosFinales(ll n) {
    return legendre(n, 5LL); // siempre hay mas factores 2 que 5
}

// ============================================================
//  Caso 3: ceros finales de n! en base b = mayor k con b^k | n!
//  b = prod p^a  ->  k = min( v_p(n!) / a )
// ============================================================
ll cerosEnBase(ll n, ll b) {
    ll k = LLONG_MAX;
    for (auto [p, a] : factorizar(b))
        k = min(k, legendre(n, p) / a);
    return k;
}

// ============================================================
//  Caso 4: factorizacion prima completa de n!
// ============================================================
vector<pair<ll, ll>> factorizarFactorial(ll n) {
    vector<pair<ll, ll>> f;
    for (ll p : criba(n))
        f.push_back({p, legendre(n, p)});
    return f;
}

// ============================================================
//  Caso 5: exponente de p en C(n, k)
// ============================================================
ll vpBinomial(ll n, ll k, ll p) {
    return legendre(n, p) - legendre(k, p) - legendre(n - k, p);
}

// Teorema de Kummer: acarreos al sumar k + (n-k) en base p (mismo valor)
ll kummer(ll n, ll k, ll p) {
    ll a = k, b = n - k, carry = 0, acarreos = 0;
    while (a > 0 || b > 0 || carry > 0) {
        ll s = a % p + b % p + carry;
        carry = (s >= p);
        acarreos += carry;
        a /= p; b /= p;
    }
    return acarreos;
}

// ============================================================
//  Caso 6: C(n, k) mod m con m CUALQUIERA, n hasta ~1e7
//  C(n,k) = prod p^{v_p(C(n,k))} -> solo multiplicaciones
// ============================================================
ll binomLegendre(ll n, ll k, ll m, const vector<ll> &primos) {
    if (k < 0 || k > n) return 0;
    ll res = 1 % m;
    for (ll p : primos) {
        if (p > n) break;
        ll e = vpBinomial(n, k, p);
        if (e) res = (lll)res * modpow(p, e, m) % m;
    }
    return res;
}

// ============================================================
//  Caso 7: menor n tal que m | n!
//  Busqueda binaria por cada p^a de m (v_p(n!) es monotono)
// ============================================================
ll menorNPotencia(ll p, ll a) {
    ll lo = 0, hi = p * a; // v_p((p*a)!) >= a siempre
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (legendre(mid, p) >= a) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

ll menorNFactorialDivisible(ll m) {
    ll n = 1;
    for (auto [p, a] : factorizar(m))
        n = max(n, menorNPotencia(p, a));
    return n;
}

// ============================================================
//  Caso 8: C(n, k) mod m con n ENORME (hasta 1e18), m no primo
//  Lucas generalizado (Granville) + Teorema Chino del Resto.
//  Requiere que cada p^a de m sea <= ~1e6 (tabla precalculada).
// ============================================================
struct BinomPotenciaPrimo {
    ll p, a, pa;
    vector<ll> pref; // producto de j <= i con gcd(j,p)=1, mod p^a

    BinomPotenciaPrimo(ll p_, ll a_) : p(p_), a(a_) {
        pa = 1;
        for (int i = 0; i < a; i++) pa *= p;
        pref.assign(pa + 1, 1);
        for (ll i = 1; i <= pa; i++)
            pref[i] = (i % p == 0) ? pref[i - 1] : pref[i - 1] * i % pa;
    }

    // n! sin factores p, mod p^a
    // n! = p^{n/p} * (n/p)! * (producto de los no multiplos de p)
    ll factSinP(ll n) {
        if (n == 0) return 1;
        ll res = modpow(pref[pa], n / pa, pa) * pref[n % pa] % pa;
        return res * factSinP(n / p) % pa;
    }

    ll binom(ll n, ll k) {
        if (k < 0 || k > n) return 0;
        ll e = vpBinomial(n, k, p); // Legendre
        if (e >= a) return 0;
        ll res = factSinP(n);
        res = res * inverso(factSinP(k), pa) % pa;
        res = res * inverso(factSinP(n - k), pa) % pa;
        return res * modpow(p, e, pa) % pa;
    }
};

// x = r1 (mod m1), x = r2 (mod m2), gcd(m1, m2) = 1
pair<ll, ll> crt(ll r1, ll m1, ll r2, ll m2) {
    ll t = (lll)(((r2 - r1) % m2 + m2) % m2) * inverso(m1 % m2, m2) % m2;
    ll m = m1 * m2;
    return {(ll)((r1 + (lll)m1 * t) % m), m};
}

ll binomGranville(ll n, ll k, ll m) {
    if (m == 1) return 0;
    ll r = 0, mod = 1;
    for (auto [p, a] : factorizar(m)) {
        BinomPotenciaPrimo bp(p, a);
        auto [x, nm] = crt(r, mod, bp.binom(n, k), bp.pa);
        r = x; mod = nm;
    }
    return r;
}

// ============================================================
//  main
// ============================================================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "== Caso 1: v_p(n!) ==\n";
    cout << "v_2(10!)  = " << legendre(10, 2) << "\n";   // 8
    cout << "v_3(100!) = " << legendre(100, 3) << "\n";  // 48

    cout << "\n== Caso 2: ceros finales ==\n";
    cout << "100! -> " << cerosFinales(100) << "\n";           // 24
    cout << "1e9! -> " << cerosFinales(1000000000LL) << "\n";  // 249999998

    cout << "\n== Caso 3: ceros en base b ==\n";
    cout << "10! base 12 -> " << cerosEnBase(10, 12) << "\n";  // 4
    cout << "10! base 2  -> " << cerosEnBase(10, 2) << "\n";   // 8

    cout << "\n== Caso 4: factorizacion de 10! ==\n10! = ";
    auto f = factorizarFactorial(10);                          // 2^8 * 3^4 * 5^2 * 7^1
    for (size_t i = 0; i < f.size(); i++)
        cout << f[i].first << "^" << f[i].second << (i + 1 < f.size() ? " * " : "\n");

    cout << "\n== Caso 5: v_p(C(n,k)) ==\n";                   // C(10,3) = 120 = 2^3 * 15
    cout << "v_2(C(10,3)) Legendre = " << vpBinomial(10, 3, 2)
         << ", Kummer = " << kummer(10, 3, 2) << "\n";         // 3, 3

    cout << "\n== Caso 6: C(n,k) mod m con criba ==\n";
    ll N = 1000000;
    vector<ll> primos = criba(N);
    cout << "C(10,3) mod 1000   = " << binomLegendre(10, 3, 1000, primos) << "\n";  // 120
    cout << "C(1e6,5e5) mod 1e9 = " << binomLegendre(N, N / 2, 1000000000LL, primos) << "\n";

    cout << "\n== Caso 7: menor n con m | n! ==\n";
    cout << "m = 1000 -> " << menorNFactorialDivisible(1000) << "\n";  // 15
    cout << "m = 1024 -> " << menorNFactorialDivisible(1024) << "\n";  // 12

    cout << "\n== Caso 8: n enorme (Granville + CRT) ==\n";
    cout << "C(1e18, 1e9) mod 1e6 = "
         << binomGranville(1000000000000000000LL, 1000000000LL, 1000000LL) << "\n";
    cout << "C(1e6,5e5) mod 1e6: Granville = " << binomGranville(N, N / 2, 1000000LL)
         << ", criba = " << binomLegendre(N, N / 2, 1000000LL, primos) << "\n";  // deben coincidir

    // Verificacion contra el triangulo de Pascal
    const int T = 60;
    bool ok = true;
    vector<ll> pr = criba(T);
    for (ll m : {2LL, 12LL, 100LL, 360LL, 1000LL, 97LL * 64}) {
        vector<vector<ll>> C(T + 1, vector<ll>(T + 1, 0));
        for (int n = 0; n <= T; n++) {
            C[n][0] = 1 % m;
            for (int k = 1; k <= n; k++) C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % m;
        }
        for (int n = 0; n <= T; n++)
            for (int k = 0; k <= n; k++) {
                if (binomLegendre(n, k, m, pr) != C[n][k]) ok = false;
                if (binomGranville(n, k, m) != C[n][k]) ok = false;
            }
    }
    cout << "\nVerificacion contra Pascal: " << (ok ? "OK" : "FALLO") << "\n";
    return 0;
}


// El código cubre ocho casos de uso:

// 1. legendre: calcula v_p(n!).
// 2. cerosFinales: resuelve CSES Trailing Zeros.
// 3. cerosEnBase: cuenta los ceros finales de n! en cualquier base. Por ejemplo, 10! en base 12 termina en 4 ceros.
// 4. factorizarFactorial: da la factorización prima completa de n!.
// 5. vpBinomial / kummer: da el exponente de p en C(n, k), calculado de dos formas para comparar.
// 6. binomLegendre: calcula C(n, k) mod m con m no primo, para n hasta ~10⁷.
// 7. menorNFactorialDivisible: encuentra el menor n tal que m divide a n!, con búsqueda binaria sobre Legendre.
// 8. binomGranville: calcula C(n, k) mod m con n hasta 10¹⁸ y m no primo. Cada potencia pᵃ de m debe ser ≤ ~10⁶ por la tabla precalculada.