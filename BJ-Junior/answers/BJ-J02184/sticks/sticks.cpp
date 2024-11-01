#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8 + 5;
int T;
int s[10] = {8,0,6,9,2,3,5,4,7,1};
int s1[10] = {7,6,6,6,5,5,5,4,3,2};
queue<int> q;
int n;
long long ans = inf,sum = 0,flag = 0;
void f(int x)
{
    if(ans && ans != inf) return;
    if(flag) return;
    if(x == 0 && sum != 0)
    {
        /*while(!q.empty())
        {
            int num = q.front();
            q.pop();
            cout << num;
        }*/
        if(ans > sum)
        {
            ans = sum;
        }
        else flag = 1;
        sum = 0;
        return;
    }
    for(int i = 0;i < 10;i++)
    {
        if(x - s1[i] < 0) continue;
        if(s[i] == 0 && x - s1[i] >= 0 && sum == 0) continue;
        if(x - s1[i] == 0)
        {
            sum *= 10;
            sum += s[i];
            ans = min(ans,sum);
            sum /= 10;
            continue;
        }
        sum *= 10;
        sum += s[i];
        f(x - s1[i]);
        sum /= 10;
    }
}
int Ans[40] = {0,-1,1,7,42,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    while(T--)
    {
        ans = inf,sum = 0;
		cin >> n;
		if(n <= 40)
        {
            cout << Ans[n] << endl;
            continue;
        }
		f(n);
		if(ans != inf && ans) cout << ans << endl;
		else
        {
            cout << -1 << endl;
		}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
