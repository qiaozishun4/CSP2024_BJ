#include<bits/stdc++.h>
using namespace std;
int n,m,L,V,d[100005],v[100005],a[100005],p[100005],cf[100005];
bool vis[100005];
struct no{
    int l,r;
};
vector<no> s;
bool cmp(no qqq,no www){
    return qqq.l<www.l;
}
void solve(){
    scanf("%d%d%d%d",&n,&m,&L,&V);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&d[i],&v[i],&a[i]);
    }
    for(int i=1;i<=m;i++)scanf("%d",&p[i]);
    int ans=0,mx=-1,zr=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            if(v[i]>V){
                int r=lower_bound(p+1,p+m+1,d[i])-p;
                if(r<=m){
                    ans++;
                    zr++;
                    mx=max(mx,r);
                }
            }
        }
        else if(a[i]>0){
            if(v[i]>V){
                int r=lower_bound(p+1,p+m+1,d[i])-p;
                if(r<=m){
                    ans++;
                    zr++;
                    mx=max(mx,r);
                }continue;
            }
            double ca=V*V-v[i]*v[i];
            double ji=2*a[i];
            int xd;
            if((int)ca%(int)ji==0){
                xd=ca/ji+d[i]+1;
            }
            else{
                xd=ceil(ca/ji)+d[i];
            }
            int r=lower_bound(p+1,p+m+1,xd)-p;
            if(r<=m){
                ans++;zr++;
                mx=max(mx,r);
            }
        }
        else{
            if(v[i]<=V)continue;
            double ca=V*V-v[i]*v[i];
            double ji=2*a[i];
            int xd;
            if((int)ca%(int)ji==0){
                xd=ca/ji+d[i];
            }
            else{
                xd=ceil(ca/ji)+d[i];
            }
            int r=lower_bound(p+1,p+m+1,xd)-p;
            int l=lower_bound(p+1,p+m+1,d[i])-p;
            if(l<r){
                ans++;
                cf[l]++,cf[r]--;
                s.push_back(no{l,r-1});
            }
        }
    }
    printf("%d ",ans);
    if(ans==0)printf("%d",m);
    else if(zr==ans){
        printf("%d",m-1);
    }
    else{
        sort(s.begin(),s.end(),cmp);
        for(int i=1;i<=m;i++)cf[i]+=cf[i-1];
        int as=ans-zr;
        int bg=-1,f=0;
        for(int i=mx;i<=m;i++){
            if(cf[i]>=bg)bg=cf[i],f=i;
        }
        as-=bg;
        for(int i=0;i<s.size();i++){
            if(p[f]<s[i].l)break;
            if(vis[i])continue;
            if(p[f]<=s[i].r){
                cf[s[i].l]--,cf[s[i].r+1]++;
                vis[i]=true;
            }
        }
        ans=1;
        while(as>0){
            bg=-1,f=0;
            for(int i=1;i<=m;i++){
                cf[i]+=cf[i-1];
                if(cf[i]>=bg)bg=cf[i],f=i;
            }as-=bg;
            for(int i=0;i<s.size();i++){
                if(p[f]<s[i].l)break;
                if(vis[i])continue;
                if(p[f]<=s[i].r){
                    cf[s[i].l]--,cf[s[i].r+1]++;
                    vis[i]=true;
                }
            }
            ans++;
        }
        printf("%d",m-ans);
        for(int i=1;i<=m;i++)cf[i]=0;
        s.clear();
        for(int i=1;i<=n;i++)vis[i]=0;
    }
    printf("\n");
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}