#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int n;

struct pocker
{
    string color;
    string number;
};

pocker p[60],q[60];
bool flag[60][60],flag2[60][60];
int cnt = 1;
int ans;

int main()
{
    freopen("pocker1.in","r",stdin);
    freopen("pocker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> p[i].color >> p[i].number;
        int x = p[i].color[0] - 'A';
        int y;
        if(p[i].number[0] >= 'A' && p[i].number[0] <= 'Z')
            y = p[i].number[0] - 'A';
        else y = p[i].number[0] - '0';
        if(!flag[x][y])
        {
            q[cnt].color = p[i].color;
            q[cnt].number = p[i].number;
            cnt++;
            flag[x][y] = true;
        }
    }
    for(int i=1;i<cnt;i++)
    {
        int x = q[i].color[0] - 'A';
        int y;
        if(q[i].number[0] >= 'A' && q[i].number[0] <= 'Z')
            y = q[i].number[0] - 'A';
        else y = q[i].number[0] - '0';
        flag2[x][y] = true;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(flag2[i][j])
                continue;
            ans++;
        } 
    }
    cout << ans << endl;
    return 0;
}