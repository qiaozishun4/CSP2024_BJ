#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+5;
int n,T;
vector<int> a;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
		a.clear();
        cin>>n;
        for(int i=1;i<=ceil(1.0*n/7);i++)
        {
            a.push_back(8);
        }
        if(n>=7)
        {
            switch(7-n%7)
            {
            case 1:
                a[0]=6;
            break;
            case 2:
                a[0]=2;
            break;
            case 3:
                a[0]=2;
                a[1]=0;
            break;
            case 4:
                a[0]=2;
                a[1]=2;
            break;
            case 5:
                a[0]=1;
            break;
            case 6:
                a[0]=1;
                a[1]=6;
            break;
            }
        }
        else
        {
			a.clear();
            switch(n)
            {
            case 0:
            case 1:
                a.push_back(-1);
            break;
            case 2:
                a.push_back(1);
            break;
            case 3:
                a.push_back(7);
            break;
            case 4:
                a.push_back(4);
            break;
            case 5:
                a.push_back(2);
            break;
            case 6:
                a.push_back(6);
            break;
            }
        }
        for(auto i:a)
        {
            cout<<i;
        }
        cout<<endl;
    }
    return 0;
}
