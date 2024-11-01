#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010],ANS;
int col[200010],ls[5];
void dfs(int k){
    if(k>n){
        ls[0]=ls[1]=0;int ans=0;
        for(int i=1;i<=n;i++){
            //cout<<ls[col[i]]<<" "<<i<<endl;
            if(ls[col[i]]==0){ls[col[i]]=i;continue;}
            if(a[ls[col[i]]]==a[i])ans+=a[i];
            ls[col[i]]=i;
        }
        ANS=max(ANS,ans);
        return;
    }
    col[k]=1;dfs(k+1);
    col[k]=0;dfs(k+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        ANS=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1);
        cout<<ANS<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}