#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    int rev = a[1],ren = 0,num = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == rev) num++;
        else
        {
            rev = a[i];
            ren = max(num,ren);
            num = 0;
        }
    }
    cout << max(num,ren);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
