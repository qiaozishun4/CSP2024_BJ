#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(;t>0;t--)
    {
       int m,n,k,w[4],d,ans=0;
       cin>>m>>n>>k;
       cin>>w[1]>>w[2]>>d;
       bool s[1005][1005]={0};
       bool p[1005][1005]={0};
       for(int i=1;i<=m;i++)
       {
           for(int j=1;j<=n;j++)
           {
                char x;
                cin>>x;
                if(x=='.')
               {
                   s[i][j]=1;
               }
           }

       }
       for(int i=1;i<=k;i++)
       {
           if(d==0)
           {
               if(s[w[1]][w[2]+1]!=0)
               {

                   if(p[w[1]][w[2]+1]==0)
                   {
                       p[w[1]][w[2]+1]=1;
                       ans++;

                   }
                   w[2]++;
               }
               else
               {
                   d++;

               }
           }
           else if(d==1)
           {
               if(s[w[1]+1][w[2]]!=0)
               {

                   if(p[w[1]+1][w[2]]==0)
                   {
                       p[w[1]+1][w[2]]=1;
                       ans++;

                   }
                   w[1]++;
               }
               else
               {
                   d++;

               }
           }
            else if(d==2)
           {
               if(s[w[1]][w[2]-1]!=0)
               {

                   if(p[w[1]][w[2]-1]==0)
                   {
                       p[w[1]][w[2]-1]=1;
                       ans++;

                   }
                   w[2]--;
               }
               else
               {
                   d++;

               }
           }
            else
           {
               if(s[w[1]-1][w[2]]!=0)
               {

                   if(p[w[1]-1][w[2]]==0)
                   {
                       p[w[1]-1][w[2]]=1;
                       ans++;

                   }
                   w[1]--;
               }
               else
               {
                   d=0;

               }
           }


       }

        cout<<ans+1<<endl;

    }


    return 0;
}
