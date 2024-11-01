#include<iostream>
//#define test
using namespace std;
int T;
int n;
const int N = 200010;
int num[N];
int color[N];
int last[3];
int max_ans = 0;
void DFS(int x){
    if(x == n + 1){
        int ans = 0;
        last[1] = 0;
        last[2] = 0;
        for(int i = 1; i <= n; i++){
            if(last[color[i]] != 0){
                if(num[last[color[i]]] == num[i]){
                    ans += num[i];
                }
            }
            last[color[i]] = i;
        }
        if(ans > max_ans){
            max_ans = ans;
            #ifdef test
            for(int j = 1; j <= n; j++){
                cout << color[j] << " ";
            }
            cout << endl;
            #endif
        }
        return;
    }
    color[x] = 1;
    DFS(x + 1);
    color[x] = 2;
    DFS(x + 1);
}
int main(){
    color[1] = 1;
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    for(int o = 1; o <= T; o++){
        max_ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> num[i];
        }
        DFS(2);
        cout << max_ans << endl;
    }
    return 0;
}