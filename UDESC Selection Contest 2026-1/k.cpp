#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    ll n,q;cin>>n>>q;
    vector<ll> arr(n);for(auto &a:arr)cin>>a;
    ll x = 1;
    for (int i = 0; i* i<n; i++)
    {
        x = i;
    }
    map<ll,ll> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    map<ll,ll> freq;
    for(auto [k,v]:mp){
        freq[v]++;
    }
    for (int i = 2; i <= x; i++)
    {
        if(freq.find(i) != freq.end()){
            ll cnt = 1;
            ll sum = 0;
            while (i*cnt<=x)
            {
                if(freq.find(i*cnt) != freq.end()){
                    sum+=freq[i];
                }
                cnt++;
            }
            freq[i] = sum;
        }     
    }
    for (int i = 0; i < q; i++)
    {
        ll p;cin>>p;
        if(p==1){
            
        }else{
            ll ind,col;cin>>ind>>col;
            ind--;
            freq[arr[ind]]--;
            if(freq[arr[ind]]!=0)freq.erase(arr[ind]);
            arr[ind]++;freq[arr[ind]]++;
        }
    }
    

    
    return 0;

}