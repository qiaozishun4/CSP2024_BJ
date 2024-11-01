#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    int t,n,ans=0;
    long long a[100010];
    cin>>t;
    for(int i=0; i<t; i++){
        ans=0;
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>a[j];
        }
        for(int j=n-1; j>=0; j--){
            for(int k=j-1; k>=0; k--){
                if(a[j]==a[k]&&j-k!=1){
                    ans+=a[k];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
