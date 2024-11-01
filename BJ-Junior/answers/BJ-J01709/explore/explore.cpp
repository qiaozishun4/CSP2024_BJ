#include<bits/stdc++.h>
#define ll long long
const int N=1e5+10, INF=0x7fffffff;
using namespace std;
int T;
int d;
struct pos
{
    int x,y;
    bool operator < (const pos &a)const
    {
        if(x==a.x)return (y<a.y);
        return (x<a.x);
    }
};
pos move(pos a)
{
    int x=a.x,y=a.y;
    if(d==0)return (pos){x,y+1};
    if(d==1)return (pos){x+1,y};
    if(d==2)return (pos){x,y-1};
    if(d==3)return (pos){x-1,y};
    return (pos){x,y};
}
map<pos, char> forest;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int n,m,k,cnt=1, turned;
        int xx,yy;
        cin>>n>>m>>k;
        cin>>xx>>yy>>d;
        pos robot=(pos){xx,yy};
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(int j=1;j<=m;j++)
            {
                forest[(pos){i,j}]=s[j-1];
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(forest[move(robot)]=='.' or forest[move(robot)]=='#')
            {
                turned=0;
                robot=move(robot);
                if(forest[robot]=='#')cnt--;
                cnt++;
                forest[robot]='#';
            }
            else
            {
                //if(turned==4)break;
                turned++;
                d=(d+1)%4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

