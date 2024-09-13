#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1005;
vector<int> adj[MAX]; // Danh sách kề
bool visited[MAX];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

bool isTree(int n) {
    memset(visited, false, sizeof(visited));
    dfs(1); // Bắt đầu DFS từ đỉnh 1

    // Kiểm tra xem có đỉnh nào chưa được thăm hay không
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T; // Số bộ test
    while (T--) {
        int N;
        cin >> N;
        
        // Khởi tạo lại danh sách kề
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Nếu số cạnh khác N-1, chắc chắn không phải cây
        if (N == 1 || isTree(N)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
