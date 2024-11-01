#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
char a[1005][1005];
bool check(int x,int y)
{
    if(x>n||y>m||x<n||y<n)
    {
        return false;
    }
    if(a[x][y]=='x')
    {
        return false;
    }
    return true;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        if(d==0)
        {
            y++;
            if(check(x,y))
            {
                cout<<"2"<<endl;
            }else{
                cout<<"1"<<endl;
            }
            y--;
        }if(d==1)
        {
            x++;
            //cout<<d;
            if(check(x,y))
            {
                cout<<"2"<<endl;
            }else{
                cout<<"1"<<endl;
            }
            x--;
        }
        if(d==2)
        {
            y--;
            //cout<<d;
            if(check(x,y))
            {
                cout<<"2"<<endl;
            }else{
                cout<<"1"<<endl;
            }
            y++;
        }
        if(d==3)
        {
            x--;
            //cout<<d;
            if(check(x,y))
            {
                cout<<"2"<<endl;
            }else{
                cout<<"1"<<endl;
            }
            x++;
        }
    }
    return 0;
}
