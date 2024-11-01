#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int biao[51]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    for (int i=0;i<T;i++)
    {
        int aaa;
        cin >> aaa;
        if(aaa<=50) // da biao chu sheng yi
        {
            cout << biao[aaa] << endl;
        }
        else if(aaa%7==0) // te xing a
        {
            for (int j=0;j<aaa/7;j++)
            {
                cout << "8";
            }
            cout << endl;
        }
        else if((aaa-1)%7==0) // te xing b
        {
            aaa-=8;
            cout << "10";
            for (int j=0;j<aaa/7;j++)
            {
                cout << "8";
            }
            cout << endl;
        }
        else
        {
            cout << "114514" << endl; // Point 9,10
        }

    }
    
}