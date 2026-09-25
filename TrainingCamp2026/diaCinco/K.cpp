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

    vector<bool> occurs(const string& T) {
        vector<ll> f(nodes, 0);
        int p = 0;
        for (char ch : T) { p = go[p][ch - MINC]; f[p]++; }
        for (int i = nodes - 1; i > 0; --i) {
            int x = byLevel[i];
            f[suf[x]] += f[x];
        }
        vector<bool> res(endNode.size());
        for (size_t i = 0; i < endNode.size(); ++i) res[i] = f[endNode[i]] > 0;
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);
            freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);

    
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
    vector<bool> res = AC.occurs(T);
    for (int i = 0; i < n; ++i)
        cout << (res[i] ? "YES" : "NO") << "\n";
    return 0;
}