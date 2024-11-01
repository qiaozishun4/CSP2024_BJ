#include<iostream>
#include<cstdio>
using namespace std;

string a[100];
int vis[100];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==1) continue;

        ans++;
        vis[i]=1;
        for(int j=1;j<=n;j++){
            if(a[i]==a[j]) vis[j]=1;
        }
    }
    cout<<52-ans<<endl;
    return 0;
}