#include <iostream>
using namespace std;

int n , mx;
int a[30] , col[30] , lst[30][2];
void dfs(int step){
    if (step == n + 1){
        for (int i = 1; i <= n; i++){
            lst[i][0] = lst[i-1][0];
            lst[i][1] = lst[i-1][1];
            if (col[i])lst[i][1] = i;
            else lst[i][0] = i;
        }
        int sum = 0;
        //for (int i = 1; i <= n; i++)cout << col[i] << ' ';
        //cout << endl;
        for (int i = 1; i <= n; i++){
            int p = lst[lst[i][col[i]]-1][col[i]];
            if (a[p] == a[i])sum += a[i];
            //cout << i << ' ' << p << ' ' << sum << endl;
            
        }
        mx = max(mx , sum);
        
        return;
    }
    dfs(step + 1);
    col[step] = 1;
    dfs(step + 1);
    col[step] = 0;
}
int main(){
    freopen("color.in" , "r" , stdin);
    freopen("color.out" , "w" , stdout);
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        mx = 0;
        for (int i = 1; i <= n; i++)cin >> a[i];
        dfs(1);
        cout << mx << endl;
    }
    return 0;
}
//17.37