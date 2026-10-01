#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    string s; cin>>s;

    map<char,ll> mapita;

    ll aux = 0;
    
    char c;
    
    for (ll i = 0; i < s.size(); i++)
    {
        mapita[s[i]]++;
    }

    for(auto [a,b] : mapita){
        if(b%2 == 1) {
            aux++;
            c = a;
        }
    }

    if(aux>1){
        cout<<"NO SOLUTION";
        return 0;
    }
    deque<char>lu;

    if(aux == 1){
        for (ll i = 0; i < mapita[c]; i++)
        {
            lu.push_back(c);
        }
        
    }

    for(auto [a,b] : mapita){
        
        if(b%2==1) continue;
        
        for (ll i = 0; i < mapita[a]/2; i++)
        {
            lu.push_back(a);
            lu.push_front(a);
        }
    }

    for(auto x : lu){
        cout<<x;
    }
    

    return 0;

}