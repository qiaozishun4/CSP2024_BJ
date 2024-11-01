#include <iostream>
using namespace std;
int n,table[10]={6,2,5,5,4,5,6,3,7,6},ans;
void dfs(int num,int s,int tot){
    if(tot==n){
        ans=min(ans,num);
        return;
    }
    for(int i=s;i<=9;i++){
        if(tot+table[i]<=n){
            dfs(num*10+i,0,tot+table[i]);
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
      cin>>n;
      ans=2147483640;
      dfs(0,1,0);
      if(ans==2147483640) cout<<-1<<endl;
      else cout<<ans<<endl;
    }
    return 0;
}
