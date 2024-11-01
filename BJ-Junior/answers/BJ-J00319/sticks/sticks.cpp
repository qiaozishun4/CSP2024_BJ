#include<iostream>
using namespace std;
char a[1005][1005];
bool flag[1005][1005]={false};
int num[10]={6,5,5,5,4,5,6,3,7,6};
int main()
{
    int n,t,a,b,c;
    bool flag=false;
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdin);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        flag=false;
        cin>>n;
        for(int j=0;j<=n;j++)
        {

            a=j/100;
            b=a%10;
            c=j%10;
            if(num[a-1]+num[b-1]==n)
            {
                if(a==0&&b==0)
                {
                    cout<<c<<endl;
                }
                else if(a==0)
                {
                    cout<<b<<c<<endl;
                }
                else
                    cout<<a<<b<<c<<endl;
                flag=true;
                break;
            }
        }
        if(flag==false)
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
