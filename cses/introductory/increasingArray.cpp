#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    ll lu = 0;


    ll previo; cin>>previo;


    for (ll i = 1; i < n; i++)
    {
        ll actual; cin>>actual;

        if(previo > actual){
            lu += previo - actual;
        }
        
        previo = max(actual,previo);

    }

    cout<<lu;
    

    return 0;

}