#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll MAX = 1000000+5;
vector<bool> is_prime(MAX + 1, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAX; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX; i += p)
                is_prime[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);


    sieve();
    
    ll n; cin>>n;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;

        ll y = round(sqrt(x));

        cout<<((y*y == x && is_prime[y]) ? "YES" : "NO")<<endl;



    }
    
    return 0;

}