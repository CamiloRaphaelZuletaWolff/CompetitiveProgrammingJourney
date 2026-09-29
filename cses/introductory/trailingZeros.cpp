#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    ll lu = 0;

    while(n!= 0){

        n/= 5;

        lu += n;

    }

    cout<<lu<<endl;
    
    return 0;

}