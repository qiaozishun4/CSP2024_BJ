#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt = 0;
    char a[53],b[53];
    cin>>n;
    if (n == 52)
    {
        cout<<0;
        return 0;
    }
    for (int i = 1;i <= n;i++)
    {
        cin>>a[i]>>b[i];
        cnt++;
        for (int j = i - 1;j >= 1;j--)
        {
            if (a[i] == a[j] && b[i] == b[j])
            {
                cnt--;
            }
        }
    }
    cout<<52 - cnt;
    fclose(stdin);
    fclose(stdout);
}