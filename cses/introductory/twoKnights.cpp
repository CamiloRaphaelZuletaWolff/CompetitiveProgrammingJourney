#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll k; cin>>k;

    for (ll i = 1; i <= k; i++)
    {
        cout<<(((i*i-1)*(i*i))/2) - 4 * (i-1)*(i-2)<<endl;
    }
    
    

    return 0;

}