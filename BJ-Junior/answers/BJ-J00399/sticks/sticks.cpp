#include<iostream>
using namespace std;

int h[10]={6,2,5,5,4,5,6,3,7,6};

int dfs(int n,int ans,int j){
    int minn=0xfffffff;
    if(n==0) return ans;
    if(n==1) return -1;
    for(int i=0;i<=9;i++){
        if(n<h[i]) continue;
        if((n==6||n==7)&&i==0) continue;
        ans+=j*i;
        int t=dfs(n-h[i],ans,j*10);
        if(t!=-1) minn=min(minn,t);
        ans-=j*i;
    }
    if(minn==0x3fffffff) return -1;
    return minn;
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,j=1,m=0,ans=0,l=0;
        cin>>n;
        cout<<dfs(n,0,1)<<"\n";
    }
    return 0;
}
