#include <iostream>
#include <algorithm>
using namespace std;
int n,k,q;
int s[1010][2010],l[1010],x[1000010],y[1000010];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cin >> l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin >> s[i][j];
                if(s[i][j]==1)
                {
                    x[++cnt]=i;
                    y[cnt]=j;
                    //cout << x[cnt] << " " << y[cnt] << endl;
                }
            }
        }
        while(q--)
        {
            int r,c;
            cin >> r >> c;
            int flag=0;
            for(int i=1;i<=cnt;i++)
            {
                for(int j=y[i]+1;j<=min(y[i]+k-1,l[x[i]]);j++)
                {
                    if(s[x[i]][j]==c)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1) break;
            }
            cout << flag << endl;
        }
    }
    return 0;
}