#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin >> n;
    string a[1001] = {};
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    int cnt = 52 - n;
    for(int i = 0;i < n;i++)
    {
        if(a[i] == "00")
        {
            continue;
        }
        for(int j = i + 1;j < n;j++)
        {
            if(a[i] == a[j])
            {
                cnt++;
                a[j] = "00";
            }
        }
    }
    if(cnt < 0)
    {
        cout << 0;
    }
    else
    {
        cout << cnt;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
