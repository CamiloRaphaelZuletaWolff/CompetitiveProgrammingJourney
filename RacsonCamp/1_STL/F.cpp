#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n,k; cin>>n>>k;

    priority_queue<ll, vector<ll>, greater<ll>> colita;


    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        colita.push(x);
    }

    ll res = 0;

    // cout<< colita.size()<<endl;

    // cout<<colita.top()<<endl;

    while(colita.top() <= k && colita.size() >= 2){

        ll primero = colita.top();

        colita.pop();

        ll segunda = colita.top();

        colita.pop();

        // cout<<"------------"<<endl;
        // cout<<primero + 2 * segunda <<endl;

        colita.push(primero + 2 * segunda);
        res++;
    }

    if(colita.top() >= k){
        cout<<res<<endl;
    }else{
        cout<<-1<<endl;
    }

    
    


    


    return 0;

}