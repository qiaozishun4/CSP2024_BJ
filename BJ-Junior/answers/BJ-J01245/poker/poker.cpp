#include <bits/stdc++.h>
using namespace std;

int poker[10][20];
int n;
string s;

void putin(string u){
    int x,y;
    if(u[0] == 'D') x = 1;
    if(u[0] == 'C') x = 2;
    if(u[0] == 'H') x = 3;
    if(u[0] == 'S') x = 4;
    if(u[1] == 'A') y = 1;
    else if(u[1] == 'T') y = 10;
    else if(u[1] == 'J') y = 11;
    else if(u[1] == 'Q') y = 12;
    else if(u[1] == 'K') y = 13;
    else y = (u[1]-'0');
    poker[x][y]++;
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>s;
        putin(s);
    }
    int ans = 52;
    for(int i = 1;i<=4;i++){
        for(int j = 1;j<=13;j++){
            if(poker[i][j]){
                ans--;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
