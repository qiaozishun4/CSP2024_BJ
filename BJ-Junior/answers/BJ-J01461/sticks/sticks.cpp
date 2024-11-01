#include<bits/stdc++.h>
using namespace std;
int T,n,sz[10]={6,2,5,5,4,5,6,3,7,6},z=0,minn=2e31-1;
void dfs(int x,int o){
    if(x==0){
        minn=min(z,minn);
        return ;
    }
    else{
        if(x==1)return ;
        for(int i=0;i<=9;i++){
            if(i==0&&o==1)continue;
            else if(x>=sz[i]){
                z=z*10+i;
                dfs(x-sz[i],o+1);
                z=(z-i)/10;
            }
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        minn=2e31-1;
        z=0;
        cin>>n;
        if(n<2)cout<<-1<<endl;
        else{
             dfs(n,1);
             cout<<minn<<endl;
        }
     }
     return 0;
}
