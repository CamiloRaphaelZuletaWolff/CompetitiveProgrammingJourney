#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

// ================== PARTE CONFIGURABLE ==================
struct Node {
    long long val;
};

Node NEUTRO = {0};  // elemento neutro (0 para suma, LLONG_MAX para min, etc.)

Node combinar(const Node &a, const Node &b) {
    return {a.val + b.val};  // cambia esto segun el problema
}
// ========================================================

int n;
long long a[MAXN];   // arreglo original (0-indexado)
Node st[4 * MAXN];
Node res;            // aqui queda el resultado de query

void build(int nodo = 1, int l = 0, int r = n - 1) {
    if (l == r) { st[nodo] = {a[l]}; return; }
    int m = (l + r) / 2;
    build(2 * nodo, l, m);
    build(2 * nodo + 1, m + 1, r);
    st[nodo] = combinar(st[2 * nodo], st[2 * nodo + 1]);
}

void update(int pos, long long v, int nodo = 1, int l = 0, int r = n - 1) {
    if (l == r) { st[nodo] = {v}; return; }
    int m = (l + r) / 2;
    if (pos <= m) update(pos, v, 2 * nodo, l, m);
    else          update(pos, v, 2 * nodo + 1, m + 1, r);
    st[nodo] = combinar(st[2 * nodo], st[2 * nodo + 1]);
}

// Antes de llamar: res = NEUTRO;  Luego: query(ql, qr);
void query(int ql, int qr, int nodo = 1, int l = 0, int r = n - 1) {
    if (qr < l || r < ql) return;               // fuera del rango
    if (ql <= l && r <= qr) {                    // totalmente dentro
        res = combinar(res, st[nodo]);
        return;
    }
    int m = (l + r) / 2;
    query(ql, qr, 2 * nodo, l, m);
    query(ql, qr, 2 * nodo + 1, m + 1, r);
}

// ==================== EJEMPLO DE USO ====================
int main() {
    n = 6;
    long long datos[] = {5, 2, 7, 1, 9, 3};
    for (int i = 0; i < n; i++) a[i] = datos[i];

    build();

    res = NEUTRO;
    query(1, 4);                       // suma de a[1..4]
    cout << res.val << "\n";           // 19

    update(2, 10);                     // a[2] = 10

    res = NEUTRO;
    query(0, 5);
    cout << res.val << "\n";           // 30

    return 0;
}