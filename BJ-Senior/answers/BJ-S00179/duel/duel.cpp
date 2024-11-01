#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n,r[maxn],box[maxn] = {0};

int main()
{
    freopen("duel.in", "r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        scanf("%d ",&r[i]);
        box[r[i]]++;
    }
    int k = 0;
    for(int i = maxn-1;i > 0;i--)
    {
        for(int j = 0;j < box[i];j++)
        {
            r[k] = i;
            k++;
        }
    }
    int cnt = 0;
    for(int i = maxn-1;i > 0;i--)
    {
        if(box[i] > 0)
        {
            int j = 0;
            while(box[j]>0)
            {
                j++;
                if(j>=maxn)
                {
                    break;
                }
            }
            if(i>j)
            {
                box[i]--;
                box[j]--;
                cnt++;
            }
            else
            {
                box[i]--;
            }
        }
    }
    cout << n - cnt;
    return 0;
}
