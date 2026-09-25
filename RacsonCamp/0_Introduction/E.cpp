#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    ll t; cin>>t;

    while (t--)
    {
        ll n,k;cin>>n>>k;

        if(n%k == 0){
            cout<<0<<endl;
            continue;
        }
        cout<<(n/k +1)*(k) - n<< endl;
        // cout<<(n/k)*k << endl;


    }
    


}