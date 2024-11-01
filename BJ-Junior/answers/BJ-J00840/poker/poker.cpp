#include <iostream>
#include <algorithm>
using namespace std;
struct poker
{
    char color;
    char number;
    int color2;
    int number2;
    bool same(poker p1,poker p2)
    {
        if(p1.color==p2.color&&p1.number==p2.number)
        {
            return true;
        }
        else
            return false;
    }
};
bool cmp(poker a,poker b)
{
    if(a.number2==b.number2)
    {
        return (a.color2<b.color2);
    }
    return (a.number2<b.number2);
}
poker p[55];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,i;
    cin>>n;
    if(n>1)
    {

        for(i=1;i<=n;i++)
        {
            cin>>p[i].color>>p[i].number;
            if(p[i].color== 'D')p[i].color2=1;
            else if(p[i].color== 'C')p[i].color2=2;
            else if(p[i].color== 'H')p[i].color2=3;
            else if(p[i].color== 'S')p[i].color2=4;
            if(p[i].number>='2'&&p[i].number<='9')
                p[i].number2=p[i].number-'0';
            else
            {
                if(p[i].number=='J')p[i].number2=11;
                else if(p[i].number=='Q')p[i].number2=12;
                else if(p[i].number=='K')p[i].number2=13;
                else if(p[i].number=='A')p[i].number2=1;
            }
        }
        sort(p+1,p+n+1,cmp);
        int cnt=52-n;
        for(i=1;i<n;i++)
        {
            if(p[i].same(p[i],p[i+1]))
            {
                cnt++;
            }
        }
        cout<<cnt;
    }
    else
        cout<<51;
    return 0;
}
