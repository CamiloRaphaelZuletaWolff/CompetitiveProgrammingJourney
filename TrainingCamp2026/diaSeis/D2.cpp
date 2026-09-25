 
#include<bits/stdc++.h>

using namespace std;
 
#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define RFOR(i, a, b) for(int i = a; i >= b; i--)
#define FORP(i, a, b, c) for(int i = a; i <= b; i += c)
#define RFORP(i, a, b, c) for(int i = a; i >= b; i -= c)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define rv(x) for(auto &i: x) cin >> i
#define includes(x, y) x.find(y) != x.end()
#define fill(x, y) memset(x, y, sizeof(x))
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))
 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
 
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
 
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<ii> vii;
typedef vector<pll> vpll;
 
typedef tuple<int, int, int> iii;
 
int t = 1;
bool multiple = false;
 
struct SuffixArray {
  string s;
  vector<ll> sa;
  vector<ll> rank;
  vector<ll> lcp;
  explicit SuffixArray(string str) : s(std::move(str)) {
    buildSuffixArray();
    buildLCP();
  }
 
private:
void buildSuffixArray() {
  string t = s;
  t.push_back('\0');
  ll n = (ll)t.size();
  sa.assign(n, 0);
  vector<ll> cls(n);
  vector<ll> cnt(max(n, 256LL), 0LL);
  for (unsigned char ch : t) {
    ++cnt[ch];
  }
 
  for (ll i = 1; i < (ll)cnt.size(); ++i) {
    cnt[i] += cnt[i - 1];
  }
 
  for (ll i = n - 1; i >= 0; --i) {
    sa[--cnt[(unsigned char)t[i]]] = i;
  }
 
  ll classes = 1;
  cls[sa[0]] = 0;
 
  for (ll i = 1; i < n; ++i) {
    if (t[sa[i]] != t[sa[i - 1]]) {
      ++classes;
    }
 
    cls[sa[i]] = classes - 1;
  }
 
  vector<ll> nextSA(n);
  vector<ll> nextCls(n);
  vector<ll> head(n);
 
  for (ll len = 1; len < n && classes < n; len <<= 1) {
    for (ll i = n - 1; i >= 0; --i) {
      head[cls[sa[i]]] = i;
    }
 
    for (ll i = 0; i < n; ++i) {
      ll start = sa[i] - len;
 
      if (start < 0) {
        start += n;
      }
 
      nextSA[head[cls[start]]++] = start;
    }
 
    ll nextClasses = 1;
    nextCls[nextSA[0]] = 0;
 
    for (ll i = 1; i < n; ++i) {
      ll current = nextSA[i];
      ll previous = nextSA[i - 1];
 
      pair<ll, ll> currentPair = {
        cls[current],
        cls[(current + len) % n]
      };
 
      pair<ll, ll> previousPair = {
        cls[previous],
        cls[(previous + len) % n]
      };
 
      if (currentPair != previousPair) {
        ++nextClasses;
      }
 
      nextCls[current] = nextClasses - 1;
    }
 
    sa.swap(nextSA);
    cls.swap(nextCls);
    classes = nextClasses;
  }
 
  sa.erase(sa.begin());
}
 
void buildLCP() {
  ll n = (ll)s.size();
 
  rank.assign(n, 0);
 
  for (ll i = 0; i < n; ++i) {
    rank[sa[i]] = i;
  }
 
  lcp.assign(max(0LL, n - 1), 0LL);
 
  ll k = 0;
 
  for (ll i = 0; i < n; ++i) {
    ll positionInSA = rank[i];
 
    if (positionInSA == n - 1) {
      k = 0;
      continue;
    }
 
    ll j = sa[positionInSA + 1];
 
    while (
      i + k < n &&
      j + k < n &&
      s[i + k] == s[j + k]
    ) {
      ++k;
    }
 
    lcp[positionInSA] = k;
 
    if (k > 0) {
      --k;
    }
  }
}
};
 
int f(int pos, int A) {
    if (pos < A) return 0;
    else if (pos == A) return -1;
    else return 1; 
}

void solve(){

    string s, t; cin>>s>>t;

    string aux = s +"#" + t;

    SuffixArray suffi = SuffixArray(aux);
    
    int res = 0, posa = -1, posb = -1;
    int A = s.size();
    for (int i = 0; i + 1 < suffi.sa.size(); i++) {
      int pri = suffi.sa[i];
      int seg = suffi.sa[i+1];

      int prio = f(pri, A);
      int sego = f(seg, A);

      if (prio == -1 || sego == -1 || prio == sego) continue;

      if (suffi.lcp[i] > res) {
        res = suffi.lcp[i];
        if (prio == 0) {
          posa = pri;
          posb = seg - A - 1;
        } else {
          posa = seg;
          posb = pri - A - 1;
        }
      }
    }
    
    cout << s.substr(posa, posb - posa + 1);
        
}
    


 
int main(){
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  // freopen("../../input.txt", "r", stdin);
  // freopen("../../output.txt", "w", stdout);
 
//   if (multiple) cin >> t;
//   while(t--) solve();
 solve();
  return 0;
}