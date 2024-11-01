#include<bits/stdc++.h>
using namespace std;
int t
,n,a[200001],b[1000001];
int main(){
    freopen("color.in","r","stdin");
    freopen("color.out","w","stdout");
    cin>>t;
    while(t--){
            int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[a[i]]++;
            if(b[a[i]]==2){
                ans+=a[i];
                b[a[i]]=0;
            }
        }
    cout<<ans<<endl;
    }
    return 0;

}