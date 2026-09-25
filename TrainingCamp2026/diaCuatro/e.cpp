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
         bool f = 1;
        ll v = 0,c = 0,cc = 0;
         for (int i = 0; i < n && f; i++)
         {
            if(arr[i] == 50){
                if(v>0){
                    v--;
                }else{
                    f = 0;
                }
                c++;
            }else if(arr[i] == 100){
                if(c>0 && v>0){
                    v--;
                    c--;
                }else if(v>2){
                    v-=3;
                }else{
                    f = 0;
                }
                cc++;
            }else{
                v++;
            }
         }
         cout<<(f?"YES\n":"NO\n");        

        return 0;

    }