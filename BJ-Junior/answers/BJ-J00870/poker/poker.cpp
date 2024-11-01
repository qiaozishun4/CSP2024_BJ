#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

long long n ;
bool flag[60][5];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w" , stdout );
    cin >>n ;
    for(int i = 1 ; i <= n ; i++)
    {
        char a , b ;
        cin >>a >>b ;
        if( a == 'D' )
        {
            if('1' <= b && b <= '9' )
            {
                flag[b-'0'][1] = true;

            }
            else
            {
                if( b == 'A' )flag[1][1] = true;
                else if( b == 'T' )flag[10][1] = true;
                else if( b == 'J' )flag[11][1] = true;
                else if( b == 'Q' )flag[12][1] = true;
                else if( b == 'K' )flag[13][1] = true;
            }

        }
        else  if( a == 'C' )
        {
            if('1' <= b && b <= '9' )
            {
                flag[b-'0'][2] = true;

            }
            else
            {
                if( b == 'A' )flag[1][2] = true;
                else if( b == 'T' )flag[10][2] = true;
                else if( b == 'J' )flag[11][2] = true;
                else if( b == 'Q' )flag[12][2] = true;
                else if( b == 'K' )flag[13][2] = true;
            }

        }
        else if( a == 'H' )
        {
            if('1' <= b && b <= '9' )
            {
                flag[b-'0'][3] = true;

            }
            else
            {
                if( b == 'A' )flag[1][3] = true;
                else if( b == 'T' )flag[10][3] = true;
                else if( b == 'J' )flag[11][3] = true;
                else if( b == 'Q' )flag[12][3] = true;
                else if( b == 'K' )flag[13][3] = true;
            }

        }
        else if(a == 'S' )
        {
            if('1' <= b && b <= '9' )
            {
                flag[b-'0'][4] = true;

            }
            else
            {
                if( b == 'A' )flag[1][4] = true;
                else if( b == 'T' )flag[10][4] = true;
                else if( b == 'J' )flag[11][4] = true;
                else if( b == 'Q' )flag[12][4] = true;
                else if( b == 'K' )flag[13][4] = true;
            }

        }
    }
    long long ans = 0 ;
    for(int i = 1 ; i <= 13 ; i++ )
    {
        for(int j = 1 ; j <= 4 ; j++)
        {
            if( flag[i][j] == false)ans++;
        }

    }
    cout << ans ;


    return 0;
}

