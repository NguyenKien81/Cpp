#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector <int> used;
vector <vector <int>> adj, r_adj;
stack <int> st;

void input(){
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        r_adj[i].clear();
    }
    cin >> n >> m;
    adj.assign(n + 1, vector <int> ());
    r_adj.assign(n + 1, vector <int> ());
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
    used.assign(n + 1, 0);
}
void dfs1(int i){
    used[i] = 1;
    for(int it : adj[i]) if(!used[it]) dfs1(it);
    st.push(i);
}
void dfs2(int i){
    used[i] = 1;
    for(int it : r_adj[i]) if(!used[it]) dfs2(it);
    cout << i << " ";
}
int main() {
    fast;
	int T; cin >> T;
    while (T--)
    {
        input();
        dfs1(1);
        used.assign(n + 1, 0);
        while(!st.empty()){
            int x = st.top(); st.pop();
            if(!used[x]) {
                dfs2(x);
                cout << "\n";
            }

        }
        
        
    }
    
}