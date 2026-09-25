    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;


    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        // freopen("../../input.txt", "r", stdin);
        // freopen("../../output.txt", "w", stdout);

         ll n;cin>>n;
         vector<pair<ll,ll>> arr(n);
         for(auto &[a,b]:arr)cin>>a>>b;
        sort(arr.begin(),arr.end());
        ll l = 0, r =0, res =0;
        for (int i = 0; i < n; i++)
        {
            auto [iz,der] = arr[i];
            if(iz>=r){
                res++;
                l = iz;
                r = der;
                continue;
            }
            if(der<r){
                l = iz;
                r = der;
            }
        }
                cout<<res<<"\n";
        return 0;

    }