#include<bits/stdc++.h>
using namespace std;
int d[100010];
int las[1000100];
int a[100010];
int n,t,last,maxans;
void dfs(int k){
    if(k==n+1){
            last=0;
            int ans=0;
        for(int i=1;i<=n;i++){
            if(d[i]==1){
                if(a[i]==last){
                    ans+=a[i];
                }
                last=a[i];
            }
        }
        last=0;
        for(int i=1;i<=n;i++){
            if(d[i]==2){
                if(a[i]==last){
                    ans+=a[i];
                }
                last=a[i];
            }
        }
        maxans=max(maxans,ans);
        return;
    }else{
        d[k]=1;
        dfs(k+1);
        d[k]=2;
        dfs(k+1);
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        maxans=0;
        dfs(1);
        cout<<maxans<<endl;
    }
    return 0;
}
