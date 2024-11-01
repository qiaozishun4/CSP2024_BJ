#include <bits/stdc++.h>
using namespace std;
int cards;
const int N=1e5+5;
struct monster
{
    int atkdef;
    bool alive=1;
    bool attack=1;
}mo[N];
bool cmp(monster x,monster y)
{
    return x.atkdef<y.atkdef;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&cards);
    for(int i=1;i<=cards;i++)
    {
        cin>>mo[i].atkdef;
    }
    sort(mo+1,mo+cards+1,cmp);
    int destruction=0;
    for(int i=1;i<cards;i++)
    {
        for(int j=i+1;j<=cards;j++)
        {
            if(mo[i].atkdef<mo[j].atkdef&&mo[j].attack==1&&mo[j].alive==1)
            {
                mo[i].alive=0;
                mo[j].attack=0;
                break;
            }
        }
    }
    for(int i=1;i<=cards;i++)
    {
        if(mo[i].alive==1)destruction++;
    }
    printf("%d\n",destruction);
    return 0;
}