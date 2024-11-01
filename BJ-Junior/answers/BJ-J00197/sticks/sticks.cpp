#include<bits/stdc++.h>
using namespace std;
const int used[]={6,2,5,5,4,5,6,3,7,6};
int n,ans=INT_MAX;
void dfs(int now,int num){
    if(now>n||num>ans)return;
    if(now==n){
        ans=min(ans,num);
        return;
    }
    int nextnum=num*10;
    for(int i=0;i<=9;i++){
        if(i==0&&now==0)continue;
        dfs(now+used[i],nextnum+i);
    }
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        ans=INT_MAX;
        cin >> n;
        dfs(0,0);
        if(ans!=INT_MAX)cout << ans;
        else cout << -1;
        cout << endl;
    }
    return 0;
}
