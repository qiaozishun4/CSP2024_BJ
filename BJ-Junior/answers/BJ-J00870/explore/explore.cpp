#include<iostream>
#include<cstdio>
using namespace std;

long long T;
char a[1005][1005];
bool flag[1005][1005];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >>T;
    while(T--)
    {
        long long n , m , k ;
        cin >>n >>m >>k ;
        long long x , y , d ;
        cin >>x>>y>>d ;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                cin >>a[i][j];
                flag[i][j] = false;
            }
        }
        flag[x][y] = true;
        for(int i = 1 ; i <= k ; i++)
        {
            int xx , yy ;
            if(d == 0 )
            {
                xx = x;
                yy = y +1;
            }
            else if(d == 1 )
            {
                xx = x+1;
                yy = y;
            }
            else if( d == 2 )
            {
                xx = x;
                yy = y - 1 ;
            }
            else if(d == 3 )
            {
                xx = x - 1 ;
                yy = y;
            }
            if( 1 <= xx && xx <= n
               && 1 <= yy && yy <= m
               && a[xx][yy] == '.')
            {
                x = xx;
                y = yy ;
                flag[x][y] = true;

            }
            else d = (d +1 ) % 4;


        }
        long long ans = 0 ;
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
                if(flag[i][j])ans++;
        cout <<ans <<"\n";
        }


    return 0;
}


