#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    

    ll n; cin>>n;

    deque<ll> arr(n);
    for(auto &a:arr)cin>>a;
    ll res = 0;
    while(n!=1){

        for (int i = 0; i < n; i+=2)
        {
            if(i == n-1){
                arr.push_back(arr[0]);
                arr.pop_front();
            }else{
                arr.push_back(max(arr[0],arr[1]));
                res = max(abs(arr[0]-arr[1]),res);
                arr.pop_front();
                arr.pop_front();
            }
        }
        // for(auto &a:arr)cout<<a<<" ";
        // cout<<"\n";
        n = arr.size();
        
    }
    cout<<res<<"\n";
    


    return 0;

}