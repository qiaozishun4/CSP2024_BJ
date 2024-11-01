#include<iostream>
#include<math.h>
using namespace std;
long long t,n,a[200086],cnt,ans;
void dfs(long long x1,long long x2,long long y){
    if(y>n){
        ans=max(cnt,ans);
        //cout<<cnt<<endl;
        return;
    }
    //1lan
    if(a[y]==x1){
        cnt+=a[y];
        dfs(x1,x2,y+1);
        cnt-=a[y];
    }
    else{
        dfs(a[y],x2,y+1);
    }
    //2hon
    if(a[y]==x2){
        cnt+=a[y];
        dfs(x1,x2,y+1);
        cnt-=a[y];
    }
    else{
        dfs(x1,a[y],y+1);
    }
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++){//gui0
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(0,0,1);
        cout<<ans<<endl;
    }
    return 0;
}
