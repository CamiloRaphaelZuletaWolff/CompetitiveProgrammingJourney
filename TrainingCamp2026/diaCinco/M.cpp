#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = INT_MAX;

template<int E = 26, char MINC = 'a'>
struct AhoCorasick {
    int nodes = 0;
    vector<array<int, E>> go;
    vector<int> suf;
    vector<int> depth;
    vector<bool> terminal;
    vector<int> endNode;
    vector<int> byLevel;

    AhoCorasick() { addNode(); }

    int addNode() {
        go.push_back({});
        suf.push_back(0);
        depth.push_back(0);
        terminal.push_back(false);
        return nodes++;
    }

    int insert(const string& s) {
        int pos = 0;
        for (char ch : s) {
            int c = ch - MINC;
            if (!go[pos][c]) {
                int v = addNode();
                depth[v] = depth[pos] + 1;
                go[pos][c] = v;
            }
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

    vector<pair<int,int>> firstLast(const string& T) {
        vector<int> first(nodes, INF), last(nodes, -1);
        int p = 0;
        for (int i = 0; i < (int)T.size(); ++i) {
            p = go[p][T[i] - MINC];
            first[p] = min(first[p], i);
            last[p] = max(last[p], i);
        }
        for (int i = nodes - 1; i > 0; --i) {
            int x = byLevel[i];
            first[suf[x]] = min(first[suf[x]], first[x]);
            last[suf[x]] = max(last[suf[x]], last[x]);
        }
        vector<pair<int,int>> res(endNode.size());
        for (size_t i = 0; i < endNode.size(); ++i) {
            int u = endNode[i];
            if (last[u] == -1) res[i] = {-1, -1};
            else res[i] = {first[u] - depth[u] + 1, last[u] - depth[u] + 1};
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);
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
    vector<pair<int,int>> res = AC.firstLast(T);
    for (int i = 0; i < n; ++i)
        cout << res[i].first << " " << res[i].second << "\n";
    return 0;
}