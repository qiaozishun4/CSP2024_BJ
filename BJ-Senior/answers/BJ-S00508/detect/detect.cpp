#include <bits/stdc++.h>
using namespace std;
int t,n,m,l,V,d[100010],v[100010],a[100010],g[100010],len[100010],maxn=0;
vector <int> h[100010];
bool check(int vv,int aa,int ss){
    double v=vv,a=aa,s=ss,sd=V;
    if(s*2*a+v*v>sd*sd) return true;
    return false;
}
void dfs(int step,int now){
    if(step==m+1){
        maxn=max(maxn,now);
        return ;
    }
    dfs(step+1,now);
    bool flag=true;
    for(int i:h[step]){
        if(!(len[i]>1)){
            flag=false;
            break;
        }
    }
    if(flag){
        for(int i:h[step]){
            len[i]--;
        }
        dfs(step+1,now+1);
        for(int i:h[step]){
            len[i]++;
        }
    }
    return ;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        vector <vector <int> > vt;
        int cnt=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            h[i].clear();
            cin>>g[i];
        }
        for(int i=1;i<=n;i++){
            vector <int> vtr;
            for(int j=1;j<=m;j++){
                if(g[j]<d[i]) continue;
                if(check(v[i],a[i],g[j]-d[i])){
                    vtr.push_back(j);
                    h[j].push_back(i);
                }
            }
            vt.push_back(vtr);
            cnt+=(!(vtr.empty()));
            len[i]=vtr.size();
        }
        cout<<cnt<<" ";
        maxn=0;
        dfs(1,0);
        vt.clear();
        cout<<maxn<<"\n";
    }
    return 0;
}
