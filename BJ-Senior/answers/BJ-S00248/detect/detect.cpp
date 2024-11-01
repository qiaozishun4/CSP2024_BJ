#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,V,d[100100],v[100100],a[100100],vd[100100],cnt;
struct le{
    int fir,la;
}car[100010];
bool f[100100],nd;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        memset(car,0,sizeof(car));
        memset(f,0,sizeof(f));
        cin>>n>>m>>V>>l;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)cin>>vd[i];
        sort(vd+1,vd+m+1);
        int cs=0;
        for(int i=1;i<=n;i++){
            double val=0,len;
            if(a[i]>0&&d[i]<=vd[m]){
                val=sqrt(v[i]*v[i]+2*a[i]*(vd[m]-d[i]));
                if(val-0.0001>l)cs++,f[m]=1;
            }else if(a[i]==0){
                if(v[i]>l&&d[i]<=vd[m])cs++,f[m]=1;
            }else{
                int les=lower_bound(vd+1,vd+m+1,d[i])-vd;
                val=sqrt(v[i]*v[i]+2*a[i]*(vd[les]-d[i]));
                if(val>l){
                    cs++;
                    car[++cnt].fir=les;
                    int ll=les,rr=m,mid;
                    while(ll<rr){
                        mid=(ll+rr)>>1;
                        int vvv=sqrt(v[i]*v[i]+2*a[i]*(vd[mid]-d[i]));
                        if(vvv>l)ll=mid+1;
                        else rr=mid-1;
                    }
                    car[cnt].la=l;
                }
            }
        }
//        cout<<cnt<<endl;
        cout<<cs<<" ";
        int ned=0,lll=0;
        for(int i=1;i<=cnt;i++){
            if(lll<car[i].fir){
                lll=car[i].la;
                f[lll]=1;
            }
        }
        for(int i=1;i<=m;i++)if(f[i])ned++;
        cout<<m-ned<<endl;
    }
    return 0;
}
