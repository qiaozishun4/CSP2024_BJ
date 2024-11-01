#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int a[2000005]={0};
        long long num=0,t,n,maxt=-1;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%lld",&t);
            a[t]++;
            if(t>maxt)maxt=t;
        }
        for(int i=1;i<=maxt;i++){
            if(a[i]>1){
                for(int j=1;j<=a[i]-1;j++){
                    ans+=i;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}