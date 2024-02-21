#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> #
using namespace __gnu_pbds;
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define MAXN 10001

int T, n, f;
vector<int> parent(MAXN);

bool bfs(vector<vector<int>>& resG, int s, int t) {
    vector<bool> visited(resG.size(), false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto vc: resG[u]) {
            int v = vc.first;
            int c = vc.second;
            if (!visited[v] && c > 0) {
                parent[v] = u;
                visited[v] = true;
                q.push(v);
                if (v == t) return true;
            }
        }
    }

    return false;
}

int maxflow(vector<vector<int>>& resG, int s, int t) {
    f = 0;
    while (bfs(resG, s, t)) {
        int minC = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            minC = min(minC, resG[parent[v]][v]);
        }
        for (int v = t; v != s; v = parent[v]) {
            resG[parent[v]][v] -= minC;
            resG[v][parent[v]] += minC;
        }
        f += minC;
    }
    return f;
}

int main() {
    send help
    cin >> T;

    
    vector<string> iToS(MAXN);
    for (int i = 0; i < T; i++) {
        cin >> n;
        unordered_map<string, int> stoi;
        unordered_map<string, int> partys;
        vector<vector<int>> resG(10*n, vector<int>(n, 0));

        int v = 1;
        int totClubs = 0;
        int totPartys = 0;
        int totMems = 0;
        string member;
        string party;
        string club;
        int club_n;
        for (int j = 0; j < n; j++) {
            cin >> member >> party >> club_n;
            if (stoi.find(member) == stoi.end()) {
                stoi[member] = v;
                iToS[v++] = member;
                totMems++;
            }
            if (partys.find(party) == partys.end()) {
                partys[party] = v++;
                totPartys++;
            }
            for (int k = 0; k < club_n; k++) {
                cin >> club;
                if (stoi.find(club) == stoi.end()) {
                    stoi[club] = v;
                    iToS[v++] = club;
                    totClubs++;
                }
                int c = stoi[club], m = stoi[member], p = partys[party];
                resG[0][c] = 1;
                //resG[c][0] = 0;
                resG[c][m] = 1;
                resG[m][c] = 0;
                resG[m][p] = 1;
                resG[p][m] = 0;
            }
        }
        const int maxCap = (totClubs - 1) / 2;
        if (totMems < totClubs || totPartys < 3) {
            cout << "Impossible.\n\n";
            continue;
        }
        for (const auto& partyEnt: partys) {
            resG[partyEnt.second][v] = maxCap;
            resG[v][partyEnt.second] = 0;
        }
        resG.resize(v+1);
        f = maxflow(resG, 0, v);
        if (f < totClubs) { 
            cout << "Impossible.\n\n";
            continue;
        }
        for (const auto& clubV: resG[0]) {
            for (const auto& memberV: resG[clubV.first]) {
                if (memberV.second == 0) {
                    cout << iToS[memberV.first] << " " << iToS[clubV.first] << "\n";
                    break;
                }
            }
        }
        cout << "\n";
    }

    return 0;
}