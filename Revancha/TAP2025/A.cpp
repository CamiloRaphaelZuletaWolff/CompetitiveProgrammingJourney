#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    string s; cin>>s;

    bool t = false, a = false, p = false;

    for (ll i = 0; i < s.size(); i++)
    {
        if(s[i] == 'T'){
            t = true;
        }
        if(t && s[i] == 'A'){
            a = true;
        }
        if(t && a && s[i] == 'P'){
            p = true;
        }
    }

    if(t&&a&&p){
        cout<<"S";
    }else{
        cout<<"N";
    }
    

    return 0;

}