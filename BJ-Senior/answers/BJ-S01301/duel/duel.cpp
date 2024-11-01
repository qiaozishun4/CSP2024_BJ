#include<bits/stdc++.h>
using namespace std;
int n,flag;
int arr[100005],a[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> arr[i];
    }
    sort(arr + 1,arr + n + 1);
    flag = 1;
    for(int i = 2 ; i <= n ; i ++)
    {
        if(arr[i] > arr[flag])
        {
            a[i] = 2;
            a[flag] = 1;
            flag++;
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++)
    {

        if(a[i] != 1)
        {
            ans ++;
        }
    }
    cout << ans;
    return 0;
}