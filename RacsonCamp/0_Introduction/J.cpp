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
        ll a; cin>>a;

        if(a > 0){
            cout<<1<<endl;
            continue;
        }
        if(a <0){
            cout<<-1<<endl;
            continue;
        }
        cout<<0<<endl;


    }
    


}