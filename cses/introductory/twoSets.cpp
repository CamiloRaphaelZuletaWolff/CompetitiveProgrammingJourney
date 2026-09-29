#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    vector<ll> lu1,lu2;
    if(n%2 == 1){
        ll aux = n-3;
        if((aux/2)%2 == 0){
            lu1.push_back(1LL);
            lu1.push_back(2LL);
            lu2.push_back(3LL);
            ll i = 4;
            for (ll cont = 0; cont < aux/2; cont++)
            {
                if(i%2 == 0){
                    lu1.push_back(i);
                    lu1.push_back(n-cont);
                }else{
                    lu2.push_back(i);
                    lu2.push_back(n-cont);
                }
                i++;
            }
        }else{
            cout<<"NO";
            return 0;
        }
    }else{
        ll aux = n;
        if((aux/2)%2 == 0){
            // lu1.push_back(1LL);
            // lu1.push_back(2LL);
            // lu2.push_back(3LL);
            ll i = 1;
            for (ll cont = 0; cont < aux/2; cont++)
            {
                if(i%2 == 0){
                    lu1.push_back(i);
                    lu1.push_back(n-cont);
                }else{
                    lu2.push_back(i);
                    lu2.push_back(n-cont);
                }
                i++;
            }
        }else{
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES"<<endl;
    cout<<lu1.size()<<endl;
    for (ll i = 0; i < lu1.size(); i++)
    {
        cout<<lu1[i]<<" ";
    }
    cout<<endl;
    cout<<lu2.size()<<endl;
    for (ll i = 0; i < lu2.size(); i++)
    {
        cout<<lu2[i]<<" ";
    }
    

    return 0;

}