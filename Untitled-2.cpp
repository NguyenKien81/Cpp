#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int m, n = 0, visited[1000007], parent[1000007];
vector <vector <int>> a(1000007);
set <int> path;
void input(){
    path.clear();
    for(int i = 1; i <= n; i++) a[i].clear();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
    }
}
void dfs(int i){
    visited[i] = 1;
    for (int it : a[i]) 
        if(!visited[it]) {
            parent[it] = i;
            dfs(it);
        }
}
void solve(int begin, int end){
    memset(visited, 0, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(begin);
    if(visited[end]){
        while(end != begin){
            path.insert(end);
            end = parent[end];
        }
    }
}
int main() {
    fast;
	int T; cin >> T;
    while (T--)
    {
        input();
        solve(1, 2);
        solve(2, 1);
        cout << path.size() << "\n";
    }
    
}