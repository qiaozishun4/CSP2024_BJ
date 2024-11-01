#include<bits/stdc++.h>
#define map unordered_map
using namespace std;
int l[100005];
map<int,map<int,int> > p;
struct T
{
    int cnt,n;
    friend bool operator<(T a,T b)
    {
        if(a.cnt!=b.cnt)return a.cnt<b.cnt;
        return a.n<b.n;
    }
    friend T operator +(T a,T b)
    {
        a.cnt+=b.cnt;
        if(b.cnt==1&&a.cnt==2&&a.n==b.n)a.cnt=1;
        if(a.cnt>2)a.cnt=2;
        if(a.n==0)a.n=b.n;
        return a;
    }
};
bool tmp[200005];
int s[200005];
int cnts;
//map<int,map<int,int> >cnt;
map<int,map<int,T> >check;
map<int,map<int,T> >mp;
int d[100005],c[100005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(l,0,sizeof(l));
        p.clear();
        memset(tmp,0,sizeof(tmp));
        cnts=0;
        check.clear();
        mp.clear();
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            //queue<int> q;
            for(int j=1;j<=l[i];j++)
            {
                //int x;
                cin>>p[i][j];
                if(!tmp[p[i][j]])
                {
                    tmp[p[i][j]]=1;
                    s[++cnts]=p[i][j];
                }
                //pos[i][p[i][j]][++cnt[i][p[i][j]]]=j;
                for(int t=1;t<k&&t<j;t++)
                {
                    check[p[i][j-t]][p[i][j]]=check[p[i][j-t]][p[i][j]]+(T){1,i};
                }
            }
        }
        int maxr=0;
        for(int i=1;i<=q;i++)
        {
            //int r,c;
            cin>>d[i]>>c[i];
            maxr=max(maxr,d[i]);
            /**/
            //cout<<mp[r][c].cnt<<endl;
        }
        for(int r=1;r<=maxr;r++)
        {
            for(int i=1;i<=cnts;i++)
            {
                for(int j=1;j<=cnts;j++)
                {
                    if(r==1&&j>1)break;
                    //T m=mp[r][s[i]];
                    if(r==1)
                    {
                        mp[r][s[i]]=mp[r][s[i]]+check[1][s[i]];
                        //continue;
                    }
                    else if(mp[r-1][s[j]].cnt==1&&check[s[j]][s[i]].cnt==1&&mp[r-1][s[j]].n==check[s[j]][s[i]].n)
                    {
                        //continue;
                    }
                    else if(mp[r-1][s[j]].cnt==0)
                    {
                        //continue;
                    }
                    else mp[r][s[i]]=check[s[j]][s[i]]+mp[r][s[i]];
                    //cout<<r<<" "<<s[i]<<" "<<s[j]<<" "<<mp[r][s[i]].cnt<<endl;
                    //mp[r][s[i]]=max(mp[r][s[i]],m);
                }
            }
        }
        for(int i=1;i<=q;i++)
        {
            if(mp[d[i]][c[i]].cnt)
            cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
