#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long t,n,m,l,lim,p[maxn],d[maxn],v[maxn],a[maxn],sp[maxn],x[maxn],op[maxn];
long long  ansv,ansd;
long long max1=-100,max2=-100;
bool vis[maxn],flag=1;
bool pd(double vx,double ax,double dx,int id){
    double t=(lim-vx)/ax;
    double s=vx*t+0.5*ax*t*t;
    x[id]=ceil(s);
    if(s>l-dx)  return false;
    else return true;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>lim;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]<0)  flag=0;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            sp[p[i]]++;
        }
        sort(p+1,p+1+m);
        for(int i=1;i<=l;i++){
            sp[i]+=sp[i-1];
        }
        for(int i=1;i<=n;i++){
            if(v[i]>lim&&a[i]==0){
                x[i]=d[i];
                if(d[i]<=p[m]) {
                    ansv++;
                    vis[i]=1;
                }
            }
            if(v[i]<lim&&a[i]>0){
                if(pd(v[i],a[i],d[i],i)){
                    if(m-sp[x[i]+d[i]]>0) {
                        ansv++;
                        vis[i]=1;
                        x[i]+=d[i];
                    }
                }
            }
            if(v[i]>lim&&a[i]<0){
                if(pd(v[i],a[i],d[i],i)){
                     if(sp[x[i]+d[i]-1]-sp[d[i]-1]>0) {
                            vis[i]=1;
                            ansv++;
                            for(long long j=d[i];j<x[i]+d[i];j++){
                                if(op[j]!=0)    break;
                                if(sp[j]-sp[j-1]==1&&op[j]==0){
                                        op[j]++;
                                        ansd++;
                                        max2=max(max2,j);
                                        break;
                                }
                            }
                     }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0)   continue;
            if(a[i]>=0)  max1=max(max1,x[i]);
        }
        if(max2<max1)   ansd++;
       // cout<<max2<<' '<<max1<<endl;
    }
    if(flag==1) cout<<ansv<<' '<<1<<endl;
    else cout<<ansv<<' '<<m-ansd;
return 0;
}
