#include<bits/stdc++.h>
using namespace std;
int n,a[1010],b[1010],ans[100010],cnt,k;
void dfs(int x){
    if(x==n+1){
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(b[i]==b[j]){
                        if(a[i]==a[j])
                    ans[k]+=a[i];
                    break;
                }
            }
        }
        k++;
    }
    else{
        b[x]=1;
        dfs(x+1);
        b[x]=0;
        dfs(x+1);
    }
}

int main(){
    int T;
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    for(int p=1;p<=T;p++){
            memset(ans,0,sizeof(ans));
            cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    k=1;
    dfs(1);
    for(int i=1;i<k;i++){
        if(ans[i]>cnt) cnt=ans[i];
    }
    cout<<cnt;
    }
return 0;
}
