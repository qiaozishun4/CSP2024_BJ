#ifdef DBG
#include <iostream>
#else
#include <fstream>
#endif
#include <cstring>
#define max(x,y) ((x>y) ? x : y)
#define min(x,y) ((x<y) ? x : y)

#ifdef DBG
template<typename... Arg>
void log(Arg... args)
{
    std::cerr << "\033[1;32m{";
    ((std::cerr << args << ' '), ...);
    std::cerr << "}\033[0;0m\n";
}
#endif

#ifndef DBG
namespace std{
    std::ifstream cin("color.in");
    std::ofstream cout("color.out");
}
#endif

int T, n, prev[200001], last[1000001];
long long int a[200001], f[200001], f2[200001];

int main()
{
    #ifdef DBG
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    #endif
    std::cin >> T;
    while(T--)
    {
        std::cin >> n;
        memset(last, 0, sizeof(last));
        for(int i = 1; i <= n; i++)
        {
            std::cin >> a[i],
            prev[i] = last[a[i]],
            last[a[i]] = i,
            f2[i] = f2[i-1];
            if(prev[i] == 0) f[i] = f[i-1];
            else
            {
                if(prev[i] == i-1 && i != 1)
                {
                    f[i] = f[i-1] + a[i],
                    f2[i] += a[i];
                }
                else
                {
                    f[i] = max(max(f[i-1], f[prev[i]] + f2[i-1] - f2[prev[i]+1] + a[i]), f[prev[i]+1] + f2[i-1]- f2[prev[i]+1] + a[i]);
                }
            }
        }
        std::cout << f[n] << '\n';
    }
    return 0;
}