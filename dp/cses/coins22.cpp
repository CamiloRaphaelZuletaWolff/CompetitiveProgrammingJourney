
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int MOD = 1e9 + 7;

int main(){

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n; cin>>n;
    vector<int> dp (n+1,100000000);
    
    for (int i = 1; i <= n; i++) {          
        for (int j = 1; j <= x; j++) {   
            dp[i][j] = dp[i-1][j];                     
            if (j - coins[i-1] >= 0)                    
                dp[i][j] = (dp[i][j] + dp[i][j - coins[i-1]]) % MOD;
    }
}

cout << dp[n][x] << '\n';
    
    
    
    

    

    

}