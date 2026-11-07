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
    vector<ll> aux(n);
    for (int i = 0; i < n; i++)
    {
        aux[(i+arr[i]-1)%n]++;
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        res += aux[i]*aux[i];
    }
    cout<<res<<"\n";

    return 0;

}