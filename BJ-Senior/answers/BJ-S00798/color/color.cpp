#include<bits/stdc++.h>
using namespace std;
int a[200005];
int book[200005];
int maxx=-1;
int n;
int check (int cnt){
    int ans=0;
    for(int i=cnt;i>1;i--){
        for(int j=i-1;j>=1;j--){
            if(book[i]==book[j]){
                if(a[i]==a[j]){
                    //cout<<i<<" "<<j<<endl;
                    ans+=a[i];
                }
                break;
            }
        }
    }
    return ans;
}
void dfs(int num){
    if(num>n){
        int ans=check(n);
        if(ans>maxx){
            maxx=ans;
            for(int i=1;i<=n;i++){
                //cout<<book[i]<<" ";
            }
            //cout<<endl;
        }
        return ;
    }
    book[num]=1;
    dfs(num+1);
    book[num]=2;
    dfs(num+1);
    return ;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        maxx=-1;
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1);
        cout<<maxx<<endl;
    }
    return 0;
}
