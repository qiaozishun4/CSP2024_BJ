#include<iostream>
using namespace std;

int n,m,k,x,y,d;
char a[1010][1010];

bool step()
{
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    int nx=x+dx[d],ny=y+dy[d];
    //cout << "dx["  << d << "]:" << dx[2] << " dy[d]:" << dy[2] << endl;
    if(nx<=n&&nx>=1&&ny<=m&&ny>=1&&a[nx][ny]!='x')
    {
        x=nx,y=ny;
        //cout << "x:" << x << " y:" << y << endl;
        return 1;
    }
    else
    {
        d=(d+1)%4;
        //cout << "d:" << d << ' ';
        return 0;
    }
}

void f()
{
    bool v[1010][1010]{0};
    cin >> n >> m >> k >> x >> y >> d;
    //cout << "d:" << d << ' ';
    //cout << "k:" << k << ' ';
    //cout << x << ' ' << y << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
        }
    }
    v[x][y]=1;
    int cnt=1;
    while(k--)
    {
        if(step())
        {/*
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    cout <<v[i][j] << ' ';
                }
                cout << endl;
            }
            cout << "\n";*/
            if(!v[x][y])
            {
                //cout << cnt << ' ';
                cnt++;
                v[x][y]=1;
                //cout << x << ' ' << y << ' ' << "d:" << d << endl;
            }
        }
    }
    //cout << "\ncnt:";
    cout << cnt << endl;
    //cout << "end.\n";
    return;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        f();
    }
    return 0;
}
