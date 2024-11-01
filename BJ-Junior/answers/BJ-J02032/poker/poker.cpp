#include <iostream>
using namespace std;

int n;
bool vis[100][100];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    int cnt = 52;
    char p[2] = {};
    for(int i = 1;i <= n;i++)
    {
        cin >> p;
        if(!vis[p[0]][p[1]])
        {
            vis[p[0]][p[1]] = 1;
            cnt--;
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


