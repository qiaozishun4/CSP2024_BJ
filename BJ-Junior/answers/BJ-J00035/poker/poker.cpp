#include<bits/stdc++.h>
using namespace std;
bool f[15][5];//1:D 2:C 3:H 4:S
int n,c;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        int hua,num;
        cin>>a>>b;
        if(b=='A') b='1';
        else if(b=='T') b='9'+1;
        else if(b=='J') b='9'+2;
        else if(b=='Q') b='9'+3;
        else if(b=='K') b='9'+4;
        num=b-'0';
        if(a=='D') hua=1;
        else if(a=='C') hua=2;
        else if(a=='H') hua=3;
        else if(a=='S') hua=4;
        f[num][hua]=true;
    }
    for(int i=1;i<=13;i++)
        for(int j=1;j<=4;j++)
            if(!f[i][j]) c++;
    cout<<c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
