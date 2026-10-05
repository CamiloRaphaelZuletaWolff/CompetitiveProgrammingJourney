#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n,m; cin>>n>>m;

    ll a =0 , b= 0;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        a+=x;
    }
    
    for (ll i = 0; i < m; i++)
    {
        ll x; cin>>x;
        b+=x;
    }

    ll propina = (a+10-1)/10;

    // cout<<a<<" "<<b<<endl;
    // cout<<a + propina <<endl;
    // cout<< b<<endl;

    if(a+propina <= b){
        cout<<"YES"<<endl;

    }else{
        cout<<"NO"<<endl;
    }

    







    


    




    return 0;

}