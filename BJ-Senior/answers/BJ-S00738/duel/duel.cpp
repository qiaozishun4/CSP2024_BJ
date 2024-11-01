#include <bits/stdc++.h>
using namespace std;
long long a[10005],n,ans;
int main(){
    freopen("duel.cpp.in","r",stdin);
    freopen("duel.cpp.out","r",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
     }
     ans=n;
     for(int j=0;j<n;j++){
      if(a[j]<a[j+1]) ans--;
     }
    cout<<ans;
    return 0;
}