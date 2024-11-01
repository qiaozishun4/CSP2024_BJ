//#define DBG

#ifdef DBG
#include <iostream>
#else
#include <fstream>
#endif
#include <algorithm>

using namespace std;

#ifdef DBG
template<typename... Arg>
void log(Arg... args)
{
    cerr << "\033[1;32m{";
    ((cerr << args << ' '), ...);
    cerr << "}\033[0;0m\n";
}
#endif

#ifndef DBG
ifstream cin("duel.in");
ofstream cout("duel.out");
#endif

int n, r[100001], res = 2147483647;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    sort(r, r+n);
    int ans = n, ptr = 0;
    for(int i = 0; i < n; i++)
    {
        if(ptr == i) continue;
        if(r[ptr] < r[i]) --ans, ++ptr;
    }
    cout << ans << '\n';
    return 0;
}