#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n,m,u,v,dc[100005],vc[100005],ac[100005],p[100005],cs[1000005],num1,num2;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        num1=0;
        num2=0;
        memset(cs,0,sizeof(cs));
        cin>>n>>m>>u>>v;
        for(int i=1;i<=n;i++) cin>>dc[i]>>vc[i]>>ac[i];
        for(int i=1;i<=m;i++) cin>>p[i];
        for(int i=1;i<=n;i++){
            if(ac[i]==0&&vc[i]>v){
                int l=1,r=m;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(dc[i]>=p[mid]){
                        l=mid+1;
                        if(dc[i]<=p[l]) break;
                    }
                    else r=mid-1;
                }
                if(dc[i]<=p[m]){
                    for(int j=l;j<=m;j++){
                        cs[p[j]]++;
                    }
                    num1++;
                }
            }
            else if(ac[i]>0){
                int x=(v*v-vc[i]*vc[i])/(2*ac[i])+vc[i];
                int l=1,r=m;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(x>=p[mid]){
                        l=mid+1;
                        if(x<=p[l]) break;
                    }
                    else r=mid-1;
                }
                if(x<=p[m]){
                    for(int j=l;j<=m;j++){
                        cs[p[j]]++;
                    }
                    num1++;
                }
            }
            else if(ac[i]<0){
                int x=(v*v-vc[i]*vc[i])/(2*ac[i])+dc[i];
                int l=1,r=m;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(dc[i]>=p[mid]){
                        l=mid+1;
                        if(dc[i]<=p[l]) break;
                    }
                    else r=mid-1;
                }
                if(p[l]<=x){
                    for(int j=l;j<=m;j++){
                        cs[p[j]]++;
                    }
                    num1++;
                }
            }
        }
        for(int i=1;i<=u;i++){
            if(cs[i]==num1){
                num2++;
            }
        }
        cout<<num1<<" "<<m-num2<<endl;
    }
    return 0;
}
