#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n,ans;
int m[100005];
bool a[100005];
int num[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    ans = n;
    for(int i= 1;i <= n;i++)
    {
        cin >> m[i];
        num[m[i]]++;
    }
    sort(m+1,m+n+1);
    for(int i = 1;i <= n;i++)
    {
        for(int j = i + num[m[i]];j <= n;j++)
        {
            if(m[j]>m[i] &&  a[j] == false)
            {
                a[j] = true;
                ans--;
                break;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
