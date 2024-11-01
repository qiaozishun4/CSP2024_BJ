#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("chain.in");
ofstream cout("chain.out");
const int NR=2e5+5;
struct node{
    int to,man;
}lin;
vector<node> vec[NR];
int T,n,k,q,m,s[NR],r,c;
bool dfs(int dest,int atnow,int range,int rl,int manba)
{
    if(atnow==dest&&range==rl)
    {
        return true;
    }
    if(range>=rl&&atnow!=dest)
    {
        return false;
    }
    for(int doge=0;doge<vec[atnow].size();doge++)
    {
        if(vec[atnow][doge].man==manba)
            continue;
        if(dfs(dest,vec[atnow][doge].to,range+1,rl,vec[atnow][doge].man)==true)
            return true;
    }
    return false;
}
int main()
{
    cin>>T;
    while(T--)
    {
        memset(vec,0,sizeof(vec));
        cin>>n>>k>>q;
        for(int p=1;p<=n;p++)
        {
            cin>>m;
            for(int j=1;j<=m;j++)
                cin>>s[j];
            for(int i=1;i<=m;i++)
            {
                for(int j=i+1;j<=min(i+k-1,m);j++)
                {
                    lin.man=p;
                    lin.to=s[j];
                    vec[s[i]].push_back(lin);
                }
            }
        }
        while(q--)
        {
            cin>>r>>c;
            if(r==1)
            {
                bool pop=0;
                for(int i=0;i<vec[1].size();i++)
                {
                    if(vec[1][i].to==c)
                    {
                        pop=1;
                        break;
                    }
                }
                cout<<int(pop)<<endl;
            }
            if(r!=1)
            {
                bool mc=dfs(c,1,0,r,0);
                cout<<int(mc)<<endl;
            }
        }
    }
    return 0;
}
//expecting 40pts
