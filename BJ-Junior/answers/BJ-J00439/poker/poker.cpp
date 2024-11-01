#include <iostream>
using namespace std;
struct node
{
    int x,y;
}m;
char z;
bool vis1[30],vis2[30],vis3[30],vis4[30];
int n,cnt;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> z;
        if(z == 'D')
        {
            m.x = 1;
        }
        else if(z == 'C')
        {
            m.x = 2;
        }
        else if(z == 'H')
        {
            m.x = 3;
        }
        else
        {
            m.x = 4;
        }
        cin >> z;
        if(z == 'A')
        {
            m.y = 1;
        }
        else if(z == 'T')
        {
            m.y = 10;
        }
        else if(z == 'J')
        {
            m.y = 11;
        }
        else if(z == 'Q')
        {
            m.y = 12;
        }
        else if(z == 'K')
        {
            m.y = 13;
        }
        else
        {
            m.y = z - '0';
        }
        if(m.x == 1)
        {
            vis1[m.y] = 1;
        }
        else if(m.x == 2)
        {
            vis2[m.y] = 1;
        }
        else if(m.x == 3)
        {
            vis3[m.y] = 1;
        }
        else
        {
            vis4[m.y] = 1;
        }
    }
    for(int i = 1;i <= 13;i++)
    {
        if(!vis1[i])
        {
            cnt++;
        }
        if(!vis2[i])
        {
            cnt++;
        }
        if(!vis3[i])
        {
            cnt++;
        }
        if(!vis4[i])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
