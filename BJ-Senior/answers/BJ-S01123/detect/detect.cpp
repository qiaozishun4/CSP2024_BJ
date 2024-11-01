#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int t,n,m,ll,d[maxn],v[maxn],a[maxn],p[maxn],ans1,ans2,cnt;
double vv;
pair<int,int> e[maxn];
int pos(double _d,double _v,double _a,bool op){
    return op?floor((vv*vv-_v*_v)/(_a*2.0)+_d)+1.0:ceil((vv*vv-_v*_v)/(_a*2.0)+_d)-1.0;
}
int read(void){
    int x=0,op=1;
    char ch=getchar();
    if(ch=='-'){
        op=-1;
    }
    while(ch<'0'||ch>'9'){
        ch=getchar();
        if(ch=='-'){
            op=-1;
        }
    }
    while(ch>='0'&&ch<='9'){
        x*=10;
        x+=ch-'0';
        ch=getchar();
    }
    return x*op;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    t=read();
    while(t--){
        ans1=0;
        ans2=0;
        cnt=0x3f3f3f3f;
        n=read();
        m=read();
        ll=read();
        vv=read();
        for(int i=1;i<=n;i++){
            d[i]=read();
            v[i]=read();
            a[i]=read();
        }
        for(int i=1;i<=m;i++){
            p[i]=read();
        }
        for(int i=1;i<=n;i++){
            if(a[i]<=0&&v[i]<=vv){
                continue;
            }
            if(a[i]>0){
                int tmp=max(lower_bound(p+1,p+m+1,pos(d[i],v[i],a[i],true))-p,lower_bound(p+1,p+m+1,d[i])-p);
                if(tmp!=m+1){
                    e[++ans1]=make_pair(tmp,m);
                }
            }
            if(a[i]==0){
                int tmp=lower_bound(p+1,p+m+1,d[i])-p;
                if(tmp!=m+1){
                    e[++ans1]=make_pair(tmp,m);
                }
            }
            if(a[i]<0){
                int tmp1=lower_bound(p+1,p+m+1,d[i])-p,tmp2=upper_bound(p+1,p+m+1,pos(d[i],v[i],a[i],false))-p-1;
                if(tmp1<=tmp2&&tmp2<m+1&&tmp1>0){
                    e[++ans1]=make_pair(tmp1,tmp2);
                }
            }
        }
        cout<<ans1<<' ';
        sort(e+1,e+ans1+1);
        for(int i=ans1;i>0;i--){
            if(cnt>e[i].second){
                cnt=e[i].first;
                ans2++;
            }
        }
        cout<<m-ans2<<'\n';
    }
    return 0;
}
