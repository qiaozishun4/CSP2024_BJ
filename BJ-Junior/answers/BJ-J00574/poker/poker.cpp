#include <bits/stdc++.h>
using namespace std;

char a[53],b[5];
int sum = 0;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin>>n;

    if(n == 52)
    {
        cout<<"0";
        return 0;
    }

    for(int i = 0; i< n;i++)
    {
        cin>>a[i]>>b[i];
        sum++;
        for(int j = 0; j<i; j++)
        {
            if(a[i] == a[j] && b[i] == b[j])
                sum--;
        }
    }

    cout<<52-sum;

    return 0;
}
