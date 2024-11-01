#include <bits/stdc++.h>
using namespace std;
int find1(string place[52],string thing)
{
    for (int i=0;i<52;i++) if (place[i]==thing) return i;
    return -1;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,wehave=0;
    cin >> n;
    string has[52],x;
    for (int i=0;i<n;i++)
    {
        cin >> x;
        if (find1(has,x)==-1)
        {
            has[i]=x;
            wehave++;
        }
    }
    cout << (52-wehave);
    return 0;
}
