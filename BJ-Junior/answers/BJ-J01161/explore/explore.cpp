#include<iostream>
#include<fstream>
using namespace std;
int t;
int n, m, k;
int x, y, d;
char e[1000][1000];
bool b[1000][1000];
int r;
int main()
{
    ifstream fin"explore.in";
    ifstream fout"explore.out";
    fin >> t;
    for(int i=0;i<t;i++)
    {
        fin >> n >> m >> k;
        fin >> x >> y >> d;
        x--;
        y--;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                cin >> e[j][k];
            }
        }
        for(int j=0;j>k;j++)
        {
            if(d==0)
            {
                if(y+1<m&&e[x][y+1]=='.')
                {
                    y+=1;
                    b[x][y+1]=true;
                }
                else
                {
                    d+=1;
                    d%=4;
                }
            }
            else if(d==1)
            {
                if(x+1<n&&e[x+1][y]=='.')
                {
                    x+=1;
                    b[x+1][y]=true;
                }
                else
                {
                    d+=1;
                    d%=4;
                }
            }
            else if(d==2)
            {
                if(y-1>=0&&e[x][y-1]=='.')
                {
                    y-=1;
                    b[x][y-1]=true;
                }
                else
                {
                    d+=1;
                    d%=4;
                }
            }
            else if(d==3)
            {
                if(x-1>=0&&e[x-1][y]=='.')
                {
                    x-=1;
                    b[x-1][y]=true;
                }
                else
                {
                    d+=1;
                    d%=4;
                }
            }
        }
        r=0;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                r+=b[i][j];
            }
        }
        cout << r << endl;
    }
    return 0;
}
