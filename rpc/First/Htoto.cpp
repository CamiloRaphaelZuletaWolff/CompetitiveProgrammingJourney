#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(),(x).end();


vector<ll> getDiv(ll N){
    vector<ll> lu;
    for (ll i = 1; i * i <= N; i++)
    {
        if(N% i == 0){
            lu.push_back(i);
            if(i*i != N) lu.push_back(N/i);
        }
    }
    sort(lu.begin(), lu.end());

    return lu;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n,k,p;cin>>n>>k>>p;

    ll l = (n+p-1)/p;

    ll r = k;


    auto lu = getDiv(n);

    ll contador = 0;

    for (ll i = 0; i < lu.size(); i++)
    {
        if(lu[i] >= l && lu[i] <= r){
            contador++;
        }
    }

    

    cout<<contador<<endl;

    if(contador == 0){
        return 0;
    }



    ll aux = 0;
    for (ll i = 0; i < lu.size(); i++)
    {
        // if(aux != 0) cout<<endl;
        if(lu[i] >= l && lu[i] <= r){
            if(aux!=0) cout<<'\n';
            cout<<lu[i];
            aux++;
        }
    }
    cout<<endl;
    
    

    





    return 0;

}