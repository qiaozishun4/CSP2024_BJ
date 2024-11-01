#include <bits/stdc++.h>
#include <stack>
using namespace std;
int n,ans,t,x,y,z,m,k,wei,q,l,r,c,a[200005],b[200005];
void find1(int x,int y,int d,int r)//x当前还剩几轮，y目标，d开头，r人。
{
    for(int i=1;i<=wei&&ans==0;i++)
    {
        if(a[i]==y)
        {
            if(x==1)
            {
                for(int j=i-1;j>=i-k+1;j--)
                {
                    if(b[j]==b[i]&&b[j]!=r)
                    {
                        if(a[j]==d)
                        {


                        ans=1;
                        return ;
                        }

                    }




                    //cout<<i<<j<<endl;
                }


            }
            else
            {
                for(int j=i-1;j>=i-k+1;j--)
                {



                    if(b[j]==b[i]&&b[j]!=r)
                    {




                        find1(x-1,a[j],d,b[j]);




                    }
                }
            }
        }
    }
    return ;
}
int main()
{

    freopen("chain.in","r",stdin);


    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)

    {
        cin>>n>>k>>q;
        wei=0;
        for(int i=1;i<=n;i++)

        {
            cin>>l;

            for(int j=wei+1;j<=wei+l;j++)
            {
                cin>>a[j];
                b[j]=i;
            }
            wei+=l;

        }

        while(q--)
        {
            cin>>r>>c;
            int d=1,ren=0;

            ans=0;

            find1(r,c,d,ren);
            if(ans==0)

            {
                cout<<"0"<<endl;
                
            }
            else

            {
                cout<<"1"<<endl;
            }
        }
    }


    return 0;
}

