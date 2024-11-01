#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdin);
    int n,abb = 0;
    cin >> n;
    char a[100],abc = 0;
    for(int i =0;i<n;i++)
    {
        cin >> abc;
        abb = 0;
        for(int i = 0;i<60;i++)
        {
            if(a[i]==abc)
            {
                if(abb==0)
                {
                    a[i] = abc;
                }
            }
            if(a[i]==0)
            {
                if(abb==0)
                {
                    a[i]=abc;
                    abb = 1;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<60;i++)
    {
        if(a[i]!=0)
        {
            ans++;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
