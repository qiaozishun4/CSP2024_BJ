#include<bits/stdc++.h>
using namespace std;
int a[20];
int n;
long long maxx=0;
int x[20];
void dfs(int cur){
    if(cur>n){
        long long cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(x[i]==x[j]){
                    if(a[i]==a[j]){
                        cnt+=a[i];
                    }
                    break;
                }
            }
        }
        maxx=max(maxx,cnt);
        return ;
    }
    for(int i=0;i<=1;i++){
        x[cur]=i;
        dfs(cur+1);
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        maxx=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1);
        cout<<maxx<<endl;
    }
    return 0;
}
