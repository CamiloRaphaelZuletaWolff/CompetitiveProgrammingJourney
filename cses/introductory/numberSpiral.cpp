#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll t; cin>>t;

    while(t--){

        ll x,y; cin>>y>>x;

        if(x > y){

            if(x%2==1){
                cout<<x*x - y + 1<<endl;
            }else{
                cout<<(x-1)*(x-1)+1 +y-1<<endl;
            }
            continue;
        }

        if(y> x){
            if(y%2 == 0){
                cout<<y*y - x +1<<endl;
            }else{
                cout<< (y-1)*(y-1) + 1 +x-1<<endl;
            }
            continue;
        }
        if(x==y){
            if(x % 2 == 1){
                cout<< x*x - (x*x - (y-1) * (y-1) + 1)/2 + 1<<endl;
            }else{
                cout<< y*y -(y*y - (x-1) * (x-1) + 1 )/2 + 1<<endl;
            }

        }
    }


    return 0;

}