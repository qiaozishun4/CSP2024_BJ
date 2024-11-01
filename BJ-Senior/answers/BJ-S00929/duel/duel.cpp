#include <bits/stdc++.h>
#define pow power
#define ll long long
#define ull unsigned long long
using namespace std;
template <typename T>void read(T &x)
{
    x=0;
    int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+c-'0';
    x*=f;
}
template <typename T>void write(T x)
{
    if(x<0)
    {
        putchar('-');
        write(-x);
        return ;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template <typename T>void writeln(T x)
{
    write(x);
    putchar('\n');
}    
const int N=1e5+5;
int a[N];
priority_queue<int> q;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    sort(a+1,a+n+1);
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++)
    {
        if(!q.empty()) 
            if(-q.top()<a[i]) q.pop();
        q.push(-a[i]);
    }
    writeln(q.size());
    return 0;
}