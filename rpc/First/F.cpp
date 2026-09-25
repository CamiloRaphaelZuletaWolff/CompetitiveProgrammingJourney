#include <bits/stdc++.h>
using namespace std;
typedef int ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);


    string s; cin>>s;


    ll a = 0, b = 0;

    for (ll i = 0; i < s.size(); i++)
    {
        if(s[i] == 'a' || s[i] == 'e'|| s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'){
            a++;
        }

        if(s[i] == 'y'){
            b++;
        }
    }

    cout<< a  <<" "<<a+b<<endl;
    

    return 0;

}