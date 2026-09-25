#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

// ============================================================================
// AHO-CORASICK — PLANTILLA CAJA NEGRA
// Uso basico:
//   AhoCorasick<26, 'a'> AC;
//   int id = AC.insert(patron);   // guarda el id que devuelve
//   AC.build();                   // OBLIGATORIO antes de cualquier consulta
//   ... llamar a los metodos del caso que necesites ...
// Borra los bloques de caso que no uses. Dependencias:
//   - Todos los casos requieren el NUCLEO.
//   - CASO 8 requiere ademas llamar a buildEuler() despues de build().
// ============================================================================

template<int E = 26, char MINC = 'a'>
struct AhoCorasick {

    // ======================== NUCLEO (no borrar) ============================
    int nodes = 0;
    vector<array<int, E>> go;     // automata completo tras build()
    vector<int> suf;              // enlace de sufijo
    vector<int> super;            // enlace de salida (terminal mas cercano)
    vector<int> depth;            // longitud de la cadena del nodo
    vector<int> cntTerm;          // # terminales en la cadena de sufijos
    vector<bool> terminal;
    vector<vector<int>> patsAt;   // ids de patrones que terminan en el nodo
    vector<int> endNode;          // endNode[id] = nodo final del patron id
    vector<int> byLevel;          // nodos en orden BFS (raiz primero)

    AhoCorasick() { addNode(); }

    int addNode() {
        go.push_back({});
        suf.push_back(0); super.push_back(0); depth.push_back(0);
        cntTerm.push_back(0); terminal.push_back(false);
        patsAt.emplace_back();
        return nodes++;
    }

    // Devuelve el id del patron (0, 1, 2, ...). Admite patrones repetidos.
    int insert(const string& s) {
        int pos = 0;
        for (char ch : s) {
            int c = ch - MINC;
            if (!go[pos][c]) {
                int v = addNode();
                depth[v] = depth[pos] + 1;
                go[pos][c] = v;
            }
            pos = go[pos][c];
        }
        terminal[pos] = true;
        int id = (int)endNode.size();
        endNode.push_back(pos);
        patsAt[pos].push_back(id);
        return id;
    }

    void build() {
        queue<int> Q;
        Q.push(0);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            byLevel.push_back(u);
            super[u] = (suf[u] == 0 || terminal[suf[u]]) ? suf[u] : super[suf[u]];
            cntTerm[u] = (u ? cntTerm[suf[u]] : 0) + (int)patsAt[u].size();
            for (int c = 0; c < E; ++c) {
                int v = go[u][c];
                if (v) { suf[v] = u ? go[suf[u]][c] : 0; Q.push(v); }
                else go[u][c] = u ? go[suf[u]][c] : 0;
            }
        }
    }

    // Avanza el automata un caracter. El estado p siempre representa el
    // sufijo mas largo del texto leido que es prefijo de algun patron.
    int next(int p, char ch) const { return go[p][ch - MINC]; }

    // ==== CASO 1: cuantas veces aparece CADA patron en T ====================
    // O(|T| + nodos). res[id] = ocurrencias del patron id.
    vector<ll> countEach(const string& T) {
        vector<ll> f(nodes, 0);
        int p = 0;
        for (char ch : T) { p = next(p, ch); f[p]++; }
        for (int i = nodes - 1; i > 0; --i) {
            int x = byLevel[i];
            f[suf[x]] += f[x];
        }
        vector<ll> res(endNode.size());
        for (size_t i = 0; i < endNode.size(); ++i) res[i] = f[endNode[i]];
        return res;
    }

    // ==== CASO 2: total de ocurrencias de todos los patrones juntos ========
    // O(|T|). Equivale a sumar countEach pero sin la propagacion.
    ll countTotal(const string& T) {
        ll ans = 0;
        int p = 0;
        for (char ch : T) { p = next(p, ch); ans += cntTerm[p]; }
        return ans;
    }

    // ==== CASO 3: existencia (que patrones aparecen al menos una vez) ======
    // O(|T| + nodos). res[id] = true si el patron id es subcadena de T.
    vector<bool> occurs(const string& T) {
        vector<ll> c = countEach(T);
        vector<bool> res(c.size());
        for (size_t i = 0; i < c.size(); ++i) res[i] = c[i] > 0;
        return res;
    }

    // ==== CASO 4: todas las ocurrencias con su posicion =====================
    // O(|T| + #ocurrencias). Devuelve pares (posInicial, idPatron).
    vector<pair<int,int>> allMatches(const string& T) {
        vector<pair<int,int>> res;
        int p = 0;
        for (int i = 0; i < (int)T.size(); ++i) {
            p = next(p, T[i]);
            for (int u = terminal[p] ? p : super[p]; u; u = super[u])
                for (int id : patsAt[u])
                    res.push_back({i - depth[u] + 1, id});
        }
        return res;
    }

    // ==== CASO 5: patron mas largo que termina en cada posicion de T =======
    // O(|T|). res[i] = id del patron mas largo que termina en T[i], o -1.
    // Util para DP de segmentacion / cobertura de texto.
    vector<int> longestEndingAt(const string& T) {
        vector<int> res(T.size(), -1);
        int p = 0;
        for (int i = 0; i < (int)T.size(); ++i) {
            p = next(p, T[i]);
            int u = terminal[p] ? p : super[p];
            if (u) res[i] = patsAt[u][0];
        }
        return res;
    }

    // ==== CASO 6: contar cadenas de longitud L que NO contienen ============
    // ningun patron (mod). O(L * nodos * E). Para "contienen al menos uno":
    // pow(E, L) - countAvoiding(L). Estados con cntTerm > 0 estan prohibidos.
    ll countAvoiding(ll L) {
        vector<ll> dp(nodes, 0);
        dp[0] = 1;
        for (ll s = 0; s < L; ++s) {
            vector<ll> nd(nodes, 0);
            for (int u = 0; u < nodes; ++u) if (dp[u] && !cntTerm[u])
                for (int c = 0; c < E; ++c) {
                    int v = go[u][c];
                    if (!cntTerm[v]) nd[v] = (nd[v] + dp[u]) % MOD;
                }
            dp = move(nd);
        }
        ll ans = 0;
        for (int u = 0; u < nodes; ++u) if (!cntTerm[u]) ans = (ans + dp[u]) % MOD;
        return ans;
    }

    // ==== CASO 7: igual que el caso 6 pero con L gigante (hasta 1e18) ======
    // Exponenciacion de matrices: O(nodos^3 log L). Usable con nodos <= ~120.
    ll countAvoidingBig(ll L) {
        int n = nodes;
        typedef vector<vector<ll>> Mat;
        auto mul = [&](const Mat& A, const Mat& B) {
            Mat C(n, vector<ll>(n, 0));
            for (int i = 0; i < n; ++i)
                for (int k = 0; k < n; ++k) if (A[i][k])
                    for (int j = 0; j < n; ++j)
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            return C;
        };
        Mat M(n, vector<ll>(n, 0)), R(n, vector<ll>(n, 0));
        for (int u = 0; u < n; ++u) {
            R[u][u] = 1;
            if (cntTerm[u]) continue;
            for (int c = 0; c < E; ++c)
                if (!cntTerm[go[u][c]]) M[u][go[u][c]]++;
        }
        while (L) {
            if (L & 1) R = mul(R, M);
            M = mul(M, M);
            L >>= 1;
        }
        ll ans = 0;
        for (int v = 0; v < n; ++v) if (!cntTerm[v]) ans = (ans + R[0][v]) % MOD;
        return ans;
    }

    // ==== CASO 8: activar/desactivar patrones dinamicamente =================
    // (estilo CF 163E e-Government). Llamar buildEuler() tras build().
    // setActive(id, on/off) en O(log nodos);
    // queryActive(T) = total de ocurrencias de los patrones ACTIVOS, O(|T| log nodos).
    // Se apoya en el arbol de enlaces de sufijo + Euler tour + BIT.
    vector<int> tin, tout;
    vector<ll> bit;
    vector<bool> active;

    void buildEuler() {
        vector<vector<int>> hijos(nodes);
        for (int i = 1; i < nodes; ++i) {
            int v = byLevel[i];
            hijos[suf[v]].push_back(v);
        }
        tin.assign(nodes, 0); tout.assign(nodes, 0);
        bit.assign(nodes + 1, 0);
        active.assign(endNode.size(), false);
        int timer = 0;
        stack<pair<int, size_t>> st;
        st.push({0, 0});
        tin[0] = timer++;
        while (!st.empty()) {
            auto& [u, i] = st.top();
            if (i < hijos[u].size()) {
                int v = hijos[u][i++];
                tin[v] = timer++;
                st.push({v, 0});
            } else {
                tout[u] = timer;
                st.pop();
            }
        }
    }

    void bitAdd(int i, ll v) { for (++i; i <= nodes; i += i & -i) bit[i - 1] += v; }
    ll bitPoint(int i) { ll s = 0; for (++i; i > 0; i -= i & -i) s += bit[i - 1]; return s; }

    void setActive(int id, bool on) {
        if (active[id] == on) return;
        active[id] = on;
        int u = endNode[id];
        ll v = on ? 1 : -1;
        bitAdd(tin[u], v);
        bitAdd(tout[u], -v);
    }

    ll queryActive(const string& T) {
        ll ans = 0;
        int p = 0;
        for (char ch : T) { p = next(p, ch); ans += bitPoint(tin[p]); }
        return ans;
    }
};

// ============================================================================
// DEMO — borra este main y escribe el tuyo
// ============================================================================
int main() {
    cin.tie(0)->sync_with_stdio(false);

    AhoCorasick<26, 'a'> AC;
    vector<string> pats = {"arco", "co", "barco", "oro", "toro"};
    for (string& s : pats) AC.insert(s);
    AC.build();
    AC.buildEuler();

    const string T = "coroparcotoro";

    cout << "CASO 1 (ocurrencias por patron):\n";
    vector<ll> f = AC.countEach(T);
    for (size_t i = 0; i < pats.size(); ++i)
        cout << "  " << pats[i] << " -> " << f[i] << "\n";

    cout << "CASO 2 (total): " << AC.countTotal(T) << "\n";

    cout << "CASO 3 (existencia):";
    vector<bool> ex = AC.occurs(T);
    for (size_t i = 0; i < pats.size(); ++i)
        if (ex[i]) cout << " " << pats[i];
    cout << "\n";

    cout << "CASO 4 (posicion, patron):\n";
    for (auto [pos, id] : AC.allMatches(T))
        cout << "  i=" << pos << " " << pats[id] << "\n";

    cout << "CASO 5 (mas largo por posicion):";
    vector<int> le = AC.longestEndingAt(T);
    for (int i = 0; i < (int)T.size(); ++i)
        if (le[i] != -1) cout << " [" << i << ":" << pats[le[i]] << "]";
    cout << "\n";

    cout << "CASO 6 (evitar, L=2): " << AC.countAvoiding(2) << "\n";
    cout << "CASO 7 (evitar, L=2, matrices): " << AC.countAvoidingBig(2) << "\n";

    AC.setActive(1, true);
    AC.setActive(3, true);
    cout << "CASO 8 (activos co+oro): " << AC.queryActive(T) << "\n";
    AC.setActive(3, false);
    cout << "CASO 8 (activo solo co): " << AC.queryActive(T) << "\n";

    return 0;
}