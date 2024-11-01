#include<bits/stdc++.h>
using namespace std ;
int a[100005],n,h[100005],hp;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            int q;
        scanf("%d",&q);
        a[q]++;
    }
    for(int i=1;i<=100001;i++){
        if(a[i]>0){
            h[++hp]=i;
        }
    }
    int now=n;
    for(int i=1;i<hp;i++){
        if(a[h[i]]<=a[h[i+1]]){
            now-=a[h[i]];
        }
        else{
            now-=a[h[i+1]];
            a[h[i+1]]=a[h[i]];
        }
    }
    printf("%d",now);
    return 0;
}
