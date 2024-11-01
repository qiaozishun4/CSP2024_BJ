#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,a[N],ma;
int b[N],c[N];
void dfs(int x){
    if(x>n){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=c[i];
        }
        ma=max(ma,ans);
        return;
    }
    for(int i=0;i<=1;i++){
        b[x]=i;
        for(int j=x-1;j>=0;j--){
            if(b[j]==b[x]){
                if(a[j]==a[x]){
                    c[x]=a[x];
                }
                break;
            }
        }
        dfs(x+1);
        c[x]=0;
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ma=INT_MIN;
        memset(b,127,sizeof(b));
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        dfs(1);
        cout<<ma<<endl;
    }
    return 0;
}
