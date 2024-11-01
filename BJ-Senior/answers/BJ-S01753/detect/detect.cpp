
//a>=0时
#include<bits/stdc++.h>
using namespace std;
double T,sum,ans,d[100005],v[100005],a[100005],p[100005],n,m,l,vv,maxx;
int main(){
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);
cin>>T;
while(T--){
    sum=0,ans=0,maxx=0;
    cin>>n>>m>>l>>vv;
    for(int i=1;i<=n;i++){
        cin>>d[i]>>v[i]>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>p[i];
        maxx=max(maxx,p[i]);
    }
    for(int i=1;i<=n;i++){
        if(d[i]<=maxx){
            if(sqrt((v[i]*v[i])+(2*a[i]*(maxx-d[i])))>vv){
                sum++;
            }
        }
    }
    cout<<sum<<" ";
    if(sum==0){
        cout<<m<<endl;
    }else{
        cout<<(m-1)<<endl;
    }

}
return 0;
}