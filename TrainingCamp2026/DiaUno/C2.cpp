#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    freopen("grant.in", "r", stdin);
    freopen("grant.out", "w", stdout);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    int n;cin>>n;
    // vector<ll> arbol(n,0);
    vector<bool> vis (n+1);

    // vector<int> padres(n+1);
    int padres[n+1] = {0};
    

    for (int i = 2; i <= n; i++)
    {
        int a;cin>>a;
        // arbol.push_back(a);
        padres[i] = a;
    }

    int res = 0;
    vector<int>vis2;

    for (int i = n; i >= 2; i--)
    {
        if(vis[padres[i]] || vis[i]) continue;
        res++;
        vis[padres[i]] = true;
        vis[i] = true;
        vis2.push_back(i);
    }

    // for (ll i = 0; i < count; i++)
    // {
    //     /* code */
    // }
    

    cout<<res*1000<<'\n';
    
    for (int i = vis2.size() -1 ; i >= 0; i--)
    {
        cout<<vis2[i]<<" ";
    }
    
    



    return 0;

}