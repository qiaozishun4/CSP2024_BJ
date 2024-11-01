#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[100005],b[100005],t,ans,c[100005];
int main(){
   freopen("duel.in","r",stdin);
   freopen("duel.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
	   if(b[a[i]]==0) c[++t]=a[i];
	   b[a[i]]++;
   }
   for(int i=1;i<=t;i++){
       ans=max(ans,b[c[i]]);
   }
   cout<<ans;
   return 0;
}
