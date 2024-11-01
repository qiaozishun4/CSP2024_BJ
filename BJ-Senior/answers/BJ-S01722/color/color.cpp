#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=1;j<=i;j++){
                if(a[i]==a[j]&&a[i]!=-1&&a[j]!=-1){
                    ans+=a[i];
                    a[i]=a[j]=-1;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
