#include <bits/stdc++.h>
using namespace std;

string fun(string s,int n){
    int acc = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        int aux = (s[i]-'0') - ((i == s.size()-1)? n:0) - acc;
        // cout<<aux<<"\n";
        if(aux< 0){
            s[i] = char(10+aux+ '0');
            acc =1;
        }else{
            s[i] = char(aux + '0');
            break;
        }
    }
    return s;
}

int main() {

    
    freopen("china.in", "r", stdin);
    freopen("china.out", "w", stdout);
    string n = "";  cin>>n;

    string s = n;
    int acc = 0;
    for (int i = 0; i < n.size(); i++)
    {
        int aux = n[i] -'0' + acc*10;
        acc = aux & 1;
        int b = aux/2;
        char a = (char)(b) + '0';
        s[i] = a;
    }

    if((n[n.size()-1] -'0') % 2 == 1){
        
    }else{
        // cout<<s<<" ";
        if((s[s.size()-1] -'0') % 2 == 1){
            s = fun(s,2);
            // cout<<'x';
        }else{
            s = fun(s,1);           
        }
        
    }
    
    int j  = 0;
    if(s[0] == '0')j++;
    for (; j < s.size(); j++)
    {
        cout<<s[j];
    }
    
    
    cout<<"\n";
    
    return 0;
}