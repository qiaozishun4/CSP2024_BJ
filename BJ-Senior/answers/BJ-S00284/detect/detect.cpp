#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,m,len,ma,p[N];
int g[N],u[N],ans1,ans2;
vector<int> h[N];
struct node{
    int d,v,a;
}c[N];
int clac_1(int x,int y,int z){
    int l=x,r=len;
    while(l<=r){
        int mid=l+r>>1;
        long long t1=y*y+1ll*2*(mid-x)*z,t2=ma*ma;
        if(t1>t2)r=mid-1;
        else l=mid+1;
    }
    return l;
}
int clac_2(int x,int y,int z){
    int l=x,r=len;
    while(l<=r){
        int mid=l+r>>1;
        long long t1=y*y+1ll*2*(mid-x)*z,t2=ma*ma;
        if(t1>t2)l=mid+1;
        else r=mid-1;
    }
    return r;
}
void solve(int x,int y){
    if(x>y)return;
    int st=0,ed=0;
    int l=1,r=m;
    while(l<=r){
        int mid=l+r>>1;
        if(p[mid]>=x)r=mid-1;
        else l=mid+1;
    }
    st=l;
    l=1,r=m;
    while(l<=r){
        int mid=l+r>>1;
        if(p[mid]<=y)l=mid+1;
        else r=mid-1;
    }
    ed=r;
    if(st>=1&&st<=m&&ed>=1&&ed<=m&&st<=ed){
        ans1++;
        h[st].push_back(ed);
        g[ed]++;
        u[st]++;
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans1=0,ans2=0;
        scanf("%d%d%d%d",&n,&m,&len,&ma);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
        for(int i=1;i<=m;i++)
            scanf("%d",&p[i]),g[i]=u[i]=0,h[i].clear();
        for(int i=1;i<=n;i++)
            if(c[i].a==0){
                if(c[i].v>ma)solve(c[i].d,len);
            }else if(c[i].a>0){
                int t=clac_1(c[i].d,c[i].v,c[i].a);
                if(t<=len&&t>=c[i].d)solve(t,len);
            }else{
                if(c[i].v<=ma)continue;
                int t=clac_2(c[i].d,c[i].v,c[i].a);
                if(t<=len&&t>=c[i].d)solve(c[i].d,t);
            }
        queue<int> q;
        for(int i=1;i<=m;i++){
            if(u[i])q.push(i);
            if(g[i]){
                ans2++;
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    for(int i=0;i<h[t].size();i++)g[h[t][i]]--;
                }
            }
        }
        printf("%d %d\n",ans1,m-ans2);
    }
    return 0;
}
