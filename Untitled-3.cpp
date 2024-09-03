#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define maxi 1000007

int m, n, k, visited[maxi];
vector <vector <int>> a(maxi);
queue <int> q;
void input(){
    cin >> n >> m >> k;
    for(int i = 0; i <= n; i++) a[i].clear();
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
    }
    memset(visited, 0, sizeof(visited));
}
void bfs(int i){
    q.push(i);
    visited[i] = 1;
    while (!q.empty())
    {
        int j = q.front();
        cout << j << " ";
        for (int it : a[j]) 
            if(!visited[it]) {
                q.push(it);
                visited[it] = 1;
            }
        q.pop();
    }
}

int main() {
    fast;
	int T; cin >> T;
    while (T--)
    {
        input();
        bfs(k);
        cout << "\n";
    }
    
}