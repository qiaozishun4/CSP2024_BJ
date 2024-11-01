#include<bits/stdc++.h>
using namespace std;
int stk[100010];
int nums[] = {6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i = 1;i <= 100000;i++)
    {
        int tmp = i;
        int cnt = 0;
        while(tmp != 0)
        {
            cnt += nums[tmp % 10];
            tmp /= 10;
        }
        stk[i] = cnt;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        bool flag = true;
        for(int i = 1;i <= 100000;i++)
        {
            if(stk[i] == n)
            {
                cout << i << endl;
                flag = false;
                break;
            }
        }
        if(flag) cout << -1 << endl;
    }
    return 0;
}
