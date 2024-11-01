#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if(num<2) cout << -1 << endl;
        else if(num>=2 && num <=7)
        {
            switch(num)
            {
                case 2:
                    cout << 1 << endl;break;
                case 3:
                    cout << 7 << endl;break;
                case 4:
                    cout << 4 << endl;break;
                case 5:
                    cout << 2 << endl;break;
                case 6:
                    cout << 6 << endl;break;
                case 7:
                    cout << 8 << endl;break;
                default:
                    break;
            }
        }
        else
        {
            int cnt = 0;
            int ans = 0;
            while(num>14)
            {
                num -= 7;
                cnt++;
            }
            switch(num)
            {
                case 8:
                    ans = 10;break;
                case 9:
                    ans = 18;break;
                case 10:
                    ans = 23;break;
                case 11:
                    ans = 20;break;
                case 12:
                    ans = 28;break;
                case 13:
                    ans = 68;break;
                case 14:
                    ans = 77;break;
                default:
                    break;
            }
            ans *= pow(10,cnt);
            while(cnt>=1)
            {
                cnt--;
                ans+=8*pow(10,cnt);
            }
            cout << ans << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
