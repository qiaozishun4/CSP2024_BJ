#include<bits/stdc++.h>
using namespace std;
int a[100005],n, maxn=-1,c;

int main(){
    freopen("duel.in","r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int p;
        scanf("%d", &p);
        a[p]++;
        if(p>maxn)maxn=p;
    }//printf("%d %d\n", a[1], a[2]);
    for(int i=1;i<=maxn;i++){
        c=max(c-a[i], 0);
        c+=a[i];
    }printf("%d", c);
}
