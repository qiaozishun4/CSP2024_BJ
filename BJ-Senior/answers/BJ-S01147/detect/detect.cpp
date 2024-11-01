#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int d[100005],v[100005],a[100005],p[100005],cs[100005],en[100005],n,m,flagc,ans,flagf;
bool vis[100005],flag[100005];
void dfs(int x){
    if(x>m){
        for(int i=1;i<=m;i++){
            if(!vis[i]) continue;
            for(int j=1;j<=n;j++){
                if(cs[j]!=-1 && en[j]!=-1){
                    if(cs[j]<=p[i] && en[j]>=p[i]) flag[j]=1;
                }
                else if(cs[j]!=-1){
                    if(cs[j]<=p[i]) flag[j]=1;
                }
            }
        }
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            if(flag[i]) cnt1++;
        }
        flagc++;
        if(flagc==1){
            cout<<cnt1<<" ";
            flagf=cnt1;
        }
        if(cnt1==flagf){
            int cnt3=0;
            for(int i=1;i<=m;i++){
                if(!vis[i]) cnt3++;
            }
            ans=max(ans,cnt3);
        }
        memset(flag,0,sizeof(flag));
        return ;
    }
    for(int i=1;i>=0;i--){
        vis[x]=i;
        dfs(x+1);
    }
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int l,V;
        bool flag=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]<0) flag=1;
        }
        for(int i=1;i<=m;i++) cin>>p[i];
        if(!flag){
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    if(v[i]>V) cs[i]=d[i];
                    else cs[i]=-1;
                }
                else{
                    if(v[i]<=V) cs[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i])+1;
                    else cs[i]=d[i];
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(p[m]>=cs[i] && cs[i]!=-1) cnt++;
            }
            if(cnt==0) cout<<0<<" "<<m<<'\n';
            else cout<<cnt<<" "<<m-1<<'\n';
        }
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    if(v[i]>V) cs[i]=d[i];
                    else cs[i]=-1;
                    en[i]=-1;
                }
                else if(a[i]>0){
                    if(v[i]<=V) cs[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i])+1;
                    else cs[i]=d[i];
                    en[i]=-1;
                }
                else{
                    if(v[i]>V) cs[i]=d[i];
                    if((V*V-v[i]*v[i])%(2*a[i])==0) en[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
                    else en[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i])+1;
                }
            }
            dfs(1);
            cout<<ans<<'\n';
            flagc=0;
            ans=0;
            flagf=0;
        }
    }
    return 0;
}

//40~60pts finish time: 18:28
//luogu uid 453759
//BJ-S01147
//:(
//IcantAKCSPS
