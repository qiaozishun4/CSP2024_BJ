#include<iostream>
#include<cstdio>
using namespace std;
int n,a[10000005],maxn=0,cnt=0,p[10000005];
int su(){
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(p[j]==p[i]){
                if(a[i]==a[j]){
                    cnt+=a[i];
                }

                break;
            }
        }
    }
    return cnt;
}
void dfs(int st){
    if(st>n){
        maxn=max(maxn,su());
        return ;
    }
    for(int i=0;i<=1;i++){
        p[st]=i;
        dfs(st+1);
    }
    return ;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        maxn=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1);
        cout<<maxn<<endl;
    }
    return 0;
}
