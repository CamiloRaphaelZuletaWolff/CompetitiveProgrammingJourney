#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    map<ll, pair<ll, ll>> r;
    
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        r[i] = {a, b};
    }
    
    ll res = 0, streak = 0;
    for (ll i = n; i >=3;)
    {
        auto [a,b] = r[i];
        bool f = 0;
        ll L = max(i-2,a), R = min(i,b);
        // cout<<L<<" "<<R<<"\n";
        if(R-L+1 == 3){
            f=1;
            for (int d = 1; d <= 2; d++)
            {
                if(!(L>=r[i-d].first && R<=r[i-d].second)){
                    f = 0;
                    break;
                }
            }
        }
        
        if(f){
            i-=3;
            res++;
        }else{
            i--;
        }
    }
    
    

    cout << res << '\n';

    return 0;
}