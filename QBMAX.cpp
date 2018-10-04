#include <bits/stdc++.h>

using namespace std;
long long a[102][102], m, n;
int main() {
    scanf("%lld%lld", &m, &n);
    for (int i=1; i<=101; i++) {
        a[0][i]=-10001;
        a[m+1][i]=-10001;
    }
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            scanf("%lld", &a[i][j]);
    long long res=-1000001;
        for (int j=2; j<=n; j++)
            for (int i=1; i<=m; i++)
                    a[i][j]+=max(a[i-1][j-1],max(a[i][j-1], a[i+1][j-1]));
    for (int i=1; i<=m; i++)
        res=max(res, a[i][n]);
    printf("%lld", res);
}
