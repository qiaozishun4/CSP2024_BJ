#include<bits/stdc++.h>
using namespace std;
bool k[5][14];
int main(){
    //freopen("poker3.in","r",stdin);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        char color,point;int col=0;
        cin>>color>>point;
        if(color=='D')  col=1;
        else if(color=='C')  col=2;
        else if(color=='H')  col=3;
        else if(color=='S')  col=4;
        if(point=='A')  k[col][1]=true;
        else if(point=='T')  k[col][10]=true;
        else if(point=='J')  k[col][11]=true;
        else if(point=='Q')  k[col][12]=true;
        else if(point=='K')  k[col][13]=true;
        else    k[col][point-48]=true;
    }
    int cnt=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(k[i][j]==false)  cnt++;
    cout<<cnt;
    return 0;
}
