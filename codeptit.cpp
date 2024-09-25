#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007

int f[10000007];
void sang(){
    f[0] = f[1] = 1;
    for (int i = 2; i <= 5000; i++)
        if(!f[i])
            for (int j = i * i; j < 10000007; j += i)
                f[j] = 1;            
}

int main() {
    fast;
    int T; cin >> T;
    sang();
    while (T--) {
        int a, b; cin >> a >> b;
        for (int i = a; i <= b; i++)
        {
            if(!f[i]) cout << i << " ";
        }
        cout << "\n";
    }
}
