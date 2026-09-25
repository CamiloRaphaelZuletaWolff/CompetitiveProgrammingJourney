#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<int E = 26, char MINC = 'a'>
struct AhoCorasick {
    int nodes = 0;
    vector<array<int, E>> go;
    vector<int> suf;
    vector<bool> terminal;
    vector<int> endNode;
    vector<int> byLevel;

    AhoCorasick() { addNode(); }

    int addNode() {
        go.push_back({});
        suf.push_back(0);
        terminal.push_back(false);
        return nodes++;
    }

    int insert(const string& s) {
        int pos = 0;
        for (char ch : s) {
            int c = ch - MINC;
            if (!go[pos][c]) go[pos][c] = addNode();
            pos = go[pos][c];
        }
        terminal[pos] = true;
        endNode.push_back(pos);
        return (int)endNode.size() - 1;
    }

    void build() {
        queue<int> Q;
        Q.push(0);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            byLevel.push_back(u);
            for (int c = 0; c < E; ++c) {
                int v = go[u][c];
                if (v) { suf[v] = u ? go[suf[u]][c] : 0; Q.push(v); }
                else go[u][c] = u ? go[suf[u]][c] : 0;
            }
        }
    }
    int next(int p, char ch) const { return go[p][ch - MINC]; }

        vector<ll> countEach(const string& T) {
        vector<ll> f(nodes, 0);
        int p = 0;
        for (char ch : T) { p = next(p, ch); f[p]++; }
        for (int i = nodes - 1; i > 0; --i) {
            int x = byLevel[i];
            f[suf[x]] += f[x];
        }
        vector<ll> res(endNode.size());
        for (size_t i = 0; i < endNode.size(); ++i) res[i] = f[endNode[i]];
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);
        //     freopen("../../input.txt", "r", stdin);
        // freopen("../../output.txt", "w", stdout);

    
    int n;
    cin >> n;
    AhoCorasick<26, 'a'> AC;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        AC.insert(s);
    }
    AC.build();
    string T;
    cin >> T;
    vector<ll> res = AC.countEach(T);
    for (int i = 0; i < n; ++i)
        cout << (res[i]) << "\n";
    return 0;
}