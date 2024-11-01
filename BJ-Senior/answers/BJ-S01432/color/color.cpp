#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,n,a[N],b[N],c[N];
bool vis[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        int sum=0;
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(b[i]==a[j]) c[i]=j;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=c[i];j>=1;j--){
                if(b[i]==a[j]){
                    bool v=!a[j];
                    for(int k=a[j];k<=b[i];k++) vis[j]=t;
                }
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(vis[i]==vis[j]&&a[i]==a[j]){
                    sum+=a[j];
                    break;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
