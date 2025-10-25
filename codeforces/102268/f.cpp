#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int group[100005] = {0};

void flood(int ind, int color) {
    group[ind] = color;
    queue<int> q;
    q.push(ind);
    while(!q.empty()) {
        int n = q.front();
        q.pop();
        for(int a : adj[n]) {
            if(group[a] == 0) {
                group[a] = color;
                q.push(a);
            }
        }
    }
}

int main() {

    int N, M;
    cin >> N >> M;

    for(int i = 0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cnt = 0;

    for(int i = 0; i<N; i++) {
        if(group[i] == 0) {
            cnt++;
            flood(i, cnt);
        }
    }

    int ans = M-(N-cnt);
    cout << ans << endl;


}