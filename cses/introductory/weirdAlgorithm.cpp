#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n;
    cin>>n;

    while (n!=1)
    {
        cout<<n<<" ";
        if(n%2==0){
            n/=2;
        }else{
            n= 3*n +1;
        }
    }
    cout<<1<<endl;
    

    return 0;

}