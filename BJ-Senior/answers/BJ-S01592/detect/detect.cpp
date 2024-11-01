#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
struct shu{
    ll d,v,a;
    bool operator<(const shu &o)const{
        return d<o.d;
    }
};
ll t;
ll n,m,L,V;
ll d,v,a,p[100005],can[100005],ans,nex[100005],tm[100005];
shu car[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int t1=1;t1<=t;t1++){
        memset(can,0,sizeof(can));
        memset(nex,0,sizeof(nex));
        memset(tm,0,sizeof(tm));
        ans=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d>>v>>a;
            car[i]={d,v,a};
        }
        sort(car+1,car+n+1);
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            if(car[i].a<0){
                for(int j=m;j>=1;j--){
                    if(p[j]<car[i].d||p[j]>L){
                        continue;
                    }
                    if(car[i].v*car[i].v+2*car[i].a*(p[j]-car[i].d)<0){
                        continue;
                    }
                    if(sqrt(car[i].v*car[i].v+2*car[i].a*(p[j]-car[i].d))*1.0>1.0*V){
                        can[i]=1;
                        nex[i]=j;
                        ans++;
                        break;
                    }
                }
            }else{
                for(int j=1;j<=m;j++){
                    if(p[j]<car[i].d||p[j]>L){
                        continue;
                    }
                    if(car[i].v*car[i].v+2*car[i].a*(p[j]-car[i].d)<0){
                        continue;
                    }
                    if(sqrt(car[i].v*car[i].v+2*car[i].a*(p[j]-car[i].d))*1.0>1.0*V){
                        can[i]=1;
                        nex[i]=j;
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans<<" ";
        ll ch[100005],allans=0,ch1[100005];
        memset(ch,0,sizeof(ch));
        while(ch[m+1]!=1){
            memset(ch1,0,sizeof(ch1));
            ch[1]++;
            ll now=1;
            while(ch[now]>=2){
                ch[now]=0;
                ch[now+1]++;
                now++;
                if(now==m+1){
                    break;
                }
            }
            if(ch[m+1]==1){
                break;
            }
            for(int j=1;j<=m;j++){
                if(ch[j]==0){
                    continue;
                }
                for(int i=1;i<=n;i++){
                    if(p[j]-car[i].d<0){
                        continue;
                    }
                    if(sqrt(car[i].v*car[i].v+2*car[i].a*(p[j]-car[i].d))*1.0>1.0*V){
                        ch1[i]++;
                    }
                }
            }
            ll f=1;
            for(int i=1;i<=n;i++){
                if(can[i]==1&&ch1[i]==0){
                    f=0;
                    break;
                }
            }
            if(f==0){
                continue;
            }
            ll ans=0;
            for(int i=1;i<=m;i++){
                if(ch[i]==0){
                    ans++;
                }
            }
            allans=max(allans,ans);
        }
        cout<<allans<<endl;
    }
    return 0;
}
