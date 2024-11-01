#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q,l,r;
    char c;
    cin >> t;
    while(t--){
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++){
            cin >> l;
            for(int j=1;j<=l;j++){
                cin >> a[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            int minn=1e9;
            cin >> r >> c;
            if(r==1){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=102;j++){
                        if(a[i][j]==c){
                            minn=min(minn,j);
                            break;
                        }
                    }
                }
                if(minn<=k){
                    cout << "1" << endl;
                }else{
                    cout << "0" << endl;
                }
            }else{
                cout << "1" << endl;
            }
        }
    }
    return 0;
}

