#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n,m,k; cin>>n>>m>>k;

    vector<ll> personas;

    priority_queue<ll, vector<ll>, greater<ll>> colita;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        personas.push_back(x);
    }

    for (ll i = 0; i < m; i++)
    {
        ll x; cin>>x;
        colita.push(x);
    }

    sort(personas.begin(), personas.end());


    ll lu = 0;

    for (ll i = 0; i < n;)
    {
        ll actualPersonas = personas[i];
        if(colita.empty()) break;
        ll actualCola = colita.top();



        if(actualCola  <= actualPersonas + k && actualCola >= actualPersonas -k){
            lu++;
            i++;
            colita.pop();
            continue;
        }

        if(actualCola > actualPersonas +k){
            i++;
            continue;
        }

        if(actualCola < actualPersonas -k){
            colita.pop();
            continue;
        }
    }

    cout<<lu<<endl;
    
    

    


    return 0;
}