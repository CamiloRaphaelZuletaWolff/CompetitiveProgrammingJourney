    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;


    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);


        ll n, x; cin>> n >> x;
        vector<ll> ch(n); for(ll &e: ch) cin >> e;
        ll aux = 0;
        ll count = 0;
        sort(ch.rbegin(), ch.rend());
        for (ll e: ch) {
            aux += e;
            if (aux > x) {
                count++;
                aux = 0;
            }
        }
        
        if (aux > 0) count++;

        cout<<count;
        

        return 0;

    }