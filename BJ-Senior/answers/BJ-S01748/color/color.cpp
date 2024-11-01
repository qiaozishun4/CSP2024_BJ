#include <iostream>
#include <cstdlib>
using namespace std;

int arr[200005];
bool isred[200005];

int n;
int ans;
void dfs(int lvl){
    if(lvl>n){
        int lst[5]={0,0};
        int curans=0;
        for(int i=1;i<=n;++i){
            if(lst[isred[i]]==arr[i]){
                curans+=arr[i];
            }lst[isred[i]]=arr[i];
        }ans=max(ans,curans);
        return ;
    }isred[lvl]=false;
    dfs(lvl+1);
    isred[lvl]=true;
    dfs(lvl+1);
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>arr[i];
        }ans=0;
        dfs(1);
        cout<<ans<<'\n';
    }return 0;
}
