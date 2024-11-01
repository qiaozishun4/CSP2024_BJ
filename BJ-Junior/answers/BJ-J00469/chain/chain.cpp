#include <iostream>
#include<vector>
using namespace std;
#define N 100005
int T,n,k,q;
int rst[N],cst[N];

vector<int> s[N];
vector<int> jyh[8][N];
bool dfs(int i,int j,int depth,const int& c,const int& r)
{
    if(jyh[depth][i][j]!=-1)return jyh[depth][i][j];
    if(depth == 1)
    {
        for(int p=j+1;p<s[i].size() && p-j+1<=k; p++)
        {
            if(s[i][p]==c)//jieshu
                return true;
        }
        return false;
    }
    bool anss=0;
    for(int p=j+1;p<s[i].size() && p-j+1<=k; p++)
    {
        for(int i1=1;i1<=n;i1++)
        {
            if(i1==i)continue;
            for(int i2=0;i2<s[i1].size();i2++)
            {
                if(s[i1][i2]==s[i][p])
                {
                    anss=dfs(i1,i2,depth-1,c,r);
                    if(anss){
                        jyh[depth][i][j]=1;
                        return 1;
                    }
                }
            }
        }
    }
    jyh[depth][i][j]=0;
    return 0;
}

int main()
{

    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);  //TODO!!
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            s[i].clear();
            jyh[0][i].clear();
                jyh[1][i].clear();
                jyh[2][i].clear();
                jyh[3][i].clear();
                jyh[4][i].clear();
                jyh[5][i].clear();
            int lg,k;
            cin>>lg;
            for(int t=0;t<lg;t++){
                cin>>k;
                s[i].emplace_back(k);
                jyh[0][i].emplace_back(-1);
                jyh[1][i].emplace_back(-1);
                jyh[2][i].emplace_back(-1);
                jyh[3][i].emplace_back(-1);
                jyh[4][i].emplace_back(-1);
                jyh[5][i].emplace_back(-1);
            }
        }
        bool t1=true,t23=true;
        for(int i=1;i<=q;i++)
        {
            cin>>rst[i]>>cst[i];
            if(rst[i]!=1)t1=0;
            if(rst[i]>5 || n>10)t23=0;
        }

        for(int i=1;i<=q;i++)//q次询问
        {
            int r=rst[i],c=cst[i];
            if(t1)                  // r恒为1
            {
                int ans=0;
                for(int i=1;i<=n;i++)
                {
                    bool flag=0; int id=0;
                    for(int j=0;j<s[i].size();j++)
                    {
                        if(s[i][j]==c && flag && j-id+1<=k && j!=id)
                            ans=1;
                        if(s[i][j]==1)flag=1,id=j;
                    }
                }
                cout<<ans<<endl;
            }
            if(t23)             //
            {
                //for(int i=1;i<=n;i++)
                 //   for(int j=0;j<s[i].size();j++)
                bool ans23=0;
                for(int i=1;i<=n;i++)
                {
                    for(int j=0;j<s[i].size();j++)
                    {
                        if(s[i][j]==1)
                            ans23|=dfs(i,j,r,c,r);
                        if(ans23)break;
                    }
                    if(ans23)break;
                }
                cout<<ans23<<endl;
            }
        }
    }
    return 0;
}
