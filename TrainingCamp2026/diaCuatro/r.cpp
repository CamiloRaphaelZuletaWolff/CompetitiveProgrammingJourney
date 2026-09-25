    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;


    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        // freopen("../../input.txt", "r", stdin);
        // freopen("../../output.txt", "w", stdout);

         string s;cin>>s;
         ll k; cin>>k;
         priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
         ll j = 0;
         for(auto x:s){
            ll aux = x-'0';
            pq.emplace(aux,j*-1);
            j++;
        } 
        while(k && !pq.empty()){
            auto [v,i] = pq.top();
            pq.pop();
            i = i*-1;
            if(i-=){

            }
        }
        return 0;

    }