#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7,M=1e6+7;
int t;
int n,m,L,V;
int d[N],v[N],a[N],p[N],sum[M],cnt[M],tot,ans1,ans2,cl[N],cr[N],ss[N];
int bf[M];
bool AB,BF;
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        memset(cnt,0,sizeof cnt),memset(sum,0,sizeof sum);
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        ans1=0,BF=0,AB=1,ans2=INT_MAX,tot=0;
        memset(cl,0,sizeof cl),memset(cr,0,sizeof cr);
        if(n<=20&&m<=20)BF=1;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
            if(a[i]<0)AB=0;
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&p[i]);
            cnt[p[i]]=1;
        }
        for(int i=0;i<=L;i++)cnt[i]+=cnt[i-1];
        for(int i=1;i<=n;i++){
            int ql=-1,qr=-1;
            if(a[i]==0){
                if(v[i]>V){
                    ql=d[i],qr=L;
                }
            }else if(a[i]<0){
                if(v[i]>V){
                    int l=d[i],r=L;

                    while(l!=r){
                        int mid=(l+r+1)>>1;
                        int vel2=(mid-d[i])*2ll*a[i]+v[i]*v[i];
                        if(vel2>V*V)l=mid;
                        else r=mid-1;
                    }

                    ql=d[i],qr=l;
                }
            }else{
                int l=d[i],r=L;
                while(l<r){
                    int mid=(l+r)>>1;
                    int vel2=(mid-d[i])*2ll*a[i]+v[i]*v[i];
                    if(vel2>V*V)r=mid;
                    else l=mid+1;
                }
                ql=l,qr=L;
            }
            if(ql!=-1&&qr!=-1){
                int cc=cnt[qr]-cnt[ql-1];
                if(cc)++ans1,cl[++tot]=ql,cr[tot]=qr,sum[ql]++,sum[qr+1]--;
            }
        }
        for(int i=1;i<=L;i++)sum[i]+=sum[i-1];
        printf("%d ",ans1);
        if(BF){
            bool flg;
            for(int s=0;s<(1<<m)-1;s++){
                if(ans2<=s)continue;
                flg=0;
                for(int i=1;i<=L;i++)bf[i]=0;
                for(int i=1;i<=m;i++){
                    if(s&(1<<(i-1)))bf[p[i]]=1;
                }
                for(int i=1;i<=L;i++)bf[i]+=bf[i-1];
                for(int i=1;i<=tot;i++){
                    if(bf[cr[i]]-bf[cl[i]-1]>0)continue;
                    flg=1;break;
                }
                if(!flg)ans2=min(ans2,(int)__builtin_popcount(s));
            }
            printf("%d\n",m-ans2);
        }else if(AB){
            if(ans1)printf("%d\n",m-1);
            else printf("%d\n",m);
        }else{
            for(int i=1;i<=m;i++)ss[i]=sum[p[i]];
            sort(ss+1,ss+1+m);
            int aa=0;
            for(int i=1;i<=m;i++){
                if(ss[i]!=ss[i-1])++aa;
            }
            printf("%d\n",aa);
        }
    }
    return 0;
}
