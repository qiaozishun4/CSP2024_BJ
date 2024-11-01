#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","w",stdout);
    int n;
    cin>>n;
    int a[5][14]={0};
    for(int i=0;i<n;i++)
    {

        char s;
        cin>>s;
        if(s=='D')
        {
            cin>>s;//cout<<s<<endl;
            if(s-'1'>=0 && s-'9'<=0)
            {
                int shu=s-'1'+1;
            //cout<<shu<<endl;
            a[1][shu]=1;
            }
            else
            {
                  if(s=='A')
                    a[1][1]=1;
                    if(s=='T')
                    a[1][10]=1;
                 if(s=='J')
                    a[1][11]=1;
                 if(s=='Q')
                    a[1][12]=1;
                 if(s=='K')
                    a[1][13]=1;
            }
        }
           else   if(s=='C')
        {
            cin>>s;
            if(s-'1'>=0 && s-'9'<=0)
            {
                int shu=s-'1'+1;
            a[2][shu]=1;
            }
            else
            {
                    if(s=='A')
                    a[2][1]=1;
                  if(s=='T')
                    a[2][10]=1;
                 if(s=='J')
                    a[2][11]=1;
                 if(s=='Q')
                    a[2][12]=1;
                 if(s=='K')
                    a[2][13]=1;
            }
        }

           else         if(s=='H')
        {
            cin>>s;
            if(s-'1'>=0 && s-'9'<=0)
            {
                 int shu=s-'1'+1;
            a[3][shu]=1;
            }
            else
            {
                if(s=='A')
                    a[3][1]=1;
                  if(s=='T')
                    a[3][10]=1;
                 if(s=='J')
                    a[3][11]=1;
                 if(s=='Q')
                    a[3][12]=1;
                 if(s=='K')
                    a[3][13]=1;
            }
        }
              else      if(s=='S')
        {

            cin>>s;

            if(s-'2'>=0 && s-'9'<=0)
             {
                 int shu=s-'1'+1;
            a[4][shu]=1;
             }
            else
            {
                if(s=='A')
                    a[4][1]=1;
                  if(s=='T')
                    a[4][10]=1;
                 if(s=='J')
                    a[4][11]=1;
                 if(s=='Q')
                    a[4][12]=1;
                 if(s=='K')
                    a[4][13]=1;
            }
        }

    }
        int ans=52;
        for(int i=1;i<=4;i++)
            for(int j=1;j<=13;j++)
            {
            
                ans-=a[i][j];
            }

        cout<<ans;















    return 0;
}
