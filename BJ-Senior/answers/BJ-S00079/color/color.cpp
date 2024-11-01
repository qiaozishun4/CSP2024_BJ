#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n;
int dfs(int cnt, int lst_0, int lst_1){
    if(cnt == n){
        return max( (a[cnt] == lst_0 ? lst_0 : 0) , (a[cnt] == lst_1 ? lst_1 : 0));
    }
    return max(  (lst_0 == a[cnt] ? lst_0 : 0)+dfs(cnt+1,a[cnt],lst_1), (lst_1 == a[cnt] ? lst_1 : 0)+dfs(cnt+1,lst_0,a[cnt]));
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        cout<<dfs(1,0,0)<<endl;
    }
}
