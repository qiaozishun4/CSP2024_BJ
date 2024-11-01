#include <bits/stdc++.h>
using namespace std;
struct node{
    long long d,v,a;
}a[100010];
long long p[100010];
void fre(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
}
int main(){
    fre();
    long long T;
    scanf("%lld",&T);
    while(T--){
        long long n,m,L,V,ans1=0;
        bool flag1=0,flag2=0;
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i].d,&a[i].v,&a[i].a);
            if(a[i].a!=0){
                flag1=1;
            }
            if(a[i].a<0){
                flag2=1;
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&p[i]);
        }
        sort(p+1,p+1+m);
        for(int i=1;i<=n;i++){
            if(a[i].a<0){
				if(a[i].d>p[m]){
					continue;
				}
                long double vshun=(p[lower_bound(p+1,p+1+m,a[i].d)-p]-a[i].d)*2.0*a[i].a+a[i].v*a[i].v;
//                cout<<(lower_bound(p+1,p+1+m,a[i].d)-p)<<i<<" "<<vshun<<endl;
                if(vshun>0){
                    vshun=sqrt(vshun);
                    if(vshun>V){
                        ans1++;
                    }
                }
                continue;
            }
            else if(a[i].a==0){
				if(a[i].d>p[m]){
					continue;
				}
                if(a[i].v>V){
                    ans1++;
                }
                continue;
            }
            else{
                if(a[i].d<=p[m]){
                    long double vshun=(p[m]-a[i].d)*2.0*(a[i].a)+a[i].v*(a[i].v);
                    if(vshun>0){
                        vshun=sqrt(vshun);
                        if(vshun>V){
                            ans1++;
                        }
                    }
                    continue;
                }
            }
        }
        if(!flag1||!flag2){
            printf("%lld %lld\n",ans1,m-1);
        }
        else
            printf("%lld %lld\n",ans1,m-2);
    }
    return 0;
}
