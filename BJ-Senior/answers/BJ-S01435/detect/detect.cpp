#include<bits/stdc++.h>
#define ll long long
const int N=1e4+10, INF=0x7fffffff;
using namespace std;
int T;
int n,m,len,lim,d[N],cnt1,cnt2;
bool a[N][N];
int b[N];
vector<pair<double,double>>t={make_pair(0,0)};
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>len>>lim;
        for(int i=1;i<=n;i++)
        {
            int enter,speed,acc;
            cin>>enter>>speed>>acc;
            if(speed>lim and acc>=0)t.push_back(make_pair(enter,len));
            else
            if(acc>0)t.push_back(make_pair( enter+((lim*lim-speed*speed)/2.0/acc) ,len));
            else
            if(speed>lim and acc<0)t.push_back(make_pair(enter, enter+((lim*lim-speed*speed)/2.0/acc) ));
        }
        for(int i=1;i<=m;i++)
        {
            cin>>d[i];
            for(int j=1;j<=n;j++)
            {
                if(t[j].first<=d[i] and d[i]<=t[j].second){a[i][j]=1;if(!b[j]){cnt1++;/*cout<<j<<endl*/;}b[j]++;}
            }

        }
        for(int i=1;i<=m;i++)
        {
            bool del=1;
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]==1 and b[j]==1)del=0;
            }
            if(del)
            {
                cnt2++;
                for(int j=1;j<=n;j++){a[i][j]=0;b[j]--;}
            }
        }
        cout<<cnt1<<" "<<cnt2;
    }


    return 0;
}
