#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(),(x).end();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n,k,p;cin>>n>>k>>p;
    ll base = n/p +(n%p !=0);
    // cout<<base<<"\n";
    deque<ll> ini,fn;
    for (int i =1; i*i <= n; i++)
    {
        if(n%i == 0){
            if(i>=base && i<=k) ini.push_back(i);
            if(i*i !=n  && (n/i>=base && n/i<=k))fn.push_front(n/i);
        }
    }
    ll sum = ini.size()+fn.size();   
    cout<<sum<<'\n';
    for(auto x:ini)cout<<x<<'\n';
    for(auto x:fn)cout<<x<<'\n';

    return 0;

}