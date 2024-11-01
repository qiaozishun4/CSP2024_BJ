#include<bits/stdc++.h>
using namespace std;

const int ma = 2e5+5;
int cnt = -1, n, t, a[ma];

bool color[ma]; //lan se : 0 , hong se: 1
bool first = true;

void dfs(int x)
{
    if(x >= n)
    {
        int c = 0, temp = 1;
        for(int i = 2; i <= n;)
        {
            if(color[temp] == color[i] && a[temp] == a[i] && color[temp] == 0 && temp != i)
            {
                c += a[temp];
                temp++;
                i = temp+1;
                continue;
            }
            if(color[temp] == color[i] && color[temp] == 0 && a[temp] != a[i])
            {
                temp = i;
                i = temp+1;
                continue;
            }
            if(color[temp] == 1)
            {
                temp++;
                i = temp+1;
            }
            if(color[i] == 1)
                i++;
        }
        temp = 1;
        for(int i = 2; i <= n;)
        {
            if(color[temp] == color[i] && a[temp] == a[i] && color[temp] == 1 && temp != i)
            {
                c += a[temp];
                temp++;
                i = temp+1;
                continue;
            }
            if(color[temp] == color[i] && color[temp] == 1 && a[temp] != a[i])
            {
                temp = i;
                i = temp+1;
                continue;
            }
            if(color[temp] == 0)
            {
                temp++;
                i = temp+1;
            }
            if(color[i] == 0)
                i++;
        }
        cnt = max(cnt, c);
      /*  if(cnt == 31&& first == true)
        {
            first = false;
            for(int i = 1; i <= n; i++)
                cout << int(color[i]) << " ";
        }   */
        return;
    }
    else{

        color[x] = 0;
        dfs(x+1);

        color[x] = 1;
        dfs(x+1);

        x--;
    }

}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        cnt = -1;
        dfs(1);
        //for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
