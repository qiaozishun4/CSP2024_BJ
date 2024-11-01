#include<bits/stdc++.h>
using namespace std;
int T;
struct xxs{
    int d,v,a;
}car[100005];
int pp[100005],tte[1000005],bak[100005];
vector<int> p[1000005],out[1000005],zz[100005];
bool b[100005],sum[100005],bsa[3005][3005],btsa[3005];
bool cmp(xxs cr,xxs ca){
    return cr.d<ca.d;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,l,vv,ans=0;
        cin>>n>>m>>l>>vv;
        for(int i=0;i<=l;i++){
            while(p[i].size()) p[i].pop_back();
            while(out[i].size()) out[i].pop_back();
            tte[i]=0;
        }
        for(int i=1;i<=n;i++){
            b[i]=0,sum[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>car[i].d>>car[i].v>>car[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>pp[i];
            tte[pp[i]]=i;
        }
        sort(car+1,car+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(car[i].v>=vv&&car[i].a>0){
                if(car[i].v==vv){
                    p[car[i].d+1].push_back(i);
                    continue ;
                }
                p[car[i].d].push_back(i);
            }
            else if(car[i].v<vv&&car[i].a>0){
                long long x=vv*1ll*vv-car[i].v*1ll*car[i].v,y=2*car[i].a;
                long long zz=car[i].d+x/y+1ll;
                if(zz>=l*1ll) continue;
                p[zz].push_back(i);
            }
            else if(car[i].v>vv&&car[i].a<0){
                long long x=vv*1ll*vv-car[i].v*1ll*car[i].v,y=2*car[i].a;
                long long zz=car[i].d+x/y+1;
                p[car[i].d].push_back(i);
                if(zz>=l*1ll) continue;
                out[zz].push_back(i);
            }
        }
        for(int i=0;i<=l;i++){
            for(int j=0;j<p[i].size();j++){
                b[p[i][j]]=1;
            }
            for(int j=0;j<out[i].size();j++){
                b[out[i][j]]=0;
            }
            if(tte[i]){
                for(int j=1;j<=n;j++){
                    sum[j]|=b[j];
                    if(b[j]) bsa[tte[i]][j]=1,zz[j].push_back(tte[i]);
                }
            }
        }
        for(int i=1;i<=n;i++){

            if(sum[i]) ans++;
        }
        cout<<ans<<' ';
        ans=m;
        for(int i=1;i<=n;i++){
            if(!zz[i].size()||btsa[i]) continue ;
            if(zz[i].size()){
                ans--;
                for(int j=1;j<=n;j++){
                    bsa[zz[i][0]][j]=1;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
