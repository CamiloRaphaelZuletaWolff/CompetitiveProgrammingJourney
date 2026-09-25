#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, a, b; cin >> n >> a >> b;
    ll aux = n-1;
    bool minimo = false;
    bool maximo = false;
    while (aux--){
        ll x; cin >> x;
        if (x == a){
            minimo = true;
        }
        if (x == b){
            maximo = true;
        }
    }

    if (a==b){
        cout << a << endl;
        return 0;
    }

    if (minimo&&maximo){
        for (ll i = a; i < b; i++){
            cout << i << " ";
        }
        cout << b << endl;
    }
    if (minimo&&!maximo){
        cout << b << endl;
    }
    if (maximo&&!minimo){
        cout << a << endl;
    }
    if (!maximo&&!minimo){
        cout << -1 << endl;
    }
}