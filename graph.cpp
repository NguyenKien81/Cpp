#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int m, n, k, c, used[1000007], born[1000007];
vector <vector <int>> adj;
vector <pair <int, int>> tree;
queue <int> qu;

void input ()
{
    tree.clear();
    for (int i = 1; i <= n; i++) adj[i].clear();
    cin >> n >> m >> k;
    c = n - 1;
    adj.assign(n + 1, vector <int>());
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void bfs(int i){
    used[i] = 1;
    qu.push(i);
    while (!qu.empty())
    {
        int j = qu.front(); qu.pop();
        for (int it : adj[j]){
            if(!used[it]){
                used[it] = 1;
                qu.push(it);
                if(c--) tree.push_back({j, it});
            }
        }
    }
}

int main() {
    fast;
    int T; cin >> T;
    while (T--)
    {
        input();
        if(m < n - 1) cout << "-1\n";
        else 
        {
            memset(used, 0, sizeof(used));
            bfs(k);
            if(!c)  for (auto it : tree) cout << it.first << " " << it.second << "\n";
            else cout << "-1\n";
        }
        
    }
    
    
   
    
}