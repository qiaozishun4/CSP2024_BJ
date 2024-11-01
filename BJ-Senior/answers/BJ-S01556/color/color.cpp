#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int a[N],b[N],c[N];

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=0;i<(1<<n);i++){
            int num=0;
            for(int j=0;j<n;j++){
                b[i]=(i>>j)&1;
            }
            for(int j=0;j<n;j++){
                for(int k=j-1;k>=0;k--){
                    if(b[k]==b[j]){
                        if(a[k]==a[j]) c[j]=a[j];
                        break;
                    }
                }
            }
            for(int j=0;j<n;j++){
                num+=c[j];
            }
            ans=max(ans,num);
        }
        cout<<ans<<endl;
    }
}
