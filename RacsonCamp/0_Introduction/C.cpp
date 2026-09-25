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
        ll a,b,n;
        cin>>a>>b>>n;
        ll dollars = a*n;
        ll cents = b*n;
        dollars += cents/100;
        cents %= 100;

        cout<<dollars<<" "<< cents<<endl;


    }
    


    return 0;

}