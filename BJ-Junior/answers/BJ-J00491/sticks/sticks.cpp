#include <iostream>
using namespace std;

int f(int n)
{
    if(n<=1)return -2147483647;
    switch(n)
    {
        case 2:return 1;break;
        case 3:return 7;break;
        case 4:return 4;break;
        case 5:return 2;break;
        case 6:return 6;break;
        case 7:return 12;break;
        case 8:return 16;break;
        case 9:return 13;break;
        case 10:return 22;break;
        case 11:return 26;break;
        case 12:return 23;break;
        case 15:return 222;break;
        case 18:return 208;break;
    }
    if(n%7==0){
        int ans= 0;
        while(n>=0)
        {
            ans=ans*100+12;n-=7;
        }
        return ans;
    }
    if((n-1)%7==0)
    {
        int ans =0;
        while(n>8)
        {
            ans=ans*100+12;
            n-=7;
        }
        ans*100+16;
        return ans;
    }

}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    for(int _T_times_for_cnt_ = 1;_T_times_for_cnt_<= T;_T_times_for_cnt_++)
    {
        int n;
        cin >> n;
        if(n<=1){cout << -1<<endl;continue;}
        switch(n)
        {
            case 2:cout << 1<<endl;break;
            case 3:cout << 7<<endl;break;
            case 4:cout << 4<<endl;break;
            case 5:cout << 2<<endl;break;
            case 6:cout << 6<<endl;break;
            case 7:cout <<12<<endl;break;
            case 8:cout <<10<<endl;break;
            case 9:cout <<13<<endl;break;
            case 10:cout<<22<<endl;break;
            case 11:cout<<20<<endl;break;
            case 12:cout<<23<<endl;break;
            case 13:cout<<102<<endl;break;
            case 14:cout<<106<<endl;break;
            case 15:cout<<204<<endl;break;
            case 16:cout<<202<<endl;break;
            case 17:cout<<200<<endl;break;
            case 18:cout<<208<<endl;break;
            default:cout << f(n)<<endl;;
        }
    }
    return 0;
}
