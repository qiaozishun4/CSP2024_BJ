#include <bits/stdc++.h>
using namespace std;

int a[10][2] = {{6, 0}, {2, 1}, {5, 2}, {4, 4}, {6, 6}, {3, 7}, {7, 8}};

long long ans[100000];

bool cmp(int x, int y){
    return x < y;
}

int n;

int dfs(int x, int y){
    if (y == 2){
        return 0;
    }
    int sum = 0;
    sum ++;
    if (x < 8 && y < 8){
        for (int i = 0; i <= 6; i ++){
            if (x % a[i][0] == 0 && x / a[i][0] == 1){
                ans[sum] += 10 * x;
            }
            if (y % a[i][0] == 0 && y / a[i][0] == 1){
                ans[sum] += y;
            }
        }
    }else{
        if (x > 7){
            dfs(dfs(2, x- 2), y);
        }else if (y > 7){
            dfs(x, dfs(2, y - 2));
        }
    }
    dfs(x + 1, y - 1);
    return 0;
}


int main(){

    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    while(cin >> n){
        if (n <= 1){
            cout << -1 << endl;
            continue;
        }else if (n <= 7){
            for (int i = 0; i <= 6; i ++){
                if (n % a[i][0] == 0 && n / a[i][0] == 1){
                    cout << a[i][1] << endl;
                    break;
                }
            }
        }else {
            dfs(2, n - 2);
            sort(a, a + n, cmp);
            cout << a[0] << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
