#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    //freopen("../../output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> x(n), h(x);
    for (int &e: x) cin >> e;
    for (int &e: h) cin >> e;
    x.push_back(1000000000);
    h.push_back(1000000000);
    int count = 0, last = -1000000000;

    for (int i = 0; i <= n; i++) {
        int p = x[i];
        if (last > p - h[i]) {
            last = p;
            count++;
        } else {
            int nxt = x[i+1];
            if (nxt - h[i+1] > p) {
                last = p;
            } else {
                last = p + h[i];
                count++;
            }
        }
    }

    cout << count;



    

    return 0;

}