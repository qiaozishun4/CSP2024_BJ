#include"bits/stdc++.h"
using namespace std;
int r[100010];
int ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    ans = n;
    for(int i = 0;i < n;i++)
    {
        cin >> r[i];
    }
    sort(r+0,r+n);
    for(int i = 0;i < n;i++)
    {
        if(r[i] != 0)
        {
            if(i == 0)
            {
                if(r[i] >= r[i+1])
                {
                    r[i+1] = 0;
                    ans--;
                }
            }
            else if(r[i-1] != 0)
            {
                r[i-1] = 0;
                ans--;
            }
            else if(r[i-1] == 0)
            {
                if(r[i] >= r[i+1])
                {
                    r[i+1] = 0;
                    ans--;
                }
                else
                {
                    for(int j = i-1;j >= 0;j--)
                    {
                        if(r[j] != 0)
                        {
                            r[j] = 0;
                            ans--;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
