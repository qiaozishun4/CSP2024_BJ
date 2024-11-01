#include<bits/stdc++.h>
using namespace std;
int n,a[100001],t[100001],sum,maxn=-1e9;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t[a[i]]++;
    }
    for(int i=1;i<=100000;i++){
        maxn=max(maxn,t[i]);
    }
    printf("%d",maxn);
    return 0;
}
