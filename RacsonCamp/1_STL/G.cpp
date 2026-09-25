#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll a,b,c; cin>>a>>b>>c;

    queue<ll> pilitaA,pilitaB,pilitaC;

    ll res1 = 0, res2=0, res3=0;


    for (ll i = 0; i < a; i++)
    {
        ll x;cin>>x;
        pilitaA.push(x);
        res1+=x;
    }

    for (ll i = 0; i < b; i++)
    {
        ll x;cin>>x;
        pilitaB.push(x);
        res2+=x;
    }
    for (ll i = 0; i < c; i++)
    {
        ll x;cin>>x;
        pilitaC.push(x);
        res3+=x;
    }

    ll mini = min({res1,res2,res3});

    while (res1 != res2 || res1 != res3 || res2 != res3)
    {

        if(res1 > mini && !pilitaA.empty()){
            
            res1 -= pilitaA.front();
            pilitaA.pop();

        }
        if(res2 > mini && !pilitaB.empty()){
            
            res2 -= pilitaB.front();
            pilitaB.pop();

        }
        if(res3 > mini && !pilitaC.empty()){
            
            res3 -= pilitaC.front();
            pilitaC.pop();

        }
        mini = min({res1,res2,res3,mini});
        


    }
    cout<<res1<<endl;






    


    return 0;

}