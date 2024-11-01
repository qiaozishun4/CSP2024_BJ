#include<bits/stdc++.h>
using namespace std;

int main()
{

    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int k;
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n, m,x2,y2,d;
        bool a[1005][1005];
        bool b[1005][1005];
        cin >>n >>m >> k;
        int ans = 1;
        cin >>x2 >>y2 >>d;
        for(int j = 1;j<=n;j++)
        {
            for(int u=1;u<=m;u++)
            {
                char c;
                cin >> c;
                if(c == '.')
                {
                    b[j][u]=1;
                }
                else
                {
                    b[j][u]=0;
                }
            }
        }
       // for(int j = 1;j<=n;j++)
      //  {
       //     for(int u=1;u<=m;u++)
      //      {
       //         cout <<b[j][u] <<' ';
       //     }
         //   cout <<endl;
     //   }
        for(int j=1;j<=k;j++)
        {
            if(d==0)
            {
                if(b[x2][y2+1] == 0 || y2+1 >m)
                {
                    d = (d+1) %4;//cout <<d <<endl;
                }
                else
                {
                    a[x2][y2+1]++;
                    y2++;
                    //cout << x2 <<' ' << y2<< 'q' << endl;
                }
            }
            else if(d==1)
            {
                if(b[x2+1][y2] == 0 || x2+1 >n)
                {
                    d = (d+1) %4;//cout <<d <<endl;
                }
                else
                {
                    a[x2+1][y2]=1;
                    x2++;//cout << x2 <<' ' << y2<< 'q' << endl;
                }
            }
            else if(d==2)
            {
                if(b[x2][y2-1] == 0 ||   y2-1 <1)
                {
                    d = (d+1) %4;//cout <<d <<endl;
                }
                else
                {
                    a[x2][y2-1]=1;
                    y2--;//cout << x2 <<' ' << y2<< 'q' << endl;
                }
            }
            else
            {
                if(b[x2-1][y2] == 0 || x2-1<1)
                {
                    d = (d+1) %4;//cout <<d <<endl;
                }
                else
                {
                    a[x2-1][y2]=1;
                    x2--;//cout << x2 <<' ' << y2<< 'q' << endl;
                }
            }


        }
        for(int j=1;j<=n;j++)
        {
            for(int u =1;u<=m;u++)
            {
                if(a[j][u])
                {
                    ans++;
                }
            }
        }
        cout <<ans;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
