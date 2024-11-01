#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[200005];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int sum=0;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(a[i]==a[j]){
                    sum+=a[j];
                    break;
                }
            }
        }
        cout<<sum<<endl;
    }
}
