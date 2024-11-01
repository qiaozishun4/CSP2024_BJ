#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=10010;
const int M=10010;
const int K=10010;

int T,cnt[N][M],tot;
int n,m;
double L,V;
double d[N],v[N],a[N],p[M];

bool cmp1 (double x,double y) {
    return x<y;
}

struct node {
    double l,r;
}line[K];

bool ndcmp(node x,node y) {
    if (x.l==y.l) return x.r<=y.r;
    return x.l<=y.l;
}

int main () {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    //distance velocity acceleration
    cin>>T;
    while(T--) {
        tot=0;
        memset(d,0.0,sizeof(d));
        memset(v,0.0,sizeof(v));
        memset(a,0.0,sizeof(a));
        memset(p,0.0,sizeof(p));
        int ans=0;
        cin>>n>>m>>L>>V;
        for (int i=1;i<=n;i++) {
            cin>>d[i]>>v[i]>>a[i];
        }
        for (int j=1;j<=m;j++) {
            cin>>p[j];
        }
        sort(p+1,p+m+1,cmp1);
        double pp=p[m];
        for (int i=1;i<=n;i++) {
            bool flag=0;
            //始终不超速
            if (v[i]<=V&&a[i]<=0.0) {
                continue;
            }
            //加速过程中超速
            else if (v[i]<=V&&a[i]>0) {
                //超速位置
                double loc=((V*V-v[i]*v[i])/(2.0*a[i]))+d[i];
                if (loc>L) continue;
                for (int j=1;j<=m;j++) {
                    if (p[j]>loc) {
                        flag=1; line[++tot]={p[j],pp};
                        break;
                    }
                }
            }
            //始终超速
            else if (v[i]>V&&a[i]>=0) {
                double loc=d[i];
                for (int j=1;j<=m;j++) {
                    if (p[j]>=loc) {
                        flag=1; line[++tot]={p[j],pp};
                        break;
                    }
                }
            }
            //减速至不超速
            else if (v[i]>V&&a[i]<0) {
                //不超速位置
                double loc=d[i]+(v[i]*v[i]-V*V)/(2.0*abs(a[i]));
                bool flag1=0; double st=0.0,ed=0.0;
                for (int j=1;j<=m;j++) {
                    if (p[j]>=d[i]&&p[j]<loc&&flag==0) {
                        flag=1; flag1=1; st=p[j];
                    }
                    if (p[j]>=loc&&flag) {
                        ed=p[j-1];
                        line[++tot]={st,ed};
                        break;
                    }
                }
            }
            if (flag) {
                ans++;
            }
        }
        //关闭探测器
        sort(line+1,line+tot+1,ndcmp);
        int res=1;
        double rar=line[1].r;
        for (int i=2;i<=tot;i++) {
            if (line[i].r>rar) {
                res++; rar=line[i].r;
            }
        }
        cout<<ans<<' '<<res+1;
    }
    return 0;
}
