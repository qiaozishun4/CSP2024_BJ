#include <bits/stdc++.h>
using namespace std;


char cxy[1010][1010];


int main()
{

    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);


    int t,n,m,k;
    int x,y,x1,y1,d;
    int ans;

    cin >> t;

    for(int i=1;i<=t;i++)
    {

        cin >> n >> m >> k;
        cin >> x >> y >> d;

        for(int j=1;j<=n;j++)
            for(int l=1;l<=m;l++)
                cin >> cxy[j][l];

        ans=1;
        for(int p=1;p<=k;p++)
        {


            if(d=0) {x1=x; y1=y+1;}
            else if(d=1) {x1=x+1; y1=y;}
            else if(d=2) {x1=x; y1=y-1;}
            else if(d=3) {x1=x-1; y1=y;}

            if(x1>=0 && x1<=n && y1>=1 && y1<=m && cxy[x1][y1]=='.')
            {
                x=x1; y=y1;
                ans+=1;
            }
            else d= (d + 1) % 4;
        }

        cout << site << endl;
        }

    return 0;
}
