#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int s[10]={6,2,5,5,4,5,6,3,7,6};
int Min=1e9+5;
int dfs(int x,int nm){
    if(x==1)return 1e9;
    if(x==0){
        return nm;
    }
    int Min=1e9;
    for(int i=0;i<9;i++){
        if(x>=s[i]){
            if(i==0&&nm==0)continue;
            int z=nm*10+i;
            Min=min(Min,dfs(x-s[i],z));
        }
    }
    return Min;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int f;
        cin>>f;
        int p=dfs(f,0);
        if(p==1e9)cout<<-1<<endl;
        else cout<<p<<endl;
    }
}
