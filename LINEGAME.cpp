#include <bits/stdc++.h>
using namespace std;

long long n, a[1000001], f[1000001][2][2];

int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    
    f[2][0][0] = 0;
    f[2][0][1] = a[1];
    f[2][1][0] = a[2];
    f[2][1][1] = a[1] - a[2];
    for (int i = 3; i <= n; i++) {
        f[i][0][0] = max(f[i - 1][0][0], f[i - 1][1][1]);
        f[i][0][1] = max(f[i - 1][0][1], f[i - 1][1][0]);
        f[i][1][0] = a[i] + max(f[i - 1][0][0], f[i - 1][1][1]);
        f[i][1][1] = -a[i] + max(f[i - 1][0][1], f[i - 1][1][0]);
    }
    long long res = 0;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            res = max(res, f[n][i][j]);
    printf("%lld", res);
    return 0;
}
