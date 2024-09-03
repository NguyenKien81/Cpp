#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define maxi 1000007

int m, n, visited[maxi];
vector <vector <int>> a(maxi);
vector <pair <int, int>> duo;
void input(){
    cin >> m >> n;
    for(int i = 0; i <= n; i++) a[i].clear();
    duo.clear();
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        duo.push_back({min(x, y), max(x, y)});
    }
    // memset(visited, 0, sizeof(visited));
}
void dfs(int i){
    visited[i] = 1;
    for(int it : a[i]) if(!visited[it]) dfs(it);
}
void dfs2(int u, int s, int t){
    visited[u] = 1;
    for (int v : a[u]){
        if((u == s && v == t) || (u == t && v == s)) continue;
        if(!visited[v]) dfs2(v, s, t);
    }
    
}
void solve2(){
    int f = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]){
            f++;
            dfs(i);
        }
    }
    vector<pair<int, int>> ans; 
    for (auto it : duo)
    {
        int x = it.first, y = it.second;
        memset(visited, 0, sizeof(visited));
        int c = 0;
        for (int j = 1; j <= n; j++)
        {
            if(!visited[j]){
                c++;
                dfs2(j, x, y);
            }
        }
        if (c > f) ans.push_back({x, y});
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans) cout << it.first << " " << it.second << " ";
}
int main() {
    fast;
	int T; cin >> T;
    while (T--)
    {
        input();
        solve2();
        cout << "\n";
    }
    
}