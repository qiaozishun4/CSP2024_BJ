#include <bits/stdc++.h>
using namespace std;
int n,a[30][30],ans;
char c,d;
int main()
{

    freopen("poker.in","r",stdin);
    
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>c>>d;
        if(c=='D')

        {


        if(d=='A')
        {
             if(a[1][1]==0)
             {
                 ans++;

                 a[1][1]=1;
             }
        }
        else if(d=='T')
        {
             if(a[1][10]==0)
             {
                 ans++;

                 a[1][10]=1;
             }

        }
        else if(d=='J')
        {
             if(a[1][11]==0)
             {
                 ans++;

                 a[1][11]=1;
             }

        }

        else if(d=='Q')
        {
             if(a[1][12]==0)
             {
                 ans++;

                 a[1][12]=1;
             }

        }

        else if(d=='K')

        {
             if(a[1][13]==0)
             {
                 ans++;

                 a[1][13]=1;
             }

        }


        else
        {
             if(a[1][d-'0']==0)
             {
                 ans++;

                 a[1][d-'0']=1;
             }

        }

        }

        if(c=='C')

        {
if(d=='A')
        {
             if(a[2][1]==0)
             {
                 ans++;

                 a[2][1]=1;
             }
        }
        else if(d=='T')
        {
             if(a[2][10]==0)
             {
                 ans++;

                 a[2][10]=1;
             }

        }
        else if(d=='J')
        {
             if(a[2][11]==0)
             {
                 ans++;

                 a[2][11]=1;
             }

        }

        else if(d=='Q')
        {
             if(a[2][12]==0)
             {
                 ans++;

                 a[2][12]=1;
             }

        }

        else if(d=='K')

        {
             if(a[2][13]==0)
             {
                 ans++;

                 a[2][13]=1;
             }

        }


        else
        {
             if(a[2][d-'0']==0)
             {
                 ans++;

                 a[2][d-'0']=1;
             }

        }
        }

        if(c=='H')
        {
if(d=='A')
        {
             if(a[3][1]==0)
             {
                 ans++;

                 a[3][1]=1;
             }
        }
        else if(d=='T')
        {
             if(a[3][10]==0)
             {
                 ans++;

                 a[3][10]=1;
             }

        }
        else if(d=='J')
        {
             if(a[3][11]==0)
             {
                 ans++;

                 a[3][11]=1;
             }

        }

        else if(d=='Q')
        {
             if(a[3][12]==0)
             {
                 ans++;

                 a[3][12]=1;
             }

        }

        else if(d=='K')

        {
             if(a[3][13]==0)
             {
                 ans++;

                 a[3][13]=1;
             }

        }


        else
        {
             if(a[3][d-'0']==0)
             {
                 ans++;

                 a[3][d-'0']=1;
             }

        }

        }

        if(c=='S')

        {
if(d=='A')
        {
             if(a[4][1]==0)
             {
                 ans++;

                 a[4][1]=1;
             }
        }
        else if(d=='T')
        {
             if(a[4][10]==0)
             {
                 ans++;

                 a[4][10]=1;
             }

        }
        else if(d=='J')
        {
             if(a[4][11]==0)
             {
                 ans++;

                 a[4][11]=1;
             }

        }

        else if(d=='Q')
        {
             if(a[4][12]==0)
             {
                 ans++;

                 a[4][12]=1;
             }

        }

        else if(d=='K')

        {
             if(a[4][13]==0)
             {
                 ans++;

                 a[4][13]=1;
             }

        }


        else
        {
             if(a[4][d-'0']==0)
             {
                 ans++;

                 a[4][d-'0']=1;
             }

        }
        }
    }

    cout<<52-ans;
    return 0;
}
