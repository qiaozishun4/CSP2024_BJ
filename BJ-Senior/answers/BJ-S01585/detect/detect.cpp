#include<bits/stdc++.h>
using namespace std;
int t;
struct car{
    int d,v,a;
};
int ans1,ans2;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t>0)
    {
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        car c[n];
        int cs[m];
        bool fl1[n],fl2[m];
        for(int i=0;i<n;i++)fl1[i]=false;
        for(int i=0;i<m;i++)fl2[i]=true;
        for(int i=0;i<n;i++)
            cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=0;i<m;i++)
        {
            cin>>cs[i];
            for(int j=0;j<n;j++)
            {
                if((double)(sqrt(pow(c[j].v,2)+2*c[j].a*(cs[i]-c[j].d)))>(double)V&&c[j].d<=cs[i]&&fl1[j]!=true)
                {
                    fl1[j]=true;
                    fl2[i]=false;
                }
            }
        }
        for(int i=0;i<n;i++)
            if(fl1[i]==true)ans1++;
        for(int i=0;i<m;i++)
            if(fl2[i]==false)ans2++;
        cout<<ans1<<' '<<ans2<<endl;
        ans1=0;
        ans2=0;
        t--;
    }
    return 0;
}
