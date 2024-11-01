#include<iostream>
using namespace std;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    int a[4][14] = {0};
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int x, y;
        if(s[0] == 'D'){
            x = 0;
        }else if(s[0] == 'C'){
            x = 1;
        }else if(s[0] == 'H'){
            x = 2;
        }else{
            x = 3;
        }
        if(s[1] == 'A'){
            y = 1;
        }else if(s[1] == 'T'){
            y = 10;
        }else if(s[1] == 'J'){
            y = 11;
        }else if(s[1] == 'Q'){
            y = 12;
        }else if(s[1] == 'K'){
            y = 13;
        }else{
            y = s[1] - '0';
        }
        a[x][y] = 1;
    }
    int ans = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j < 14; j++){
            if(a[i][j] == 0){
                ans++;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
