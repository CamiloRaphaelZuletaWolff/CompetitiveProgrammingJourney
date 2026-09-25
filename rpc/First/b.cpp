#include<bits/stdc++.h>

using namespace std;
typedef long long ll;




const ll MOD = 9302023;
ll pow(ll n){
    ll base = 1;
    for (int i = 0; i < n; i++)
    {
        base = (base*2)%MOD;
    }
    return base;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;cin>>s;
    ll n = s.size();
    s = s+"00000000000";
    vector<ll> dp(s.size());
    vector<string> vs = {"zero","one", "two","three","four","five","six","seven","eight","nine"};
    vector<string> mix = {"eighthree","twone"};
    ll cnt =0;
    vector<ll> cont(s.size());
    for (int i = n - 1; i >= 0; i--)
    {
        bool f = 0;
        for (int j = 0; j < vs.size(); j++)
        {
            int m =vs[j].size();
            if(s.substr(i,m)==vs[j]){
                f = 1;
                if((j == 5 || j == 9 || j == 8 || j == 3 || j==1) &&cont[i+m-1]){
                    cont[i+m-1]= 0;
                }
                dp[i] = min(dp[i+m]+1,dp[i+1]+1);
                break;
            }    
        }
        for (int j = 0; j < 2; j++)
        {
            int m =mix[j].size();
            if(s.substr(i,m)==mix[j]){
                cont[i]++;
                break;
            }
        }        
        if(!f)dp[i] = dp[i+1]+1;
    }
    for (int i = 0; i < n; i++)
    {
        cnt+=cont[i];
    }
    
    ll mn = dp[0];
    ll res = pow(cnt);
    cout<<mn<<"\n"<<res<<endl;


    return 0;
}