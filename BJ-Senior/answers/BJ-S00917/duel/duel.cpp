#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[100005], vis[100005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]>a[j]&&vis[a[i]]!=0){
                ans--;
                vis[a[i]]--;
            }
        }
    }
    cout<<ans;
    return 0;
}

