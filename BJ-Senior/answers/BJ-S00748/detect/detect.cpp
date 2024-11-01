#include<bits/stdc++.h>
using namespace std;
const double eps=1e-10;
int T;
int n,m,D,V;
int Floor(int a,int b){
    int t=a/b;
    if(a%b!=0){
        if(t<0) t--;
    }
    return t;
}
int Ceil(int a,int b){
    int t=a/b;
    if(a%b!=0){
        if(t>=0){
            t++;
        }
    }
    return t;
}
struct Car{
    int d,v,x;
    int l,r;
    void calc(){
        if(x>0){
            l=max(d,d+Floor(V*V-v*v,2*x)+1);
            r=D;
        }
        else if(x<0&&v>V){
            r=d+Ceil(V*V-v*v,2*x)-1;
            l=d;
        }
        else{
            if(v>V){
                l=d;
                r=D;
            }
            else{
                l=r=0;
            }
        }
    }
}a[100005];
bool cmp(Car a,Car b){
    return a.l<b.l;
}
int pos[100005];
bool vis[100005];
int main(){
    freopen("detect2.in","r",stdin);
    //freopen("detect.in","r",stdin);
    //freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        memset(pos,0,sizeof(pos));
        scanf("%d %d %d %d",&n,&m,&D,&V);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i].d,&a[i].v,&a[i].x);
            a[i].calc();
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&pos[i]);
        }
        sort(a+1,a+n+1,cmp);
        int ans1=0,ans2=0,p=1;
        for(int i=1;i<=n;i++){
            while(pos[p]<a[i].l&&p<m){
                p++;
            }
            if(a[i].l==0&&a[i].r==0){
                continue;
            }
            if(pos[p]>=a[i].l&&pos[p]<=a[i].r){
                //printf("%d %d\n",p,i);
                vis[p]=1;
                ans1++;
            }
        }
        ans2=m;
        for(int i=1;i<=m;i++){
            if(vis[i]){
                ans2--;
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}

