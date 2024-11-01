#include<bits/stdc++.h>
using namespace std;
char a[5][60];
int b[5][60];
int n,c,ans=52;
int main()
{
    cin>>n;
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=2;i++)
            cin>>a[i][j];
        if(a[2][j]=='T')
            c=10;
        else
            if(a[2][j]=='J')
                c=11;
            else
                if(a[2][j]=='Q')
                    c=12;
                else
                    if(a[2][j]=='K')
                        c=13;
                    else
                        if(a[2][j]=='A')
                            c=1;
                        else
                            c=a[2][j]-'0';
        if(a[1][j]=='D')
            b[1][c]++;
        else
            if(a[1][j]=='C')
                b[2][c]++;
            else
                if(a[1][j]=='H')
                    b[3][c]++;
                else
                    b[4][c]++;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
            if(b[i][j]>0)
                ans--;
    }
    cout<<ans;
    return 0;
}
