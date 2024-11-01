#include<bits/stdc++.h>
using namespace std;
int m,flag[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        flag[m]++;
    }
    int ans=0;
    for(int i=1;i<=100005;i++){
        if(ans<flag[i]){
            ans=flag[i];
        }
    }
    cout<<ans;
    return 0;
}
