// =====================================================================
//  TEMPLATE DE GEOMETRÍA COMPUTACIONAL — C++17
//
//  CÓMO COPIAR:
//   1. Copia SIEMPRE la sección [0] BASE (es obligatoria).
//   2. Copia solo las secciones que necesites. Cada una indica
//      "Requiere: ..." y termina con una línea  ==== FIN [X] ====
//   3. Copia el MAIN del final (o el tuyo).
//
//  ÍNDICE                                   REQUIERE
//   [0]  BASE (Point, cross, orient)        —            OBLIGATORIA
//   [1]  Segmentos (enteros)                [0]
//   [2]  Rectas y distancias (ld)           [0] [1]
//   [3]  Polígonos (área, punto dentro, Pick) [0] [1]
//   [4]  Envolvente convexa                 [0]
//   [5]  Punto en polígono convexo O(log n) [0] [1]
//   [6]  Par de puntos más cercano          [0]
//   [7]  Diámetro (rotating calipers)       [0]
//   [8]  Orden angular (sin atan2)          [0]
//   [9]  Truco Manhattan                    [0]
//   [10] Círculos (ld)                      [0]
//   [11] Corte de polígono por recta (ld)   [0] [2]
//   [12] Intersección de semiplanos (ld)    [0]
// =====================================================================


// ======================== [0] BASE — OBLIGATORIA ======================
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9;
const ld PI = acosl(-1.0L);

// Signo con tolerancia. Con ll el EPS no estorba (x > 1e-9 <=> x >= 1).
template<class T> int sgn(T x) { return (x > EPS) - (x < -EPS); }

template<class T> struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
    Point operator*(T k) const { return Point(x * k, y * k); }
    Point operator/(T k) const { return Point(x / k, y / k); }
    bool operator<(const Point& o) const { return tie(x, y) < tie(o.x, o.y); }
    bool operator==(const Point& o) const { return x == o.x && y == o.y; }
    T dot(const Point& o) const { return x * o.x + y * o.y; }
    T cross(const Point& o) const { return x * o.y - y * o.x; }
    // cross(b - *this, c - *this): >0 si this->b->c gira a la izquierda
    T cross(const Point& b, const Point& c) const { return (b - *this).cross(c - *this); }
    T norm2() const { return x * x + y * y; }
    ld norm() const { return sqrtl((ld)norm2()); }
    ld angle() const { return atan2l((ld)y, (ld)x); }
    Point perp() const { return Point(-y, x); }          // rota 90° CCW
    Point<ld> toD() const { return Point<ld>((ld)x, (ld)y); }
    friend istream& operator>>(istream& in, Point& p) { return in >> p.x >> p.y; }
    friend ostream& operator<<(ostream& out, const Point& p) { return out << p.x << ' ' << p.y; }
};
using P  = Point<ll>;   // coordenadas enteras (lo usual en CSES)
using PD = Point<ld>;   // cuando hay divisiones, sqrt, intersecciones

// +1: c a la izquierda de a->b (CCW) | -1: a la derecha (CW) | 0: colineales
template<class T> int orient(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    return sgn(a.cross(b, c));
}
// ============================ FIN [0] BASE ============================


// ======================= [1] SEGMENTOS — Requiere [0] =================
// ¿p está sobre el segmento [a,b]? (incluye extremos)
template<class T> bool onSegment(const Point<T>& p, const Point<T>& a, const Point<T>& b) {
    return orient(a, b, p) == 0 && sgn((a - p).dot(b - p)) <= 0;
}
// ¿Se tocan [a,b] y [c,d]? Incluye tocar en extremos y traslape colineal.
template<class T> bool segIntersect(const Point<T>& a, const Point<T>& b,
                                    const Point<T>& c, const Point<T>& d) {
    int o1 = orient(a, b, c), o2 = orient(a, b, d);
    int o3 = orient(c, d, a), o4 = orient(c, d, b);
    if (o1 * o2 < 0 && o3 * o4 < 0) return true;              // cruce propio
    return onSegment(c, a, b) || onSegment(d, a, b) ||
           onSegment(a, c, d) || onSegment(b, c, d);
}
// ============================== FIN [1] ===============================


// =============== [2] RECTAS Y DISTANCIAS (ld) — Requiere [0] [1] ======
// Intersección de las RECTAS ab y cd. Precondición: no paralelas.
PD lineInter(PD a, PD b, PD c, PD d) {
    PD ab = b - a, cd = d - c;
    return a + ab * ((c - a).cross(cd) / ab.cross(cd));
}
// Proyección de p sobre la recta ab, y reflexión de p respecto a ella
PD project(PD p, PD a, PD b) {
    PD ab = b - a;
    return a + ab * ((p - a).dot(ab) / ab.norm2());
}
PD reflect(PD p, PD a, PD b) { return project(p, a, b) * 2 - p; }
// Distancia de p a la RECTA ab
ld distLine(PD p, PD a, PD b) { return fabsl(a.cross(b, p)) / (b - a).norm(); }
// Distancia de p al SEGMENTO [a,b]
ld distSeg(PD p, PD a, PD b) {
    if (a == b) return (p - a).norm();
    if ((p - a).dot(b - a) < 0) return (p - a).norm();
    if ((p - b).dot(a - b) < 0) return (p - b).norm();
    return distLine(p, a, b);
}
// Distancia entre segmentos [a,b] y [c,d]
ld distSegSeg(PD a, PD b, PD c, PD d) {
    if (segIntersect(a, b, c, d)) return 0;
    return min({distSeg(a, c, d), distSeg(b, c, d), distSeg(c, a, b), distSeg(d, a, b)});
}
// Puntos de intersección de SEGMENTOS: 0 puntos, 1 punto,
// o 2 puntos (extremos del tramo compartido si son colineales y se traslapan)
vector<PD> segInterPoints(PD a, PD b, PD c, PD d) {
    ld oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b, c), od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return {(a * ob - b * oa) / (ob - oa)};
    vector<PD> r;
    for (PD q : {a, b}) if (onSegment(q, c, d)) r.push_back(q);
    for (PD q : {c, d}) if (onSegment(q, a, b)) r.push_back(q);
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end(), [](const PD& u, const PD& v) {
        return sgn(u.x - v.x) == 0 && sgn(u.y - v.y) == 0; }), r.end());
    return r;
}
// ============================== FIN [2] ===============================


// =================== [3] POLÍGONOS — Requiere [0] [1] =================
// Área CON SIGNO multiplicada por 2 (>0 si es CCW). Exacta con enteros.
template<class T> T area2(const vector<Point<T>>& p) {
    T s = 0; int n = p.size();
    for (int i = 0; i < n; i++) s += p[i].cross(p[(i + 1) % n]);
    return s;
}
template<class T> ld perimeter(const vector<Point<T>>& p) {
    ld s = 0; int n = p.size();
    for (int i = 0; i < n; i++) s += (p[(i + 1) % n] - p[i]).norm();
    return s;
}
// Punto en polígono (cualquiera, simple). 0 = fuera, 1 = dentro, 2 = borde
template<class T> int pointInPolygon(const vector<Point<T>>& poly, const Point<T>& p) {
    int n = poly.size(); bool in = false;
    for (int i = 0; i < n; i++) {
        Point<T> a = poly[i], b = poly[(i + 1) % n];
        if (onSegment(p, a, b)) return 2;
        if ((a.y > p.y) != (b.y > p.y)) {          // arista cruza la horizontal de p
            int o = orient(a, b, p);
            if (b.y > a.y ? o > 0 : o < 0) in = !in; // cruce a la derecha de p
        }
    }
    return in ? 1 : 0;
}
// Pick: A = I + B/2 - 1. Devuelve {puntos interiores, puntos en el borde}
pair<ll, ll> latticePoints(const vector<P>& p) {
    ll B = 0, A2 = llabs(area2(p)); int n = p.size();
    for (int i = 0; i < n; i++) {
        P d = p[(i + 1) % n] - p[i];
        B += gcd(llabs(d.x), llabs(d.y));
    }
    return {(A2 - B + 2) / 2, B};
}
// ============================== FIN [3] ===============================


// ================= [4] ENVOLVENTE CONVEXA — Requiere [0] ==============
// Monotone chain O(n log n). Devuelve la envolvente en CCW sin repetir el inicio.
// keepCollinear = true -> incluye puntos colineales del borde (CSES Convex Hull).
template<class T> vector<Point<T>> convexHull(vector<Point<T>> pts, bool keepCollinear = false) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    int n = pts.size();
    if (n <= 2) return pts;
    if (keepCollinear) {                       // caso todos colineales
        bool all = true;
        for (int i = 1; i < n - 1 && all; i++) all = orient(pts[0], pts[n - 1], pts[i]) == 0;
        if (all) return pts;
    }
    auto bad = [&](int o) { return keepCollinear ? o < 0 : o <= 0; };
    vector<Point<T>> h(2 * n); int k = 0;
    for (int i = 0; i < n; i++) {                          // cadena inferior
        while (k >= 2 && bad(orient(h[k - 2], h[k - 1], pts[i]))) k--;
        h[k++] = pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {          // cadena superior
        while (k >= t && bad(orient(h[k - 2], h[k - 1], pts[i]))) k--;
        h[k++] = pts[i];
    }
    h.resize(k - 1);
    return h;
}
// ============================== FIN [4] ===============================


// ========== [5] PUNTO EN POLÍGONO CONVEXO O(log n) — Requiere [0] [1] =
// h en CCW, sin 3 vértices consecutivos colineales. 0 fuera, 1 dentro, 2 borde
template<class T> int inConvex(const vector<Point<T>>& h, const Point<T>& p) {
    int n = h.size();
    if (n == 1) return p == h[0] ? 2 : 0;
    if (n == 2) return onSegment(p, h[0], h[1]) ? 2 : 0;
    int o1 = orient(h[0], h[1], p), o2 = orient(h[0], h[n - 1], p);
    if (o1 < 0 || o2 > 0) return 0;
    int lo = 1, hi = n - 1;                    // buscar la "cuña" h0, h[lo], h[lo+1]
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (orient(h[0], h[mid], p) >= 0) lo = mid; else hi = mid;
    }
    int o = orient(h[lo], h[lo + 1], p);
    if (o < 0) return 0;
    if (o == 0) return 2;
    if ((lo == 1 && o1 == 0) || (lo + 1 == n - 1 && o2 == 0)) return 2;
    return 1;
}
// ============================== FIN [5] ===============================


// ============= [6] PAR MÁS CERCANO O(n log n) — Requiere [0] ==========
// Devuelve la distancia AL CUADRADO mínima (n >= 2).
ll closestPair(vector<P> pts) {
    sort(pts.begin(), pts.end());
    set<pair<ll, ll>> s;                       // (y, x) de la ventana activa
    ll best = LLONG_MAX; int j = 0;
    for (int i = 0; i < (int)pts.size(); i++) {
        ll d = (ll)sqrtl((ld)best) + 1;
        while (pts[i].x - pts[j].x > d) { s.erase({pts[j].y, pts[j].x}); j++; }
        auto lo = s.lower_bound({pts[i].y - d, LLONG_MIN});
        auto hi = s.upper_bound({pts[i].y + d, LLONG_MAX});
        for (auto it = lo; it != hi; ++it) {
            ll dx = pts[i].x - it->second, dy = pts[i].y - it->first;
            best = min(best, dx * dx + dy * dy);
        }
        s.insert({pts[i].y, pts[i].x});
    }
    return best;
}
// ============================== FIN [6] ===============================


// ========== [7] DIÁMETRO (ROTATING CALIPERS) — Requiere [0] ===========
// h = envolvente convexa CCW SIN colineales. Devuelve distancia^2 máxima.
template<class T> T diameter2(const vector<Point<T>>& h) {
    int n = h.size();
    if (n == 1) return 0;
    if (n == 2) return (h[0] - h[1]).norm2();
    T best = 0;
    for (int i = 0, j = 1; i < n; i++) {
        Point<T> e = h[(i + 1) % n] - h[i];
        while (e.cross(h[(j + 1) % n] - h[j]) > 0) j = (j + 1) % n;
        best = max({best, (h[i] - h[j]).norm2(), (h[(i + 1) % n] - h[j]).norm2()});
    }
    return best;
}
// ============================== FIN [7] ===============================


// ============== [8] ORDEN ANGULAR (SIN atan2) — Requiere [0] ==========
// Ordena vectores (no nulos) por ángulo en [0, 2π). Exacto con enteros.
template<class T> int half(const Point<T>& p) { return p.y < 0 || (p.y == 0 && p.x < 0); }
template<class T> bool angleLess(const Point<T>& a, const Point<T>& b) {
    int ha = half(a), hb = half(b);
    if (ha != hb) return ha < hb;
    return a.cross(b) > 0;
}
// Uso: sort(v.begin(), v.end(), angleLess<ll>);
// ============================== FIN [8] ===============================


// ================== [9] TRUCO MANHATTAN — Requiere [0] ================
// |x1-x2| + |y1-y2| = max(|u1-u2|, |v1-v2|) con u = x+y, v = x-y
P toChebyshev(const P& p) { return P(p.x + p.y, p.x - p.y); }
// Máxima distancia Manhattan entre dos puntos del conjunto
ll maxManhattan(const vector<P>& pts) {
    ll mxu = LLONG_MIN, mnu = LLONG_MAX, mxv = LLONG_MIN, mnv = LLONG_MAX;
    for (auto& p : pts) {
        P q = toChebyshev(p);
        mxu = max(mxu, q.x); mnu = min(mnu, q.x);
        mxv = max(mxv, q.y); mnv = min(mnv, q.y);
    }
    return max(mxu - mnu, mxv - mnv);
}
// ============================== FIN [9] ===============================


// ===================== [10] CÍRCULOS (ld) — Requiere [0] ==============
struct Circle { PD c; ld r; };
// Centro de la circunferencia por 3 puntos (no colineales)
PD circumcenter(PD a, PD b, PD c) {
    PD u = c - a, v = b - a;
    return a + (u * v.norm2() - v * u.norm2()).perp() / (2 * u.cross(v));
}
// Intersección círculo - RECTA ab
vector<PD> circleLine(const Circle& C, PD a, PD b) {
    PD ab = b - a, p = a + ab * ((C.c - a).dot(ab) / ab.norm2());
    ld s = a.cross(b, C.c), h2 = C.r * C.r - s * s / ab.norm2();
    if (h2 < -EPS) return {};
    if (h2 < EPS) return {p};
    PD h = ab / ab.norm() * sqrtl(h2);
    return {p - h, p + h};
}
// Intersección círculo - círculo (concéntricos -> vacío)
vector<PD> circleCircle(const Circle& A, const Circle& B) {
    PD d = B.c - A.c; ld d2 = d.norm2();
    if (sgn(d2) == 0) return {};
    ld pd = (d2 + A.r * A.r - B.r * B.r) / 2;
    ld h2 = A.r * A.r - pd * pd / d2;
    if (h2 < -EPS) return {};
    PD p = A.c + d * (pd / d2);
    if (h2 < EPS) return {p};
    PD h = d.perp() * sqrtl(h2 / d2);
    return {p - h, p + h};
}
// Círculo mínimo que encierra todos los puntos. O(n) esperado (Welzl).
Circle minEnclosingCircle(vector<PD> p) {
    shuffle(p.begin(), p.end(), mt19937(712367));
    Circle c{p[0], 0};
    auto in = [&](const PD& q) { return (q - c.c).norm() <= c.r + EPS; };
    for (int i = 0; i < (int)p.size(); i++) if (!in(p[i])) {
        c = {p[i], 0};
        for (int j = 0; j < i; j++) if (!in(p[j])) {
            c = {(p[i] + p[j]) / 2, (p[i] - p[j]).norm() / 2};
            for (int k = 0; k < j; k++) if (!in(p[k])) {
                PD o = circumcenter(p[i], p[j], p[k]);
                c = {o, (o - p[i]).norm()};
            }
        }
    }
    return c;
}
// ============================== FIN [10] ==============================


// ========= [11] CORTE DE POLÍGONO POR RECTA (ld) — Requiere [0] [2] ===
// Parte del polígono CONVEXO que queda a la izquierda (o sobre) de a->b
vector<PD> polygonCut(const vector<PD>& poly, PD a, PD b) {
    vector<PD> res; int n = poly.size();
    for (int i = 0; i < n; i++) {
        PD cur = poly[i], prv = poly[(i + n - 1) % n];
        int sc = sgn(a.cross(b, cur)), sp = sgn(a.cross(b, prv));
        if (sc * sp < 0) res.push_back(lineInter(prv, cur, a, b));
        if (sc >= 0) res.push_back(cur);
    }
    return res;
}
// ============================== FIN [11] ==============================


// ========== [12] INTERSECCIÓN DE SEMIPLANOS (ld) — Requiere [0] =======
// Semiplano = lado IZQUIERDO (incluye la recta) de la recta dirigida a -> b
struct HalfPlane {
    PD p, pq; ld ang;
    HalfPlane() {}
    HalfPlane(PD a, PD b) : p(a), pq(b - a), ang(atan2l(pq.y, pq.x)) {}
    bool out(const PD& r) const { return pq.cross(r - p) < -EPS; }
    bool operator<(const HalfPlane& o) const { return ang < o.ang; }
};
PD hpInter(const HalfPlane& s, const HalfPlane& t) {
    ld alpha = (t.p - s.p).cross(t.pq) / s.pq.cross(t.pq);
    return s.p + s.pq * alpha;
}
// O(n log n). Devuelve el polígono (CCW) intersección; vacío si no existe
// o es degenerado. Agrega una caja de tamaño INF para acotar la región.
vector<PD> hpIntersection(vector<HalfPlane> H, ld INF = 1e9) {
    PD box[4] = {PD(INF, INF), PD(-INF, INF), PD(-INF, -INF), PD(INF, -INF)};
    for (int i = 0; i < 4; i++) H.push_back(HalfPlane(box[i], box[(i + 1) % 4]));
    sort(H.begin(), H.end());
    deque<HalfPlane> dq; int len = 0;
    for (int i = 0; i < (int)H.size(); i++) {
        while (len > 1 && H[i].out(hpInter(dq[len - 1], dq[len - 2]))) { dq.pop_back(); len--; }
        while (len > 1 && H[i].out(hpInter(dq[0], dq[1]))) { dq.pop_front(); len--; }
        if (len > 0 && fabsl(H[i].pq.cross(dq[len - 1].pq)) < EPS) {   // paralelos
            if (H[i].pq.dot(dq[len - 1].pq) < 0) return {};             // opuestos
            if (H[i].out(dq[len - 1].p)) { dq.pop_back(); len--; }
            else continue;
        }
        dq.push_back(H[i]); len++;
    }
    while (len > 2 && dq[0].out(hpInter(dq[len - 1], dq[len - 2]))) { dq.pop_back(); len--; }
    while (len > 2 && dq[len - 1].out(hpInter(dq[0], dq[1]))) { dq.pop_front(); len--; }
    if (len < 3) return {};
    vector<PD> ret(len);
    for (int i = 0; i + 1 < len; i++) ret[i] = hpInter(dq[i], dq[i + 1]);
    ret.back() = hpInter(dq[len - 1], dq[0]);
    return ret;
}
// ============================== FIN [12] ==============================


// ============================ MAIN (plantilla) ========================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << fixed << setprecision(10);   // si imprimes ld

    return 0;
}
// ============================== FIN MAIN ==============================