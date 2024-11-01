#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
long long T;


long long explore()
{
    long long n,m,k,nowx,nowy,nowd;
    long long ans=0;
    char ditu[1005][1005]={};
    cin >> n >> m >> k >> nowx >> nowy >> nowd;
    for (long long i=1;i<=n;i++)
    {
        for (long long j=1;j<=m;j++)
        {
            cin >> ditu[i][j];
        }
    }
    //nowx--;
    //nowy--;
    ditu[nowx][nowy]='T';
    ans++;
    for (int meiyouyongdebianliang=0;meiyouyongdebianliang<k;meiyouyongdebianliang++)
    {
        long xp,yp;
        xp=nowx;
        yp=nowy;
        if(nowd==0)
        {
            yp++;
            
        }
        if(nowd==1)
        {
            xp++;
        }
        if(nowd==2)
        {
            yp--;
        }
        if(nowd==3)
        {
            xp--;
        }
        if(xp>=1 && xp<=n && yp>=1 && yp<=m && ditu[xp][yp]!='x')
        {
            /*for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=m;j++)
                {
                    cerr << ditu[i][j];
                }
                cerr << endl;
            }
            cerr<<endl;*/
            ditu[nowx][nowy]='o';
            if(ditu[xp][yp]=='.')
            {
                ans++;
            }
            ditu[xp][yp]='T';
            nowx=xp;
            nowy=yp;
        }
        else
        {
            nowd+=1;
            nowd%=4;
        }
    }
    return ans;

}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    
    cin >> T;
    for (int i=0;i<T;i++)
    {
        cout << explore() << endl;
    }
}