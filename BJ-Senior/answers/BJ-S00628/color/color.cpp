#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +5;
//四个标记 redL redR blueL blueR
//用max比较一下RB或不选的价值
//但是我要骗分
int main() {
    int ans = 0;
    freopen("color.in","r",stdin);
    freopen("color.out", "w", stdout);
    int b, n;
    cin >> b;
    for(int k = 0; k < b; k ++) {
        cin >> n;
        int a[100001];
        for(int i = 0; i < n; i ++){
            cin >>a[i];
            int t = a[i];
            for(int j = 0; j <= i; j ++){
                if(a[j] == t && i - j <= 2){
                    ans ++;
                    a[j] = -1;
                    a[i] = -1;
                }
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}