#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;char ch=' ';
    while(!isdigit(ch))
        ch=getchar();
    while(isdigit(ch))
        x=x*10+ch-'0',
        ch=getchar();
    return x;
}
vector<int>dict[100005];
//int r[100005],c[100005];
int n,k,q,tmp,len,r,c;bool flag;
void dfs(int rd,int ed)//round,end
{
    if(flag)return;
    if(rd==0){rd=true;return;}
    for(int i=1;i<=n;++i)
    {
        for(int j=dict[i].size()-1;j>=0;--j)
            if(true){}
    }
}
map<int,int>mir;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;cin>>T;while(T--)
    {
        n=read(),k=read(),q=read();
        for(int i=1;i<=n;++i)
        {
            len=read();
            dict[i].push_back(0);
            for(int j=1;j<=len;++j)
            {
                tmp=read();
                dict[i].push_back(tmp);
                mir[tmp]=max(mir[tmp],j);
            }
        }
        while(q--)
        {
            cin>>r>>c;flag=false;
            if(r==1)
            {
                cout<<(mir[tmp]>=2)<<endl;
            }
            else
            {
                //cout<<dfs(r,c);
            }
        }
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
