#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
struct node{
    int d,v,a;
};
int diff[MAX],p[MAX],mark[MAX];
map<int,int>fa;
map<int,int>vis;
int findf(int x){
    if(fa[x]==x)return x;
    return fa[x]=findf(fa[x]);
}
void add(int x,int y){
    int u=findf(x),v=findf(y);
    if(u!=v)fa[u]=v;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,L,V,ans1=0,ans2=0;
        cin>>n>>m>>L>>V;
        node car[MAX];
        vis.clear();fa.clear();
        memset(mark,0,sizeof(mark));
        for(int i=-m;i<=n;i++)fa[i]=i;
        for(int i=1;i<=n;i++)cin>>car[i].d>>car[i].v>>car[i].a;
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++){
            memset(diff,0,sizeof(diff));
            int d=car[i].d,v=car[i].v,a=car[i].a;
            if(v>V&&a>=0){
                diff[d]+=1;
            }
            else if(v>V&&a<0){
                int D=(v*v-V*V-1)/(-2*a)+1+d;
                //cout<<D<<endl;
                diff[d]+=1;
                if(D<L)diff[D]-=1;
            }
            else if(v<V&&a>0){
                int D=(V*V-v*v-1)/(2*a)+1+d;
                if(D<=L){
                    diff[D+1]+=1;
                }
            }
            else if(v==V&&a>0){
                if(d+1<=L){
                    diff[d+1]+=1;
                }
            }
            for(int j=1;j<=L;j++){
                diff[j]+=diff[j-1];
                //cout<<diff[j]<<' ';
            }
            //cout<<endl;
            int flag=0;
            for(int j=1;j<=m;j++){
                if(diff[p[j]]){
                    mark[j]=1;
                    flag=1;
                    add(i,-j);
                    //cout<<i<<' '<<-j<<endl;
                }
            }
            if(flag==1)ans1++;
        }
        for(int i=-m;i<=-1;i++){
            if(mark[-i]==0)ans2++;
            int x=findf(i);
            //cout<<x<<' ';
            if(vis[x]){
                //cout<<x<<endl;
                ans2++;
            }
            else vis[x]=1;
        }
        //cout<<endl;
        cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}
