#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    string s; cin>>s;
    int digitoImpar = s[s.size()-1]-'0';
    bool f = 0;
    ll index = -1;
    for (int i = 0; i < s.size()-1; i++)
    {
        ll aux = s[i]-'0';
        if(aux%2 == 0){
            f = 1;
            index= i;
            if(aux<digitoImpar){
                break;
            }
        }        
    }
    
    if(f){
        swap(s[s.size()-1],s[index]);
        cout<<s<<"\n";
    }else{
        cout<<-1<<"\n";
    }


    

    return 0;

}