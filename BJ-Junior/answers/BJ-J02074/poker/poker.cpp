#include<iostream>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.in","w",stdout);
    int b,c;
    int a;
    cin>>c;
    for(int i=0;i<=c;i++)
    {
        cin<<a;
        b+=1;
    }
    cout<<52-b;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

