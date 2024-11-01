#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200005];
long long num[1000005];
long long ans=0;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    memset(num,0,sizeof(num));
    cin>>t;
    while(t--){
        memset(num,0,sizeof(num));
        memset(a,0,sizeof(a));
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            num[a[i]]+=1;
        }
        for(int i=0;i<n;i++){
            if(num[a[i]]>1){
                ans+=a[i]*(num[a[i]]-1);
                num[a[i]]=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

