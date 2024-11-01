#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int t,n,m,l,p[maxn];
double v0;
struct node{
    int d=0,fl=0,tst=0;
    double a=0,v=0.0;
}car[maxn];
bool cmp1(node x,node y) {
    if (x.d!=y.d) return x.d < y.d;
    if (x.a!=y.a) return x.a < y.a;
    return x.v < y.v;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v0;
        v0*=1.0;
        for(int i=0;i<maxn;i++)
            car[i].fl=car[i].tst=0;
        for (int i=1;i<=n;i++) {
            cin>>car[i].d>>car[i].v>>car[i].a;
            car[i].v*=1.0; car[i].a*=1.0;
        }
        for (int i=1;i<=m;i++) cin>>p[i];
        sort(car+1,car+n+1,cmp1);
        for (int i=1;i<=n;i++) {
            car[i].fl=car[i-1].fl;
            while(p[car[i].fl]<car[i].d) car[i].fl++;
        }
        int cnt=0;
        for (int i=1;i<=n;i++) {
            if(car[i].a>0) {
                int s=p[m]-car[i].d;
                double v1=sqrt(car[i].v*car[i].v+2.0*s*car[i].a);
                if (v1>=v0) {cnt++; car[i].tst=m;}
            }
            else if(car[i].a==0||car[i].v<v0)
                if (car[i].v>v0) cnt++;
        }
        cout<<cnt<<' '<< m-1<<endl;
    }
    return 0;
}