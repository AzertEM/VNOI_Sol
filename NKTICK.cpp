#include <bits/stdc++.h>
using namespace std;
int n, a[60001], f[60001], b[60001];
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for (int i=1; i<=n-1; i++)
        scanf("%d", &b[i]);
    f[1]=a[1];
    f[2]=min(a[1]+a[2], b[1]);
    for (int i=3; i<=n; i++) {
        f[i]=min(f[i-1]+a[i], f[i-2]+b[i-1]);
    }
    printf("%d", f[n]);
}
