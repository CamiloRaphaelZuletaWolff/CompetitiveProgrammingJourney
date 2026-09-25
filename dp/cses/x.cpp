#include <bits/stdc++.h>
#include <thread>
using namespace std;

const int LIM = 1000001;
int dp[LIM];
bool vis[LIM];

int solve(int v) {
    if (v == 0) return 0;
    if (vis[v]) return dp[v];
    vis[v] = true;
    int mejor = INT_MAX, tmp = v;
    while (tmp > 0) {
        int d = tmp % 10; tmp /= 10;
        if (d > 0) mejor = min(mejor, solve(v - d) + 1);
    }
    return dp[v] = mejor;
}

void run() {
    int n; cin >> n;
    cout << solve(n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::thread t(run);
    t.join();
    return 0;
}