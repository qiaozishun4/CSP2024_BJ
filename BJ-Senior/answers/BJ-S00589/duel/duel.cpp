#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'
#define INF 9e18

inline long long read()
{
    long long num = 0;
    bool neg = false;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
        {
            neg = !neg;
        }
        ch = getchar();
    }
    while (isdigit(ch))
    {
        num = num * 10 + (ch - '0');
        ch = getchar();
    }
    if (neg)
    {
        num = -num;
    }
    return num;
}

inline void write_x(long long x)
{
    if (!x)
    {
        return;
    }
    if (x < 0)
    {
        cout << '-';
        x = -x;
    }
    write_x(x / 10);
    cout << x % 10;
}

inline void write(long long x, char End)
{
    if (!x)
    {
        cout << 0 << End;
        return;
    }
    write_x(x);
    cout << End;
}

struct Monster
{
    long long r, id;
    bool operator < (const Monster &mns) const
    {
        return r < mns.r;
    }
};

multiset<Monster> attack, survive;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    long long n = read();
    for (long long i = 1; i <= n; ++i)
    {
        long long r;
        cin >> r;
        attack.insert({r, i});
        survive.insert({r, i});
    }
    while (true)
    {
        Monster m = *survive.begin();
        long long idx = m.id;
        multiset<Monster>::iterator eater = attack.upper_bound(m);
        if (eater == attack.end())
        {
            break;
        }
        if (((attack.begin()) -> id) == idx)
        {
            attack.erase(attack.begin());
        }
        attack.erase(eater);
        survive.erase(survive.begin());
    }
    write(survive.size(), EOL);
    return 0;
}
