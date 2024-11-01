#include<bits/stdc++.h>
using namespace std;
int t,n,ans,maxx;
int a[200005];
int b[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        maxx=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=(1<<n);i++){
            ans=0;
            for(int j=0,k=n;j<n,k>=1;j++,k--){
                b[k]=(i>>j)%2;
            }
            for(int j=1;j<=n;j++){
                int pd=0;
                for(int k=j-1;k>=1;k--){
                    if(a[j]==a[k]&&b[j]==b[k]&&pd==0){
                        ans+=a[j];
                        pd=1;
                    }else if(b[j]==b[k]&&a[j]!=a[k]){
                        ans+=0;
                        pd=1;
                    }
                }
            }
            maxx=max(maxx,ans);
        }
        cout<<maxx<<endl;
    }
    return 0;
}