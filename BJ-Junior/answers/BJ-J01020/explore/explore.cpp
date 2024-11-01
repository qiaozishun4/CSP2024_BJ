#include<bits/stdc++.h>
using namespace std;
int lkj;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>lkj;
    for(int dddd=1;dddd<=lkj;dddd++)
    {
        char v[1005][1005]={'0'};
        int vis[1005][1005]={0};
        int n,m,a,b,d,k,r=0;

        cin>>n>>m>>k;
        cin>>a>>b>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                   cin>>v[j][i];

            }

        }

        if(k==1)
        {


            if(d==0)
            {

                if(v[a+1][b]=='.')
                 cout<<"1"<<endl;



            }
            if(d==1)
            {

                if(v[a][b+1]=='.')
                    cout<<"1"<<endl;







            }
            if(d==2)
            {

                if(v[a-1][b]=='.')
                 cout<<"1"<<endl;


            }
            if(d==3)
            {

                if(v[a][b-1]=='.')
                 cout<<"1"<<"\n";



            }


               }
               else
               {
                   cout<<min(n-1+m+n+m-1-1-1,k);
               }






    }

}
