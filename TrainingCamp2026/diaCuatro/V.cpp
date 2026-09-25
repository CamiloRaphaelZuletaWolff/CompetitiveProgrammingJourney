#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll pow(ll b,ll e){
    ll res = 1;
    for (int i = 0; i < e; i++)
    {
        res*=b;
    }
    return res;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;
    
    ll base = 1;
    if(n == 1){
        cout<<"codeforces\n";
        return 0;
    }
    while(pow(base,10)<n){
        base++;
    }
    ll expo = 10;
    while(pow(base,expo-1)*pow(base-1,10-expo+1)>=n){
        // cout<<pow(base,expo-1)*pow(base-1,10-expo+1)<<'\n';
        expo--;
    }    
    vector<ll>res(10,base-1);
    for (int i = 0; i < expo; i++)
    {
        res[i]++;
    }
    string s = "codeforces";
    // for(auto a:res){
    //     cout<<a<<" ";
    // }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < res[i]; j++)
        {
            cout<<s[i];
        }
    }
    cout<<"\n";
    
    // cout<<"\n";    
    

    return 0;

}