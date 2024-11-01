#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010],c[200010],p[200010],maxn;
void dfs(int x){
    if(x>n){
        memset(c,0,sizeof(c));
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(p[j]==p[i]){
                    if(a[i]==a[j]){
                        c[i]=a[j];
                    }
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            sum+=c[i];
        }
        maxn=max(maxn,sum);
        return;
    }
    p[x]=1;
    dfs(x+1);
    p[x]=2;
    dfs(x+1);
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
        maxn=0;
        dfs(1);
        cout<<maxn<<endl;
    }
    return 0;
}
