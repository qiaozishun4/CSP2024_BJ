#include<iostream>
#define ll long long
using namespace std;
char c,b;
ll poker[3000][3000],n,x,need=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c>>b;
        if(c=='S'){
            x=2;
        }else if(c=='C'){
        x=1;
        }else if(c=='H'){
        x=3;
        }else if(c=='D'){
        x=4;

        }
        if(b<='9'&&b>='0'){
            poker[x][b-'0']++;

        }else if(b=='A'){
        poker[x][1]++;
        }else if(b=='T'){
        poker[x][10]++;
        }else if(b=='J'){
        poker[x][11]++;
        }else if(b=='Q'){
        poker[x][12]++;
        }else if(b=='K'){
        poker[x][13]++;
    }
    x=0;
    }
    for(int i=1;i<=4;i++){
         for(int j=1;j<=13;j++){
            if(poker[i][j]!=0){
                need=need-1;
            }
        }
    }
       cout<<need;
       return 0;
    }


