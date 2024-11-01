#include<bits/stdc++.h>
#define ll long long
const int N=1e5+10, INF=0x7fffffff;
using namespace std;
int T;
int n;
int a[N];bool red[N];//buhui
int last[N];
int c;
vector<pair<int,int>>loops;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        c=0;
        memset(a,0,sizeof(a));
        memset(last,0,sizeof(last));
        memset(red,0,sizeof(red));
        loops.clear();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(last[a[i]]!=0)
            {
                //cout<<last[a[i]]<<" "<<i<<endl;
                loops.push_back(make_pair(last[a[i]],i));
            }
            last[a[i]]=i;
        }
        int len=loops.size();
        int l=loops[0].second;
        c=a[l];if(!len)c=0;
        red[loops[0].first]=red[loops[0].second]=1;
        //cout<<"==="<<endl;
        for(int i=1;i<len;i++)
        {
            //buhui

            if(loops[i].first>=l)
            {
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //cout<<loops[i].first<<" "<<loops[i].second<<endl;
                red[loops[i].first]=red[loops[i].second]=1;
                l=loops[i].second;
                c+=a[l];
            }
        }
        int lastblue=0;
        for(int i=1;i<=n;i++)
        {
            //buhuibuhuibuhui
            if(!red[i])
            {
                if(a[i]==a[lastblue]){c+=a[i];/*cout<<"blue "<<lastblue<<" "<<i<<endl;*/}
                lastblue=i;
            }

        }
        cout<<c<<endl;
    }

    return 0;
}
