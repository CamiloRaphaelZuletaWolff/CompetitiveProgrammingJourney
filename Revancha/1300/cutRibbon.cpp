#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> a1 (3);
bool primera = true;
ll f(ll n){

    if(!primera &&(n == a1[1] || n == a1[2] || n == a1[0])) return 1;
    primera = false;

    ll res = 0;
    ll a = -10,b = -10 ,c = -10;

    if(n - a1[0] == a1[1] || n - a1[0] == a1[2]){

        a = f(n-a1[0]);

    }
    if(n - a1[1] == a1[0] || n - a1[1] == a1[2]){

        b = f(n-a1[1]);

    }
    if(n - a1[2] == a1[1] || n - a1[2] == a1[0]){

        c = f(n-a1[2]);

    }

    return max({a,b,c});
    
    

    

    


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n>>a1[0]>>a1[1]>>a1[2];

    ll lu = f(n);

    
    cout<< max(lu,0LL)+1 <<endl;


    return 0;

}