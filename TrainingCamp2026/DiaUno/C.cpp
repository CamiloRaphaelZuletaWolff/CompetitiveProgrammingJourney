#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string fun(string s,int n){
    int acc = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        int aux = (s[i]-'0') - ((i == s.size()-1)? n:0) - acc;
        // cout<<aux<<"\n";
        if(aux< 0){
            s[i] = char(10+aux+ '0');
            acc =1;
        }else{
            s[i] = char(aux + '0');
            break;
        }
    }
    return s;
}

int main() {

    
    freopen("grant.in", "r", stdin);
    freopen("grant.out", "w", stdout);
    ll n;cin>>n;
    vector<vector<ll>> arbol(n);    
    vector<ll> padres(n);
    for (int i = 0; i < n-1; i++)
    {
        ll a;cin>>a;
        a--;
        arbol[a].push_back(i+1);
        padres[i+1] =a;
    }
    queue<ll> q;
    vector<ll> pa(n);
    vector<ll> si(n,1);
    vector<vector<ll>> pares(n,vector<ll>(2)); 
    for (int i = 0; i < n; i++)
    {
        pares[i][0] =1;
        if(arbol[i].size() == 0){
            q.push(i);
            // si[i] = 1;
        }else{
            pa[i] = arbol[i].size();
        }
    }
    ll res = 0;
    vector<ll> r;
    while(!q.empty()){
        auto x =q.front();
        // cout<<x<<"\n";
        q.pop();
        ll p = padres[x];
        pares[p][0] +=pares[x][1];
        pares[p][1] +=pares[x][0];
        pa[p]--;
        if(pa[p] == 0){
            q.push(p);
        }
    }
    res = max(pares[0][0],pares[0][1]);
    if(pares[0][0]>pares[0][1]){
        
    }else{

    }
    cout<<res<<"\n";
    sort(r.begin(),r.end());
    for(auto a:r)cout<<a<<" ";
    cout<<"\n";
    
    return 0;
}