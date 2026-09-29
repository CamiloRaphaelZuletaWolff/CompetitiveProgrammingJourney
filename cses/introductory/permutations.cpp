#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    if(n == 2 || n == 3){
        cout<<"NO SOLUTION";
        return 0;
    }

    for (ll i = 1; i <= n; i++)
    {
        if(i % 2 == 0){
            cout<<i<<" ";
        }
    }
    
    for (ll i = 1; i <= n; i++)
    {
        if(i % 2 != 0){
            cout<<i<<" ";
        }
    }



    return 0;

}