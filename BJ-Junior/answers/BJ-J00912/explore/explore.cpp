#include <bits/stdc++.h>
using namespace std;

int g;
int row,col,k;
int d;
int nx,ny;
int x,y;
string board[1002];
bool vis[1002][1002];

int dist[4][2];


bool is_ilgal()
{
    //cout <<"x y" <<  x << y <<endl;
    //cout << " d:" << d << endl;
    int nx = x + dist[d][0];
    int ny = y + dist[d][1];
    //cout  <<" nx ny" << nx << ny << endl;
    bool c1 = (nx >= 1);
    bool c2 = (nx <= row );
    bool c3 = (ny >= 1);
    bool c4 = (ny <= col);
    bool c5;

    if (c1&&c2&&c3&&c4)
    {
        //cout << "board: " << board[1]<<endl;

        //cout << nx << ny << ": " << board[nx][ny] << endl;
        c5 = ((board[nx][ny - 1]) == '.');
        //cout << c1 << c2 << c3 << c4 << c5 << endl;
        return (c5 == true);
    }

    //cout << board[nx][ny] << endl;
    //cout << c1 << c2 << c3 << c4 << c5 << endl;
    return false;
}

void cln()
{
    for (int i = 1 ; i <= row ; i ++)
    {
        for (int j = 1 ; j <= col ; j ++)
        {
            vis[i][j] = false;
        }
    }
}

int f()
{
    int ans = 0;

    cln();

    vis[x][y] == true;
    ans ++;
    for (int i = 1 ; i <= k ; i ++)
    {
        //cout << "cnt" << i << endl;
        if(is_ilgal())
        {
            //cout << "if : b=t" <<endl;
            x = x + dist[d][0];
            y = y + dist[d][1];
            //cout << "index " << x << " " << y << endl;
            //cout << "d: " << d << endl;
            if(vis[x][y] == false)
            {
                vis[x][y] == true;
                ans ++;
            }
            //cout << "ans" << ans << endl;
            //cout << endl;
        }
        else
        {
            //cout << "if : b=f" <<endl;
            d = (d + 1) % 4;
            //cout << "index " << x << " " << y << endl;
            //cout << "d " << d << endl;
            //cout << "ans" << ans << endl;
        }
    }

    return ans;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    dist[0][0] = 0;
    dist[0][1] = 1;
    dist[1][0] = 1;
    dist[1][1] = 0;
    dist[2][0] = 0;
    dist[2][1] = -1;
    dist[3][0] = -1;
    dist[3][1] = 0;

    cin >> g;
        //cout << g << endl;
    for (int i = 1 ; i <= g ; i ++)
    {
        cin >> row >> col >> k >> x >> y >> d;
            //cout << row << col << k << x << y << d << endl;
        for (int j = 1 ; j <= row ; j ++)
        {
                cin >> board[j];
        }
#if 0
            for (int i = 1 ; i <= row ; i ++)
                {
                    for (int j  = 1 ; j  <= col; j ++)
                    {
                        //cout <<  board[i][j] << " ";
                    }
                    //cout << endl <<endl;
                }
#endif
        cout  << f() << endl;
    }


    return 0;
}
