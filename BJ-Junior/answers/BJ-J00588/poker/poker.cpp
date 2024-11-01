#include <bits/stdc++.h>
using namespace std;
bool haved[13][4] = {0};
int rt = 0;
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
int n; string ls;
cin >> n;
for(int i = 0;i < n;i++){
    cin >> ls;
    int b=0,c=0;
    switch (ls[0] ){
    case 'D':
        b = 0;
        break;
    case 'C':
        b = 1;
        break;
    case 'H':
        b = 2;
        break;
    case 'S':
        b = 3;
        break;}
    switch(ls[1]){
    case 'A':
        c=0;
        break;
    case '2':
        c=1;
        break;
    case '3':
        c=2;
        break;
    case '4':
        c=3;
        break;
    case '5':
        c=4;
        break;
    case '6':
        c=5;
        break;
    case '7':
        c=6;
        break;
    case '8':
        c=7;
        break;
    case '9':
        c=8;
        break;
    case 'T':
        c=9;
        break;
    case 'J':
        c=10;
        break;
    case 'Q':
        c=11;
        break;
    case 'K':
        c=12;
        break;


    }
    haved[c][b] = 1;
}
for(int i = 0;i<13;i++){
    for(int e = 0;e < 4;e++){
        if(haved[i][e] == 0){
            rt ++;
        }
    }
}

cout << rt;
return 0;
}
