#include<bits/stdc++.h>
using namespace std;
int pok[5][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int num;
    cin >> num;
    for(int i = 0;i < num + 1;i ++){
        string a;
        getline(cin,a);
        if(i != 0){
            int x,y;
            if(a[0] == 'D') x = 0;
            else if(a[0] == 'C') x = 1;
            else if(a[0] == 'H') x = 2;
            else if(a[0] == 'S') x = 3;
            if(a[1] == 'A') y = 0;
            else if(a[1] == 'T') y = 9;
            else if(a[1] == 'J') y = 10;
            else if(a[1] == 'Q') y = 11;
            else if(a[1] == 'K') y = 12;
            else y = int(a[1]) - 49;
            pok[x][y] = 1;
        }
    }
    int cnt = 0;
    for(int i = 0;i < 4;i ++) for(int j = 0;j < 13;j ++) if(pok[i][j] == 0) cnt ++;
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
