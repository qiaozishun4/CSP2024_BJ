#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
long long mn=LONG_LONG_MAX;
void dfs(int sx,long long number){
    if(sx==0){mn=min(number,mn);
    return;}
    if(sx<2)return;
    if(number!=0)dfs(sx-num[0],number*10+0);
    for(int i=1;i<=9;i++){
        if(sx>=num[i])dfs(sx-num[i],number*10+i);
    }
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int a;
    cin>>a;
    while(a--){
        int n;
        cin>>n;
        dfs(n,0);
        if(mn==LONG_LONG_MAX)cout<<-1<<endl;
        else
        cout<<mn<<endl;
        mn=LONG_LONG_MAX;
    }
    return 0;
}
