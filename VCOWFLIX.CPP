#include <bits/stdc++.h>
//TRIETTT122@GMAIL.COM
bool data[22];
int arr[22], w=0, x=0, n, c, t=0;

void choose(int a) {
    if (x>c) {
        x-=t;
        w=std::max(w, x);
    }
     if (a>n||x==c) {
        w=std::max(w,x);
        x=0;
        return;
    }
    for (int j=1; j<=n; j++)
        if (data[j]) {
            x+=arr[j];
            t=arr[j];
            data[j]=false;
            choose(a+1);
            data[j]=true;
        }
}

int main() {
    scanf("%d%d", &c, &n);
    for (int i=1; i<=n; i++) {
        data[i]=true;
        scanf("%d", &arr[i]);
    }
    choose(1);
    printf("%d", w);
    return 0;
}
