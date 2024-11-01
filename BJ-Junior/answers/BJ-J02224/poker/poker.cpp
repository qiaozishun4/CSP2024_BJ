#include<bits/stdc++.h>
using namespace std;
int a[10][20];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;

        if(c=='D')
        {
            char x;
            cin>>x;
            int num;
            if(x>'1'&&x<='9')num=x-'0';
            if(x=='T')num=10;
            if(x=='J')num=11;
            if(x=='Q')num=12;
            if(x=='K')num=13;
            if(x=='A')num=1;
            a[1][num]++;
        }
        if(c=='S')
        {
            char x;
            cin>>x;
            int num;
            if(x>'1'&&x<='9')num=x-'0';
            if(x=='T')num=10;
            if(x=='J')num=11;
            if(x=='Q')num=12;
            if(x=='K')num=13;
            if(x=='A')num=1;
            a[2][num]++;
        }
        if(c=='C')
        {
            char x;
            cin>>x;
            int num;
            if(x>'1'&&x<='9')num=x-'0';
            if(x=='T')num=10;
            if(x=='J')num=11;
            if(x=='Q')num=12;
            if(x=='K')num=13;
            if(x=='A')num=1;
            a[3][num]++;
        }
        if(c=='H')
        {
            char x;
            cin>>x;
            int num;
            if(x>'1'&&x<='9')num=x-'0';
            if(x=='T')num=10;
            if(x=='J')num=11;
            if(x=='Q')num=12;
            if(x=='K')num=13;
            if(x=='A')num=1;
            a[4][num]++;
        }
    }
    int cnt=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(!a[i][j])cnt++;
    cout<<cnt;
    return 0;
}