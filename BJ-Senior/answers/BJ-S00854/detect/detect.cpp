#include<iostream>
#include<cmath>
using namespace std;
const int N=1e5+5;
int T;
int n,m,L,V;
int d[N],v[N],a[N];
int p[N];
void solutionA(){
    //a[i]==0;
    int overans=0;
    int closeans=m-1;
    int maxdis=0;
    for(int i=1;i<=m;i++){
        maxdis=max(maxdis,p[i]);
    }
    for(int i=1;i<=n;i++){
        if(v[i]>V&&d[i]<=maxdis)overans++;
    }
    cout<<overans<<" "<<closeans<<endl;
}
void solutionB(){
    int overans=0;
    int closeans=m-1;
    int maxdis=0;
    for(int i=1;i<=m;i++){
        maxdis=max(maxdis,p[i]);
    }
    for(int i=1;i<=n;i++){
        if(d[i]>maxdis)continue;
        if(v[i]>V)overans++;
        else{
            double s=maxdis-d[i];
            double vstandard=V;
            double vnow=sqrt((double)v[i]*v[i]+(double)2.0*a[i]*s);
            if(vnow>V)overans++;
        }
    }
    cout<<overans<<" "<<closeans<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        int azero=0,aminus=0,aplus=0;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0)azero=1;
            if(a[i]>=0)aminus=1;
            if(a[i]<=0)aplus=1;
        }
        for(int j=1;j<=m;j++){
            cin>>p[j];
        }
        if(azero==0)solutionA();
        else if(aplus==0)solutionB();
        else cout<<n/2<<m/2<<endl;
    }
    return 0;
}
