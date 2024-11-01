#include<bits/stdc++.h>
using namespace std;
bool vis[1000005];
int a[1000005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(vis,0,sizeof(vis));
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 1;i <= n;i++){
                cin >> a[i];
                if(!vis[a[i]]){
                    vis[a[i]] = 1;
                }
                else sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}