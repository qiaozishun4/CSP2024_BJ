#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int minn = INT_MAX;
vector<int> v;
int main()
{
    freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    do
    {
        v.clear();
        for(int i = 1; i <= n; i++)v.push_back(a[i]);
        auto it = v.begin();
        for(int i = 0; i < v.size() - 1; i++, it++)
        {
            if(v[i] < v[i + 1])
            {
                v.erase(it);
                i--;
                it--;
            }
        }
        minn = min(minn, int(v.size()));
    }while(next_permutation(a + 1, a + n + 1));
    cout <<minn << "\n";
}
