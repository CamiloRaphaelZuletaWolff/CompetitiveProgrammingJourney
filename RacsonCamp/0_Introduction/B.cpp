#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    string n;
    cin>>n;

    

    if(n.size() == 1){
        cout<<0;
    }else{
        cout<<n[n.size()-2];
    }


    return 0;

}