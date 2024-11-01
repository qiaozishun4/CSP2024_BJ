#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
using namespace std;
long d[100002];int v[100002];int a[100002];long p[100002];
//struct node{
//    int c;
//    int f;
//}pv[100002];
long gv(int v,int a,long s){
    long vn= ceil(sqrt((double)pow(v,2)+(double)(2*a*s)));
    return vn;
}
int main(){
    int i,j,k=1;
    int n,m,L,V,t;
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){

    int ans=0;
    cin>>n>>m>>L>>V;
    int A=1,B=1;
    for(i=1;i<=n;i++){
        cin>>d[i]>>v[i]>>a[i];
        if(a[i]!=0){
            A=0;
        }
        if(a[i]<0){
            B=0;
        }

    }
    for(i=1;i<=m;i++){
        cin>>p[i];
    }
    sort(p+1,p+1+m);
    for(i=1;i<=n;i++){
        if(a[i]==0&&v[i]>V&&d[i]<=p[m]){
            ans++;
        }
        //cout<<p[m]<<" "<<d[i]<<" "<<p[m]-d[i]<<endl;
        if(a[i]>0&&(p[m]-d[i])>0){
            long pv=gv(v[i],a[i],(p[m]-d[i]));
            //if(t==20){
            //cout<<pv<<" "<<V<<endl;//}
            if(pv>V){
                //if(t==20)
                    //cout<<t<<" "<<ans<<endl;
                ans++;
            }
        }

    }
    if(ans==0){
        cout<<0<<" "<<m<<endl;
        continue;
    }
    else if(A==1){

        cout<<ans<<" "<<m-1<<endl;
        continue;
    }
    else if(B==1){
        cout<<ans<<" "<<m-1<<endl;
        continue;
    }
    }
    return 0;
}
