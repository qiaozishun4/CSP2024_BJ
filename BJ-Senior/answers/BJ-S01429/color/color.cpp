#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],v[200005];
int dfs(int x){
    if(x==n){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(v[i]==v[j]){
                    if(a[i]==a[j]){
                        ans+=a[i];
                    }
                    break;
                }
            }
        }
        return ans;
    }
    else{
        v[x]=1;
        int y=dfs(x+1);
        v[x]=0;
        int z=dfs(x+1);
        return max(y,z);
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
        cout<<dfs(1)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
