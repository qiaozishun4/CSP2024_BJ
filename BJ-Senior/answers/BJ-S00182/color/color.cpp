#include<bits/stdc++.h>
using namespace std;
int n,t,a[110],col[110],aans=-1;
int shuchu(){
    int ans=0;
    for(int i=0;i<n;i++){
        if(i!=0){
            for(int j=i-1;j>=0;j--){
                if(a[j]==a[i]&&col[j]==col[i]){
                    ans+=a[j];
                    break;
                }
            }
        }
    }
    return ans;
}
void dfs(int I){
    if(I==n){
        aans=max(aans,shuchu());
        return ;
    }
    col[I]=1;
    dfs(I+1);
    col[I]=0;
    dfs(I+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t>0){
        t--;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        dfs(0);
        cout<<aans<<endl;
        aans=-1;
    }

    return 0;
}
