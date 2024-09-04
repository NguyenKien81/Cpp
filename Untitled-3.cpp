#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int m, n = 0, visited[1000007], parent[1000007];
vector<vector<int>> a(1000007);

// Hàm input dùng để nhập dữ liệu
void input() {
    for(int i = 1; i <= n; i++) a[i].clear(); // Xóa các đỉnh trước đó
    cin >> n >> m; // Nhập số đỉnh và số cạnh
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; // Nhập một cạnh (x, y)
        a[x].push_back(y); // Thêm đỉnh y vào danh sách kề của đỉnh x
    }
}

// Hàm dfs để duyệt đồ thị từ đỉnh i
void dfs(int i) {
    visited[i] = 1; // Đánh dấu đỉnh i đã được thăm
    for (int it : a[i])  // Duyệt qua tất cả các đỉnh kề của i
        if (!visited[it]) { // Nếu đỉnh it chưa được thăm
            parent[it] = i; // Gán đỉnh cha của it là i
            dfs(it); // Đệ quy duyệt từ đỉnh it
        }
}

// Hàm solve dùng để tìm đường đi từ đỉnh t tới đỉnh s
void solve(int t, int s) {
    memset(visited, 0, sizeof(visited)); // Đặt lại mảng visited
    memset(parent, 0, sizeof(parent)); // Đặt lại mảng parent
    dfs(t); // Duyệt đồ thị bắt đầu từ đỉnh t
    
    int path = 0;
    if (visited[s]) { // Nếu đỉnh s đã được thăm trong quá trình duyệt từ t
        while (t != s) { // Duyệt ngược lại từ s về t
            path++; // Đếm số bước
            t = parent[t]; // Chuyển t về đỉnh cha của nó
        }
    }
    cout << path << " "; // In ra độ dài đường đi từ t tới s
}

int main() {
    fast;
    int T; cin >> T; // Nhập số lượng test cases
    while (T--) {
        input(); // Nhập dữ liệu cho từng test case
        solve(1, 2); // Tìm đường đi từ 1 tới 2
        solve(2, 1); // Tìm đường đi từ 2 tới 1
        cout << "\n";
    }
}
