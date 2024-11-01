#include<iostream>
using namespace std;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int T;
    cin>>T;
    for(int k=1;k<=T;k++)
    {
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        int squarevmax=V*V;

        int ans1=0;
        int d[n+1],squarev[n+1],a[n+1],p[m+1];
        bool bedetected[n+1];
        int start[n+1],finish[n+1];
        int numdetect[m+1];

        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>squarev[i]>>a[i];
            squarev[i]=squarev[i]*squarev[i];
            bedetected[i]=0;
            start[i]=-1;
            finish[i]=-1;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(squarev[i]+2*(p[j]-d[i])*a[i]>squarevmax && (p[j]>=d[i]))
                {
                    if(bedetected[i]==0)
                    {
                        bedetected[i]=1;
                        ans1++;
                    }
                    if(start[i]==-1)start[i]=j;
                    finish[i]=j;
                }
            }
        }

        int ans2=m;
        while(1)
        {
            for(int i=1;i<=m;i++)
            {
                numdetect[i]=0;
            }
            for(int i=1;i<=n;i++)
            {
                if(start[i]==-1)continue;
                for(int j=start[i];j<=finish[i];j++)numdetect[j]++;
            }
            int maxnum=-1,maxp;
            for(int i=1;i<=m;i++)
            {
                if(numdetect[i]>maxnum)
                {
                    maxnum=numdetect[i];
                    maxp=i;
                }
            }
            if(maxnum>0)
            {
                ans2--;
                for(int i=1;i<=n;i++)
                {
                    if(maxp>=start[i]&&maxp<=finish[i])start[i]=-1;
                }
            }
            else break;
        }
        cout<<ans1<<" "<<ans2<<endl;
    }

    return 0;
}
