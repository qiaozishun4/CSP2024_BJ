#include<bits/stdc++.h>
using namespace std;
bool a[10][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    string s;
    for(int i = 1; i<=9; i++){
        for(int j = 1; j<=19; j++){
            a[i][j] = false;
        }
    }
    for(int i = 1; i<=n; i++){
        cin >> s;
        int t1, t2;
        if(s[0]=='D'){
            t1 = 1;
        }else if(s[0]=='C'){
            t1 = 2;
        }else if(s[0]=='H'){
            t1 = 3;
        }else t1 = 4;
        if(s[1]=='A'){
            t2 = 1;
        }else if(s[1]=='J'){
            t2 = 11;
        }else if(s[1]=='Q'){
            t2 = 12;
        }else if(s[1]=='K'){
            t2 = 13;
        }else if(s[1]=='T'){
            t2 = 10;
        }else{
            t2 = int(s[1]-'0');
        }
        a[t1][t2] = true;
    }
    int sum = 0;
    for(int i = 1; i<=4; i++){
        for(int j = 1; j<=13; j++){
            if(a[i][j]==false){
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}
