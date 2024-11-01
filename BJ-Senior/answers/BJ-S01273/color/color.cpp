#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,flag[1000005];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        for(int i=1;i<=1000000;i++){
            flag[i]=0;
        }
        cin>>n;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            flag[x]++;
        }
        int ans=0;
        for(int i=1;i<=1000000;i++){
            if(flag[i]!=0){
                ans=ans+i*(flag[i]-1);
            }
        }
        cout<<ans<<endl;
    }
}
