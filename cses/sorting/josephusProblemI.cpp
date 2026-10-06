#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;


ll power(ll base, ll exp,ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll res2 = 1;
ll inicial;

void f2(ll n,ll depth){
    
    if(n == 1) return;

    ll aux = 1;

    while (aux <= inicial)
    {
        cout<< res2 + aux*()
    }
    
    

    if(n %2 == 0) f2(n/2,depth+1);
    else{
        res2 += pow(2,depth);
        f2(n/2,depth+1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    cin>>inicial;




    
    
    
    return 0;

}