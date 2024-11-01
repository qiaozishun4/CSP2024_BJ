#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,L,V,cnt1,cnt2,minn;
int d[1000005];
int v[1000005];
int a[1000005];
int p[1000005];
int pp[1000005];
int pd1=0,pd2=0,pd3=0;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        pd1=0,pd2=0,pd3=0;
        cnt1=cnt2=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]>0) pd1=1;
            else if(a[i]==0) pd2=1;
            else if(a[i]<0) pd3=1;
        }
        for(int i=1;i<=m;i++) cin>>p[i];
        if(pd2==1&&pd1==0&&pd3==0){
            for(int i=1;i<=n;i++){
                if(v[i]>V&&v[i]!=0&&d[i]<=p[m]){
                    cnt1++;
                }
            }
            cout<<cnt1<<" ";
            if(cnt1==0) cnt2=m;
            else cnt2=m-1;
            cout<<cnt2<<endl;
        }else {
            minn=10000000;
            for(int i=1;i<=n;i++){
                int pd=0;
                for(int j=1;j<=n;j++){
                    if(d[i]<=p[j]&&v[i]*v[i]+2*a[i]*(p[j]-d[i])>V*V){
                        if(pd==0){
                           cnt1++;
                           pd=1;
                        }
                        pp[i]=1;
                    }
                }
            }
            cout<<cnt1<<" ";
            if(cnt1==0) cnt2=m;
            else{
                for(int i=1;i<=m;i++){
                    if(pp[i]==1) cnt2++;
                }
            }
            cout<<cnt2<<endl;
            for(int i=1;i<=m;i++){
                pp[i]=0;
            }
        }
    }
    return 0;
}