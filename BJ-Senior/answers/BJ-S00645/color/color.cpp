#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int a[200010];
bool color[200010];
int n;
int dfs(int x){
    if(x==n+1){
        int bac=0,pre1=-1,pre0=-1;
        for(int i=1;i<=n;i++){
            if(color[i]){
                if(pre1!=-1&&a[pre1]==a[i]){
                    bac+=a[i];
                }
                pre1=i;
            }
            else{
                if(pre0!=-1&&a[pre0]==a[i]){
                    bac+=a[i];
                }
                pre0=i;
            }
        }
        return bac;
    }
    color[x]=0;
    int bac=dfs(x+1);
    color[x]=1;
    return max(bac,dfs(x+1));
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        cout << dfs(1) << endl;
    }
    return 0;
}
