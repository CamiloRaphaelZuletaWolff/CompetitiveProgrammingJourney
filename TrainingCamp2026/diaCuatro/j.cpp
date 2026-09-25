    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;


    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        // freopen("../../input.txt", "r", stdin);
        // freopen("../../output.txt", "w", stdout);
        ll n; cin>>n;
        vector<ll> arr(n);for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end());
        ll mn = 0,mx = 0;
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            ll aux = mn+arr[i];
            if(mx+1<aux){
                res = mx+1;
                break;
            }

            mx = mx+arr[i];
        }
        cout<<max(res,mx+1)<<"\n";
        
        
        
        return 0;

    }