#include<bits/stdc++.h>
using namespace std;

int main()
{
   freopen("sticks.in","r",stdin);
   freopen("sticks.out","w",stdout);
    int t,n,s[9] ={8,10,18,22,20,28,68},b[9] = {-1,-1,1,-1,4,2,6};
    cin >> t;
    for(int q = 1;q<=t;q++)
    {
        cin >> n;
        if(n<7)
        {
            cout<< b[n] << endl;
            continue;
        }
        int k = (n%7);
        cout << s[k];
        int l = n/7;
        for(int i = 1;i<l;i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    return 0;
}
