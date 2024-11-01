#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans=0,maxx=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        ans+=a[i];
        if(maxx<a[i]){
            maxx=a[i];
        }
    }
    cout<<ans-maxx;
    return 0;
}
