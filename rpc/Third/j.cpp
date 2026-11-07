#include <bits/stdc++.h>
using namespace std;
typedef long long ll;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n;cin>>n;
    vector<ll> arr(n);for(auto &a:arr)cin>>a;
    vector<ll> brr(62);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 62; j++)
        {
            brr[j] += (arr[i]>>j)&1; 
        }
    }
    // for(auto x:brr)cout<<x<<" ";cout<<"\n";
    for (int i = 1; i < 62; i++)
    {
        brr[i] += brr[i-1]/2;
    }
    // for(auto x:brr)cout<<x<<" ";cout<<"\n";
    ll res = 0;
    for (int i = 0; i < 62; i++)
    {
        res+= brr[i]>0?1LL<<i:0; 
    }
    cout<<res<<"\n";
    

    return 0;

}