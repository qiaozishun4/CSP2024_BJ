#include<bits/stdc++.h>
using namespace std;
string s;
char x,y;
int a,b,n,sum;
bool num[10][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        x=s[0],y=s[1];
        if(x=='D')a=1;
        if(x=='C')a=2;
        if(x=='H')a=3;
        if(x=='S')a=4;
        if(y>='2'&&y<='9')b=y-'0';
        if(y=='A')b=1;
        if(y=='T')b=10;
        if(y=='J')b=11;
        if(y=='Q')b=12;
        if(y=='K')b=13;
        num[a][b]=true;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!num[i][j])sum++;
        }
    }
    cout<<sum;
    return 0;
}
