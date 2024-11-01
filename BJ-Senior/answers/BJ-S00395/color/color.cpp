#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

const int N = 2e5 + 10;
int n;
int a[N];
int T;
int c[N];//1 红 2 蓝
int ans;

void work1(int pos,int r,int b,int cnt)
{
    //printf("*** pos = %d,r = %d,b = %d,cnt = %d\n",pos,r,b,cnt);
    if(pos == n)
    {
        cnt += max(((a[r] == a[pos]) ? a[r] : 0),((a[b] == a[pos]) ? a[b] : 0));
        ans = max(ans,cnt);
        return ;
    }
    work1(pos + 1,pos,b,cnt + ((a[r] == a[pos]) ? a[r] : 0));
    work1(pos + 1,r,pos,cnt + ((a[b] == a[pos]) ? a[b] : 0));
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> T;
    while(T--)
    {
        ans = -0x3f;
        cin >> n;
        //if(n <= 100)
        //{
            for(int i = 1;i <= n;i++)
                cin >> a[i];
            work1(1,0,0,0);
            cout << ans << endl;
        //}
    }
    return 0;
}
