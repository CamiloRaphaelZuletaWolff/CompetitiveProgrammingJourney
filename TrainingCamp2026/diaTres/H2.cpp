/* by ivant23 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
const int MOD = 1e9 + 7;
const int INF = 1e9;
//int t = 1;
map<ll,ll> A;
map<ll,ll> x2;
set<ll> vivo;

void factPrim(ll y){
    for (int i = 2; i*i <= y; i++) {
        ll aux =0;
        while(y%i == 0){
            aux++;
            y/=i;
        }
        if(aux == 0) continue;
        A[i] += aux;
        if(A[i] > 1e5){
            A[i] = 1000;
            vivo.erase(i);
        }else{
            vivo.insert(i);
        }
    }
    if(y>1){
        A[y] += 1;
        if(A[y] > 1e5){
            A[y] = 1000;
            vivo.erase(y);
        }else{
            vivo.insert(y);
        }
    }
}

void factPrim2(ll y){
    for (int i = 2; i*i <= y; i++) {
        while(y%i == 0){
            x2[i]++;
            y/=i;
        }
    }
    if(y>1)x2[y]++;
}

void solve() {
    ll q;
    cin>>q;
    while(q--){
        ll t,x;
        cin>>t>>x;
        if(t == 1){
            factPrim(x);
            continue;
        }
        if(t==2){
            for(auto it = vivo.begin(); it != vivo.end(); ){
                ll p = *it;
                A[p] = A[p] * x;
                if(A[p] > 1e5){
                    A[p] = 1000;
                    it = vivo.erase(it);
                }else{
                    ++it;
                }
            }
            continue;
        }
        if(t == 3){
            factPrim2(x);
            bool f = 1;
            for(auto [p,can]:x2){
                if(A.find(p)== A.end() || A[p] < can){

                    //cout<<p<<" "<<can<<"\n";
          //cout<<A[p]<<"\n";
                    f = 0;
                    break;
                }
            }
            x2.clear();
            /*cout<<M<<"\n";
      for(auto [f,g]:A){
        cout<<f<<" "<<g<<"\n";
      }
      for(auto [f,g]:Mr){
        cout<<f<<" "<<g<<"\n";
      }*/
            cout<<(f?"Yes\n":"No\n");
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

