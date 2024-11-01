#include "bits/stdc++.h"
using namespace std;
string too(long long n)
{
    int x,i;
    string sx;
    while(n)
    {
        x *= 10;
        x  += n%2;
        n /= 2;
        i++;
    }
    int j = 0;
    while(x)
    {
        sx[j] = x%10+'0';
        j++;
        x /= 10;
    }
    return sx;
}
string o(long long n,long long m)
{
    string sn = too(n),sm = too(m);
    for(int i = 0;i < max(sn.size(),sm.size());i++)
    {
        if(sn[i] == sm[i])
            sn[i] = 0;
        else
            sn[i] = 1;
    }
    return sn;
}
long long zhen(string n)
{
    long long ans;
    for(int i = 0;i < n.size();i++)
    {
        long long ans1 = 1;
        for(int j = 1;j <= i-1;j++)
            ans1 *= 2;
        ans1 *= n[i] - '0';
        ans += ans1;
    }
    return ans;
}
long long check(long long a[],long long k,string r[],long long l)
{
    if(k == 1)
        return 1;
    long long ans = 0;
    long long a1[100010];
    int j = 0;
    for(int i = 0;i < k;i += 2)
    {
        if(r[l][i])
        {
            if(a[2*i] >= a[2*i+1])
            {
                if(a[2*i] >= l ||a[2*i] == -1)
                {
                    a1[j] = a[2*i];
                    j++;
                }
                else
                {
                    a1[j] = a[2*i+1];
                    j++;
                }
            }
            else
            {
                if(a[2*i+1] >= l || a[2*i+1] == -1)
                {
                    a1[j] = a[2*i+1];
                    j++;
                }
                else
                {
                    a1[j] = a[2*i];
                    j++;
                }
            }
        }
        else
        {
            if(a[2*i] <= a[2*i+1])
            {
                if(a[2*i] >= l || a[2*i] == -1)
                {
                    a1[j] = a[2*i];
                    j++;
                }
                else
                {
                    a1[j] = a[2*i+1];
                    j++;
                }
            }
            else
            {
                if(a[2*i+1] >= l || a[2*i+1] == -1)
                {
                    a1[j] = a[2*i+1];
                    j++;
                }
                else
                {
                    a1[j] = a[2*i];
                    j++;
                }
            }
        }
    }
    return check(a1,j+1,r,l+1);
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int m,n;
    cin >> n >> m;
    long long a[100010];
    for(int i = 0;i < n;i++)
        cin >> a[i];
    int c[100010];
    for(int i = 0;i < m;i++)
        cin >> c[i];
    int k;
    for(;;k++)
    {
        int ans = 1;
        if(ans >= n)
        break;
        for(int i = 1;i <= k;i++)
            ans *= 2;
    }
    string r[500];
    for(int i = 0;i < k-n;i++)
        cin >> r[i];
    int t;
    cin >> t;
    while(t--)
    {
        long long ans[100010];
        for(int i = 0;i < m;i++)
            ans[i] = 0;
        int aas = 0;
        long long x[4];
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        long long mm[100010];
        for(int i = 0;i < n;i++)
            mm[i] = zhen(o(x[i],x[i%4]));
        for(int i = 0;i < m;i++)
        {
            long long a1[100010];
            for(long long hhh = 0;hhh < mm[i];hhh++)
                a1[i] = a[i];
            for(long long hh = mm[i];hh < k;hh++)
                a1[i] = -1;
            ans[aas] = check(a1,k,r,1);
            aas++;
        }
        int answer = ans[0];
        for(int i = 1;i < m;i++)
        {
            answer = zhen(o(answer,(i+1)*ans[i]));
        }
        cout << answer << endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
