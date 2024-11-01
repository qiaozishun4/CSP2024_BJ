#include<iostream>
#include<set>
using namespace std;

int n, ans, cnt, a[100005];

bool flag = false;

multiset<int> st;

bool operator< (auto v, auto w)
{
    if(v == w) return false;
    if(*v < *w) return true;
    if(*v > *w) return false;

    auto u = v;
    while(*u == *v)
    {
        u ++;
        if(u == w)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        if(x != 1 && x != 2) flag = true;
        st.insert(x);
    }

    if(!flag)
    {
        auto v = st.begin();
        while(v != st.end())
        {
            a[++ cnt] = st.count(*v);
            v = st.upper_bound(*v);
        }

        for(int i = 1; i <= cnt; i ++)
        {
            if(a[i + 1] - a[i] < 0) ans += a[i] - a[i + 1];
        }

        cout << ans << endl;
        return 0;
    }

    auto v = st.begin(), lst = v;
    while(true)
    {
        auto w = st.upper_bound(*v);
        if(w == st.end()) break;
        lst ++;
        if(lst == st.end()) break;

        if(w < lst)
        {
            //nothing.
            ans ++;
        }
        else
        {
            lst = w;
            ans ++;
        }
        v ++;
    }

    cout << n - ans << endl;

    return 0;
}