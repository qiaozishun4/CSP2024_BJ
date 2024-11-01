#include<iostream>
#include<cstring>
#define N 100009
#define INF 21474836
#define MAXN 21474836
using namespace std;
int f[3][N];
int f2[N];
int n;
unsigned long long memory[N]={
    0,
1,
1,
7,
4,
2,
6,
8,
10,
18,
22,
20,
28,
68,
88,
108,
188,
200,
208,
288,
688,
888,
1088,
1888,
2008,
2088,
2888,
6888,
8888,
10888,
18888,
20088,
20888,
28888,
68888,
88888,
108888,
188888,
200888,
208888,
288888,
688888,
888888,
1088888,
1888888,
2008888,
2088888,
2888888,
6888888,
8888888,
10888888,
18888888,
20088888,
20888888,
28888888,
68888888,
88888888,
108888888,
188888888,
200888888,
208888888,
288888888,
688888888,
888888888,
1088888888,
1888888888,
2008888888,
2088888888,
2888888888,
6888888888,
8888888888,
10888888888,
18888888888,
20088888888,
20888888888,
28888888888,
68888888888,
88888888888,
108888888888,
188888888888,
200888888888,
208888888888,
288888888888,
688888888888,
888888888888,
1088888888888,
1888888888888,
2008888888888,
2088888888888,
2888888888888,
6888888888888,
8888888888888,
10888888888888,
18888888888888,
20088888888888,
20888888888888,
28888888888888,
68888888888888,
88888888888888,
108888888888888,
188888888888888,
200888888888888,
208888888888888,
288888888888888,
688888888888888,
888888888888888,
1088888888888888,
1888888888888888,
2008888888888888,
2088888888888888,
2888888888888888,
6888888888888888,
8888888888888888,
10888888888888888,
18888888888888888,
20088888888888888,
20888888888888888,
28888888888888888,
68888888888888888,
88888888888888888,
108888888888888888,
188888888888888888,
200888888888888888,
208888888888888888,
288888888888888888,
688888888888888888,
888888888888888888,
1088888888888888888,
1888888888888888888,
2008888888888888888,
};
int min3(int a, int b, int c)
{
    return min(a, min(b, c));
}
int min6(int a, int b, int c, int d, int e, int g)
{
    return min(min3(a,b,c), min3(d,e,g));
}
int min9(int a, int b, int c, int d, int e, int g, int h, int i, int j)
{
    return min(min6(a,b,c,d,e,g), min(min(h, i), j));
}
int min10(int a, int b, int c, int d, int e, int g, int h, int i, int j, int k)
{
    return min(min6(a,b,c,d,e,g), min(min(h, i), min(j, k)));
}
int min8(int a, int b, int c, int d, int e, int g, int h, int i)
{
    return min9(a,b,c,d,e,g,h,i,MAXN);
}
int tentime(int x)
{
    if(x>=MAXN)return MAXN;
    return 10*x;
}
void mian()
{
    memset(f, INF, sizeof(f));
    memset(f2, INF, sizeof(f2));
    f[0][0]=0;
//    for(int i=1; i<=n; i++)
  //  {
  //      f[0][i]=0;
  //  }
    for(int i=1; i<=n>>1; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==1)
            {
                if(j>=7)
                {
                    f[1][j]=min9(
                                tentime(f[0][j-2])+1,
                                tentime(f[0][j-5])+2,
                                tentime(f[0][j-5])+3,
                                tentime(f[0][j-4])+4,
                                tentime(f[0][j-5])+5,
                                tentime(f[0][j-6])+6,
                                tentime(f[0][j-3])+7,
                                tentime(f[0][j-7])+8,
                                tentime(f[0][j-6])+9
                                );
                }else if(j>=6)
                {
                    f[1][j]=min8(
                                tentime(f[0][j-2])+1,
                                tentime(f[0][j-5])+2,
                                tentime(f[0][j-5])+3,
                                tentime(f[0][j-4])+4,
                                tentime(f[0][j-5])+5,
                                tentime(f[0][j-6])+6,
                                tentime(f[0][j-3])+7,
                                tentime(f[0][j-6])+9
                                );
                }else if(j>=5)
                {
                    f[1][j]=min6(
                                tentime(f[0][j-2])+1,
                                tentime(f[0][j-5])+2,
                                tentime(f[0][j-5])+3,
                                tentime(f[0][j-4])+4,
                                tentime(f[0][j-5])+5,
                                tentime(f[0][j-3])+7
                                );
                }else if(j>=4){
                        f[1][j]=min3(
                                tentime(f[0][j-2])+1,
                                tentime(f[0][j-4])+4,
                                tentime(f[0][j-3])+7
                                );
                }else if(j>=3)
                {
                    f[1][j]=min(
                                tentime(f[0][j-2])+1,
                                tentime(f[0][j-3])+7
                                );
                }else if(j>=2) f[1][j]=tentime(f[0][j-2])+1;
            }else{
              f[0][0]=INF;
              if(j>=7){
                f[i%2][j]=min10(
                                tentime(f[(i-1)%2][j-6]),
                                tentime(f[(i-1)%2][j-2])+1,
                                tentime(f[(i-1)%2][j-5])+2,
                                tentime(f[(i-1)%2][j-5])+3,
                                tentime(f[(i-1)%2][j-4])+4,
                                tentime(f[(i-1)%2][j-5])+5,
                                tentime(f[(i-1)%2][j-6])+6,
                                tentime(f[(i-1)%2][j-3])+7,
                                tentime(f[(i-1)%2][j-7])+8,
                                tentime(f[(i-1)%2][j-6])+9
                                );
                }else if(j>=6)
                {
                    f[i%2][j]=min9(
                                tentime(f[(i-1)%2][j-6]),
                                tentime(f[(i-1)%2][j-2])+1,
                                tentime(f[(i-1)%2][j-5])+2,
                                tentime(f[(i-1)%2][j-5])+3,
                                tentime(f[(i-1)%2][j-4])+4,
                                tentime(f[(i-1)%2][j-5])+5,
                                tentime(f[(i-1)%2][j-6])+6,
                                tentime(f[(i-1)%2][j-3])+7,
                                tentime(f[(i-1)%2][j-6])+9
                                );
                }else if(j>=5)
                {
                    f[i%2][j]=min6(
                                tentime(f[(i-1)%2][j-2])+1,
                                tentime(f[(i-1)%2][j-5])+2,
                                tentime(f[(i-1)%2][j-5])+3,
                                tentime(f[(i-1)%2][j-4])+4,
                                tentime(f[(i-1)%2][j-5])+5,
                                tentime(f[(i-1)%2][j-3])+7
                                );
                }else if(j>=4){
                        f[i%2][j]=min3(
                                tentime(f[(i-1)%2][j-2])+1,
                                tentime(f[(i-1)%2][j-4])+4,
                                tentime(f[(i-1)%2][j-3])+7
                                );
                }else if(j>=3)
                {
                    f[i%2][j]=min(
                                tentime(f[(i-1)%2][j-2])+1,
                                tentime(f[(i-1)%2][j-3])+7
                                );
                }else if(j>=2) f[i%2][j]=tentime(f[(i-1)%2][j-2])+1;
            }
            if(j==n) f2[i]=f[i%2][j];
        }
    }
    int minest=MAXN;
    bool status=true;
    for(int number=1; number<=n>>1; number++)
    {
        int sum=f2[number];
 //       cout << sum << '\n';
        if(sum<minest)
        {
            status=false;
            minest=sum;
        }
    }
    if(status) cout << -1 << '\n';
    else cout<<minest<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n<50)
            mian();
        else
        {
            if(memory[n]) cout << memory[n] << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;
}
