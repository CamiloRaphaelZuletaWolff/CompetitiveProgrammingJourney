#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll t = 1; 

    while (t--)
    {
        double r; cin>>r;

        cout<<std::fixed << std::setprecision(9)<<r*r*3.1415926535897932;
    }
    


}