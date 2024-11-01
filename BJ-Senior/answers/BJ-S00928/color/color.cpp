#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n,a[200055];
int b[200005];
long long cnt=0;
void dp(int i){
    if(i>n){
        long long ans=0;
        int nr=0,nb=0;
        for(int j=1;j<=n;j++){
            if(b[j]==0){
                if(a[j]==a[nr]){
                    ans+=a[j];
                }
                nr=j;
            }else if(b[j]==1){
                if(a[j]==a[nb]){
                    ans+=a[j];
                }
                nb=j;
            }
        }
        cnt=max(cnt,ans);
        return;
    }
    for(b[i]=0;b[i]<=1;b[i]++){//0-red
        dp(i+1);
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int ca[1000005]={};
    int T;
    long long ans=0;
    cin>>T;
    while(T>0){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ca[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(ca[a[i]]>=2){
                ans+=a[i]*ca[a[i]];
            }
        }
        //dp(1);
        cout<<ans<<endl;
        T--;
    }
    return 0;
}
