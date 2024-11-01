#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int N=1e5+10;
int d[N],v[N],a[N],p[N];
int pos[N];//表示向右边最远到哪个摄像头
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,l,vm,ans=0;
        cin>>n>>m>>l>>vm;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>p[i];
        sort(p+1,p+1+m);
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0){
                if(v[i]>vm&&d[i]<=p[m]){
                    ans++;
                    int j=upper_bound(p+1,p+1+m,d[i])-p;
                    //if(pos[j]!=0)pos[j]=min(pos[j],m);
                    //else pos[j]=m;
                    pos[j]=m;
                }
            }

            if(a[i]>0)
            {
                if(v[i]>vm){
                    if(d[i]<=p[m])ans++;
                    continue;
                }
                double x=(vm*vm-v[i]*v[i])/(2.0*a[i]);
                int j=upper_bound(p+1,p+1+m,x+d[i])-p;
                if(j<=m){
                    ans++;
                    //if(pos[j]!=0)pos[j]=min(pos[j],m);
                    //else pos[j]=m;
                    pos[j]=m;
                }
            }

            if(a[i]<0)
            {
                if(v[i]<=vm)continue;
                double x=(vm*vm-v[i]*v[i])/(2.0*a[i]);
                int k=lower_bound(p+1,p+1+m,d[i])-p;//大与他初始位置的探测器
                int j=lower_bound(p+1,p+1+m,x+d[i])-p-1;//小于他速度达标位置的探测器
                //if(k>m||j<k)continue;
                if(j<=m&&p[j]>=d[i])
                {
                    ans++;
                    pos[k]=j;
                }
                //ans++;
                //pos[k]=j;
                //cout<<k<<" "<<j<<endl;
            }
        }

        //for(int i=1;i<=m;i++)cout<<pos[i]<<" ";
        cout<<ans<<" ";

        int cnt=0,mr=0;
        for(int i=1;i<=m;i++)
        {
            if(pos[i]==0||i<=mr)cnt++;
            else mr=pos[i];
        }
        cout<<cnt<<endl;
    }
    return 0;
}
