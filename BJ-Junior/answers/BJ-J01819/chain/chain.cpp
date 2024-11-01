#include<bits/stdc++.h>
using namespace std;
int s[1005][2005];
int n,k,q,past;
int l[1005];
bool f=0,sf[1005][2005];
void fil(int x,int y,int times,int z)
{
    if(x==y&&times==z)
        f=1;
    if(times>z)
        return ;
    //cout<<x<<" "<<y<<" "<<times<<" "<<z<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=l[i];j++)
        {
            if(s[i][j]==x&&sf[i][j]==0&&past!=i)
            {
                sf[i][j]=1;
                past=i;
                int ttt[2005][100];
               // ttt[0][times]=111;
                for(int p=j+1;p<=l[i];p++)
                {
                    int lo=1;
    //cout<<sf[i][p]<<" "<<s[i][p]<<endl;
                    if(sf[i][p]==0&&lo<k)
                    {
                        sf[i][p]=1;
                        fil(s[i][p],y,times+1,z);
                        ttt[p][times]=1;
                        lo++;
                    }
                }
                for(int p=j+1;p<=l[i];p++)
                {
                    if(ttt[p][times]==1){
                        sf[i][p]=0;
                        ttt[p][times]=0;
                        }
                }
                sf[i][j]=0;
            }
        }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
                sf[i][j]=0;

            }
        }
        while(q--)
        {
            f=0;
            int r,c;
            cin>>r>>c;
            fil(1,c,0,r);
            cout<<f<<endl;
        }
    }
    return 0;
}
