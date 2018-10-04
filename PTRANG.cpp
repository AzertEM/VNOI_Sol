#include <bits/stdc++.h>

using namespace std;
int l, n, a[6001], f[6001], s=0;
int main() {
    scanf("%d%d", &n, &l);
    for (int i=1; i<=n;i++) {
        scanf("%d", &a[i]);
//        f[i]=a[i];
    }
//    f[1]=l-a[1];
    for (int i=1; i<=n; i++) {
        f[i] = 100000000;
        s=0;
        for (int j=i; j>=1; j--) {
            s+=a[j];
            if (s>l)
                break;
            f[i]=min(f[i], max(l-s, f[j-1]));
        }
    }
//    int res=0;
//    for (int i=1; i<=n; i++)
//        res=max(res, f[i]);
    printf("%d", f[n]);
    return 0;
}
