#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],b[i]=0;
        b[1]=1;
        for(int i=2;i<=n;i++){
            if(b[i]>0){
                for(int j=i;j<=n;j++){
                    if(a[j]==a[i])b[j]=b[i],ans+=a[i];
                }
            }else{
                for(int j=i;j<=n;j++){
                    if(a[j]==a[i])b[j]=b[i]=b[i-1],ans+=b[i];
                    else b[j]=2;
                }
            }
        }cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
