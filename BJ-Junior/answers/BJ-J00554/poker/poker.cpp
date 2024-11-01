#include<bits/stdc++.h>
using namespace std;
int poker[5][20];
int awa(char s){
    if(s == 'A'){
        return 1;
    }
    if(s >= '2' && s <= '9'){
        return s - '0';
    }
    if(s == 'T'){
        return 10;
    }
    if(s == 'J'){
        return 11;
    }
    if(s == 'Q'){
        return 12;
    }
    if(s == 'K'){
        return 13;
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string s[100];
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> s[i];
    }
    for(int i = 1;i <= n;i ++){
        if(s[i][0] == 'D'){
            poker[1][awa(s[i][1])] ++;
        }
        if(s[i][0] == 'C'){
            poker[2][awa(s[i][1])] ++;
        }
        if(s[i][0] == 'H'){
            poker[3][awa(s[i][1])] ++;
        }
        if(s[i][0] == 'S'){
            poker[4][awa(s[i][1])] ++;
        }
    }
    n = 0;
    for(int i = 1;i <= 4;i ++){
        for(int j = 1;j <= 13;j ++){
            if(poker[i][j] == 0){
                n ++;
            }
        }
    }
    cout << n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
