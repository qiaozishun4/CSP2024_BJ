#include<iostream>
using namespace std;
int huase(char c)
{
    int hs[4]={'D','C','H','S'};
    for(int i=0;i<4;i++)
        if(c==hs[i])return i;
    return 0;
}
int poker(char c)
{
    int pk[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    for(int i=0;i<13;i++)
        if(c==pk[i])return i;
    return 0;
}
bool vis[4][13];
int cnt=52,n;
int main(void)
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char hs,pk;
        cin>>hs>>pk;
        int h=huase(hs),p=poker(pk);
        if(vis[h][p]==0)
        {
            cnt--;
            vis[h][p]=1;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
