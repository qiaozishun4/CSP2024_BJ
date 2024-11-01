#include <bits/stdc++.h>
using namespace std;

const long long MAXN=1e5+5;
struct node{int l,r;}t[MAXN];

int n,m,l,V,d[MAXN],v[MAXN],a[MAXN],p[MAXN],cf[MAXN],qzh[MAXN];
bool vis[MAXN];

double speed(int i){
    if(a[i]==0){
        if(v[i]>V)return d[i]-1;
        return l;
    }
    if(a[i]>0)return (V*V-v[i]*v[i])*1.0/(2*a[i])+d[i];
    return (v[i]*v[i]-V*V)*1.0/(2*(0-a[i]))+d[i];
}


int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
int T;cin>>T;while(T--){
    scanf("%d%d%d%d",&n,&m,&l,&V);
    int ans1=0,ans2=0;
    memset(cf,0,sizeof(cf));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)scanf("%d%d%d",&d[i],&v[i],&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&p[i]);
    for(int i=1;i<=n;i++){
        t[i].l=t[i].r=0;
        if(a[i]>=0){
            int tmp=speed(i)+1;
            int tmpl=lower_bound(p+1,p+1+m,tmp)-p;
            if(tmpl<=m)
            t[i].l=tmpl,t[i].r=m,cf[tmpl]++,ans1++;
        }
        else{
            if(v[i]>V){
                int tmp=speed(i)-0.00000001;
                int tmpl=lower_bound(p+1,p+1+m,d[i])-p;
                int tmpr=lower_bound(p+1,p+1+m,tmp)-p-1;
                if(tmpl<=tmpr&&tmpr<=m){
                    t[i].l=tmpl,t[i].r=tmpr,cf[tmpl]++,cf[tmpr+1]--,ans1++;
                }
            }
        }
    }
    printf("%d ",ans1);
    int last=ans1;
    while(last){
        qzh[0]=0;
        int maxn=0,xb;
        for(int i=1;i<=m;i++){
            qzh[i]=qzh[i-1]+cf[i];
            if(qzh[i]>maxn)maxn=qzh[i],xb=i;
        }
        ans2++;
        for(int i=1;i<=n;i++){
            if(vis[i]==0&&t[i].l<=xb&&xb<=t[i].r){
                cf[t[i].l]--,cf[t[i].r+1]++;
                vis[i]=1;
                last--;
            }
        }
    }
    printf("%d\n",m-ans2);
}
    fclose(stdin);
    fclose(stdout);
}
