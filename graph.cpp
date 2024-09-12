#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 10007

int GCD(int a, int b) {
    if (a < b) return GCD(b, a);
    if (!b) return a;
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    return (a / GCD(a, b) * b) % mod;
}

int main() {
    fast;
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n; cin >> n;
        int a[n], sum = 0;
        for (int &it : a) cin >> it;
        int l = 0;
        while (l < n)
        {
            for (int i = 0; i < n; i++)
            {
                int tmp = a[i];
                for (int j = 0; j + l < n; j++)
                {
                    tmp = LCM(tmp, a[j]);
                }
                if(i + l < n){
                    cout << tmp << " ";
                    sum += tmp;
                }
            }
            l++;
            cout << "\n";
        }
        cout << sum << "\n";
    }
    
    
}
