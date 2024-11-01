#include<bits/stdc++.h>
using namespace std;
int T, n, a[10005], ans;
bool u[100005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=1;i<=n;i++){
            if(u[a[i]]) ans+=a[i];
            u[a[i]]=true;
        }
    }
    cout << ans;
    return 0;
}
