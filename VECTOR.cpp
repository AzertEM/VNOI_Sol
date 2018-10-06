#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int n, res=0, check[31], dem[6000+5][6000+5];
bool data[31];
pair <int, int> vec[31];
pair <long, long> target, sum;

int id(int x){
    return x+3000;
}

void recur(int a) {
    if (a>n/2) {
        dem[id(sum.X)][id(sum.Y)]++;
        return;
    }
    recur(a+1);
    sum.X+=vec[a].X;
    sum.Y+=vec[a].Y;
    recur(a+1);
    sum.X-=vec[a].X;
    sum.Y-=vec[a].Y;
}

void recurB(int a) {
    if (a>n) {
        res+=dem[id(target.X - sum.X)][id(target.Y-sum.Y)];
        return;
    }
    recurB(a+1);
    sum.X+=vec[a].X;
    sum.Y+=vec[a].Y;
    recurB(a+1);
    sum.X-=vec[a].X;
    sum.Y-=vec[a].Y;
}

int main() {
    sum.X=sum.Y=0;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d%d", &vec[i].X, &vec[i].Y);
    scanf("%ld%ld", &target.X, &target.Y);
    recur(1);
    sum.X=sum.Y=0;
    recurB(n/2+1);
    printf("%d", res);
}
