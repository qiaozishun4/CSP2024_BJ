#include<bits/stdc++.h>
using namespace std;
#define ldb long double
const int MAXN=1e5+15;
struct node{
    int cmo,bsp,addsp;
    bool operator<(const node &a) const{
        return cmo<a.cmo;
    }
};
inline void read(int &x){
    x=0;
    int neg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-'){
        neg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=neg;
    return;
}
int t,n,m,len,spd,u,v,w,lcnt,mcnt,eqcnt,ansa,ansb,mxbeg,mnpos,l,r,lseg;
int pos[MAXN],seg[MAXN];
bool vis[MAXN];
node a[MAXN];
inline ldb getspeed(const int &bsp,const int &addsp,const int &len){
    if(len<0) return 0;
    return sqrt(1ll*bsp*bsp+2ll*addsp*len);
}
void dfs(int idx){
    if(idx>m){
        int add=0,res=0,l=1,r=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[j]&&getspeed(a[i].bsp,a[i].addsp,pos[j]-a[i].cmo)>spd){
                    add++;
                    break;
                }
            }
        }
        for(int i=1;i<=m;i++) if(!vis[i]) res++;
        if(add>=ansa) ansb=max(res,ansb);
        return;
    }
    dfs(idx+1);
    vis[idx]=true;
    dfs(idx+1);
    vis[idx]=false;
    return;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    read(t);
    while(t--){
        read(n);
        read(m);
        read(len);
        read(spd);
        lcnt=mcnt=eqcnt=0;
        for(int i=1;i<=n;i++){
            read(u);
            read(v);
            read(w);
            a[i]={u,v,w};
            if(w<0) lcnt++;
            else if(w>0) mcnt++;
            else eqcnt++;
        }
        for(int i=1;i<=m;i++) read(pos[i]);
        sort(a+1,a+1+n);
        if(mcnt==n){
            ansa=0,ansb=m-1;
            for(int i=1;i<=n;i++) if(a[i].cmo<=pos[m]&&getspeed(a[i].bsp,a[i].addsp,pos[m]-a[i].cmo)>spd) ansa++;
            ansb+=ansa<=0;
            cout<<ansa<<' '<<ansb<<'\n';
        }
        else if(eqcnt==n){
            ansa=0,ansb=m-1;
            for(int i=1;i<=n;i++) if(a[i].cmo<=pos[m]&&a[i].bsp>spd) ansa++;
            ansb+=ansa<=0;
            cout<<ansa<<' '<<ansb<<'\n';
        }
        else{
            ansa=ansb=0;
            memset(vis,false,sizeof(vis));
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(getspeed(a[i].bsp,a[i].addsp,pos[j]-a[i].cmo)>spd){
                        ansa++;
                        break;
                    }
                }
            }
            dfs(1);
            cout<<ansa<<' '<<ansb<<'\n';
        }
    }
    return 0;
}
