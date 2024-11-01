#include<bits/stdc++.h>
using namespace std;
long long t;
long long n,n1,n2;
long long i;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=0;i<=t;i++)
    {
        cin>>n;
        if(n=1)
        {
            cout<<-1;
        }
        while(true)
        {
            i++;
            while(i>0)
            {
                n1=i%10;
                i/=10;
                n2+=a[n1];
                if(n2>n)
                {
                    break;
                }
            }
            if(n2==n)
            {
                cout<<i<<endl;
                break;
            }
        }
        n1=0;
        n2=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*2
 1 5 4
 1 1 2
 ....x
 5 5 20
 1 1 0
 .....
 .xxx.
 .x.x.
 ..xx.
 x....*/
