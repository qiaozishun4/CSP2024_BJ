#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=100000+5;
ll t,n,m,L,V,b[N],c[N],ans1,ans2;
db d[N],v[N],a[N],p[N],s,sv;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        memset(b,0,N);
        memset(c,0,N);
        ans1=0;
        ans2=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++){
            cin>>p[i];
            for(int j=1;j<=n;j++){
                if(p[i]>=d[j]){
                    s=p[i]-d[j];
                    sv=sqrt(v[j]*v[j]+2*a[j]*s);
                    if(sv>db(V)){
                        if(c[j]==1&&b[i]==0){
                            b[i]=1;
                            ans2++;
                        }
                        if(c[j]==0){
                            c[j]=1;
                            b[i]=1;
                            ans1++;
                        }
                    }
                }
            }
        }
        cout<<ans1<<' '<<ans2<<endl;
    }

    return 0;
}

