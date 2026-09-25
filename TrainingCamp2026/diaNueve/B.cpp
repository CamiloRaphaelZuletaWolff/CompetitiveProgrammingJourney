#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    vector<ll> res(n + 1, 0);          
    vector<set<ll>> bloqueados(n + 1);     
    for(ll i = 1; i <= n; i++){
        ll l = 0;
        for(ll j = i; j >= 1; j--)          
            if(!bloqueados[i].count(j)){l = j; break; }

        cout << "? " << l << " " << i << '\n';
        cout.flush(); 
        
        ll s;
        
        ll bl, br;
        cin >> s >> bl >> br;
        if(s == -1 && bl == -1 && br == -1) return 0;


        res[i] = res[l - 1] + s;
        bloqueados[br].insert(bl);
    }

    cout << "!" << '\n';
    cout.flush();
    for(ll i = 1; i <= n; i++){

        cout << res[i] - res[i - 1] << " ";

    }
    cout << '\n';
    cout.flush();

    return 0;
}