#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    
    int n, k; cin>>n>>k;


    map<char,int> contador;

    int c = 0;

    vector<string> lu;

    for (ll i = 0; i < n; i++)
    {
        string s; cin>>s;

        string aux;

        for (ll j = 0; j < s.size(); j++)
        {
            char actual = s[j];
            
            contador[(char)(((26 + actual - c %26))%26)]++;

            
            cout<<(char)((26 + actual - c %26))%26<<endl;
            
            cout<<"sssssssssssssssssss"<<c<<endl;

            
            aux.push_back((char)(((26 + actual - c %26))%26));
            if(contador[(char)actual - c %26] % k == 0){
                c++;
                cout<<"entrooooo "<<actual<<endl;
            }
        }

        lu.push_back(aux);
        
    }
    for (ll i = 0; i < n; i++)
    {
        if(i != 0) cout<<" ";
        cout<<lu[i];
    }
    cout<<endl;
    
    

    return 0;
}