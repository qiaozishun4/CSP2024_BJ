#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct path{
    int st,en;
};
bool cmp(path a,path b){
    return a.en > b.en;
}
bool fast[maxn];
int d[maxn],vi[maxn],ai[maxn],p[maxn];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(d,0,sizeof(d));
        memset(vi,0,sizeof(vi));
        memset(ai,0,sizeof(ai));
        memset(p,0,sizeof(p));
        memset(fast,0,sizeof(fast));
        path car[maxn],mach1[maxn],mach2[maxn];
        vector<int >edge[maxn],w[maxn];
        int n,m,l,v,ans=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>vi[i]>>ai[i];
            if(ai[i]==0){
                if(vi[i]>v)
                    car[i].st=d[i],car[i].en=l;
                else
                    car[i].st=car[i].en=-1;
            }
            else if(ai[i]<0){
                if(vi[i]<=v)
                    car[i].st=car[i].en=-1;
                else
                    car[i].st=d[i],car[i].en=min(d[i]+(v*v-vi[i]*vi[i])/(2*ai[i]),l);
            }
            else{
                if(vi[i]>v)
                    car[i].st=d[i],car[i].en=l;
                else if(vi[i]==v)
                    car[i].st=d[i]+1,car[i].en=l;
                else
                    car[i].en=l,car[i].st=d[i]+(v*v-vi[i]*vi[i])/(2*ai[i]);
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    mach1[j].st=mach2[j].st=j;
                if(p[j]>=car[i].st&&p[j]<=car[i].en){
                    fast[i]=1;
                    edge[i].push_back(j);
                    w[j].push_back(i);
                    mach1[j].en++;
                    mach2[j].en++;
                }
            }
        }
        for(int i=1;i<=n;i++)
            if(fast[i]){
                ans++;
            }
        cout<<ans<<" ";
        int j=1,sum=0;
        sort(mach1+1,mach1+m+1,cmp);
        bool flag=0;
        while(ans>0){
            flag=0;
            for(int i=1;i<=m;i++)
                if(mach1[i].en==1)
                    flag=1;
            if(!flag)
                break;
            for(int k=0;k<w[mach1[j].st].size();k++){
                int u=w[mach1[j].st][k];
                for(int e=0;e<edge[u].size();e++){
                    int f=edge[u][e];
                    mach2[f].en--;
                }
                ans--;
            }
            sum++;
            mach1[j].en=0;
            for(int z=j;z<=n;z++){
                mach1[z].st=mach2[z].st;
                mach1[z].en=mach2[z].en;
                if(mach2[z].st==mach1[j].st)
                    mach1[z].en=0;
            }
            sort(mach1+1,mach1+m+1,cmp);
        }
        cout<<m-sum<<endl;
    }
    return 0;
}
