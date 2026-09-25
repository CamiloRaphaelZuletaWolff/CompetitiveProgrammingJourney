    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;


    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);


        ll n; cin>>n;

        // ll res = 0;
        // ll actual = 0;

        vector<ll> num(n);

        ll c1=0,c2=0,c3=0,c4=0;


        for (ll i = 0; i < n; i++)
        {
            ll s;cin>>s;
            if(s == 1){
                c1++;
            }
            if(s == 2){
                c2++;
            }
            if(s == 3){
                c3++;
            }
            if(s == 4) c4++;
        }

        ll res = c4 + min(c3,c1) + c2/2;
        c1 =         min(c3,c1);
        c3 = min(c3,c1);
        c2 /=2;
        res+= c3;
        res+= c1/4;
        c1 /=4;

        if(c1 == 3) {res++;
        c1 =0;
    } 

        if(c2 == 1 && c1 <= 2){
            c1 = 0;
            c2 = 0;
            res++;

        }
if(c2 == 1){
    res++;
}
        

        cout<<res;

        return 0;

    }