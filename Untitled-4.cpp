#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define maxi 1000007

int m, n, visited[maxi];
vector <vector <int>> a(maxi);
void input(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++) a[i].clear();
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}
void dfs(int i){
    visited[i] = 1;
    for(int it : a[i]) if(!visited[it]) dfs(it);
}
void solve(){
    vector <int> v;
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
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        int c = 0;
        for (int j = 1; j <= n; j++)
        {
            if(!visited[j]){
                c++;
                dfs(j);
            }
        }
        if (c > f) v.push_back(i);
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int it : v) cout << it << " ";
}
int main() {
    fast;
	int T; cin >> T;
    while (T--)
    {
        input();
        solve();
        cout << "\n";
    }
    
}