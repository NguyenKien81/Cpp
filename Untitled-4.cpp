#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void bfs(int s, int t, vector<vector<int>>& adj, int n) {
    vector<int> visited(n + 1, 0), parent(n + 1, -1);
    queue<int> q;
    
    q.push(s);
    visited[s] = 1;

    // BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
                
                if (v == t) break; // Dừng lại khi tìm thấy đỉnh t
            }
        }
    }

    // Nếu không tìm thấy đường đi đến đỉnh t
    if (!visited[t]) {
        cout << "-1\n";
        return;
    }

    // Truy vết đường đi từ t về s
    vector<int> path;
    for (int v = t; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    // In ra đường đi
    for (int v : path) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {
    fast;
    
    int T;
    cin >> T; // Số lượng bộ test
    while (T--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        
        vector<vector<int>> adj(n + 1); // Danh sách kề
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // Vì đồ thị vô hướng
        }
        
        bfs(s, t, adj, n);
    }
    
    return 0;
}