#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {

        ll n; cin >> n;

        vector<ll> lu(n);

        ll ceros = 0;

        for (ll i = 0; i < n; i++)
        {
            cin >> lu[i];
            if (lu[i] == 0) ceros++;
        }

        if (ceros == 1) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        string s(n, 'A');

        if (ceros >= 2) {
            
            bool usado = false;

            for (ll i = 0; i < n; i++)
            {
                if (lu[i] != 0) {
                    s[i] = 'C';
                    continue;
                }

                if (!usado) {
                    s[i] = 'B';
                    usado = true;
                    continue;
                }

                s[i] = 'A';
            }
        }

        cout << s << endl;
    }
    return 0;
}