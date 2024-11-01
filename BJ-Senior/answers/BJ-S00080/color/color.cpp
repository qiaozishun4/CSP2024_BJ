#include<bits/stdc++.h>
using namespace std;
int t,n;
long long num[200010]={},ans,explam;
bool num_map[200010]={},as[200010]={};
void dfs(int time_borad){
    if(time_borad==n){
        for(int i=n-1;i>=0;i--){
            if(as[i]){
                for(int j=i-1;j>=0;j--){
                    if(num_map[j]==num_map[i]){
                        if(num[j]==num[i]){
                            explam+=num[i];
                            as[j]=false;
                        }break;
                    }
                }
            }
        }ans=max(ans,explam);
        explam=0;
        return;
    }else{
        num_map[time_borad]=false;
        dfs(time_borad+1);
        num_map[time_borad]=true;
        dfs(time_borad+1);
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        ans=explam=0;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>num[j];
            as[j]=true;
        }dfs(0);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}