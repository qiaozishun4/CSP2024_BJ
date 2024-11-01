#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
int t,n,m,l,V,a[100005],d[100005],v[100005],p[100005],dp[100005];
set<int>pos;
struct seg{
    double l,r;
};
vector<seg>s,s1;
map<int,int>h;
bool cmp(seg a,seg b){
    return a.r<b.r;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        s.clear();
        s1.clear();
        pos.clear();
        memset(dp,0,sizeof(dp));
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]>0){
                if(v[i]<V){s.push_back(seg{d[i],l+1});continue;}
                double x=(pow(V,2)-pow(v[i],2))/(2.0*a[i]);
                if(x>l-d[i]+eps) continue;
                s.push_back(seg{d[i]+x,l+1});
            }if(a[i]==0){
                if(v[i]>V) s.push_back(seg{d[i],l+1});
            }if(a[i]<0){
                if(v[i]<=V) continue;
                double x=(pow(V,2)-pow(v[i],2))/(2.0*a[i]);
                s.push_back(seg{d[i],min(d[i]+x,double(l+1))});
            }
        }
        for(int i=1;i<=m;i++) cin>>p[i],pos.insert(p[i]),h[p[i]]=i;
        int ans=0;
        for(seg d:s){
            auto it=pos.lower_bound(d.l);
            if(*it<d.r){
                ans++;
                auto it1=pos.upper_bound(d.r);
                it1--;
                s1.push_back(seg{h[*it],h[*it1]});
            }
        }
        sort(s1.begin(),s1.end(),cmp);
        int now=0,maxl=0;
        dp[0]=0;
        multiset<int>sx;
        sx.insert(0);
        for(int i=1;i<=m;i++){
            if(s1[now].r>i){dp[i]=dp[i-1];sx.insert(dp[i]);continue;}
            dp[i]=*sx.rbegin()+1;
            while(s1[now].r==i&&now<s1.size()){
                if(s1[now].l>maxl){
                    for(int k=maxl;k<s1[i].l;k++)
                        sx.erase(sx.lower_bound(dp[k]));
                    maxl=s1[i].l;
                }now++;
            }
            sx.insert(dp[i]);
        }
        cout<<ans<<" "<<dp[m]<<endl;
    }
    return 0;
}
