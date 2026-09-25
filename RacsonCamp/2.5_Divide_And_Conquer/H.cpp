#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;




ll res = 1;


void f(ll n,ll depth){
    if(n == 1) return;
    if(n %2 == 0) f(n/2,depth+1);
    else{
        res += pow(2,depth);
        f(n/2,depth+1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    f(n,1);

    cout<<res<<endl;


    
    
    
    return 0;

}