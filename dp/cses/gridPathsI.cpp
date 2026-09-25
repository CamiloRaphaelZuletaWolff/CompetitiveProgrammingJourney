#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int MOD = 1e9 + 7;

int main(){

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n; cin>>n;
    vector<string> grid;
    for (ll i = 0; i < n; i++)
    {
        string x; cin>>x;
        grid.push_back(x);
    }

    vector<vector<ll>>dp(n,vector<ll>(n,0));

    if(grid[0][0] == '*'){
        cout<<0;
        return 0;
    }

    dp[0][0] = 1;
    int a =0, b =0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            a = 0;
            b = 0;
            if(j == 0 && i == 0) continue;
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
                continue;
            }
            
            if(j - 1 >=0) a =dp[i][j-1];
            if(i-1 >=0) b =dp[i-1][j];

            dp[i][j] = (a + b )%MOD; 
        }
        
    }
    cout<<dp[n-1][n-1]<<'\n';
    


    

}

    
    

    

    
