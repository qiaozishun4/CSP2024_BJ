#include<bits/stdc++.h>
using namespace std;
int a[100005],b[1000005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","r",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int now=0;
        for(int i=1;i<=n;i++){
                cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            b[a[i]]++;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]==a[j]){
                    ans+=a[j];
                }else if(b[a[j]]==1){
                    break;
                }

            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
