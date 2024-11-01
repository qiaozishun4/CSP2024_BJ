#include<bits/stdc++.h>
using namespace std;

int r[11] = {6,2,5,5,4,5,6,3,7,6};
int d[111213]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,228,208,288,688,888, 1088,1888, 2288, 2088, 2888, 6888, 8888, 10888, 18888, 20888, 28888, };



int main()
{   
    freopen("sticks.out", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    int ans=-1;
    cin >>t;
    for(int i=1;i<=t;i++)
    {

        int n;
        cin >>n;
        int s=n%7;
        if(s==2)
        {
            cout <<1;
            for(int j=1;j<=(n-2)/7;j++)
            {
                cout <<8;
            }
        }
        else if(n==1)
        {
            cout <<-1;
        }
        else if(n==2)
        {

            cout <<1;
        }
        else if(n%7==0)
        {
            for(int j=n;j>0;j-=7)
            {
                cout <<8;
            }
        }
        else if(n==6)
        {
            cout <<6;
        }
        else if(n%7==1)
        {
            cout <<10;
            for(int j = 1;j<=(n-8)/7;j++)
            {
                
                cout <<8;
            }
                
        }
        else if(n==3 )
        {

                cout <<7;

        }
        else{}
        cout <<d[n];



    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}
