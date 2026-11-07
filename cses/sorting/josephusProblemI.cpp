#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll lu = 1;
ll inicial;

void f2(ll n,ll depth){
    
    if(n == 1) {
        // cout<<lu;
        return;
    }
    
    // ll aux = 1<<depth-1;
    // ll xd = lu;
    // for (ll i = 0; i < n/2; i++)
    // {
    //     cout<<xd+aux<<" ";
    //     xd += aux+aux;
    // }

    if(n %2 == 0) f2(n/2,depth+1);
    else{
        // cout<<lu<<" ";
        lu += 1<<depth;
        
        f2(n/2,depth+1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    // cin>>inicial;

    for (ll i = 2; i <= 64; i++)
    {
        
        f2(i,1);
        cout<<i<<" "<< lu<<endl;
        lu = 1;
    }
    



    
    
    
    return 0;

}