#include <bits/stdc++.h>
using namespace std;
int mons[114514],cnt;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int a;
    scanf("%d",&a);
    cnt=a;
    for(int i=0;i<a;i++)
        scanf("%d",&mons[i]);
    sort(mons,mons+a);
    int j=1;
    for(int i=0;i<a-1;i++)
    {
        for(;j<a;j++)
        {
            if(mons[i]<mons[j])
            {
                cnt--;
                j++;
                break;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
