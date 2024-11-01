#include<iostream>
using namespace std;
int c[4][13];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n;
    char a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(a=='D')
        {
            if(b=='A')
            {
                c[0][0]=1;
            }else if(b=='2')
            {
                c[0][1]=1;
            }else if(b=='3')
            {
                c[0][2]=1;
            }else if(b=='4')
            {
                c[0][3]=1;
            }else if(b=='5')
            {
                c[0][4]=1;
            }else if(b=='6')
            {
                c[0][5]=1;
            }else if(b=='7')
            {
                c[0][6]=1;
            }else if(b=='8')
            {
                c[0][7]=1;
            }else if(b=='9')
            {
                c[0][8]=1;
            }else if(b=='T')
            {
                c[0][9]=1;
            }else if(b=='J')
            {
                c[0][10]=1;
            }else if(b=='Q')
            {
                c[0][11]=1;
            }else if(b=='K')
            {
                c[0][12]=1;
            }
        }else if(a=='C')
        {
            if(b=='A')
            {
                c[1][0]=1;
            }else if(b=='2')
            {
                c[1][1]=1;
            }else if(b=='3')
            {
                c[1][2]=1;
            }else if(b=='4')
            {
                c[1][3]=1;
            }else if(b=='5')
            {
                c[1][4]=1;
            }else if(b=='6')
            {
                c[1][5]=1;
            }else if(b=='7')
            {
                c[1][6]=1;
            }else if(b=='8')
            {
                c[1][7]=1;
            }else if(b=='9')
            {
                c[1][8]=1;
            }else if(b=='T')
            {
                c[1][9]=1;
            }else if(b=='J')
            {
                c[1][10]=1;
            }else if(b=='Q')
            {
                c[1][11]=1;
            }else if(b=='K')
            {
                c[1][12]=1;
            }
        }else if(a=='H')
        {
            if(b=='A')
            {
                c[2][0]=1;
            }else if(b=='2')
            {
                c[2][1]=1;
            }else if(b=='3')
            {
                c[2][2]=1;
            }else if(b=='4')
            {
                c[2][3]=1;
            }else if(b=='5')
            {
                c[2][4]=1;
            }else if(b=='6')
            {
                c[2][5]=1;
            }else if(b=='7')
            {
                c[2][6]=1;
            }else if(b=='8')
            {
                c[2][7]=1;
            }else if(b=='9')
            {
                c[2][8]=1;
            }else if(b=='T')
            {
                c[2][9]=1;
            }else if(b=='J')
            {
                c[2][10]=1;
            }else if(b=='Q')
            {
                c[2][11]=1;
            }else if(b=='K')
            {
                c[2][12]=1;
            }
        }else
        {
            if(b=='A')
            {
                c[3][0]=1;
            }else if(b=='2')
            {
                c[3][1]=1;
            }else if(b=='3')
            {
                c[3][2]=1;
            }else if(b=='4')
            {
                c[3][3]=1;
            }else if(b=='5')
            {
                c[3][4]=1;
            }else if(b=='6')
            {
                c[3][5]=1;
            }else if(b=='7')
            {
                c[3][6]=1;
            }else if(b=='8')
            {
                c[3][7]=1;
            }else if(b=='9')
            {
                c[3][8]=1;
            }else if(b=='T')
            {
                c[3][9]=1;
            }else if(b=='J')
            {
                c[3][10]=1;
            }else if(b=='Q')
            {
                c[3][11]=1;
            }else if(b=='K')
            {
                c[3][12]=1;
            }
        }
    }
    int k=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(c[i][j]==0)
            {
                k++;
            }
        }
    }
    cout<<k;
    fclose(stdin);
    fclose(stdout);
    return 0;
}