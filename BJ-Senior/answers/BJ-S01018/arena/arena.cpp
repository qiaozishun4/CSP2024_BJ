#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
int t,n,m,aa[200005],a[200005],c[200005],x[6],id,cnt,lun,lunid[200005],ls[200005],rs[200005],dp[200005];
char ch[200005];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;cnt=n-1;
    for(int i=1;i<=n;i++)
        cin>>aa[i];
    for(int i=1;i<=m;i++)
        cin>>c[i];
    cnt=n;
    while((cnt&(cnt+1)))cnt++;
    while((1<<lun)<=cnt)lun++;
    for(int i=1;i<=lun;i++){//第i层:结尾为 cnt-(1<<(lun-i))+1
        if(i==1){
            for(int j=1,jj=2;jj<=cnt+1;j+=2,jj+=2){
                ls[++id]=j,rs[id]=jj;lunid[id]=i;
                //cout<<id<<":"<<j<<" "<<jj<<"\n";
            }
        }
        else{
            for(int j=cnt-(1<<(lun-i+2))+2,jj=cnt-(1<<(lun-i+2))+3;jj<=cnt-(1<<(lun-i+1))+1;j+=2,jj+=2){
                ls[++id]=j,rs[id]=jj;lunid[id]=i;
                //cout<<id<<":"<<j<<" "<<jj<<"\n";
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        cin>>ch[i];
        while(ch[i]=='\n')cin>>ch[i];
    }
    cin>>t;
    memset(a,-1,sizeof a);
    while(t--){
        ll ans;
        for(int i=0;i<4;i++)cin>>x[i];
        for(id=1;id<=m;id++){
            for(int i=1;i<=c[id];i++)a[i]=aa[i]^x[i%4],a[i]=min(a[i],lun);
            for(int i=1;i<=c[id]-1;i++){
                if(i<=(1<<lun-1)){
                    if(ch[i]=='0'){
                        if(a[ls[i]]>=lunid[i])dp[i]=ls[i];
                        else dp[i]=rs[i];
                    }
                    else{
                        if(a[rs[i]]>=lunid[i])dp[i]=rs[i];
                        else dp[i]=ls[i];
                    }
                }
                else{
                    if(ch[i]=='0'){
                        if(a[dp[ls[i]]]>=lunid[i])dp[i]=dp[ls[i]];
                        else dp[i]=dp[rs[i]];
                    }
                    else{
                        if(a[dp[rs[i]]]>=lunid[i])dp[i]=dp[rs[i]];
                        else dp[i]=dp[ls[i]];
                    }
                }
            }
            ans^=1ll*id*dp[c[id]];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
