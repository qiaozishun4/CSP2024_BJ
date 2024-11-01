#include<bits/stdc++.h>
using namespace std;
int t,n,x,ans;
bool f[1000001];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>x;
            //cout<<x<<" "<<f[x]<<endl;
            if(f[x]==1)ans+=x;
            else f[x]=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
