#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool a[200001];
int num[200001];
void dfs(int l){
    if(l==n+1){
        int mp[2]={0,0};
        int all=0;
//        cout<<"case:";
//        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//        cout<<endl;
        for(int i=1;i<=n;i++){
            if(mp[a[i]]>0&&num[mp[a[i]]]==num[i]){
                mp[a[i]]=i;
                all+=num[i];
//                cout<<"plus at"<<i<<endl;
            }
            else{
                mp[a[i]]=i;
            }
        }
//        cout<<"all:"<<all<<endl;
        ans=max(all,ans);
        return;
    }
    a[l]=1;
    dfs(l+1);
    a[l]=0;
    dfs(l+1);
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>num[i];
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
