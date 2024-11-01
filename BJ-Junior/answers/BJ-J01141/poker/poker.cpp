#include<bits/stdc++.h>
using namespace std;
int c[10][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string m;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m;
        int x=0,y=0;
        if(m[0]=='S'){
            x=0;
        }
        if(m[0]=='H'){
            x=1;
        }
        if(m[0]=='D'){
            x=2;
        }
        if(m[0]=='C'){
            x=3;
        }
        if(m[1]=='A'){
            y=0;
        }else if(m[1]=='T'){
            y=9;
        }else if(m[1]=='J'){
            y=10;
        }else if(m[1]=='Q'){
            y=11;
        }else if(m[1]=='K'){
            y=12;
        }else{
            y=m[1]-'0'-1;
        }
        c[x][y]=1;
    }
    int r=0;
    for(int i=0; i<4; i++){
        for(int l=0; l<13; l++){
            if(c[i][l]==1){
                r++;
            }
        }
    }
    cout << 52-r;
    return 0;
}