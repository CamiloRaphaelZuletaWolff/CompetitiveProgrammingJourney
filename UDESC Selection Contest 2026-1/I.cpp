#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n; cin >> n;
    if (n > 9) {
        int nueves = n / 9;

        string res = "";
        int first = n - nueves * 9;
        if (first > 0) res += to_string(first);
        for (int i = 0; i < nueves; i++) {
            res += "9";
        }
        cout << res;
    } else {
        cout << n;
    }

    return 0;

}