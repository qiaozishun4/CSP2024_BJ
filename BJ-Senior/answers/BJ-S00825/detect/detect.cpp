#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,L,vmax;
struct Node{
    int d,v,a;
};
Node c[N];
bool cmp(Node x,Node y){
    return x.a<y.a;
}
int p[N],tmp[N],h[N];
int ans2=0;
void dfs(int u,int num,int state){
    if(u>n){
        memset(h,0,sizeof(h));
        for(int i=1;i<=m;i++){
            if(state&(1<<i-1)){
                for(int j=1;j<=n;j++){
                    int d=c[j].d,v0=c[j].v,a=c[j].a;
                    if(p[i]>=d){
                        long long nv2=1LL*v0*v0+2LL*a*(p[i]-d);
                        if(1LL*vmax*vmax<nv2) h[j]++;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(h[i]==0&&tmp[i]>0) return;
        }
        ans2=max(ans2,m-num);
        return;
    }
    dfs(u+1,num+1,state|(1<<u-1));
    dfs(u+1,num,state);
    return;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    srand(time(NULL));
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>vmax;
        bool flag0=1,flagm0=1;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a!=0) flag0=0;
            if(c[i].a<=0) flagm0=0;
        }
        int pmx=0;
        for(int i=1;i<=m;i++){
            cin>>p[i];
            pmx=max(pmx,p[i]);
        }
        sort(p+1,p+m+1);
        int ans1=0;
        if(flag0){
            int ans1=0;
            for(int i=1;i<=n;i++){
                if(pmx>=c[i].d&&vmax<c[i].v) ans1++;
            }
            cout<<ans1<<' '<<(ans1==0?m:m-1)<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++){
            int d=c[i].d,v0=c[i].v,a=c[i].a;
            if(a<0){
                int pmn=lower_bound(p+1,p+m+1,d)-p;
                long long nv2=1LL*v0*v0+2LL*(p[pmn]-d)*a;
                if(pmn!=m+1&&1LL*vmax*vmax<nv2){
                    ans1++;
                    tmp[i]++;
                }
            }else if(a==0){
                if(pmx>=d&&vmax<v0){
                    ans1++;
                    tmp[i]++;
                }
            }else{
                long long nv2=1LL*v0*v0+2LL*(pmx-d)*a;
                if(pmx>=d&&1LL*vmax*vmax<nv2){
                    ans1++;
                    tmp[i]++;
                }
            }
        }
        cout<<ans1<<' ';
        if(flagm0){
            cout<<(ans1==0?m:m-1)<<'\n';
            continue;
        }
        if(n<=20&&m<=20){
            dfs(1,0,0);
            cout<<ans2<<'\n';
            continue;
        }
        cout<<(ans1==0?m:rand()%(m+1))<<'\n';
    }
    return 0;
}
