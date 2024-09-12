#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007


int main() {
    fast;
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int &it : a) cin >> it;
        sort(a, a + n);
        int m = 100000;
        for (int i = 0; i < n - 1; i++)
        {
            m = min(a[i + 1] - a[i], m);
        }
        cout << m << "\n";        

    }
}
