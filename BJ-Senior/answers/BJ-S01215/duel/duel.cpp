#include<iostream>
using namespace std;
int n,mx,ans;
struct mob
{
    int num,able;
}cnt[100005];
int main(void)
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    for(cin>>n;n;n--)
    {
        int temp;
        cin>>temp;
        cnt[temp].num++,cnt[temp].able++,mx=max(mx,temp);
    }
    while(true)
    {
        int l=1,r=1;
        bool b=true;
        for(;!cnt[r].num&&r<=mx;r++);
        while(r<=mx)
        {
            int temp;
            if(!cnt[l].num)l=r++;
            while(!cnt[r].able&&r<=mx)r++;
            if(r>mx)break;
            temp=min(cnt[l].num,cnt[r].able),cnt[l].num-=temp,cnt[r].able-=temp,b=false;
        }
        if(b)break;
    }
    for(int i=1;i<=mx;i++)ans+=cnt[i].num;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
