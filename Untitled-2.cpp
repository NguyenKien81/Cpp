#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define max_in 1000007

int m, n, visited[max_in];
vector <vector <int>> a(max_in);
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
void solve(){
    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        sort(a[i].begin(), a[i].end());
        for (int it : a[i]) cout << it << " ";
        cout << "\n";
    }
}
int main() {
    fast;
	int T; cin >> T;
    while (T--)
    {
        input();
        solve();
    }
    
}