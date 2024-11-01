#include <bits/stdc++.h>
using namespace std;
int r[100010];
int r2[100010];
int bb[100010];
int tui[100010] = {0};
int att[100010] = {0};
vector<int> b;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        scanf("%d", &r[i]);
        r2[i] = r[i];
        //bb[r2[i]] = i;
    }
    sort(r2 + 1, r2 + n + 1);
    //int flag = 0;
    for(int i = 1;i <= n;i++){
        if(tui[i] == 1 || att[i] == 1){
            continue;
        }
        int flag = 0;
        for(int j = i;j <= n;j++){
            if(tui[j] == 1 || att[j] == 1){
                continue;
            }
            if(r2[j] > r2[i]){
                flag = 1;
                att[j] = 1;
                tui[i] = 1;
                break;
            }
        }
        if(flag == 0){
           if(i == n){
              for(int j = n;j >= 1;j--){
                if(tui[j] == 1 || att[j] == 1){
                    continue;
                }
                if(r2[j] < r2[n]){
                    att[n] = 1;
                    tui[j] = 1;
                }
              }
           }else{
                break;
           }
        }
    }
    int cnt98 = 0;
    for(int i = 1;i <= n;i++){
        if(tui[r2[i]] == 0){
            cnt98++;
            //cout << r[i] << " ";
        }
    }
    //cout << endl;
    cout << cnt98;
    return 0;
}
