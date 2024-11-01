#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,z = 0;
    string a[60];
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            if(a[i] == a[j])
                z++;
        }
    }
    printf("%d",52 - n + z);
    return 0;
}
