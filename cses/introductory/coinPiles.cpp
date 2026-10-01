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
        ll x,y; cin>>x>>y;

        if(x == 0 && y == 0){
            cout<< "YES"<<endl;
            continue;
        }
        if(x == 0 || y == 0){

            cout<<"NO"<<endl;
            continue;
        }
        if((x+y)%3 == 0 && max(x,y) <= min(x,y) * 2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    

    return 0;

}