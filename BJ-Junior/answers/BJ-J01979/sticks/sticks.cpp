#include<bits/stdc++.h>
using namespace std;
int t,n,ans=999999,cnt;
int a[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int x) {
    if(x==0) {
        if(cnt<ans) {
            ans=cnt;
        }
        return;
    }
    for(int i=0;i<=9;i++) {
        if(x==n && i==0) {
            continue;
        }
        if(a[i]>x) {
            continue;
        }
        cnt=cnt*10+i;
        dfs(x-a[i]);
        cnt=(cnt-i)/10;
    }
}
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--) {
        cin>>n;
        ans=999999;
        cnt=0;
        if(n<2) {
            cout<<-1<<endl;
            continue;
        }
        dfs(n);
        cout<<ans<<endl;
    }
    return 0;
}