#include <bits/stdc++.h>
using namespace std;
bool po[4][14];
int n;
char f,s;
int cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> f >> s;
        if(f == 'D'){
            if(s == 'A') po[0][1] = 1;
            else if('2' <= s && s <= '9') po[0][s-48] = 1;
            else if(s == 'T') po[0][10] = 1;
            else if(s == 'J') po[0][11] = 1;
            else if(s == 'Q') po[0][12] = 1;
            else if(s == 'K') po[0][13] = 1;
        }else if(f == 'C'){
            if(s == 'A') po[1][1] = 1;
            else if('2' <= s && s <= '9') po[1][s-48] = 1;
            else if(s == 'T') po[1][10] = 1;
            else if(s == 'J') po[1][11] = 1;
            else if(s == 'Q') po[1][12] = 1;
            else if(s == 'K') po[1][13] = 1;
        }else if(f == 'H'){
            if(s == 'A') po[2][1] = 1;
            else if('2' <= s && s <= '9') po[2][s-48] = 1;
            else if(s == 'T') po[2][10] = 1;
            else if(s == 'J') po[2][11] = 1;
            else if(s == 'Q') po[2][12] = 1;
            else if(s == 'K') po[2][13] = 1;
        }else if(f == 'S'){
            if(s == 'A') po[3][1] = 1;
            else if('2' <= s && s <= '9') po[3][s-48] = 1;
            else if(s == 'T') po[3][10] = 1;
            else if(s == 'J') po[3][11] = 1;
            else if(s == 'Q') po[3][12] = 1;
            else if(s == 'K') po[3][13] = 1;
        }
    }
    for(int i = 0;i < 4;i ++){
        for(int j = 1;j <= 13;j ++){
            if(po[i][j] == 1) cnt ++;
        }
    }
    cout << 52-cnt;
    fclose(stdin);
    fclose(stdout);
}
