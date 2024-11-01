#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[200005],b[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int i=1;i<=200005;i++){
            b[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            while(b[a[i]]>1){
                ans+=a[i];
                b[a[i]]--;
            }
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}
