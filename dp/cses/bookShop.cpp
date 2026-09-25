#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int MOD = 1e9 + 7;

int main(){

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n,x; cin>>n>>x;

    vector<ll> dp(x+1,0);
    vector<ll> dinero(n);
    vector<ll> paginas(n);

    for (ll i = 0; i < n; i++)
    {
        cin>>dinero[i];
    }
    
    for (ll i = 0; i < n; i++)
    {
        cin>>paginas[i];
    }

    for (int j = 0; j < n; j++) {    
        for (int i = x; i >= 0; i--) {
            if(i-dinero[j] >=0)
            dp[i] = max(dp[i], dp[i-dinero[j]]+ paginas[j]);
            
        }


    }

    cout << dp[x] << '\n';
    
}

    
    

    

    
