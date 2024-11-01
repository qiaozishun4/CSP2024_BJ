#include <bits/stdc++.h>
using namespace std;
char p[5][14];
int n,sum;
string x;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x[0]=='D'){
            if(x[1]=='A') p[1][1]++;
            else if(x[1]=='J') p[1][11]++;
            else if(x[1]=='Q') p[1][12]++;
            else if(x[1]=='K') p[1][13]++;
            else if(x[1]=='T') p[1][10]++;
            else p[1][int(x[1]-48)]++;
        }
        else if(x[0]=='C'){
            if(x[1]=='A') p[2][1]++;
            else if(x[1]=='J') p[2][11]++;
            else if(x[1]=='Q') p[2][12]++;
            else if(x[1]=='K') p[2][13]++;
            else if(x[1]=='T') p[2][10]++;
            else p[2][int(x[1]-48)]++;
        }
        else if(x[0]=='H'){
            if(x[1]=='A') p[3][1]++;
            else if(x[1]=='J') p[3][11]++;
            else if(x[1]=='Q') p[3][12]++;
            else if(x[1]=='K') p[3][13]++;
            else if(x[1]=='T') p[3][10]++;
            else p[3][int(x[1]-48)]++;
        }
        else if(x[0]=='S'){
            if(x[1]=='A') p[4][1]++;
            else if(x[1]=='J') p[4][11]++;
            else if(x[1]=='Q') p[4][12]++;
            else if(x[1]=='K') p[4][13]++;
            else if(x[1]=='T') p[4][10]++;
            else p[4][int(x[1]-48)]++;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(p[i][j]){
                sum++;
            }
        }
    }
    cout<<52-sum;
    return 0;
}
