#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int maxn = 1000007;

int n = 0, m, k, color[maxn];
vector <int> adj[maxn];

void input(){
    for (int i = 1; i <= n; i++) adj[i].clear();
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(color, 0, sizeof(color));
}

int paint(int u, int c){
    for (int it : adj[u]) if(color[it] == c) return 0;
    return 1;
}

int count(int c){
    int ans = 0;
    for (int i = 1; i <= n; i++) 
        if(!color[i] && paint(i, c)) 
        {
            color[i] = c;
            ++ans;
        }
    return ans;
}

int main() {
    fast;
    int t; cin >> t;
    while (t--)
    {
        input();
        int sum = 0;
        for (int i = 1; i <= k; i++) sum += count(i);
        for (int i = 0; i < n; i++)
        {
            cout << color[i + 1] << " ";
        }
        
        if(sum != n) cout << "NO\n";
        else cout << "YES\n";
    }
}