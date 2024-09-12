#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n; cin >> n;
    cin.ignore();
    int matrix[n + 1][n + 1];
    memset(matrix, 0, sizeof(matrix));
    for (int i = 1; i <= n; i++)
    {
        string s; getline(cin, s);
        stringstream ss(s);
        while (ss >> s) matrix[i][stoi(s)] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }    
}
