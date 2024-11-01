//16:51 second
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
inline int read(){
    int x=0,w=1;
    char ch=getchar();
    for(;ch<'0'||'9'<ch;ch=getchar())if(ch=='-')w=-1;
    for(;'0'<=ch&&ch<='9';ch=getchar())x=10*x+ch-'0';
    return x*w;
}
struct seg{int l,r;}b[N];
int ans,num,tot,n,m,L,V,d[N],v[N],a[N],p[N];
long long vm;
bool cmp(seg a,seg b){return a.r==b.r?a.l<b.l:a.r<b.r;}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T=read();
    while(T--){
        tot=ans=num=0,n=read(),m=read(),L=read(),V=read();
        for(int i=1;i<=n;++i)d[i]=read(),v[i]=read(),a[i]=read();
        for(int i=1;i<=m;++i)p[i]=read();
        for(int i=1;i<=n;++i){
            if(a[i]==0){
                if(v[i]>V&&d[i]<=p[m]){
                    ++ans;
                    int x=lower_bound(p+1,p+m+1,d[i])-p;
                    b[++tot].l=x,b[tot].r=m;
                }
            }else if(a[i]>0){
                if(p[m]<d[i])continue;
                vm=v[i]*v[i]+2ll*a[i]*(p[m]-d[i]);
                if(vm>V*V){
                    ++ans;
                    double pos=max(0.0,0.5*(V*V-v[i]*v[i])/a[i])+d[i];
                    int x=upper_bound(p+1,p+m+1,pos)-p;
                    if(v[i]>V)x=lower_bound(p+1,p+m+1,d[i])-p;
                    b[++tot].l=x,b[tot].r=m;
                }
            }else{
                int x=lower_bound(p+1,p+m+1,d[i])-p;
                vm=v[i]*v[i]+2ll*a[i]*(p[x]-d[i]);
                if(vm>V*V){
                    ++ans;
                    double pos=0.5*(V*V-v[i]*v[i])/a[i]+d[i];//printf("b%lf\n",pos);
                    int y=lower_bound(p+1,p+m+1,pos)-p-1;
                    b[++tot].l=x,b[tot].r=y;
                }
            }
        }//printf("%d\n",tot);
        sort(b+1,b+tot+1,cmp);
        //for(int i=1;i<=tot;++i)printf("%d %d\n",b[i].l,b[i].r);
        for(int i=1,j=1;i<=tot;){
                //printf("%d\n",j);
            ++num;
            while(i<=tot&&b[i].l<=b[j].r)++i;
            j=i;
        }//printf("a%d\n",num);
        printf("%d %d\n",ans,m-num);
    }return 0;
}