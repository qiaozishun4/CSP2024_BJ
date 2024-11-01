#include<bits/stdc++.h>
using namespace std;
int T;
int a[200020];
int tot[1000010];
int ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        memset(tot,0,1000010);
        int n;
        cin>>n;
        ans=0;

        for(int i=1;i<=n;i++){
            cin>>a[i];
            tot[a[i]]++;
        }

        for(int i=1;i<=100000;i++){
            ans+=(tot[i]/2)*i;

        }
        cout<<ans<<endl;
    }
    return 0;

}
