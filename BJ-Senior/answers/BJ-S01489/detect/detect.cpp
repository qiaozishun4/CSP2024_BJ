#include <bits/stdc++.h>
using namespace std;
const int N=1e5+105;
struct qj{
    int s,e;
};
int T;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,l,V,cnt=0;
        scanf("%d%d%d%d",&n,&m,&l,&V);
        int d[N],v[N],a[N],p[N];
        qj f[N];
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",d+i,v+i,a+i);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",p+i);
        }
        sort(p+1,p+1+m);
        for(int i=1;i<=n;i++){
            bool flag=0;
            int post=1;
            for(int j=1;j<=m;j++){
                if(p[j]<d[i]){
                    post=j;
                    continue;
                }
                int speed=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
                if(speed==0) continue;
                if(speed>V){
                    if(flag==0){
                        cnt++;
                        flag=1;
                    }
                    if(a[i]>0){
                        f[i].s=j;
                        f[i].e=m;
                        break;
                    }else if(a[i]<0){
                        f[i].s=post;
                        f[i].e=j;
                    }else{
                        f[i].s=post;
                        f[i].e=m;
                        break;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(f[j].e==0) continue;
            qj p=f[j];
            for(int i=1;i<=j;i++){
                if(f[i].e<=0||i==j) continue;
                if(p.s<f[i].e&&p.e>f[i].e){
                   p.e=f[i].e;
                   f[i].e=-1;
                }
                if(p.e>=f[i].s&&p.s<f[i].s){
                    p.s=f[i].s;
                    f[i].e=-1;
                }
                if(p.e<=f[i].e&&p.s>=f[i].s){
                    p.e=f[i].e;
                    f[i].e=-1;
                }
                if(p.s<=f[i].s&&p.e>=f[i].e){
                    p.s=f[i].s;
                    f[i].e=-1;
                }
            }
            f[j]=p;
        }
        int cnt2=0;
        for(int i=1;i<=n;i++){
            if(f[i].e<=0) continue;
            cnt2++;
        }
        cout<<cnt<<" "<<m-cnt2<<endl;
    }
    return 0;
}