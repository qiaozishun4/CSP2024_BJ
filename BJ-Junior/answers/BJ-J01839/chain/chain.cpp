#include<bits/stdc++.h>
using namespace std;
int a[1005][20005],n,m,q,l[1005];
bool check(int r,int c){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= max(1,l[i] - m + 1);j++){
            for(int k = j + 1;k <= j + m - 1;k++){
                if(a[i][j] == 1 and a[i][k] == c)return true;
            }
        }
    }
    return false;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(l,0,sizeof(l));
        cin >> n >> m >> q;
        for(int i = 1;i <= n;i++){
            cin >> l[i];
            for(int j = 1;j <= l[i];j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1;i <= q;i++){
            int r,c;
            cin >> r >> c;
            cout << check(r,c) << endl;
        }
    }
    
    return 0;
}