#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    ll t; cin>>t;
    while(t--){
        ll a,b,r; cin>>a>>b>>r;

        cout<<a << " "<<b+r<<endl;
    }
    return 0;

}