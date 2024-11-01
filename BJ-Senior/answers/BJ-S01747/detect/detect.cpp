#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
struct node{int d,v,a;}c[N];
struct width{int l,r;}be_det[N];
int t,n,m,l,vmax,p[N],ans;
bool cmp(width s1,width s2){
    if(s1.l!=s2.l) return p[s1.l]<p[s2.l];
    return p[s1.r]<p[s2.r];
}
void dfs(int dep,int pos,int sum){
    if(sum>=ans) return ;
    if(dep>n){
        ans=min(ans,sum);
        return ;
    }
    if(pos>=be_det[dep].l && pos<=be_det[dep].r)
        dfs(dep+1,pos,sum);
    else{
        for(int i=be_det[dep].l;i<=be_det[dep].r;i++)
            dfs(dep+1,i,sum+1);
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=100000;i++){
            c[i].d=c[i].v=c[i].a=0;
            be_det[i].l=be_det[i].r=0;
        }
        scanf("%d%d%d%d",&n,&m,&l,&vmax);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
        int maxs=-1;
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
            maxs=max(maxs,p[i]);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(c[i].d>maxs) continue;
            if(c[i].d==maxs){
                if(c[i].v>vmax){
                    cnt++;
                    be_det[i].l=be_det[i].r=m;
                }
                continue;
            }
            if(c[i].v<=vmax && c[i].a<0) continue;
            int pos=lower_bound(p+1,p+1+m,c[i].d)-p;
            if(c[i].a==0){
                if(c[i].v>vmax){
                    cnt++;
                    be_det[i].l=pos;
                    be_det[i].r=m;
                }
                continue;
            }
            if(c[i].v>=vmax && c[i].a>0){
                cnt++;
                if(c[i].v==vmax && p[pos]==c[i].d) be_det[i].l=pos+1;
                else be_det[i].l=pos;
                be_det[i].r=m;
            }
            if(c[i].v>=vmax && c[i].a<0){
                double t=(double)abs(c[i].v-vmax)/(double)(abs(c[i].a));
                double x=1.0*c[i].d+1.0*c[i].v*t+0.5*c[i].a*t*t;
                if(x<=p[pos]) continue;
                else{
                    cnt++;
                    be_det[i].l=pos;
                    if(x>=maxs) be_det[i].r=m;
                    else{
                        int rrr=lower_bound(p+1,p+1+m,x)-p;
                        if(p[rrr]>=x) rrr--;
                        be_det[i].r=rrr;
                    }
                }
            }
            if(c[i].v<vmax && c[i].a>0){
                double t=(double)abs(c[i].v-vmax)/(double)(abs(c[i].a));
                double x=1.0*c[i].d+1.0*c[i].v*t+0.5*c[i].a*t*t;
                if(x>=maxs) continue;
                else{
                    cnt++;
                    int lll=lower_bound(p+1,p+1+m,x)-p;
                    if(p[lll]<=x) lll++;
                    be_det[i].l=lll;
                    be_det[i].r=m;
                }
            }
        }
        printf("%d ",cnt);
        sort(be_det+1,be_det+1+n,cmp);
        int l=1;
        while(be_det[l].l==0) l++;
        int tmp=0;
        ans=2e9;
        for(int i=be_det[l].l;i<=be_det[l].r;i++){
            dfs(l+1,i,1);
        }
        printf("%d\n",m-ans);
    }
    return 0;
}
