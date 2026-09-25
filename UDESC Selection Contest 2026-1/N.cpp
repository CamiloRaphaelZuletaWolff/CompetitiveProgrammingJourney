#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    

    ll n; cin>>n;

    vector<ll> picos(n);

    for (ll i = 0; i < n; i++)
    {
        // cout<<"++++++"<<endl;
        cin>>picos[i];
    }

    if(n <= 2){
        cout<<0;
        return 0;
    }

    ll res = 0;

    vector<bool> vis (n,false);

    for (ll i = 1; i < n-1; i++)
    {

        if(!vis[i] && i+1 != n && picos[i] > picos[i+1] && picos[i] > picos[i-1]){
            res++;
            vis[i+1] = true;
        }

    }
    cout<<res;
    


    return 0;

}