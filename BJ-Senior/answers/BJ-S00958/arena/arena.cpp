#include<iostream>
#include<cmath>
#include<algorithm>
#include<cassert>
using namespace std;
const int maxn=140000;
int n,m,k,T,p_[maxn],p[maxn],d[maxn],rd[maxn];
int ct[5],js[maxn*2],tl[20][maxn],ed[maxn],cy[maxn];
pair<int,int> c[maxn];
char str[maxn/2];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>p_[i];
    for(int i=1;i<=m;++i)cin>>c[i].first,c[i].second=i;
    sort(c+1,c+m+1);
    while((1<<k)<n)++k;
    for(int i=1;i<=m;++i){
        ed[i]=1;cy[i]=k;
        while(ed[i]<c[i].first){
            ed[i]<<=1;
            --cy[i];
        }
    }
    for(int i=1,j=0;i<=k;++i){
        cin>>str+1;
        for(int u=(1<<k-i);u>=1;--u){
            if(str[u]=='0')d[++j]=0;
            else d[++j]=1;
        }
    }
    reverse(d+1,d+(1<<k));
    for(int i=1;i<(1<<k);++i){
        rd[i]=rd[i>>1]-1;
        if(i==1)rd[i]=k;
    }
    for(int i=0;i<=k;++i){
        for(int j=0;j<(1<<k-i);++j){
            int nw=(1<<k)+j,res=0;
            while(nw!=(1<<i)){
                if((nw&1)==d[nw>>1])res=max(res,rd[nw>>1]);
                nw>>=1;
            }
            tl[i][j+1]=res;
        }
    }
    for(int i=1;i<=(1<<k);++i)js[(1<<k)+i-1]=i;
    cin>>T;//T=256;
    while(T--){
        cin>>ct[0]>>ct[1]>>ct[2]>>ct[3];
        //ct[0]=ct[1]=ct[2]=ct[3]=0;
        for(int i=1;i<=(1<<k);++i)p[i]=(p_[i]^ct[i%4]);
        for(int i=(1<<k)-1;i>=1;--i){
            if(d[i]==0){
                if(p[js[i<<1]]>=rd[i])js[i]=js[i<<1];
                else js[i]=js[i<<1|1];
            }
            else{
                if(p[js[i<<1|1]]>=rd[i])js[i]=js[i<<1|1];
                else js[i]=js[i<<1];
            }
        }
        long long ans=0;
        for(int i=1;i<=m;++i){
            int nw=c[i].first+(1<<k)-1,a=c[i].first,b=c[i].first+1;
            int tp=c[i].first;
            while(nw&(nw-1)){
                int tmp=(nw>>1);
                if(nw&1){
                    if(d[tmp]){
                        if(b>tp){
                            if(p[a]<rd[tmp])a=js[tmp<<1];
                        }
                        else{
                            if(p[js[tmp<<1]]>=tl[cy[i]][js[tmp<<1]])a+=js[tmp<<1];
                        }
                    }
                    else{
                        if(p[js[tmp<<1]]>=rd[tmp]){
                            a=js[tmp<<1];
                            b=tp+1;
                        }
                    }
                }
                else{
                    if(d[tmp]){
                        if(b>tp){
                            if(p[a]<tl[cy[i]][a])a=0;
                        }
                    }
                    else{
                        if(b>tp){
                            if(p[a]<rd[tmp])a=0;
                            else b+=(tp&-tp);
                        }
                    }
                    tp+=(tp&-tp);
                }
                nw=tmp;
            }
            ans=(ans^(a+(long long)(b+ed[i])*(ed[i]-b+1)/2)*c[i].second);
        }
        cout<<ans<<'\n';
    }
    return 0;
}