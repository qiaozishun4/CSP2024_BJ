#include<iostream>
using namespace std;

char str[10000][10000];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    
    int cnt=0;
    int n=0 ,m=0,T=0,k=0,x=0,y=0;
    cin>>T>>n>>m>>k>>x>>y;
    int d;
    cin>>d;
    while(T!=0)
    {

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {

                cin>>str[i][j];
            }
        }
        if(k==1)
        {
            cout<<1;
            break;
        }
        T--
    }

    return 0;
}
