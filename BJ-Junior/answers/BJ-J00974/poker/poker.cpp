#include<bits/stdc++.h>
using namespace std;
bool poker[5][14];
char tmp1,tmp2;
int b,s,cnt;
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(poker,false,sizeof(poker));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>tmp2>>tmp1;
        if(tmp1=='A')b=1;
        else if(tmp1=='2')b=2;
        else if(tmp1=='3')b=3;
        else if(tmp1=='4')b=4;
        else if(tmp1=='5')b=5;
        else if(tmp1=='6')b=6;
        else if(tmp1=='7')b=7;
        else if(tmp1=='8')b=8;
        else if(tmp1=='9')b=9;
        else if(tmp1=='T')b=10;
        else if(tmp1=='J')b=11;
        else if(tmp1=='Q')b=12;
        else if(tmp1=='K')b=13;
        if(tmp2=='D')s=1;
        else if(tmp2=='C')s=2;
        else if(tmp2=='H')s=3;
        else if(tmp2=='S')s=4;
        poker[s][b]=true;
    }
    for(int i=1;i<=4;i++)
    for(int j=1;j<=13;j++)
    if(poker[i][j]==false)
    {
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}
