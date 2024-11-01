#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],ans;
void dfs(int cur){
    if(cur==n+1){
        int lst0=0,lst1=0,sum=0;
        for(int i=1;i<=n;i++){
            if(b[i]==0){
                if(lst0!=0 && a[lst0]==a[i]) sum+=a[i];
                lst0=i;
            }else{
                if(lst1!=0 && a[lst1]==a[i]) sum+=a[i];
                lst1=i;
            }
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=0;i<=1;i++){
        b[cur]=i;
        dfs(cur+1);
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
