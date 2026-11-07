#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n,target;cin>>n>>target;

    vector<ll> numeritos;

    vector<ll> prefix(n+1,0);

    for (ll i = 1; i <= n; i++)
    {
        ll a; cin>>a;
        
        prefix[i] = prefix[i-1] + a;

        numeritos.push_back(a);
    }

    

    ll lu = 0;

    ll left = 0;
    ll right = 1;


    while(left != n-1){
        ll actual = prefix[right] - prefix[left];
        // cout<<left<<" "<<right<<" "<<actual<<endl;
        if(actual == target){
            lu++;
            left++;
        }

        if(actual > target){
            
            left++;
        }

        if(actual < target){
            if(right < n) right++;
            else left++;
        }
    }
    if(numeritos[n-1] == target) lu++;

    cout<< lu;

    
    return 0;
}