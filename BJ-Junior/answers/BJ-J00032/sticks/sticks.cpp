#include <bits/stdc++.h>
using namespace std;
int a[8] = {0,-1,1,7,4,2,0,8};
int b[8];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n == 1)
        {
            cout << -1;
            return 0;
        }
        int p = 100000005;
        int q = -1;
        for(int i = 2;i <= n;i++)
        {
            if(n%i == 0) b[i] = n/i;
            else b[i] = n/i+1;
            if(b[i] < p)
            {
                p = b[i];
                q = i;
            }
        }
        int k = q-(7-q);
        int c[100005];
        int w = 1;
        while(n >= 0)
        {
            int sum = 100000005;
            int s = -1;
            for(int i = k;i <= 7;i++)
            {
                if(sum>a[i])
                {
                    sum = a[i];
                    s = i;
                }
            }
            if(n>=2*p)
            {
                n-=2*n;
                c[w] = sum;
                c[w+1] = a[p+(p-s)];
                w+=2;
            }
            else if(n>=p)
            {
                n-=p;
                c[w] = p;
                w++;
            }
            else
            {
                n=0;
                c[w] = a[n];
                w++;
            }
        }
        sort(c+1,c+n+1);
        if(c[1] == 0) swap(c[2],c[1]);
        for(int i = 1;i <= w-1;i++)
        {
            cout << c[i];
        }
        cout << endl;
    }
    return 0;
}
