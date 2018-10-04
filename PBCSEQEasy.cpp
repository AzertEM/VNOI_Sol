#include <bits/stdc++.h>

using namespace std;
const int Max=1000000;
int l[Max+1], f[Max+1], n, r[Max+1];

void sapxep() {
    for (int i=1; i<=n-1; i++)
        for (int j=i+1; j<=n; j++)
            if (r[i]-l[i]<r[i]-r[j]) {
                swap(r[i],r[j]);
                swap(l[i], l[j]);
            }
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d%d", &l[i], &r[i]);
        f[i]=1;
    }
    sapxep();
    for (int i=1; i<=n-1; i++) {
        for (int j=i+1; j<=n; j++) {
            if (l[j]>=l[i] && r[j]<=r[j])
                f[j]=max(f[i]+1, f[j]);
        }
    }
    int res=0;
    for (int i=1; i<=n; i++)
        res=max(res, f[i]);
    printf("%d", res);
}
