#include <bits/stdc++.h>

int a[100005];

using namespace std;

bool check[100005];


void duel(int a[], int n)
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (check[i] == false)
            flag = false;
    }
    if (flag)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
                n++;
        }
        cout << n;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if (a[i] < a[i+1])
        {
            a[i] = 0;
            check[i+1] = true;
        }
    }
    duel(a, n);
}





int main()
{

    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);


    bool check[100005];
    bool flag = true;
    int n;
    cin >> n;

    //输入 正确
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 2)
            flag = false;
    }

    //特判_正确
    if(flag)
    {
        int one;
        int two;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                one++;
            }
            if (a[i] == 2)
            {
                two++;
            }
        }
        if (two > one)
        {
            cout << two;
        }
        else
        {
            cout << one;
        }
    }
    else
    {
        duel(a, n);
    }


    return 0;
}
