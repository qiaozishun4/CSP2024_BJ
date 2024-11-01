#include<bits/stdc++.h>
#define int long long
#define unlimitedhyperlink ll
#define eps 1e-7
using namespace std;
struct node
{
    int d,v,a;
    // 驶入距离，初始速度，加速度
}a[200005];
int det[200005];
bool unlimitedhyperlink[2005][2005];
bool OK[2005];
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof a);
        memset(det,0,sizeof det);
        memset(ll,0,sizeof ll);
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        bool flag1=true,flag2=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].d>>a[i].v>>a[i].a;
            if(a[i].a>0)
                flag1=false;
            if(a[i].a<0)
                flag1=false,flag2=false;
            if(a[i].a==0)
                flag2=false;
        }
        for(int i=1;i<=m;i++)
            cin>>det[i];
        if(n<=20&&m<=20)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i].a>0) //加速
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(a[i].d<=det[j])
                        {
                            double vvv=sqrt(a[i].v*a[i].v+2*a[i].a*(det[j]-a[i].d));
                            if(vvv>V)
                                ll[i][0]=ll[i][j]=true;
                        }
                    }
                    if(ll[i][0])
                        cnt++;//,cout<<"CAR: "<<i<<endl;
                }
                if(a[i].a==0) //匀速
                {
                    for(int j=1;j<=m;j++)
                        if(a[i].d<=det[j]&&a[i].v>V)
                            ll[i][0]=ll[i][j]=true;
                    if(ll[i][0])
                        cnt++;//,cout<<"CAR: "<<i<<endl;
                }
                if(a[i].a<0) //减速
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(a[i].d<=det[j])
                        {
                            double vvv=sqrt(a[i].v*a[i].v+2*a[i].a*(det[j]-a[i].d));
                            if(vvv>V)
                                ll[i][0]=ll[i][j]=true;
                        }
                    }
                    if(ll[i][0])
                        cnt++;//,cout<<"CAR: "<<i<<endl;
                }
            }
            cout<<cnt<<" ";
            //cout<<endl<<"LL:\n";
            //for(int i=1;i<=n;i++)
            //{
            //    for(int j=0;j<=m;j++)
            //        cout<<ll[i][j]<<" ";
            //    cout<<endl;
            //}
            int maxx=pow(2,m);
            int ans1=0,ans2=n+1; //当前使用的数量和最少使用的数量
            for(int i=0;i<=maxx;i++)
            {
                memset(OK,0,sizeof OK);
                ans1=0;
                for(int j=0;j<m;j++)
                {
                    int ls=pow(2,j);
                    if(i&ls) //保留第j+1个
                    {
                        //cout<<j+1<<" ";
                        ans1++;
                        for(int k=1;k<=n;k++)
                        {
                            //cout<<"NOW: "<<ll[k][j+1]<<endl;
                            if((ll[k][j+1]==1))
                                OK[k]=true;
                        }
                    }
                }
                //for(int j=1;j<=n;j++)
                //    cout<<OK[j]<<" ";
                //cout<<endl;
                bool flag=true;
                int ans3=0;
                for(int j=1;j<=n;j++)
                    if(OK[j])
                    {
                        ans3++;
                    }
                if(cnt==ans3)
                    ans2=min(ans2,ans1);
                //cout<<"ANS: "<<ans1<<endl;
                //cout<<"CAR: "<<ans3<<endl;
                //cout<<endl;
            }
            cout<<m-ans2<<endl;
        }
        else if(flag1)
        {
            //ai=0
            int cnt=0;
            for(int i=1;i<=n;i++)
                if(a[i].v>V&&a[i].d<=det[m])
                    cnt++;
            if(cnt==0)
                cout<<cnt<<" "<<m<<endl;
            else
                cout<<cnt<<" "<<m-1<<endl;
        }
        else if(flag2) //一直加速
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i].d<=det[m])
                {
                    double vvv=sqrt(a[i].v*a[i].v+2*a[i].a*(det[m]-a[i].d));
                    if(vvv>V)
                        cnt++;
                }
            }
            if(cnt==0)
                cout<<cnt<<" "<<m<<endl;
            else
                cout<<cnt<<" "<<m-1<<endl;
        }
        else
        {
            cout<<n<<" "<<m<<endl;
        }
    }
    return 0;
}
