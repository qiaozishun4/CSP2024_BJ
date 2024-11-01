#include <bits/stdc++.h>
#include <iostream>
int t;
int sswitch(char b)
{
    if (b=='A')
    {
        t=1;
        return 0;
    }
    if (b=='2')
    {
        t=2;
        return 0;
    }if (b=='3')
    {
        t=3;
        return 0;
    }if (b=='4')
    {
        t=4;
        return 0;
    }if (b=='5')
    {
        t=5;
        return 0;
    }if (b=='6')
    {
        t=6;
        return 0;
    }if (b=='7')
    {
        t=7;
        return 0;
    }if (b=='8')
    {
        t=8;
        return 0;
    }if (b=='9')
    {
        t=9;
        return 0;
    }if (b=='T')
    {
        t=10;
        return 0;
    }if (b=='J')
    {
        t=11;
        return 0;
    }if (b=='Q')
    {
        t=12;
        return 0;
    }if (b=='K')
    {
        t=13;
        return 0;
    }
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n,ans=0;
    int arr[5][14]={0};
    char a,b;
    std::cin>>n;
    for (int i=0;i<n;i++)
    {
        std::cin>>a>>b;
        if (a=='D')
        {
            sswitch(b);
            arr[1][t]++;
        }
        else if(a=='C')
        {

            sswitch(b);
            arr[2][t]++;
        }
        else if(a=='H')
        {
            sswitch(b);
            arr[3][t]++;

        }
        else if(a=='S')
        {

            sswitch(b);
            arr[4][t]++;
        }
    }
    for (int i=1;i<=4;i++)
    {
        for (int j=1;j<=13;j++)
        {

            if (arr[i][j]==0)
            {
                ans++;
            }

        }
    }
    std::cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
