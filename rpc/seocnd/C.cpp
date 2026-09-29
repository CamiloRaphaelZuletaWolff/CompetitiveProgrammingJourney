#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<vector<int>> grafo(n+1);
    vector<int> arr(n+1);
    for (int i = 2; i <= n; i++)
    {
        int a; cin >> a;
        arr[i] = a;
        grafo[a].push_back(i);
    }
    vll dp(n+1);
    vector<int> cant(n+1, 1);

    vector<int> fx(n+1);
    for (int i = n; i >= 2; i--)
    {
        dp[arr[i]] += dp[i] + cant[i];
        cant[arr[i]] += cant[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto x : grafo[i]) {
            dp[x] = dp[i] + cant[i] - (2LL * cant[x]);
            cant[x] = cant[i];
        }
    }
    vector<int> mx1(n+1);
    vector<int> mx2(n+1);
    for (int i = n; i >= 1; i--) {
        fx[i] = max(fx[i], mx1[i] + mx2[i]);
        if (i > 1) {
            int p = arr[i];
            fx[p] = max(fx[p], fx[i]);
            int d = mx1[i] + 1;
            if (d > mx1[p]) {
                mx2[p] = mx1[p];
                mx1[p] = d;
            } else if (d > mx2[p]) {
                mx2[p] = d;
            }
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += dp[i];
    }
    cout << res / 2 << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << fx[i] << " ";
    }
    cout << "\n";

    return 0;
}