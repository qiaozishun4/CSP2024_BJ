#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
using std::cout,std::endl,std::ifstream;
using std::string,std::vector,std::map;
using std::max,std::min;
ifstream cin("chain.in");
ofstream cout("chain.out");
struct pi
{
    int l,r;
};
int n,k,q,maxd;
vector<vector<int>>psns;
vector<map<int,int>>psnk;
map<std::pair<int,int>,char>cache;
bool dfs(int psn,int want,int deep)
{
    char cach=cache[{psn,want}];
    if(deep>=maxd)return 1;
    if(cach)return cach-1;
    int top=psnk[psn][want];
    for(int i=0;i<n;i++){
        if(i==psn)continue;
        for(int j=max(0,top-k);j<top-1;j++){
            if(dfs(i,j,deep+1))
                return (cache[{i,want}]=2)-1;
        }
    }
    return (cache[{psn,want}]=1)-1;
}
void term()
{
    cin>>n>>k>>q;
    psns.clear();
    psnk.clear();
    psns.resize(n);
    psnk.resize(n);
    for(size_t i=0;i<n;i++)
    {
        int l;cin>>l;
        psns[i].resize(l);
        for(size_t j=0;j<l;j++)
        {
            cin>>psns[i][j];
            psnk[i][psns[i][j]]=j;
        }
    }
    for(size_t i=0;i<q;i++)
    {
        int end;
        bool st=0;
        cin>>maxd>>end;
        for(size_t j=0;j<n;j++){
            if(dfs(j,end,0))
            {
                cout<<(st=1)<<endl;
                break;
            }
        }
        if(!st)cout<<"0\n";
    }
}
int main()
{
    int t;cin>>t;
    while(t--)term();
    return 0;
}
