#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;


ll power(ll base, ll exp,ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}


ll res = 1;
bool roto = false;
ll respuesta = 1;



void f(ll n,ll depth, ll query){
    // cout<<n<<" "<<depth<<" "<<query<<endl;
    if(n == 1) return;
    if(n %2 == 0) {
        
        if(n >= query*2){

            if(depth == 1){
                respuesta = query*2;
                roto = true;
                // return;
            }
            if(!roto){
                if(query== 1){
                    respuesta = res + power(2,depth-1,LLONG_MAX);
                    roto = true;
                    // return;
                }else{

                    respuesta = res + power(2,depth-1,LLONG_MAX) + (query-1)* power(2,depth,LLONG_MAX);
                    roto = true;
                    // return;
                }
            }
        }else{
            f(n/2,depth+1,abs((n+2-1)/2 - query));
        }
    
    }
    else{
        // cout<< (n+2-1)/2 <<endl;
        // cout<<"++++++++++"<<endl;

        if((n+2-1)/2 == query && !roto){
            respuesta = res;
            roto = true;
            return;
        }
        if(n >= 2*query){
            // cout<<"holaaaa"<<endl;
            
            if(depth == 1){
                respuesta = query*2;
                roto = true;
                // return;
            }
            if(!roto){
                if(query== 1){
                    // cout<<res<<endl;
                    respuesta = res + power(2,depth-1,LLONG_MAX);
                    roto = true;
                    // return;
                }else{

                    respuesta = res + power(2,depth-1,LLONG_MAX) + (query-1)* power(2,depth,LLONG_MAX);
                    roto = true;
                    // return;
                }
            }
        }



        res += power(2,depth,LLONG_MAX);
        f(n/2,depth+1,abs((n+2-1)/2 - query));
    }
}


ll res2 = 1;


void f2(ll n,ll depth){
    
    if(n == 1) return;
    if(n %2 == 0) f2(n/2,depth+1);
    else{
        res2 += pow(2,depth);
        f2(n/2,depth+1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    while (n--)
    {
        ll a, b; cin>>a>>b;

        if( a == b){
             f2(a,1);
             cout<<res2<<endl;
        }else{
        f(a,1,b);
        cout<<respuesta<<endl;

        }
        // f(a,1,b);


        // cout<<respuesta<<endl;

        roto = false;
        respuesta = 1;
        res = 1;
        res2 = 1;
    }
    




    
    
    
    return 0;

}