#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
bool vis[100010],at[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int j=2;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        while(a[i]==a[j])j++;
        while(vis[j]||at[j])j++;
        if(j>n)break;
        //cout<<i<<" "<<j<<endl;
        vis[i]=1;at[j]=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i])cnt++;
    }
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}