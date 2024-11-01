#include<bits/stdc++.h>
using namespace std;
int f[10][100],n,x,s=0;
char a,b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a=='D')
            x=1;
        else  if(a=='C')
            x=2;
        else  if(a=='H')
            x=3;
        else  if(a=='S')
            x=4;
        if(b=='A')
            f[x][1]=1;
        else if(b=='2')
            f[x][2]=1;
        else if(b=='3')
            f[x][3]=1;
        else if(b=='4')
            f[x][4]=1;
        else if(b=='5')
            f[x][5]=1;
        else if(b=='6')
            f[x][6]=1;
        else if(b=='7')
            f[x][7]=1;
        else if(b=='8')
            f[x][8]=1;
        else if(b=='9')
            f[x][9]=1;
        else if(b=='T')
            f[x][10]=1;
        else if(b=='J')
            f[x][11]=1;
        else if(b=='Q')
            f[x][12]=1;
        else if(b=='K')
            f[x][13]=1;
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(f[i][j]==0)
                s++;
    cout<<s;
    return 0;
}