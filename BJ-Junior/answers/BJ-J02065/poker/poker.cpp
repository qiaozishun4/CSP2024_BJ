#include<bits/stdc++.h>

using namespace std;

int n,p1[5],p2[15],sum;
string s;
bool po[5][15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s[0]=='D')
            p1[i]=1;
        else if(s[0]=='C')
            p1[i]=2;
        else if(s[0]=='H')
            p1[i]=3;
        else if(s[0]=='S')
            p1[i]=4;
        if(s[1]=='A')
            p2[i]=1;
        else if(s[1]=='J')
            p2[i]=11;
        else if(s[1]=='Q')
            p2[i]=12;
        else if(s[1]=='K')
            p2[i]=13;
        else if(s[1]=='T')
            p2[i]=10;
        else
        {
            for(int j=49;j<=57;j++)
            {
                if(s[1]==j)
                    p2[i]=j-48;
            }
        }
        po[p1[i]][p2[i]]=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(po[i][j]==0)
            {
                sum++;
            }
        }
    }
    printf("%d",sum);
    return 0;
}
