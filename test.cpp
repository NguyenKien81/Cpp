#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int T; cin >> T;
    while (T--) {
        int n, p; cin >> n >> p;
        vector<int> cnt(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            int temp = i;
            while (temp % p == 0) {
                cnt[i]++;
                temp /= p;
            }
            cnt[i] += cnt[i - 1];
            cout << cnt[i] << " ";
        }
        cout << "\n";
    }
}
