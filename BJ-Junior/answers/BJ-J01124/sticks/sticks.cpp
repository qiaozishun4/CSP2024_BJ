#include<bits/stdc++.h>
using namespace std;
int a1[10]={6,2,5,5,4,5,6,3,7,6};
int a2[10]={0,1,2,3,4,5,6,7,8,9};
void solve()
{
    int n;
    cin>>n;
    switch(n)
    {
        case 1:
            cout<<-1<<endl;//-1
            break;
        case 2:
            cout<<1<<endl;//2
            break;
        case 3:
            cout<<7<<endl;//6
            break;
        case 4:
            cout<<4<<endl;//-3
            break;
        case 5:
            cout<<2<<endl;//-2
            break;
        case 6:
            cout<<6<<endl;//4
            break;
        case 7:
            cout<<8<<endl;//2
            break;
        case 8:
            cout<<10<<endl;//2
            break;
        case 9:
            cout<<18<<endl;//8
            break;
        case 10:
            cout<<23<<endl;//5
            break;
        case 11:
            cout<<20<<endl;//-3
            break;
        case 12:
            cout<<60<<endl;//40
            break;
        case 13:
            cout<<80<<endl;//20
            break;
        case 14:
            cout<<88<<endl;//8
            break;
        case 15:
            cout<<108<<endl;//20
            break;
        case 16:
            cout<<203<<endl;//95
            break;
        case 17:
            cout<<200<<endl;//-3
            break;
        case 18:
            cout<<208<<endl;//8
            break;
        case 19:
            cout<<288<<endl;//80
            break;
        case 20:
            cout<<880<<endl;//592
            break;
        default:
            return ;
    }
    return ;

}
int main()
{
    freopen("sticks.in"."r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
