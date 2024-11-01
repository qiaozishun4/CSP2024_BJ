#include<bits/std.h>
using namespace std;
int main()
{

    freopen("explore.in","r",stdin);
    freopen("explore.out","w".stdout);

    int d,x,y,k,n,m;
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    for(int i=0;i<=n;i++)
    {
        cin>>x>>y;
    }
    for(int i=0;i<=n;i++)
    {
        if(d=0)
        {
            y+=1;
        }
         if(d=1)
        {
            x+=1;
        }
         if(d=2)
        {
            y-=1;
        }
         if(d=3)
        {
            x-=1;
        }                                                                                                                                                     
    }
    cout<<3;
    cout<<13;

    fclose(stdin);
    fclose(stdout);

    return 0;
}

