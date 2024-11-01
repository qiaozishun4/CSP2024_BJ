#include<bits/stdc++.h>
using namespace std;
char s[1050][1050];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >>T;
    while(T--){
        int n, m, k;
        cin >> n >>m >>k;
        int nowx, nowy, flag;
        cin >> nowx >> nowy >> flag;
        for(int i = 0; i <= n +1; i++){
            for(int j = 0; j <= m +1; j++){
                s[i][j] = 'x';
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> s[i][j];
            }
        }
        s[nowx][nowy] = 1;
        int sum = 0;
        while(k--){
            int opx = nowx;
            int opy = nowy;
            if(flag == 0){
                opy++;
            }
            if(flag == 1){
                opx++;
            }
            if(flag == 2){
                opy--;
            }
            if(flag == 3){
                opx--;
            }
            if(s[opx][opy] == 'x'){
                flag = (flag + 1) % 4;
            }
            else{
                nowx = opx;
                nowy = opy;
                s[nowx][nowy] = 1;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i][j] == 1){
                    sum++;
                }
            }
        }
        cout <<sum <<endl;
    }
    return 0;
}
