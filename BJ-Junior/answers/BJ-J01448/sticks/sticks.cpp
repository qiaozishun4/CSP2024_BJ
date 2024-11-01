#include <iostream>
#include <algorithm>
using namespace std;
int st[10]={1,5,2,2,3,2,1,4,0,1};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        int w=(x+6)/7;
        int s=(7-x%7)%7;
        if(s==6&&w==1)
        {
            cout << "-1" << endl;
            continue;
        }
        for(int i=1;i<=9;i++)
        {
            if(w==1)
            {
                if(s==st[i])
                {
                    cout << i;
                    w=s=0;
                    break;
                }
            }
            else if(s>=st[i])
            {
                s-=st[i];
                w--;
                cout << i;
                break;
            }
        }
        while(s>0)
        {
            for(int i=0;i<=9;i++)
            {
                if(w==1)
                {
                    if(s==st[i])
                    {
                        cout << i;
                        w=s=0;
                        break;
                    }
                }
                else if(s>=st[i])
                {
                    s-=st[i];
                    w--;
                    cout << i;
                    break;
                }
            }
        }
        for(int i=1;i<=w;i++)
        {
            cout << "8";
        }
        cout << endl;
    }
    return 0;
}