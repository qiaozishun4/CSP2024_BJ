//zhe zhi shi ban cheng pin !
//fhz
#include<bits/stdc++.h>
using namespace std;
int d[100007];
int v[100007];
int a[100007];
int p[100007];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++)//
        {
            //how far does it drive when speed at max
            //( pow(V) - pow(v[i]) )  /  ( 2 * a[i] )

            if(a[i]>0&&v[i]<=V)//drive faster
            {
                if((V*V)-(v[i]*v[i]) < (L * (2*a[i])) )
                {//it speed>max sometime
                    //but we do not know who can find it or not
                    bool flag=0;
                    //flag=0,nobody found
                    //flag=1,somebody found
                    for(int j=1;j<=m;j++)
                    {
                        if(p[j]<d[i]) continue;
                        if((p[j]-d[i]) * (2*a[i]) <= ((V*V)-(v[i]*v[i]))) continue;
                        //p[j]-d[i] <= max speed far
                        flag=1;
                        //cout<<p[j]<<endl;
                    }
                    if(flag==1)
                    {
                        ans++;
                    }
                }
                else
                {//its speed<max forever
                    //do nothing
                }
            }
            else if(a[i]<0&&v[i]>=V)//drive slower
            {
                if((V*V)-(v[i]*v[i]) < (L * (2*a[i])) || (1))
                {//always do this
                    //but we do not know who can find it or not
                    bool flag=0;
                    //flag=0,nobody found
                    //flag=1,somebody found
                    for(int j=1;j<=m;j++)
                    {
                        if(p[j]<d[i]) continue;
                        if((p[j]-d[i]) * (2*a[i]) <= ((V*V)-(v[i]*v[i]))) continue;
                        //p[j]-d[i] >= max speed far
                        flag=1;
                        //cout<<p[j]<<endl;
                    }
                    if(flag==1)
                    {
                        ans++;
                    }
                }
                else
                {//empty
                    //do nothing
                }
            }
            else if(a[i]==0)
            {//drive at a same speed forever
                if(v[i]>V)
                {
                    bool flag=0;
                    //flag=0,nobody found
                    //flag=1,somebody found
                    for(int j=1;j<=m;j++)
                    {
                        if(p[j]>=d[i])
                        {
                            flag=1;
                        }
                    }
                    if(flag==1)
                    {
                        ans++;
                    }
                }
                else
                {

                }
            }
            else if(a[i]>0&&v[i]>V)
            {//start fast and faster
                bool flag=0;
                //flag=0,nobody found
                //flag=1,somebody found
                for(int j=1;j<=m;j++)
                {
                    if(p[j]>=d[i])
                    {
                        flag=1;
                    }
                }
                if(flag==1)
                {
                    ans++;
                }
            }
            else if(a[i]<0&&v[i]<V)
            {//start slow and slower

            }
        }
        cout<<ans<<" "<<ans<<endl;
    }
    return 0;
}
