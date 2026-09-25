#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    

    ll n,m;cin>>n>>m;
    vector<string> ma(n);
    for (int i = 0; i < n; i++)
    {
        cin>>ma[i];
    }
    vector<vector<ll>> sufx(n,vector<ll>(m)), sufy(n,vector<ll>(m)); 
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            if(ma[i][j] == ma[i][j+1]){
                sufx[i][j] = sufx[i][j+1]+1;
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 1; i <n; i++)
        {
            if(ma[i][j] == ma[i-1][j]){
                sufy[i][j] = sufy[i-1][j]+1;
            }
        }
    }
    ll res = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <m-1; j++)
        {
            res += sufx[i][j] * sufy[i][j];
        }
    }
    cout<<res<<"\n";
    return 0;

}