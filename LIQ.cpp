#include <bits/stdc++.h>

using namespace std;
unsigned long long arr[21], n, dem =1, daycon=0;
int f[21];

int main() {
//    freopen ("LIQ.INP","r",stdin);
//    freopen ("LIQ.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
        f[i]=1;
    }
    for (int i=1; i<=n-1; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            if (arr[j]>arr[i])
                f[j]=max(f[i]+1, f[j]);
        }
    }
    int res=0;
    for (int i =1; i<=n; i++)
        res=max(res, f[i]);
    printf("%d", res);
    return 0;
}
