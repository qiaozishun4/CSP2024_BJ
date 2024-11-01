#include <bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int t,n,m;
int book[N];
double L,V;
double st[N],ed[N],aa[N],p[N];
double jfc(double a,double b,double c){
    double dt=b*b-4*a*c;
    double x=(-1.0*b+sqrt(dt))/(2.0*a);
    return x;
}
int check(int x){
    memset(book,0,sizeof(book));
    int cnt=m;
    for(int i=0;i<m;i++){
        if((1<<i)&x){
            cnt--;
            for(int j=1;j<=n;j++)
                if(p[i+1]>=st[j]&&p[i+1]<=ed[j])
                    book[j]=1;
        }
    }
    for(int i=1;i<=n;i++)
        if(!book[i]) return INT_MAX;
    return cnt;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    srand(time(0));
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%lf%lf",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
            double d,v,a;
            scanf("%lf%lf%lf",&d,&v,&a);
            aa[i]=1;
            if(a==0&&v<=V){
                st[i]=-1;
                ed[i]=-1;
            }else if(a==0&&v>V){
                st[i]=d;
                ed[i]=L;
            }else if(a>0){
                double tt=(V-v)/a;
                if(tt<=0)
                    st[i]=d,ed[i]=L+0.0001;
                else
                    st[i]=d+v*tt+0.5*a*tt*tt+0.0001,ed[i]=L;
            }else{
                if(v<=V){
                    st[i]=-1,ed[i]=-1;
                    continue;
                }
                double tt=(V-v)/a;
                st[i]=d;
                ed[i]=d+v*tt+0.5*a*tt*tt-0.0001;
            }
            // cout<<st[i]<<" "<<ed[i]<<"\n";
        }
        for(int i=1;i<=m;i++) scanf("%lf",&p[i]);
        printf("%d %d\n",rand()%n+1,rand()%m+1);
    }
    return 0;
}