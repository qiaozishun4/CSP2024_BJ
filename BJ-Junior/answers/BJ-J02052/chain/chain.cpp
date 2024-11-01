#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
vector<int> a[100005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            a[i].push_back(x);
            for(int j=1;j<=x;j++){
                int y;
                cin >> y;
                a[i].push_back(y);
            }
        }
        while(q--){
            int r,c;
            bool flag = 0;
            cin >> r >> c;
            if(r<=1){
                for(int i=1;i<=n;i++){
                    int last = -1e9;
                    for(int j=1;j<a[i][0];j++){
                        if(j-last<k && a[i][j]==c){
                            flag = 1;
                            break;
                        }
                        if(a[i][j]==1){
                            last = j;
                        }
                    }
                    if(flag){
                        break;
                    }
                }
                cout << flag << endl;
            }
        }
    }
    return 0;
}
