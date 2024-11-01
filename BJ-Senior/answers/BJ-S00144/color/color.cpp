#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],ans;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1]) ans+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
