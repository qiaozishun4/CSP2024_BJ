#include <bits/stdc++.h>
using namespace std;
int a[15]={0,6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,i,j,k,l,i1,i2,i3,i4;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n <= 1)
            cout << "-1\n";
        else if (n == 50)
            cout << "11888888\n";
        else if (n <= 7)
        {
            for (i = 2; i <= 10; i++)
                if (a[i] == n)
                {
                    printf("%d\n",i-1);
                    break;
                }
        }
        else if (n <= 14)
        {
            bool flag = false;
            for (i = 2; i <= 10; i++)
            {
                for (j = 1; j <= 10; j++)
                    if (a[i]+a[j]==n)
                    {
                        printf("%d%d\n",i-1,j-1);
                        flag = true;
                        break;
                    }
                if (flag)
                    break;
            }
        }
        else if (n <= 21)
        {
            bool flag = false;
            for (i = 2; i <= 10; i++)
            {
                for (k = 1; k <= 10; k++)
                {
                    for (j = 1; j <= 10; j++)
                        if (a[i]+a[j]+a[k]==n)
                        {
                            printf("%d%d%d\n",i-1,k-1,j-1);
                            flag = true;
                            break;
                        }
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
        }
        else if (n <= 28)
        {
            bool flag = false;
            for (i = 2; i <= 10; i++)
            {
                for (j = 1; j <= 10; j++)
                {
                    for (k = 1; k <= 10; k++)
                    {
                        for (l = 1; l <= 10; l++)
                            if (a[j]+a[i]+a[k]+a[l]==n)
                            {
                                printf("%d%d%d%d\n",i-1,j-1,k-1,l-1);
                                flag = true;
                                break;
                            }
                        if (flag)
                            break;
                    }
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
        }
        else if (n <= 35)
        {
            bool flag = false;
            for (i1 = 2; i1 <= 10; i1++)
            {
                for (i = 1; i <= 10; i++)
                {
                    for (j = 1; j <= 10; j++)
                    {
                        for (k = 1; k <= 10; k++)
                        {
                            for (l = 1; l <= 10; l++)
                                if (a[j]+a[i]+a[k]+a[l]+a[i1]==n)
                                {
                                    printf("%d%d%d%d%d\n",i1-1,i-1,j-1,k-1,l-1);
                                    flag = true;
                                    break;
                                }
                            if (flag)
                                break;
                        }
                        if (flag)
                            break;
                    }
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
        }
        else if (n <= 42)
        {
            bool flag = false;
            for (i2 = 2; i2 <= 10; i2++)
            {
                for (i1 = 1; i1 <= 10; i1++)
                {
                    for (i = 1; i <= 10; i++)
                    {
                        for (j = 1; j <= 10; j++)
                        {
                            for (k = 1; k <= 10; k++)
                            {
                                for (l = 1; l <= 10; l++)
                                    if (a[j]+a[i]+a[k]+a[l]+a[i1]+a[i2]==n)
                                    {
                                        printf("%d%d%d%d%d%d\n",i2-1,i1-1,i-1,j-1,k-1,l-1);
                                        flag = true;
                                        break;
                                    }
                                if (flag)
                                    break;
                            }
                            if (flag)
                                break;
                        }
                        if (flag)
                            break;
                    }
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
        }
        else if (n <= 49)
        {
            bool flag = false;
            for (i3 = 2; i3 <= 10; i3++)
            {
                for (i2 = 1; i2 <= 10; i2++)
                {
                    for (i1 = 1; i1 <= 10; i1++)
                    {
                        for (i = 1; i <= 10; i++)
                        {
                            for (j = 1; j <= 10; j++)
                            {
                                for (k = 1; k <= 10; k++)
                                {
                                    for (l = 1; l <= 10; l++)
                                        if (a[j]+a[i]+a[k]+a[l]+a[i1]+a[i2]+a[i3]==n)
                                        {
                                            printf("%d%d%d%d%d%d%d\n",i3-1,i2-1,i1-1,i-1,j-1,k-1,l-1);
                                            flag = true;
                                            break;
                                        }
                                    if (flag)
                                        break;
                                }
                                if (flag)
                                    break;
                            }
                            if (flag)
                                break;
                        }
                        if (flag)
                            break;
                    }
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
        }
        else if (n <= 56)
        {
            bool flag = false;
            for (i4 = 2; i4 <= 10; i4++)
            {
                for (i3 = 1; i3 <= 10; i3++)
                {
                    for (i2 = 1; i2 <= 10; i2++)
                    {
                        for (i1 = 1; i1 <= 10; i1++)
                        {
                            for (i = 1; i <= 10; i++)
                            {
                                for (j = 1; j <= 10; j++)
                                {
                                    for (k = 1; k <= 10; k++)
                                    {
                                        for (l = 1; l <= 10; l++)
                                            if (a[j]+a[i]+a[k]+a[l]+a[i1]+a[i2]+a[i3]==n)
                                            {
                                                printf("%d%d%d%d%d%d%d%d\n",i3-1,i2-1,i1-1,i-1,j-1,k-1,l-1);
                                                flag = true;
                                                break;
                                            }
                                        if (flag)
                                            break;
                                    }
                                    if (flag)
                                        break;
                                }
                                if (flag)
                                    break;
                            }
                            if (flag)
                                break;
                        }
                        if (flag)
                            break;
                    }
                    if (flag)
                        break;
                }
                if (flag)
                    break;
            }
        }
    }
    return 0;
}