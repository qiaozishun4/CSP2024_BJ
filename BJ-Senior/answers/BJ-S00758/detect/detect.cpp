#include <bits/stdc++.h>
#define N 1000000
using namespace std;
int T,p[N+5],n,tr[N+5],m,L,V,ans1;
bool isc[N+5];
struct Car{
    int d,v,a;
}a[N+5];
int lowbit(int x){
    return x&(-x);
}
void upd(int x,int d){
    for(;x<=N;x+=lowbit(x))  tr[x]+=d;
}
int query(int x){
    int res=0;
    for(;x;x-=lowbit(x))  res+=tr[x];
    return res;
}
int query(int l,int r){
    return query(r+1)-query(l);
}
void solve(){
    for(int i=1;i<=m;i++){
        cin>>p[i];
        upd(p[i]+1,1);
    }
    for(int i=1;i<=n;i++){
        isc[i]=0;
        if(a[i].a>0){
            if(a[i].v>V){
                if(query(a[i].d,L)){
                    isc[i]=1;
                    ans1++;
                }
                continue;
            }
            int l=a[i].d+(V*V-a[i].v*a[i].v)/(2*a[i].a)+1;
            if(l>L)  continue;
            if(query(l,L)){
                isc[i]=1;
                ans1++;
            }
        }else if(a[i].a<0){
            if(a[i].v<=V)  continue;
            int r=a[i].d+(V*V-a[i].v*a[i].v)/(2*a[i].a);//a[i].d~r
            if(query(a[i].d,r)){
                isc[i]=1;
                ans1++;
            }
        }else{
            if(query(a[i].d,L)&&a[i].v>V){
                isc[i]=1;
                ans1++;
            }
        }
    }
    cout<<ans1<<" ";
    for(int i=1;i<=m;i++){
        upd(p[i]+1,-1);
    }
}
void solve1(){
    cout<<m-(ans1>0)<<"\n";
    ans1=0;
}
bool check(int pos,int i){
    if(a[i].a>0){
        if(a[i].v>V)  return (a[i].d<=pos);
        int l=a[i].d+(V*V-a[i].v*a[i].v)/(2*a[i].a)+1;
        if(l>L)  return 0;
        return (l<=pos)&&(pos<=L);
    }else if(a[i].a==0){
        return (a[i].d<=pos)&&(pos<=L)&&(a[i].v>V);
    }else{
        if(a[i].v<=V)  return 0;
        int r=a[i].d+(V*V-a[i].v*a[i].v)/(2*a[i].a);//a[i].d~r
        return (a[i].d<=pos&&pos<=r);
    }
}
void solve2(){
    int ans2=0;
    for(int k=0;k<(1<<m);k++){
        bool flg=1;int cnt=0;
        for(int j=0;j<m;j++)  cnt+=((k>>j)&1);
        for(int i=1;i<=n;i++){
            if(!isc[i])  continue;
            bool isd=0;
            for(int j=0;j<m;j++){
                if(((k>>j)&1)==0)  continue;
                if(check(p[j+1],i)){
                    isd=1;
                    break;
                }
            }
            if(!isd){
                flg=0;
                break;
            }
        }
        if(flg)  ans2=max(ans2,m-cnt);
    }
    cout<<ans2<<"\n";
    ans1=0;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].v>>a[i].a;
        }
        solve();
        if(n<=20&&m<=20)  solve2();
        else  solve1();
    }
    return 0;
}