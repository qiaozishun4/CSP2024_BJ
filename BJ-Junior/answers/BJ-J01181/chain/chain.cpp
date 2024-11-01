#include <bits/stdc++.h>

using namespace std;

int t,n,k,q;
struct str
{
    string s;
    int c;
};
int nx[200005];
string s[200005];
struct qe
{
    int num,val;
};
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d%d",&n,&k,&q);
        memset(s,0,sizeof(s));
        memset(nx,0,sizeof(nx));
        vector<str>ss;
        for(int j=1;j<=n;j++)
        {
            int l;
            scanf("%d",&l);
            for(int m=1;m<=l;m++)
            {
                int num;
                scanf("%d",&num);
                s[j]+=(num+'0');
            }
        }
        //for(int j=1;j<=n;j++)cout<<s[j]<<endl;
        for(int j=1;j<=n;j++)
        {
            for(int m=0;m<s[j].size();m++)
            {
                for(int p=2;p<=k;p++)
                {
                    if(m+p-1>=s[j].size())break;
                    ss.push_back({s[j].substr(m,p),j});
                }
            }
            nx[j]=ss.size();
        }
        //for(auto j:ss)cout<<j.s<<" "<<j.c<<endl;
        nx[n+1]=ss.size()+1;
        vector<int>a[ss.size()+1];
        vector<int>b[11];
        for(int j=0;j<ss.size();j++)
        {
            int cc=upper_bound(nx+1,nx+1+n,j)-nx;
            cc--;
            for(int l=0;l<ss.size();l++)
            {
                if(l>=nx[cc]&&l<nx[cc+1])
                {
                    l=nx[cc+1]-1;
                    continue;
                }
                if(ss[j].s[ss[j].s.size()-1]==ss[l].s[0])a[j].push_back(l);
            }
        }
        for(int j=0;j<ss.size();j++)b[ss[j].s[0]-'0'].push_back(j);
        for(int j=1;j<=q;j++)
        {
            int r,c;
            bool flag=0;
            scanf("%d%d",&r,&c);
            for(int l=0;l<b[1].size();l++)
            {
                queue<qe>q;
                q.push({b[1][l],1});
                while(!q.empty())
                {
                    int numm=q.front().num,val=q.front().val;
                    q.pop();
                    char ccc=ss[numm].s[ss[numm].s.size()-1];
                    if(val>r)break;
                    if(ccc-'0'==c&&val==r)
                    {
                        flag=1;
                        break;
                    }
                    for(int m=0;m<a[numm].size();m++)q.push({a[numm][m],val+1});
                }
                if(flag)break;
            }
            if(flag)printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
