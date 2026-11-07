#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int A, B, C; cin >> A >> B >> C;
    int res = B - A;

    if (res == 0) cout << "S\n";
    else if (res % C == 0) cout << "S\n"; 
    else cout << "N\n";

    return 0;

}