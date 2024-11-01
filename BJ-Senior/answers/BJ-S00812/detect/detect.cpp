#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxN=100010;
struct node{
    int l,r;
    bool book;
} a[maxN],g[maxN];
bool fir(node n1,node n2){
    return n1.l<=n2.l;
}
bool cmp(node n1,node n2){
    if(n1.l!=n2.l) return n1.l>n2.l;
    else return n1.r<n2.r;
}
int b[maxN];
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    scanf("%lld",&t);
    while(t--){
        int n,m,len,v,pos,st,det,cnt=0;
        scanf("%lld%lld%lld%lld",&n,&m,&len,&v);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&pos,&st,&det);
            if(det>0){
                if(st>v){
                    cnt++;
                    a[cnt].l=pos,a[cnt].r=len;
                } else {
                    int x=pos+(v*v-st*st)/(2*det);
                    x++;
                    if(x<=len){
                        cnt++;
                        a[cnt].l=x;
                        a[cnt].r=len;
                    }
                }
            } else if(det==0){
                if(st>v){
                    cnt++;
                    a[cnt].l=pos,a[cnt].r=len;
                }
            } else {
                if(st>v){
                    int k=v*v-st*st;
                    int x=pos+(v*v-st*st)/(2*det);
                    if(k%(2*det)==0) x--;
                    cnt++;
                    a[cnt].l=pos;
                    a[cnt].r=min(x,len);
                }
            }
        }
        for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
        sort(b+1,b+m+1);
        sort(a+1,a+cnt+1,fir);
        int cur=1,ans=cnt;
        for(int i=1;i<=m;i++){
            while(a[cur].l<=b[i] && cur<=cnt){
                if(a[cur].r<b[i]) ans--;
                else a[cur].book=1;
                cur++;
            }
        }
        ans-=(cnt-cur+1);
        printf("%lld ",ans);
        sort(a+1,a+cnt+1,cmp);
        int minr=1e9,tot=0;
        for(int i=1;i<=cnt;i++){
            if(a[i].r>=minr || !a[i].book) continue;
            tot++;
            minr=a[i].r;
            g[tot].l=a[i].l,g[tot].r=a[i].r;
        }
        cur=1,ans=0;
        int last=-1;
        for(int i=tot;i;i--){
            bool flag=0;
            if(last<g[i].l){
                flag=1;
                ans++;
            }
            while(b[cur]<=g[i].r && cur<=m){
                if(flag) last=b[cur];
                cur++;
            }
        }
        printf("%lld\n",m-ans);
    }
    return 0;
}
