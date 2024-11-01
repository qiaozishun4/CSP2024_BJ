#include<bits/stdc++.h>
using namespace std;
int T;
int n;
const int N=5e6;
int sticks[10]={6,2,5,5,4,5,6,3,7,6};
int ans[N],ans2[N];
int a=1e7;
bool check(int a[],int b[],int c){
    for(int i=c;i>0;i--){
        if(a[i]<b[i])return 0;
    }
    return 1;

}
void dfs(int x,int xb){
    if(x<0)return;
    if(x==0){
       if(xb<a){
        for(int i=xb;i>0;i--){
            ans[i]=ans2[i];
        }
        a=xb;
       }
       else if(check(ans,ans2,xb)){
        for(int i=xb;i>0;i--){
            ans[i]=ans2[i];
        }
        a=xb;
       }
     return;
    }
    for(int i=0;i<10;i++){
        if(xb==1&&i==0)
        continue;
        else
        ans2[xb]=i;
        dfs(x-sticks[i],xb+1);
    }
}
int main(){
freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin>>T;
    while(T--){
        a=1e7;
        cin>>n;
        dfs(n,1);
        if(a!=1e7)
        for(int i=1;i<a;i++){
            cout<<ans[i];
        ans[i]=0;
        }
        else cout<<-1;
        cout<<endl;
    }


fclose(stdin);
    fclose(stdout);
}
