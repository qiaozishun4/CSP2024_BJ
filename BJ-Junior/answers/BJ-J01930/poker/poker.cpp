#include <iostream>

using namespace std;

struct card
{
    char color;
    char num;
};

bool poker[5][14];
card input[53];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>input[i].color>>input[i].num;
    }
    int ans=52;
    for(int i=1;i<=n;i++)
    {
        int num1;
        int color1;
        if(input[i].color=='D')
        {
            color1=1;
        }
        else if(input[i].color=='C')
        {
            color1=2;
        }
        else if(input[i].color=='H')
        {
            color1=3;
        }
        else if(input[i].color=='S')
        {
            color1=4;
        }
        if(input[i].num<58)
        {
            num1=input[i].num-48;
        }
        else if(input[i].num=='A')
        {
            num1=1;
        }
        else if(input[i].num=='T')
        {
            num1=10;
        }
        else if(input[i].num=='J')
        {
            num1=11;
        }
        else if(input[i].num=='Q')
        {
            num1=12;
        }
        else if(input[i].num=='K')
        {
            num1=13;
        }
        if(!poker[color1][num1])
        {
            poker[color1][num1]=true;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
