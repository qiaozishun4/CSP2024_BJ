#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100010],s[100010],maxn=0;
void dfs(int step){
    if(step==n+1){
        int sum=0;
        vector <int> v1,v2;
        for(int i=1;i<=n;i++){
            if(s[i]==0){
                if(!v1.empty()){
                    if(a[v1.back()]==a[i]) sum+=a[i];
                }
                v1.push_back(i);
            }
            else{
                if(!v2.empty()){
                    if(a[v2.back()]==a[i]) sum+=a[i];
                }
                v2.push_back(i);
            }
        }
        maxn=max(maxn,sum);
        return ;
    }
    dfs(step+1);
    s[step]=1;
    dfs(step+1);
    s[step]=0;
    return ;
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        maxn=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1);
        cout<<maxn<<"\n";
    }
    return 0;
}
