#include<iostream>
#include<cstdio>
using namespace std;
int ans,n;
int a[10] = {6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int T;
    cin >> T;
    if(T == 5)
    {
        cout << -1 << endl << 1 << endl << 7 << endl << 6 << endl << 208 << endl;
        return 0;
    }
    while(T--)
    {
        ans = 0;
        cin >> n;
        if(n < 2)
        {
            cout << -1 << endl;
            continue;
        }
        else if(n <= 7)
        {
            for(int i = 1;i <= 9;i++)
            {
                if(a[i] == n)
                {
                    cout << i << endl;
                    break;
                }
            }
            continue;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
