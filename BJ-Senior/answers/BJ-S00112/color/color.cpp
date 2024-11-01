#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int T,n,a[105],ans,sign[105];
void dfs(int x){
    if(x==n){
        int las[3]={-1,-1,-1},sum=0;
        for(int i=1;i<=n;i++){
            if(las[sign[i]]==-1){
                las[sign[i]]=i;
                continue;
            }
            if(a[las[sign[i]]]==a[i]){
                sum+=a[i];
            }
            las[sign[i]]=i;
        }
        ans=max(ans,sum);
        return ;
    }
    sign[x+1]=1;
    dfs(x+1);
    sign[x+1]=2;
    dfs(x+1);

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >>T;
    while(T--){
        cin >>n;
        ans=-1e9;
        for(int i=1;i<=n;i++)cin >> a[i];
        dfs(0);
        cout << ans << endl;
    }
}

