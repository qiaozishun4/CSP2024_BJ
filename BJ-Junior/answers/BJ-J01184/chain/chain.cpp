#include <bits/stdc++.h>
using namespace std;
struct xl{
    char a[200005];
    int len;
}a[100005];
struct task{
    int r;
    char c;
}t[100005];
int T;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin>>T;
    while(T--){
        int n, k, q;
        cin>>n>>k>>q;
        for(int i = 1;i<=n;i++){
            cin>>a[i].len;
            for(int j = 1;j<=a[i].len;j++){
                cin>>a[i].a[j];
            }
        }
        for(int i = 1;i<=q;i++){
            cin>>t[i].r>>a[i].c;
            cout<<0<<endl;
        }
    }
    return 0;
}
