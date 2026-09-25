#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int MOD = 1e9 + 7;

int main(){

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n; cin>>n;

    vector<ll> dp(n+1,10000000);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {    
        string s = to_string(i);      
        for (int j = 0; j < s.size(); j++) {
            char digitoChar = s[j];
            int digito = digitoChar - '0';
            if(i-digito >=0){
                dp[i] = min(dp[i], dp[i-digito] + 1);
            }
        }


    }

    cout << dp[n] << '\n';
    
}

    
    

    

    
