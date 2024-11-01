#include<bits/stdc++.h>
using namespace std;
int n,minn=0x3f3f3f3f;
int a[100001];
bool vis[100001],st[100001];
int sum;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int t=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]<a[j]&&!vis[j]&&!st[i]){
                vis[j]=1;
                st[i]=1;
                break;
            }else if(a[i]>a[j]&&!vis[i]&&!st[j]){
                vis[i]=1;
                st[j]=1;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!st[i])sum++;
    }
    cout<<sum;
    return 0;
}
