#include <bits/stdc++.h>
//#define int long long
using namespace std;
bool vis[5][30];
int check(char a){
    if(a=='D') return 0;
    else if(a=='C') return 1;
    else if(a=='H') return 2;
    else if(a=='S') return 3;
    else return 4;
}
int check2(char a){
    if(a=='A') return 1;
    else if(a=='2') return 2;
    else if(a=='3') return 3;
    else if(a=='4') return 4;
    else if(a=='5') return 5;
    else if(a=='6') return 6;
    else if(a=='7') return 7;
    else if(a=='8') return 8;
    else if(a=='9') return 9;
    else if(a=='T') return 10;
    else if(a=='J') return 11;
    else if(a=='Q') return 12;
    else if(a=='K') return 13;
    else return 14;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char input[10];
        cin>>input;
        int len=strlen(input);
        if(len==2){
            vis[check(input[0])][check2(input[1])]=true;
        }

    }
    int need=52;
    for(int i=0;i<=3;i++){
        for(int j=1;j<=13;j++){
            need-=int(vis[i][j]);
        }
    }
    cout<<need;
    return 0;
}
