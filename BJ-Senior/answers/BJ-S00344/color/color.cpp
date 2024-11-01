#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n;
int a[N];
int f[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
   cin>>t;
   while(t--){
    cin>>n;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int t1=0;
        for(int j=i-1;j>=1;j--){
            if(a[j]==a[i]){
                t1=j;
                break;
            }
        }
        f[i]=f[i-1];
        if(t1==0) continue;
        f[i]=max(f[i-1]+a[i],f[i]);

    }
    cout<<f[n]<<'\n';
   }
   return 0;
}
