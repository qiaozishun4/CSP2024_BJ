#include<iostream>
using namespace std;
int t,n;
char ns[8]={'n','n','1','7','4','2','0','8'};
string ans,tans;
bool cmp(void)
{
    if(tans=="")return true;
    if(tans.length()!=ans.length())return tans.length()>ans.length();
    for(int i=ans.length()-1;i>=0;i--)
    {
        if(tans[i]!=ans[i])
            return tans[i]>ans[i];
    }
    return false;
}
void dfs(int n)
{
    if(n==0)
    {
        if(ans[ans.length()-1]=='0')
            ans[ans.length()-1]='6';
        if(cmp())
        {
            tans=ans;
        }
    }
    if(n<2)return;
    string a=ans;
    for(int i=min(n,7);i>=2;i--)
    {
        ans+=ns[i];
        dfs(n-i);
        ans=a;
    }
}
int main(void)
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        tans=ans="";
        dfs(n);
        if(tans!="")
        {
            for(int i=tans.length()-1;i>=0;i--)
                printf("%c",tans[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
