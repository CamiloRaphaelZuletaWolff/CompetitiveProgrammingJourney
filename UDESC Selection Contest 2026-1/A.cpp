#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    ll h, a,b; cin>>h>>a>>b;

    if(h >= min(a,b) &&  h <= max(a,b)){

        cout<<"SIM";
    }else{
        cout<<"NAO";
    }


    return 0;

}