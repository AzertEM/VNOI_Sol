#include <bits/stdc++.h>
using namespace std;
int n, a[25000], f[25000];
int main(){
    scanf("%d", &n);
    for (int i=1; i<n; i++)
        scanf("%d", &a[i]);
    f[2]=a[1];
    f[3]=a[2]+a[1];
    for (int i=4; i<=n; i++) {
        f[i]=a[i-1]+min(f[i-1],f[i-2]);
    }
    printf("%d", f[n]);
}
//NKTICK
