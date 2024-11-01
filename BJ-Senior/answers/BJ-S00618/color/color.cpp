#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[114514],b[114514];
int main(){
    int t;
    freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    cin>>t;
    for(;t>0;t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        int tp=n;
        while(tp>=0){
            if(b[tp]==b[tp-1]){
                tp--;
                ans+=b[tp];
            }
            tp--;
        }
       cout<<ans<<endl;
       for(int i=1;i<=n;i++){
            a[i]=0;
            b[i]=0;
       }
    }
    return 0;
}
