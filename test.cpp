#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1007;
vector<int> adj[MAXN];  // Danh sách kề
int color[MAXN];  // Mảng màu cho các đỉnh

bool bfs(int start, int M) {
    queue<int> q;
    q.push(start);
    color[start] = 0;  // Khởi tạo đỉnh bắt đầu với màu 0
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // Duyệt qua các đỉnh kề của u
        for (int v : adj[u]) {
            // Nếu đỉnh kề chưa được tô màu
            if (color[v] == -1) {
                color[v] = (color[u] + 1) % M;  // Tô màu khác màu với đỉnh u
                q.push(v);
            }
            // Nếu đỉnh kề đã được tô màu và trùng màu với đỉnh hiện tại
            else if (color[v] == color[u]) {
                return false;  // Không thể tô màu với M màu
            }
        }
    }
    return true;  // Đồ thị có thể được tô màu
}

int main() {
    int T;  // Số lượng bộ test
    cin >> T;
    
    while (T--) {
        int V, E, M;  // V: số đỉnh, E: số cạnh, M: số màu
        cin >> V >> E >> M;
        
        // Xóa dữ liệu của đồ thị trước đó
        for (int i = 1; i <= V; ++i) {
            adj[i].clear();
        }
        
        // Nhập các cạnh của đồ thị
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Khởi tạo màu sắc cho các đỉnh (chưa được tô màu là -1)
        memset(color, -1, sizeof(color));
        
        bool isPossible = true;  // Biến kiểm tra có thể tô màu được không
        
        // Duyệt từng đỉnh
        for (int i = 1; i <= V; ++i) {
            // Nếu đỉnh chưa được tô màu
            if (color[i] == -1) {
                // Kiểm tra nếu không thể tô màu với BFS thì báo lỗi
                if (!bfs(i, M)) {
                    isPossible = false;
                    break;
                }
            }
        }
        
        // In kết quả
        if (isPossible) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
