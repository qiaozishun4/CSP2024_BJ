#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    string data[55];
    string in;
    int n, ans = 0,p = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> in;
        for(int j = 0; j < 54; j++)
        {
            if(in == data[j])
            {
                ans--;
                break;
            }
        }
        data[i] = in;
        ans++;
    }
    cout << 52-ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}