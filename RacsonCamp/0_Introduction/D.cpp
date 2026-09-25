#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    ll t; cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        if(n%2 == 0){
            cout<<n+2;
        }else cout<<n+1;

        cout<<endl;
    }
    


    return 0;

}