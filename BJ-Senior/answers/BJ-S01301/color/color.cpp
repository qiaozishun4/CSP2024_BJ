#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int maxn;
int a[105][2],jg[105];
int digui(int x,int a[105][2])
{
    for(int i = 0 +x;i < n ; i ++)
    {
        a[i][1] = 1;
        digui(x++,a);
        a[i][1] = 2;
        digui(x++,a);
    }
    int fllag = 0;
    for(int i = 1 ;i < n ; i ++)
    {
        fllag = 0;
        int s = i;
        while(s>=0)
        {
            if(a[s][1] == a[i][1])
            {
                break;
            }
            s--;
        }
        if(a[s][0] == a[i][0])
        {
            fllag += a[i][0];
            if(fllag > maxn)
            {
                maxn = fllag;
            }
        }
    }
    return maxn;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> T;
    int flag = 0;
    while(T--)
    {

        cin >> n;
        for(int i = 0 ;i < n ; i ++)
        {
            cin >> a[i][0];
        }
        jg[flag] = digui(0,a);
        flag++;
    }
    for(int i =0;i<n;i++)
    {
        cout << jg[i]<<endl;
    }
}
