#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,l,vs,t;
ll d[100005];
ll v[100005];
ll lll[100005];
ll a[100005];
struct node{
   ll lx,rx;
}p[100005];
ll jl[100005];
bool vis[30005];
ll sum[30005];
ll ansa,ansb;
bool cmp(node x,node y){
    if(x.rx!=y.rx) return x.rx<y.rx;
    else return x.lx<y.lx;
}
ll f[3005][3005];
ll ss[3005][3005];
bool vist[30005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >>t;
    while(t--){
       // cout <<"!";
        cin >>n >>m >>l >>vs;
        //cout <<n <<m <<l <<vs;
       // cout <<"!";
        //cout <<m <<" ";
//        for(int i=0;i<=l;i++) c[i]=0;
        ansa=ansb=0;
      //  cout <<"!";
        for(int i=1;i<=n;i++) f[i][0]=0;
        for(int i=1;i<=m;i++) ss[i][0]=0;
        memset(vist,0,sizeof(vist));
        memset(sum,0,sizeof(sum));
       // cout <<"!";

        for(int i=1;i<=n;i++){
            vis[i]=0;
            cin >>d[i] >> v[i] >>a[i];
            if(a[i]==0){
                if(v[i]>vs)p[i].lx=d[i],p[i].rx=l;
                else{
                    p[i].lx=-1;
                    continue;
                }
            }else{
                if(a[i]>0){
                    if(v[i]>vs)p[i].lx=d[i],p[i].rx=l;
                    else{
                        ll id=((vs*vs)-(v[i]*v[i]))/(2*a[i]);
                        if(id+d[i]+1>l){
                            p[i].lx=-1;
                            continue;
                        }
                        p[i].lx=id+d[i]+1;
                        p[i].rx=l;
                    }
                }else{
                    if(v[i]<=vs){
                        p[i].lx=-1;
                        continue;
                    }
                    ll id=((vs*vs)-(v[i]*v[i]))/(2*a[i]);
                    if(((vs*vs)-(v[i]*v[i]))%(2*a[i])==0) id--;
                    p[i].lx=d[i];
                    if(id+d[i]>l) p[i].rx=l;
                    else p[i].rx=id+d[i];
                }
            }
           // cout <<p[i].lx <<" " <<p[i].rx <<'\n';
        }
        //cout <<"!";
        //cout <<"!";

        for(int i=1;i<=m;i++) cin >>jl[i];
       // cout <<"!";
        sort(jl+1,jl+1+m);
        //cout <<"!";
        sort(p+1,p+1+n,cmp);
        ll op=1;
       // cout <<"!";
        for(int i=1;i<=n;i++){
            if(p[i].lx==-1) op++;
            else break;
        }
        for(int i=1;i<=m;i++){
            while(jl[i]>p[op].rx && op<=n) op++;
            if(op>n)break;
            ll fff=0;
            for(int j=op;j<=n;j++){
                if(p[j].lx==-1) continue;
                if(!vis[j] && p[j].lx<=jl[i])ansa++,vis[j]=1,fff=1;
                if(p[j].lx<=jl[i]){
                    f[j][++f[j][0]]=i;
                    sum[i]++;
                    ss[i][++ss[i][0]]=j;
                }
            }
        }
        //cout <<"!";
        for(int i=1;i<=n;i++){
            if(vis[i] && !vist[i]){
                ll ids;
                ll maxn=-1;
                for(int j=1;j<=f[i][0];j++){
                    //sum[f[i][j]]--;
                    if(maxn<sum[f[i][j]]){
                        ids=f[i][j];
                        maxn=sum[f[i][j]];
                    }
                }
                ansb++;
                for(int j=1;j<=ss[ids][0];j++){
                    if(vist[ss[ids][j]]==1) continue;
                    vist[ss[ids][j]]=1;
                    for(int k=1;k<=f[ss[ids][j]][0];k++){
                        sum[f[ss[ids][j]][k]]--;
                    }
                }
                //cout <<ids <<" ! ";
            }
        }
        cout <<ansa <<" " <<m-ansb;
        cout <<'\n'; //<<'\n';
    }
    return 0;
}
