#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,m,L,V,d[N],v[N],a[N],p[N],cnt,l[N],l2[N],c[N],ans;
bool flag,f2,ff1,ff2;
vector<int>g[N];
double sv(int s,int bv,int a){
    if(a==0)return bv;
    return sqrt(bv*bv+2*a*s);
}
inline void dfs(int x,int ccnt){
    if(x>m){
        f2=true;
        for(register int i=1;i<=n;i++){
            l2[i]=l[i];
        }
        for(register int i=1;i<=m;i++){
            if(c[i]==1)continue;
            for(register int j=0;j<g[i].size();j++){
                l2[g[i][j]]--;
            }
        }
        for(register int i=1;i<=n;i++){
            if(l2[i]==0 && l[i]!=0){
                f2=false;
                break;
            }
        }
        if(f2)ans=max(ans,ccnt);
        return;
    }
    c[x]=0;
    dfs(x+1,ccnt+1);
    c[x]=1;
    dfs(x+1,ccnt);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        ans=-1000005;
        flag=false;
        ff1=true;
        cnt=0;
        cin>>n>>m>>L>>V;
        for(register int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]<0)ff1=false;
        }
        for(register int i=1;i<=m;i++){
            cin>>p[i];
        }
        if(ff1){
            cnt=0;
            for(register int i=1;i<=n;i++){
                if(d[i]>p[m]){
                    continue;
                }
                if(sv(p[m]-d[i],v[i],a[i])>(double)V){
                    cnt++;
                }
            }
            cout<<cnt<<' '<<(m-1)<<'\n';
            continue;
        }
        for(register int i=1;i<=n;i++){
            flag=false;
            for(register int j=1;j<=m;j++){
                if(d[i]>p[j]){
                    continue;
                }
                if(sv(p[j]-d[i],v[i],a[i])>(double)V){
                    g[j].push_back(i);
                    l[i]++;
                    flag=true;
                }
            }
            if(flag)cnt++;
        }
        cout<<cnt<<' ';
        //for(int i=1;i<=n;i++){
        //    cout<<l[i]<<' ';
        //}
        //cout<<'\n';
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
