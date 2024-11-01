#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int maxn = 2e3 + 10;
int t,n,mxl,q,r,c,l[maxn],ok[12][12][200002],mxr,lstc,hh[200002];
vector<int> s[maxn];
void dfs(int r,int lst,int st)
{
    //cout << r << " : " << st << '\n';
    if(ok[r][lst][st])
        return ;
    //cout << "jump1\n";
    ok[r][lst][st] = 1;
    if(r == 11)
        return ;
    //cout << "jump2\n";
    for(int k=1;k<=n;k++)
    {
        if(k == lst)    continue;
        int curl = l[k];
        for(int i=0;i<curl-1;i++) //find starting
        {
            //cout << r << " id : " << i << " , val : " << s[r][i] << '\n';
            if(s[k][i] != st)   continue;
            //cout << r << " : ok : " << i << '\n';
            for(int j=i+1;j-i+1<=mxl&&j<curl;j++)
            {
                dfs(r+1,k,s[k][j]);
            }
        }
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    //remember to freopen
    cin >> t;
    while(t --)
    {
        //reset
        cin >> n >> mxl >> q;
        int mxv = 0,mnv = INF;
        for(int i=1;i<=n;i++)
        {
            cin >> l[i];
            for(int j=1;j<=l[i];j++)
            {
                int x;
                cin >> x;
                mxv = max(mxv,x);
                mnv = min(mnv,x);
                s[i].push_back(x);
            }
        }
        for(int i=0;i<=10;i++)
            for(int k=0;k<=10;k++)
                for(int j=mnv;j<=mxv;j++)
                    ok[i][k][j] = 0;
        for(int i=mnv;i<=mxv;i++)   hh[i] = 0;
        //offline
        if(n <= 10)
            dfs(1,0,1);
        /*
1
3 3 7
5 1 2 3 4 1
3 1 2 5

3 5 1 6
        */
        if(n <= 1000)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<l[i]-1;j++)
                {
                    if(s[i][j] != 1)    continue;
                    for(int k=j+1;k-j+1<=mxl&&k<l[i];k++)
                    {
                        hh[s[i][k]] = 1;
                    }
                }
            }
        }
        while(q --)
        {
            cin >> mxr >> lstc;
            if(lstc < mnv || lstc > mxv)
            {
                cout << "0\n";
                continue;
            }
            if(n <= 10)
            {
                int flag = 0;
                for(int i=1;i<=n;i++)
                {
                    if(ok[mxr+1][i][lstc])
                    {
                        flag = 1;
                        break;
                    }
                }
                cout << flag << '\n';
                continue;
            }
            if(mxr == 1)
            {
                cout << hh[lstc] << '\n';
                continue;
            }

        }
    }


    return 0;
}
