#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, lph; cin >> n >> lph;
    ll aux = n;
    ll lphf = 5 * lph;
    priority_queue<ll, vector<ll>, greater<ll>> cola;

    while (n--){
        ll p; cin >> p;
        cola.push(p);
    }

    int res = 0;
    for (ll i = 0; i < aux; i++){
        lphf -= cola.top();
        cola.pop();

        if (lphf >= 0){
            res ++;
        } else {
            break;
        }
    }
    cout << res << endl;
    
}