#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    int x,y;
    while(T--){
        int ans=0,maxn=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=0;i<(1<<n);i++){
            y=0,x=0,ans=0;
            for(int j=n-1;j>=0;j--){
                if(i&(1<<j)){
                    if(x==0){
                        x=a[n-j];
                        continue;
                    }
                    if(x==a[n-j]){
                        ans+=x;
                        x=a[n-j];
                    }
                    if(x!=a[n-j]) x=a[n-j];
                }else{
                    if(y==0){
                        y=a[n-j];
                        continue;
                    }
                    if(y==a[n-j]){
                        ans+=a[n-j];
                        y=a[n-j];
                    }
                    if(y!=a[n-j]){
                        y=a[n-j];
                    }
                }
            }
            maxn=max(maxn,ans);
        }
        cout<<maxn<<endl;
    }
    return 0;
}
