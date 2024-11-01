#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+9;
int a[maxn];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        for(int i = 1;i<=maxn;i++) a[i] = 0;
        int n,ans = 0;
        cin>>n;
        for(int i = 1;i<=n;i++){
            int x;
            cin>>x;
            a[x]++;
        }
        for(int i = 1;i<=maxn;i++){
            int k = a[i]/2;
            //if(k) cout<<a[i]<<" ";
            ans+=k*i;
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
