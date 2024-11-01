#include<bits/stdc++.h>
using namespace std;
int t,n,a[1005],c[1005],hl[1005],dp[1005][1005],hh=0;
int main(){
    freopen("detect.in","r","stdin");
    freopen("detect.out","w","stdout");
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[i];
            hh=a[j];
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]>a[i]&&v[j]==1&&a[j]!=-1&&a[i]!=-1){
                ans--;
                a[i]=-1;
                v[j]=0;
            }
        }
    }
        cout<<dp[n][hh];
    }
    return 0;
}
