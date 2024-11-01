#include<iostream>
using namespace std;
long long n,a[200005],k[200005],t,ans,T;
void dfs(long long o){
    if(o==0){
       for(int i=1;i<=n;i++){
           for(int j=i-1;j>=1;j--){
               if(a[j]==a[i]&&k[j]==k[i]){
                  t+=k[i];
               }
           }
       }
       ans=max(t,ans);
       o+=1;
       return;
    }
    for(int i=1;i<=2;i++){
        a[o]=i;
        dfs(o-1);
        o+=1;
        return;
    }
}
int main(){
   freopen("color.in","r",stdin);
   freopen("color.out","w",stdout);
   cin>>T;
   while(T--){
      cin>>n;
      for(int i=1;i<=n;i++) cin>>k[i];
      ans=0;
      dfs(n);
      cout<<ans<<endl;
   }
   return 0;
}
