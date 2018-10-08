#include <bits/stdc++.h>

using namespace std;

const int Max=100001;
long long n, l, r=1;
long long a[Max+1], b[Max+1];

int main() {
//    freopen("NKSGAME.INP", "r", stdin);
//    freopen("NKSGAME.OUT", "w", stdout);
    scanf("%lld", &n);
    for (int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i=1; i<=n; i++) {
        scanf("%lld", &b[i]);
        b[i]=-b[i];
    }
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    //Two Pointers
    long long res=LLONG_MAX, t;
    for (l=1; l <= n && r <= n; l++) {
        for (;r<=n; r++)
            if (b[r] > a[l]) break;
        if (r == 1) res=abs(a[l] - b[r]);
        if (r > n) res=min(res, abs(a[l]-b[r-1]));
        if (r>1 && r<=n) res = min(res, min(abs(a[l] - b[r]), abs(a[l] - b[r-1])));
    }
    printf("%lld", res);
    return 0;
}
