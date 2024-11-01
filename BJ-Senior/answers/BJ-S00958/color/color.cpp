#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=200005;
int T,n,p[maxn],l[maxn],k;
long long du[maxn];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        int n_;cin>>n_;n=k=0;
        long long sum=0,ans=0;
        while(n_--){
            int x;cin>>x;
            //if(T==9)printf("d %d\n",x);
            if(n&&p[n]==x){
                sum+=x;
                continue;
            }
            p[++n]=x;
            l[++k]=x;
        }
        sort(l+1,l+k+1);
        k=unique(l+1,l+k+1)-l-1;
        for(int i=1;i<=k;++i)du[i]=-1;
        for(int i=1;i<=n;++i)p[i]=lower_bound(l+1,l+k+1,p[i])-l;
        long long nw=0;
        for(int i=1;i<n;++i){
            long long tmp=nw;
            if(du[p[i+1]]>=0)tmp=max(tmp,du[p[i+1]]+l[p[i+1]]);
            ans=max(ans,tmp);
            //if(T==9)printf("%d %d\n",i,tmp);
            du[p[i]]=max(du[p[i]],tmp);
            nw=max(nw,tmp);
        }
        cout<<sum+ans<<'\n';
    }
    return 0;
}