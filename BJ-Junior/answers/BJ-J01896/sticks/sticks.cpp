#include<iostream>
#include<cstring>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,a[11]={6,2,5,5,4,5,6,3,7,6};
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        if(n%7==0)
        {
            int c=n/7;
            for(int i=1;i<=c;i++)
            {
            cout<<"8";
            }
        }
        else if(n<7)
        {
            for(int j=0;j<9;j++)
            {
                if(n==a[j])
                {
                    cout<<j+1;
                    break;
                }
            }
        }
        else if(7<n<14)
        {
            for(int j=0;j<9;j++)
            {
                for(int k=j+1;j<9;j++)
                {
                    if(a[j]+a[k]==n)
                    {
                    cout<<a[j]+a[k]+2;
                    break;
                    }
                }
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
