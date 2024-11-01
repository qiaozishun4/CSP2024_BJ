#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a;
    cin>>a;
    short b[5][14]={0};
    for(int i=1;i<=a;i++)
    {
        char c;
        char d;
        cin>>c>>d;
        if(c=='C')
        {
            if(int(d)-int('1')>=9||int(d)-int('1')==0)
            {
                if(d=='A')
                {
                    b[1][0]=1;
                }
                else if(d=='T')
                {
                    b[1][9]=1;
                }
                else if(d=='J')
                {
                    b[1][10]=1;
                }
                else if(d=='Q')
                {
                    b[1][11]=1;
                }
                else if(d=='K')
                {
                    b[1][12]=1;
                }
            }

            else
            {
                b[1][int(d)-int('1')]=1;
            }



        }
        else if(c=='H')
        {
                if(d=='A')
                {
                    b[2][0]=1;
                }
                else if(d=='T')
                {
                    b[2][9]=1;
                }
                else if(d=='J')
                {
                    b[2][10]=1;
                }
                else if(d=='Q')
                {
                    b[2][11]=1;
                }
                else if(d=='K')
                {
                    b[2][12]=1;
                }
                else
                {
                    b[2][int(d)-int('1')]=1;
                }


        }
        else if(c=='S')
        {

                if(d=='A')
                {
                    b[3][0]=1;
                }
                else if(d=='T')
                {
                    b[3][9]=1;
                }
                else if(d=='J')
                {
                    b[3][10]=1;
                }
                else if(d=='Q')
                {
                    b[3][11]=1;
                }
                else if(d=='K')
                {
                    b[3][12]=1;
                }
                else
                {
                    b[3][int(d)-int('1')]=1;
                }

        }
        else
        {

                if(d=='A')
                {
                    b[4][0]=1;
                }
                else if(d=='T')
                {
                    b[4][9]=1;
                }
                else if(d=='J')
                {
                    b[4][10]=1;
                }
                else if(d=='Q')
                {
                    b[4][11]=1;
                }
                else if(d=='K')
                {
                    b[4][12]=1;
                }
                else
                {
                    b[4][int(d)-int('1')]=1;
                }
        }

    }
    int ans=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=0;j<13;j++)
        {

            if(b[i][j]==0)
            {

                ans++;
            }

        }
    }
    cout << ans<< endl;
    return 0;
}
