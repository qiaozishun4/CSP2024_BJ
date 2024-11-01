#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
bool col[100005];
int calc(){
    int res=0;
    for(int i=1;i<=n;i++){
        int j=i-1;
        for(j;j>0;j--){
            if(col[i]==col[j])break;
        }
        if(a[i]==a[j]&&col[i]==col[j])res+=a[i];
    }
    return res;
}
void dfs(int p){
    if(p>n){
        ans=max(ans,calc());
        return;
    }
    col[p]=1;
    dfs(p+1);
    col[p]=0;
    dfs(p+1);
}
void slv(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=0;
    dfs(1);
    cout<<ans<<endl;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}