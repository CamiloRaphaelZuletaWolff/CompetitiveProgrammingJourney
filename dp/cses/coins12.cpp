
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int MOD = 1e9 + 7;

int main(){

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n,x; cin>>n>>x;
    vector<int> dp(x + 1);
    vector<int> coins;

    for (int i = 0; i < n; i++)
    {
        int z;cin>>z;
        coins.push_back(z);
    }

    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i-coins[j] >= 0){
                dp[i] = (dp[i] + dp[i-coins[j]]) %  MOD;
            }
        }
        
    }

    cout<<dp[x] << '\n';
    
    
    
    
    

    
    return 0;
    

}