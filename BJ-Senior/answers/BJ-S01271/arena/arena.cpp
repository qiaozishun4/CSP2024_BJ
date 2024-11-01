#include<bits/stdc++.h>
using namespace std;
long long n,m,aa[1010100],b[1010100],ans[1010100],lastt[1010100],tmp[1010100],x[5];
char c[30][100100];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>aa[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    for(int yy=1;yy<=log2(2*n-1);yy++)
    {
    for(int i=1;i<=(2*n-1)/pow(2,yy);i++)
    {
       // cout<<yy<<" "<<i
        cin>>c[yy][i];
    }
    }

    int q;
    cin>>q;
    while(q--)
    {
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++)
        {
            ans[i]=aa[i]^(x[i%4]);
        //    cout<<ans[i]<<endl;
        }
       // cout<<endl<<endl;
       long long ansssss=0;
        for(int h=1;h<=n;h++)
        {
            int uu=b[h];
            for(int j=1;j<=uu;j++) lastt[j]=j
                ;
            int lun=1;
            while(uu>1)
            {
            for(int j=1;j<=uu;j++)
            {
                if(j%2==0) continue;
              //  cout<<j<<" "<<ans[j]<<" "<<c[lun][(j+1)/2]<<" "<<lun<<" "<<lastt[j]<<" "<<lastt[j+1]<<endl;
                if((c[lun][(j+1)/2]=='0'&&ans[j]>=lun)||(c[lun][(j+1)/2]=='1'&&ans[j+1]<lun))
                {tmp[(j+1)/2]=lastt[j];}
                //cout<<"cqs"<<endl;}
                else tmp[(j+1)/2]=lastt[j+1];
            }
            lun++;
            uu/=2;
            for(int j=1;j<=uu;j++) lastt[j]=tmp[j];
            }
            ansssss^=(lastt[1]*h);
        }
        cout<<ansssss<<endl;
    }
    return 0;
}
