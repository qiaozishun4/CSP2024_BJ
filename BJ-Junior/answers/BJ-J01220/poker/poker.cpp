#include<bits/stdc++.h>
using namespace std;
int n,i,j,x,y,z=0;
string a;
int b[5][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a[0]=='D')
            x=1;
        if(a[0]=='C')
            x=2;
        if(a[0]=='H')
            x=3;
        if(a[0]=='S')
            x=4;
        if(a[1]=='A')
            y=1;
        if(a[1]=='2')
            y=2;
        if(a[1]=='3')
            y=3;
        if(a[1]=='4')
            y=4;
        if(a[1]=='5')
            y=5;
        if(a[1]=='6')
            y=6;
        if(a[1]=='7')
            y=7;
        if(a[1]=='8')
            y=8;
        if(a[1]=='9')
            y=1;
        if(a[1]=='T')
            y=10;
        if(a[1]=='J')
            y=11;
        if(a[1]=='Q')
            y=12;
        if(a[1]=='K')
            y=13;
        b[x][y]++;
    }
    for(i=1;i<=4;i++)
        for(j=1;j<=13;j++)
            if(b[i][j]==0)
                z++;
    cout<<z<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}