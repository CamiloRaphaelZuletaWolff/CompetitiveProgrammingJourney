#include<bits/stdc++.h>

using namespace std;
#define nohay
typedef long long ll;

void solve() {
    ll n, a, b; cin >> n >> a >> b;
    int da = log10(a) + 1, db = log10(b) + 1;
    if ((n != a * b) || (a % 10 == 0 && b % 10 == 0) || da != db) {
        cout << "NO\n";
        return;
    }
    unordered_map<int, int> ndigits, abdigits;
    for (char e: to_string(n)) ndigits[e - '0']++;
    for (char e: to_string(a)) abdigits[e - '0']++;
    for (char e: to_string(b)) abdigits[e - '0']++;
    if (ndigits == abdigits) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}