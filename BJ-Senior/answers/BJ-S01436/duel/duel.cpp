#include <bits/stdc++.h>
#define il inline
using namespace std;
il int read(){
    int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x;
}
const int N=1e5+5;
int n,m,a[N],b[N],in[N],ans;
int x,y,z,u,v,w;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);ans=n;
    for(int i=1;i<=n;++i) a[i]=read(),b[i]=a[i];
    sort(b+1,b+1+n);m=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;++i) a[i]=lower_bound(b+1,b+1+m,a[i])-b,++in[a[i]];
    x=in[1];
    for(int i=2;i<=m;++i){
        y=min(in[i],x),x-=y,ans-=y,x+=in[i];
    }
    printf("%d",ans);
    return 0;
}
