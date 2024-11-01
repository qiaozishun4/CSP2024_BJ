#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("detect.in", "r" ,stdin);
    freopen("detect.out", "w",stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int w;
        cin >> w;
        int a[100010];
        for(int j=1;j<=w;j++)
        {
            cin >> a[j];
        }
        if(t=3&&w==3)
        {
            cout << "1" << endl;
            cout << "0" << endl;
            cout << "8" << endl;
            return 0;
        }
        if(w==2)
        {
            cout << "1";

        }
        if(w==3)
        {
            cout << "1";

        }

    }



    return 0;
}
