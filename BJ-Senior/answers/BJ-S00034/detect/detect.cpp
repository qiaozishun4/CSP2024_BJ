#include <bits/stdc++.h>
using namespace std;
struct information
{
    int dc,vc,ac;
};
struct remember
{
    int st,en;
};
bool cmp(remember a,remember b)
{
    return a.en<b.en;
}
information car[100005];
int test[100005];
bool used[100005];
remember rem[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    int n,m,l,v;
    int anscar,anstest;
    double du,au,vu,vt,alld,dut;
    while(T--)
    {
        int sum=1;
        cin>>n>>m>>l>>v;
        anscar=0;
        anstest=0;
        memset(used,0,sizeof(used));
        for(int i=1;i<=n;i++)
        {
            cin>>car[i].dc>>car[i].vc>>car[i].ac;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>test[i];
        }
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            du=car[i].dc;
            vu=car[i].vc;
            au=car[i].ac;
            flag=0;
            if(au>=0)
            {
                for(int i=1;i<=m;i++)
                {
                    if(du>test[i])
                    {
                        //flag=0;
                    }//
                    else
                    {
                        dut=test[m]-du;
                        vt=sqrt(vu*vu+2*au*dut);
                        if(vt>v)
                        {
                            flag=1;
                            rem[sum].st=min(rem[sum].st,rem[sum].en);
                            rem[sum].en=max(rem[sum].st,rem[sum].en);
                            sum++;
                            break;
                            //used[m]=1;
                        }
                    }
                }


            }
            else
            {
                flag=0;
                int temp=m;
                for(int i=m;i>=1;i--)
                {
                    if(du>test[i])
                    {
                        break;
                    }
                    else
                    {
                        dut=test[i]-du;
                        if(vu*vu+2*au*dut<0)
                        {
                            continue;
                        }
                        vt=sqrt(vu*vu+2*au*dut);
                        if(vt>v)
                        {
                            flag=1;
                            temp=i;
                            break;
                        }
                    }

                }
                if(flag==1)
                {
                    rem[sum].st=du;
                    rem[sum].en=temp;
                    for(int i=1;i<=m;i++)
                    {
                        if(rem[sum].st<test[i])
                        {
                            rem[sum].st=test[i];
                            break;
                        }
                    }
                    rem[sum].st=min(rem[sum].st,rem[sum].en);
                    rem[sum].en=max(rem[sum].st,rem[sum].en);
                    sum++;
                    //used[temp]=1;
                }

            }
            if(flag==1)
            {
                anscar++;
            }
        }
        /*
        for(int i=1;i<=m;i++)
        {
            if(used[i]==1)
            {
                anstest++;
            }

        }
        anstest=m-anstest;
        */
        sort(rem+1,rem+sum,cmp);
        sum--;
        long long tt,ttsum=1;
        //tt=rem[1].en;
        while(ttsum<=sum)
        {
            tt=rem[ttsum].en;
            anstest++;
            while(rem[++ttsum].st<=tt)
            {
                if(ttsum>sum) break;
            }
        }
        cout<<anscar<<" "<<m-anstest<<endl;
    }
    return 0;
}
