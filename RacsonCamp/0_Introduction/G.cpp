#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll t; cin>>t;

    while (t--)
    {
        ll a,b,l,n;cin>>a>>b;

        ll maxi = max(a,b);
        ll mini = min(a,b);
        if(mini % 2 == 1) mini++;
        if(maxi % 2 == 1) maxi++;

        if((maxi-mini)/2 == 0){
            cout<<1<<endl;
            continue;
        }
        cout<<(maxi-mini)/2<<endl;
         
        

    }
    


}