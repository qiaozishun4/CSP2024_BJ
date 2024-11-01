#include<bits/stdc++.h>
using namespace std;
int S[(int)1e5+10][(int)2e5+10],task[2][110];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin >> T;
    for(int i = 1;i <= T;i++){
        int n,k,q;
        cin >> n >> k >> q;
        for(int j = 1;j <= n;j++){
            int l;
            cin >> l;
            S[j][0] = l;
            for(int x = 1;x <= l;x++){
                cin >> S[j][x];
            }
        }
        for(int j = 1;j <= q;j++){
            cin >> task[0][j] >> task[1][j];
            bool flag = false;
            for(int x = 1;x <= n;x++){
                for(int y = 1;y <= S[x][0];y++){
                    if(task[1][j] == S[x][y]) flag = true;
                }
            }
            if(flag == false) cout << 0 << endl;
            else if(task[1][j] > k) cout << 0 << endl;
            else if(task[1][j] < 2) cout << 0 << endl;
            else cout << 1 << endl;
        }
        memset(S,0,sizeof(S));
        for(int j = 0;j <= 1;j++){
            for(int x = 1;x <= 105;x++){
                task[j][x] = 0;
            }
        }
    }
    return 0;
}