#include <bits/stdc++.h>
#include <utility>

using namespace std;
const int N=300000;
pair <long, int> vt[N+1];
int demA[N+1], demB[N+1];
int n, a, b;

int cayA(int x) {
    if (vt[x].second==1)
        return 1;
    else return 0;
}

int cayB(int x) {
    if(vt[x].second==2)
        return 1;
    else return 0;
}

int main() {
    demA[0]=0;
    demB[0]=0;
    scanf("%d%d%d", &n, &a, &b);
    for (int i=1; i<=n; i++) {
        scanf("%ld%d", &vt[i].first, &vt[i].second);
    }
    sort(vt+1, vt+n+1);
    for (int i=1; i<=n; i++) {
        demA[i]=cayA(i)+demA[i-1];
        demB[i]=cayB(i)+demB[i-1];
    }
    int l, r=a+b, tung, truc;
    long res=1000000001;
    for (l=1; l<=n-(a+b)+1; l++) {
        while (r<=n) {
            tung=demA[r]-demA[l-1];
            truc=demB[r]-demB[l-1];
            if (tung>=a && truc>=b) {
                res=min(res, vt[r].first-vt[l].first);
                break;
            }
            r++;
        }
    }
    if (res==1000000001) printf("-1");
    else printf("%ld", res);
}
