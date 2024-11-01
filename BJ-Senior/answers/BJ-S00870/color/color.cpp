#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t,n;
int a[N],ans,c[N];
void dfs(int x){
    if(x > n){
        int sum = 0;
        for(int i = n;i >= 1;i--){
            for(int j = i - 1;j >= 1;j--){
                if(c[j] == c[i]){
                    if(a[j] == a[i]){sum += a[i];}
                    break;
                }
            }
        }
        ans = max(sum,ans);
        return ;
    }
    c[x] = 1;
    dfs(x + 1);
    c[x] = 2;
    dfs(x + 1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        dfs(1);
        cout << ans << endl;
    }

}