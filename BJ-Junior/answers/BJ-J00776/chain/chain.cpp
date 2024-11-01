#include<bits/stdc++.h>
using namespace std;
int t;
struct mission{
    int r;
    int c;
}a[100000];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    while(t --){
        int n,k,q,l,s[200000];
        cin >> n >> k >> q;
        for(int i = 0;i < n;i ++){
            cin >> l;
            for(int j = 0;j < l;j ++){
                cin >> s[j];
            }
        }
        for(int j = 0;j < q;j ++){
            cin >> a[i].r >> a[i].c;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
