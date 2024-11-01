#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e5+10;
int T,t,n,m,V,d[N],v[N],a[N],p[N];
bool f[N];//每辆车有没有超速
struct X{
    int l,r;
}car[N];
bool cmp(X a,X b){
    return a.l==b.l?a.r>b.r:a.l<b.l;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        memset(f,0,sizeof(f));
        t=0;
        cin>>n>>m>>V>>V;
        bool f1=1,f2=1,f3=1;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0)f1=0;
            if(a[i]>0)f3=0;
            if(a[i]<0)f2=0;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(d[i]>p[m])continue;
            if(a[i]>0){
                int speed=a[i]*(p[m]-d[i])*2+v[i]*v[i];
                if(speed>1ll*V*V){
                    cnt++;
                    f[i]=1;
                }
            }
            if(a[i]<0){
                int x=lower_bound(p+1,p+m+1,d[i])-p;
                int need=v[i]*v[i]/(-2*a[i])+bool(v[i]*v[i]%(-2*a[i]));
                if(d[i]+need<=p[x])continue;
                int speed=2*a[i]*(p[x]-d[i])+v[i]*v[i];
                if(speed>1ll*V*V){
                    cnt++;
                    f[i]=1;
                }
            }
            if(a[i]==0&&v[i]>V){
                cnt++;
                f[i]=1;
            }
        }
        cout<<cnt<<' ';
        if(cnt==0){
            cout<<m<<'\n';
            continue;
        }
        if(f2||f1){
            cout<<m-1<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++){
            if(f[i]){
                if(a[i]==0||a[i]>0&&v[i]>V){
                    int x=lower_bound(p+1,p+m+1,d[i])-p;
                    car[++t]={x,m};
                    continue;
                }
                int x=V*V-v[i]*v[i];
                if(a[i]>0){
                    int dis=x/(2*a[i])+bool(x%(2*a[i]));
                    int y=lower_bound(p+1,p+m+1,d[i]+dis)-p;
                    car[++t]={y,m};
                }
                else {
                    int dis=x/(2*a[i]);
                    int y=upper_bound(p+1,p+m+1,d[i]+dis)-p-1;
                    int o=lower_bound(p+1,p+m+1,d[i])-p;
                    car[++t]={o,y};
                }
            }
        }
        sort(car+1,car+t+1,cmp);
        while(1){
            bool fl=0;
            for(int i=1;i<t;i++){
                if(car[i].r>=car[i+1].r){
                    car[i].l=m+1;
                    cnt--;
                    fl=1;
                }
            }
            if(!fl)break;
            sort(car+1,car+t+1,cmp);
            t=cnt;
        }
        int sum=1,last=car[1].r;
        for(int i=2;i<=t;i++){
            while(i<=t&&last>=car[i].l)i++;
            if(i>t)break;
            sum++;
            last=car[i].r;
        }
        cout<<m-sum<<'\n';
    }
    return 0;
}
/*
1
9 10 62098 741
1143 996 -3
1514 952 -8
280 883 -5
44155 834 -216
1813 879 -5
1100 882 -69
4216 909 -3
11307 810 -2
2306 873 -18
1062 1304 1722 2663 5502 12378 16995 22981 27236 44366
*/
