#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct card
{
    int id,r;
    bool life=1,atk=1;
} a[100005];
int box[100005],cnt=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    cnt=n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].r;
        a[i].id=i;
        box[a[i].r]++;
    }
    int last=-1,rem=0;
    for(int i=1;i<=100000;++i)
    {
        if(box[i])
        {
            if(last==-1)
            {
                last=i;
                rem=box[i];
                continue;
            }
            if(box[i]>=rem)
            {
                cnt-=rem;
                rem=box[i];
            }
            else
            {
                cnt-=box[i];
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
