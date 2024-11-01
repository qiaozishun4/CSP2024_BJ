#include <bits/stdc++.h>
using namespace std;
int d[100050],v[100050],a[100050],p[100050],jishu[100050],chaosu_che[1000][1000];
double v_now,vmax_now[100050];
bool speed_over[100050];
int cls=0;
unsigned long long ans=0;

double jisuan_v(int che_i,int ce_j)
{
    if(a[che_i]==0)
    {
        return double(v[che_i]);
    }
    double vans=sqrt(v[che_i]*v[che_i]+2*a[che_i]*(p[ce_j]-d[che_i]));
    if(vans<0)
    {
        return 0.0;
    }
    else
    {
        return vans;
    }
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,T,m,L,vmaxn;
    cin>>T;
    while(T--)
    {
        v_now=0;
        memset(vmax_now,0,sizeof(vmax_now));
        cls=0;
        ans=0;
        int asd=1;
        cin>>n>>m>>L>>vmaxn;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i])
            {
                asd=0;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)//di n liang che
        {
    //        cout<<"di "<<i<<" liang che"<<endl;
            for(int j=1;j<=m;j++)//pan duan di m ge cesuyi shi chaosu?
            {
                if(d[i]>p[j])
                {
  //                  cout<<"     di "<<j<<" ge cesuyi,guole..."<<endl;
                    continue;
                }
  //              cout<<"     di "<<j<<" ge cesuyi sudu:";
                v_now=jisuan_v(i,j);
  //              cout<<v_now<<endl;
  //              cout<<"             cishi,dao di "<<j<<" ge cesuyi de zuida sudu:";
    //            vmax_now[j]=max(vmax_now[],v_now);
                if(vmax_now[j]<v_now)//j chu de vmax
                {
                    vmax_now[j]=v_now;
                }
   //             cout<<vmax_now[j]<<endl;
                if(v_now>vmaxn)//chaosu
                {
                    chaosu_che[j][jishu[j]]=i;
                    jishu[j]++;
                    speed_over[i]=1;
     //               cout<<"           chaosu!"<<endl;
                }
            }
        }
 /*       cout<<"================================"<<endl;
        int summm=0;
        sort(jishu+1,jishu+m+1);
        int flagg[100050]={0};
        bool flaggg=1;
      //  for(int j=1;j<=m;j++)//j chu chaosu de che
       // {
            for(int e=m;e>=1;e--)
            {
                cout<<chaosu_che[e][jishu[e]]<<endl;
                for(int ii=1;ii<=n;ii++)
                {
                    if(ii==chaosu_che[e][jishu[e]])
                    {
                        flagg[ii]=1;
                    }
                }
                for(int ii=1;ii<=n;ii++)
                {
                    if(!flagg[ii])
                    {
                        flaggg=0;
                    }
                }
                if(flaggg)
                {
                    cls++;
                    break;
                }
            }
        //}
        */
        for(int i=1;i<=n;i++)//chaosu de she
        {
            if(speed_over[i])
            {
                ans++;
            }
        }
        if(asd)
        {
            int asdf=1;
            int cll=0;
            for(int j=1;j<=m;j++)
            {
                for(int i=1;i<=n;i++)
                if(p[j]<v[i])
                {
                    asdf=0;
                }
                if(asdf)
                {
                    cll++;
                }
            }
            cout<<ans<<' '<<cll<<'\n';
        }
        else
        cout<<ans<<' '<<n-ans<<'\n';
    }
    return 0;
}
/*

1
5
5
15
3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2
5
8
9
15


*/
