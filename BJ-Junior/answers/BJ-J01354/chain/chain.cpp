#include<bits/stdc++.h>
using namespace std;
vector<bool> dp[105][100005],dp2[105][100005];
int n,k,q,l[100005],cntc[200005],ans[105][200005];
vector<int> s[100005],c[200005][5];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k >> q;
        for(int i = 1;i <= 200000;i++){
            cntc[i] = 0;
            c[i][1].clear();
            c[i][2].clear();
            c[i][1].push_back(0);
            c[i][2].push_back(0);
            for(int j = 0;j <= 100;j++){
                ans[j][i] = 0;
            }
        }
        for(int i = 1;i <= n;i++){
            cin >> l[i];
            dp[0][i].push_back(0);
            dp2[0][i].push_back(0);
            s[i].push_back(0);
            for(int j = 1;j <= l[i];j++){
                dp[0][i].push_back(0);
                dp2[0][i].push_back(0);
                int tmp;
                cin >> tmp;
                s[i].push_back(tmp);
                cntc[tmp]++;
                c[tmp][1].push_back(i);
                c[tmp][2].push_back(j);
                if(tmp == 1){
                    dp[0][i][j] = 1;
                }
            }
        }
        for(int i = 1;i <= 100;i++){
            for(int j = 1;j <= n;j++){
                int tmp = -1e9;
                dp[i][j].push_back(0);
                dp2[i][j].push_back(0);
                for(int l2 = 1;l2 <= l[j];l2++){
                    dp[i][j].push_back((tmp) >= l2 - k + 1);
                    dp2[i][j].push_back(0);
                    for(int t2 = 1;t2 <= cntc[s[j][l2]];t2++){
                        if(c[s[j][l2]][1][t2] != j){
                            dp2[i][j][l2] = (dp2[i][j][l2] | dp[i - 1][c[s[j][l2]][1][t2]][c[s[j][l2]][2][t2]]);
                        }
                    }
                    if(dp2[i][j][l2]){
                        tmp = l2;
                    }
                    ans[i][s[j][l2]] = (ans[i][s[j][l2]] | dp[i][j][l2]);
                    //cout << dp[i][j][l2] << " " << dp2[i][j][l2] << '\n';
                }
                //cout << '\n';
            }
            //cout << '\n';
        }
        while(q--){
            int r,c;
            cin >> r >> c;
            cout << ans[r][c] << "\n";
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 100;j++){
                dp[j][i].clear();
                dp2[j][i].clear();
            }
            s[i].clear();
        }
    }
    return 0;
}
/*
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6

*/
