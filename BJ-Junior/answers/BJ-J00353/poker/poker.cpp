#include <bits/stdc++.h>
using namespace std;
const int maxn=6e1+10;
int n,ans=52;
char huase,digit;
bool visited[maxn][maxn];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        cin>>huase>>digit;
        if (huase=='D'){
            if (digit=='A') visited[1][1]=true;
            else if (digit=='T') visited[1][10]=true;
            else if (digit=='J') visited[1][11]=true;
            else if (digit=='Q') visited[1][12]=true;
            else if (digit=='K') visited[1][13]=true;
            else visited[1][digit-'0']=true;}
        else if (huase=='C'){
            if (digit=='A') visited[2][1]=true;
            else if (digit=='T') visited[2][10]=true;
            else if (digit=='J') visited[2][11]=true;
            else if (digit=='Q') visited[2][12]=true;
            else if (digit=='K') visited[2][13]=true;
            else visited[2][digit-'0']=true;}
        else if (huase=='H'){
            if (digit=='A') visited[3][1]=true;
            else if (digit=='T') visited[3][10]=true;
            else if (digit=='J') visited[3][11]=true;
            else if (digit=='Q') visited[3][12]=true;
            else if (digit=='K') visited[3][13]=true;
            else visited[3][digit-'0']=true;}
        else if (huase=='S'){
            if (digit=='A') visited[4][1]=true;
            else if (digit=='T') visited[4][10]=true;
            else if (digit=='J') visited[4][11]=true;
            else if (digit=='Q') visited[4][12]=true;
            else if (digit=='K') visited[4][13]=true;
            else visited[4][digit-'0']=true;}}
    for (int i=1;i<=4;i++)
        for (int j=1;j<=13;j++)
            if (visited[i][j]) ans--;
    printf("%d",ans);
    return 0;}
//D C H S
//A 2 3 4 5 6 7 8 9 T J Q K

