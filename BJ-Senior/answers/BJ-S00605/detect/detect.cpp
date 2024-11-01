#include<bits/stdc++.h>
using namespace std;
struct node{
    int st,vs,vp;
};
struct spst{
    bool vs;
    double fr,to;
};vector<int> t;
bool cmp(spst a,spst b){
    if(a.fr==b.fr) return a.to<b.to;
    return a.fr<b.fr;
}
int T,n,m,l,v,ans;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){ans=0;t.clear();
        scanf("%d%d%d%d",&n,&m,&l,&v);
        for(int i=1;i<=n;i++){
            int d,vi,a;
            scanf("%d%d%d",&d,&vi,&a);
            if(vi<=v) continue;
            t.push_back(d);
        }int tem;
        for(int i=1;i<=m;i++)scanf("%d",&tem);
        for(auto i:t) if(i<=tem) ans++;
        if(ans>0)cout<<ans<<' '<<m-1<<'\n';
        else cout<<ans<<' '<<m<<'\n';
    }
    return 0;
}
