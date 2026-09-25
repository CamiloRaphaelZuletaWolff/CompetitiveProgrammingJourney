/*
by ivant23
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    ll N, M; cin >> N >> M;
    
  vector<ll> sum (N);
    //ll A[N+5][M+5];
    for(int i = 0; i < M; i++){
    ll a, b; cin >> a >> b;
    a--;b--;
    sum[a]++;
    sum[b]++;
    // edges.pb({a, b});
  }

//   for (int i = 0; i < N; i++)
//   {
//     for (int j = 0; j < M; j++)
//     {
//         cout<<A[i][j]<< " ";
//     }
//     cout<<endl;
    
//   }
  
  
  
  
//   for(int i = 1; i <= N; i++){
//     for(int j = 1; j <= M; j++){
//       if (i == edges[j-1].F || i == edges[j-1].S) A[i][j] = 1;
//       else A[i][j] = 0;
//     }
//   }
  

  ll res =0;

  for (ll i = 0; i < N; i++)
  {
    res += sum[i]*sum[i];
  }

  cout<<res;
  
  

  
//   ll AT[N+5][M+5];
//   for(int j = 1; j <= N; j++){
//     for(int i = 1; i <= M; i++){
//       AT[j][i] = A[i][j];
//     }
//   }
     
//   ll rs = 0;
  
//   for(int i = 1; i <= N; i++){
//     for(int j = 1; j <= M; j++){
//       for(int k = 1; k <= M; k++){
//         rs += AT[i][k] * A[k][j];
//       }
//     }
//   }
    
    // cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    solve();
    
    return 0;
}