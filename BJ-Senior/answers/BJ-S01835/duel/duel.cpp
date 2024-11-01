#include<bits/stdc++.h>
using namespace std;
const int Len = 100005;
int r[Len],lv[Len];
bool il[Len] = {false};
int ms[Len];
int liv;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    liv = n;
    for (int i = 0;i < n;i++)
    {
        scanf("%d",&r[i]);
        ++ms[r[i]];
    }
    int l = 0;
    for (int i = 0;i < Len;i++)
    {
        if (!ms[i]) continue;
        lv[l] = i;
        ++l;
    }
    for(int i = 1;i < l;i++)
    {
        int num = ms[lv[i]];
        if (num >= ms[lv[i-1]])
        {
            num -= ms[lv[i-1]];
            liv -= ms[lv[i-1]];
            ms[lv[i-1]] = 0;
            for (int j = 0;j < i;++j)
            {
                if (!ms[lv[j]]) continue;
                if (num >= ms[lv[j]])
                {
                    num -= ms[lv[j]];
                    liv -= ms[lv[j]];
                    ms[lv[j]] = 0;
                }
                else
                {
                    ms[lv[j]] -= num;
                    liv -= num;
                    num = 0;
                    break;
                }
            }
        }
        else
        {
            ms[lv[i-1]] -= num;
            liv -= num;
        }
    }
    printf("%d",liv);
    return 0;
}
