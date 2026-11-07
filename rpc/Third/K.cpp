#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    int n, m, t; cin >>  n >> m >> t;
    vector<int> p(m), s(m), d(m), l(m);
    for (int i = 0; i < m; i++) {
        char c; cin >> p[i] >> s[i] >> c >> l[i];
        d[i] = (c == 'L')? 0: 1;
    }
    
    for (int i = 0; i < m; i++) {
        if (d[i] == 0) { // Va a la izquierda
            int head = p[i] + (s[i] * t * -1);
            int tail = p[i] + (s[i] * t * -1) + l[i] - 1;
            if (head >= n || tail < 0) cout << string(n, '=') << '\n';
            else {
                int a =  max(head, 0LL);
                int b = min(tail, n - 1);
                cout << string(a, '=');
                if (head < 0) cout << string(b - a + 1, '#');
                else cout << '!' << string(b - a, '#');
                cout << string(n - b - 1, '=') << '\n';
            }
        } else { // Va a la derecha
            int head = p[i] + (s[i] * t) + l[i] - 1;
            int tail = p[i] + (s[i] * t);
            if (head < 0 || tail >= n) cout << string(n, '=') << '\n';
            else {
                int a = max(tail, 0LL);
                int b = min(head, n - 1);
                cout << string(a, '=');
                if (head >= n) cout << string(b - a + 1, '#');
                else cout << string(b - a, '#') << '!';
                cout << string(n - b - 1, '=') << '\n';
            }
        }
    }

    return 0;
}