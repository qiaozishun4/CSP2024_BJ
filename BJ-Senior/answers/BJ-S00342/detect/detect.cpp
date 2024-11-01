#include<bits/stdc++.h>
#define N 100005
using namespace std;
int T,n,m,l,v;
struct car{
    int d,v,a;
    int mxShift;
} c[N];
int p[N];
void solve(){
    int mode=0,ans=0;
    memset(c,0,sizeof(c));
    memset(p,0,sizeof(p));
    scanf("%d%d%d%d",&n,&m,&l,&v);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
        if(c[i].a==0) mode=0;
        if(c[i].a>0) mode=1;
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<=n;i++){
        if(c[i].d>p[m]) continue;
        if(mode==0){
            if(c[i].v>v) ans++;
        }
        if(mode==1){
            if(c[i].v*c[i].v+2*c[i].a*(p[m]-c[i].d)>v*v){
                ans++;
            }
        }
    }
    printf("%d ",ans);
    if(ans==0) printf("%d\n",m);
    else printf("%d\n",m-1);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
#include<bits/stdc++.h>
#define N 100005
using namespace std;
int T,n,m,l,v;
struct car{
    int d,v,a;
    int mxShift;
} c[N];
int p[N],ans,nxtP[N*10];
void solve(){
    memset(c,0,sizeof(c));
    memset(p,0,sizeof(p));
    memset(nxtP,0,sizeof(nxtP));
    ans=0;
    scanf("%d%d%d%d",&n,&m,&l,&v);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
        if(c[i].a<0)
            c[i].mxShift=min(l,c[i].d+(int)ceil(-double(c[i].v*c[i].v)/double(c[i].a*2)));
        else
            c[i].mxShift=l;
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&p[i]);
        nxtP[p[i]]=p[i];
    }
    for(int i=l;i>=0;i--){
        if(nxtP[i]) nxtP[i]=i;
        else nxtP[i]=nxtP[i+1];
    }
    for(int i=1;i<=n;i++){
        if(c[i].a>0){
            if(c[i].d>p[m]) continue;
            if(c[i].v*c[i].v+2*c[i].a*(p[m]-c[i].d)>v*v){
                ans++;
            }
            continue;
        }
        if(c[i].a==0){
            if(c[i].d>p[m]) continue;
            if(c[i].v>v) ans++;
            continue;
        }
        if(c[i].a<0){
            if(c[i].d>p[m]) continue;
            if(nxtP[i]==0) continue;
            if(c[i].v*c[i].v+2*c[i].a*(nxtP[c[i].d]-c[i].d)>v*v){
                ans++;
            }
            continue;
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("detect.in","r",stdin);
    //freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

*/
