    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;


    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        // freopen("../../input.txt", "r", stdin);
        // freopen("../../output.txt", "w", stdout);

         ll n,m,k = 1;cin>>n;
        vector<ll> arr(n);
        for(auto &a:arr)cin>>a;
        cin>>m;
        vector<ll> brr(m);
        for(auto &a:brr)cin>>a;
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        ll i =0, j = 0;
        ll res = 0;
        while(i<n && j< m){
            if(abs(arr[i]-brr[j])<= k){
                res++;
                i++,j++;
            }else if(arr[i]<=brr[j]){
                i++;
            }else{
                j++;
            }
        }
        cout<<res<<"\n";
        return 0;

    }