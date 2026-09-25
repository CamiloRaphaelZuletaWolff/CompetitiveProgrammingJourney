#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;


ll f91(ll n ){
    if(n >= 101) return n - 10;

    return f91(f91(n+11));

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll a; cin>>a;

    while (a != 0)
    {
        cout<< "f91("<<a<<") = "<<f91(a)<<endl;
        cin>>a;
    }
    

    
    
    
    return 0;

}