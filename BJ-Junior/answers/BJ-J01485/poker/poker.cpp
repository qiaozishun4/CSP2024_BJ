#include<iostream>
using namespace std;
int n;
bool poker[5][14];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin>>n;
    while(n--){
        char a, b;
        int x, y;
        cin>>a>>b;
        if(a=='S'){
            x=1;
        }
        if(a=='H'){
            x=2;
        }
        if(a=='D'){
            x=3;
        }
        if(a=='C'){
            x=4;
        }
        if(b>='0'&&b<='9'){
            y=b-'0';
        }
        if(b=='A'){
            y=1;
        }
        if(b=='T'){
            y=10;
        }
        if(b=='J'){
            y=11;
        }
        if(b=='Q'){
            y=12;
        }
        if(b=='K'){
            y=13;
        }
        poker[x][y]=1;
    }
    int cnt=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!poker[i][j]){
                cnt++;
            }
        }
    }
    cout<<cnt;
	return 0;
}
