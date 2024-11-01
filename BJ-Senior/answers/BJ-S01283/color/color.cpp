#include<bits/stdc++.h>
using namespace std;
int a[10005],h[10005],maxx=1e9;
int col[10005],n;
void dfs(int cur) {
    if(cur>n) {
		memset(h,0,sizeof(h));
        int sum=0;
        for(int i=1;i<=n;i++) {
            if(h[col[i]]==a[i]) {
                sum+=a[i];
            } h[col[i]]=a[i];
        } maxx=max(maxx,sum);
    } else {
        for(int c=1;c<=2;c++) {
            col[cur]=c;
            dfs(cur+1);
            col[cur]=0;
        }
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    int t;  cin>>t;
    while(t--) {
        maxx=-1e9;
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        } dfs(1);
        cout<<maxx<<"\n";
    }
    return 0;
}
