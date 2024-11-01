#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e6+10;
struct car{
    int d,v,a;
} a[N];
struct line{
    int x,y;
} b[N];
int n,m,L,V,p[N],dis[N],d[M],c[M];
vector<int> g[N];
bool vis[N];
int check(int len,int x){
    int v=a[x].v,aa=a[x].a;
    return max(v*v+2*aa*len,0);
}
void getdis(int x){
    int d=a[x].d,v=a[x].v,aa=a[x].a;
    if(aa==0){
        if(v>V){
            dis[x]=d;
        }
        return ;
    }
    if(aa>0){
        int l=0,r=L,ans=-1;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid,x)>V*V){
                r=mid;
            }else if(check(mid,x)<V*V){
                l=mid+1;
            }else if(check(mid,x)==V*V){
                break;
            }
        }
        ans=(l+r)/2;
        dis[x]=ans+d;
    }else{
       int l=0,r=L,ans=-1;
       while(l<r){
            int mid=(l+r)/2;
            if(check(mid,x)>V*V){
                l=mid+1;
            }else if(check(mid,x)<V*V){
                r=mid;
            }else if(check(mid,x)==V*V){
                break;
            }
        }
        ans=(l+r)/2;
        dis[x]=ans+d-1;
    }
}
void solve(){
    memset(vis,false,sizeof(vis));
    memset(d,0,sizeof(d));
    memset(c,0,sizeof(c));
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    memset(dis,-1,sizeof(dis));
    cin >>n>>m>>L>>V;
    for(int i=1;i<=n;i++){
        cin >>a[i].d>>a[i].v>>a[i].a;
        getdis(i);
    }
    c[1]=1;
    for(int i=1;i<=m;i++){
        g[i].clear();
        cin >>p[i];
        for(int j=p[i-1];j<p[i];j++){
            d[j]=i-1;
        }
    }
    for(int j=p[m];j<=L;j++){
        d[j]=m;
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        if(dis[i]==-1){
            continue;
        }
        if(a[i].a>=0){
            if(d[L]-d[dis[i]+1]!=0){
                ans1++;
            }
        }else{
            if(d[dis[i]]-d[a[i].d]!=0){
                ans1++;
            }
        }
    }
    cout <<ans1<<" ";
    memset(d,0,sizeof(d));
    int pos=0;
    for(int i=1;i<=n;i++){
        if(dis[i]==-1){
            continue;
        }
        if(a[i].a>=0){
            b[++pos].x=min(dis[i]+1,L);
            b[pos].y=L;
        }else{
            b[++pos].x=a[i].d;
            b[pos].y=dis[i];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=pos;j++){
            if(b[j].x<=p[i] && b[j].y>=p[i]){
                g[i].push_back(j);
            }
        }
    }
    int ccnt=0;
    while(ccnt!=ans1){
        int mx=0,mxid=0;
        for(int i=1;i<=m;i++){
            int sum=0;
            for(int j=0;j<g[i].size();j++){
                if(vis[g[i][j]]==0){
                    sum++;
                }
            }
            if(sum>mx){
                mx=sum;
                mxid=i;
            }
        }
        ccnt+=mx;
        for(int i=0;i<g[mxid].size();i++){
            vis[g[mxid][i]]=1;
        }
        ans2++;
    }
    cout <<n-ans2<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}
