#include<bits/stdc++.h>

using namespace std;

int t;
char c[1001][1001];
set<pair<int,int> > st;

void work()
{
    st.clear();
    int n,m,k,x,y,d;
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c[i][j];
        }
    }
    st.insert(make_pair(x,y));
    while(k--)
    {
        bool canm=false;
        int xx=x,yy=y;
        switch(d)
        {
            case 0:yy++;break;
            case 1:xx++;break;
            case 2:yy--;break;
            case 3:xx--;break;
        }
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
        {
            if(c[xx][yy]=='.')
            {
                canm=true;
            }
        }
        if(canm)
        {
            x=xx;
            y=yy;
            st.insert(make_pair(x,y));
        }
        else
        {
            d=(d+1)%4;
        }
    }
    cout<<st.size()<<endl;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        work();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
