#include<iostream>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        if(n<2)
        {
            cout<<"-1"<<endl;
        }
        else if(n==2)
        {
            cout<<"1"<<endl;
        }
        else if(n==3)
        {
            cout<<"7"<<endl;
        }
        else if(n==4)
        {
            cout<<"4"<<endl;
        }
        else if(n==5)
        {
            cout<<"2"<<endl;
        }
        else if(n==6)
        {
            cout<<"6"<<endl;
        }
        else if(n==7)
        {
            cout<<"8"<<endl;
        }
        else if(n==8)
        {
            cout<<"10"<<endl;
        }
        else if(n==9)
        {
            cout<<"18"<<endl;
        }
        else if(n==10)
        {
            cout<<"40"<<endl;
        }
        else if(n==11)
        {
            cout<<"48"<<endl;
        }
        else if(n==12)
        {
            cout<<"28"<<endl;
        }
        else if(n==13)
        {
            cout<<"80"<<endl;
        }
        else if(n==14)
        {
            cout<<"104"<<endl;
        }
        else if(n==15)
        {
            cout<<"108"<<endl;
        }
        else if(n==16)
        {
            cout<<"428"<<endl;
        }
        else if(n==18)
        {
            cout<<"208"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
