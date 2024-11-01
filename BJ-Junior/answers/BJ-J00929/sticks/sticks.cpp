#include <cstdio>
#include <cstring>

int stra[5000005];
//int stra2[5000005];
unsigned long long special_a(int n)
{
    unsigned long long res = 0;
    while (n)
    {
        n -= 7;
        res = res * 10 + 8;
    }

    return res;
}

unsigned long long special_b(int n)
{
    unsigned long long res = 10;
    n -= 8;
    while (n)
    {
        n -= 7;
        res = res * 10 + 8;
    }

    return res;
}

unsigned long long f(int n)
{
    unsigned long long res = 0;
    int i = 0;
    //int i2 = 0;
memset(stra, 0, sizeof(stra));
    while (n != 0)
    {
        if (i < 0)
        {
            return 0;
        }
        if (stra[i] == 0)
        {
            stra[i] = 7;
            n -= 7;
        }
        else
        {
            stra[i]--;
            n++;
        }
        if (stra[i] == 1)
        {
            n++;
            stra[i]--;
            i--;
            continue;
        }

        if (n >= 0)
        {
            i++;
        }
    }
    /*memset(stra2, 0, sizeof(stra2));

    while (n != 0)
    {
        if (i2 < 0)
        {
            return 0;
        }
        if (stra2[i2] == 0)
        {
            stra2[i2] = 7;
            n -= 7;
        }
        else
        {
            stra2[i2]--;
            n++;
        }
        if (stra2[i2] == 1)
        {
            n++;
            stra2[i2]--;
            i2--;
            continue;
        }

        if (n >= 0)
        {
            i2++;
        }
    }*/

    //i = 0;

    /*while (n != 0)
    {
        if (i < 0)
        {
            return 0;
        }
        if (stra[i] == 0)
        {
            stra[i] = 2;
            n -= 2;
        }
        else
        {
            stra[i]++;
            n--;
        }
        if (stra[i] == 8 || i >= i2)
        {
            n-=8;
            stra[i]=0;
            i--;
            continue;
        }

        if (n >= 0 && i < i2)
        {
            i++;
        }
    }*/

    unsigned long long lis[10];
    memset(lis, 0, sizeof(lis));
    for (int x = 0; x < i; ++x)
    {
        lis[stra[x]]++;
    }

    if (!lis[2] && !lis[3] && !lis[4] && !lis[5] && !lis[7])
    {
        res = 6;
        for (int x = 0; x < lis[6] - 1; ++x)
        {
            res *= 10;
        }
        return res;
    }

    if (lis[2])
    {
        lis[2]--;
        res = 1;
    }
    else if (lis[5])
    {
        lis[5]--;
        res = 2;
    }
    else if (lis[4])
    {
        lis[4]--;
        res = 4;
    }
    else if (lis[3])
    {
        lis[3]--;
        res = 7;
    }
    else if (lis[7])
    {
        lis[7]--;
        res = 8;
    }

    for (int x = 0; x < lis[6]; ++x)
    {
        res *= 10;
        res += 0;
    }

    for (int x = 0; x < lis[2]; ++x)
    {
        res *= 10;
        res += 1;
    }

    for (int x = 0; x < lis[5]; ++x)
    {
        res *= 10;
        res += 2;
    }

    for (int x = 0; x < lis[4]; ++x)
    {
        res *= 10;
        res += 4;
    }

    for (int x = 0; x < lis[3]; ++x)
    {
        res *= 10;
        res += 7;
    }

    for (int x = 0; x < lis[7]; ++x)
    {
        res *= 10;
        res += 8;
    }

    return res;
}

int main()
{
    int T;
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    scanf("%d", &T);
    for (int _ = 0; _ < T; ++_)
    {
        int n;
        scanf("%d", &n);

        if (n < 2)
        {
            printf("-1\n");
            continue;
        }

        if (n % 7 == 0)
        {
            printf("%llu\n", special_a(n));
            continue;
        }

        if (n % 7 == 1)
        {
            printf("%llu\n", special_b(n));
            continue;
        }

        unsigned long long res = f(n);
        if (res == 0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%llu\n", res);
        }
    }

    return 0;
}
