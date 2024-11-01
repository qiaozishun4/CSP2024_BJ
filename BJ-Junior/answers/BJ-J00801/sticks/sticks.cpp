#include<bits/stdc++.h>
using namespace std;
int num[10] = {6,2,5,5,4,5,6,3,7,6},num1[8] = {-1,-1,1,7,4,2,0,8};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for (int i = 0;i < t;i++)
    {
        int n;
        cin>>n;
        if (n == 1)
        {
            cout<<-1<<"\n";
            continue;
        }
        else if (n <= 7)
        {
            for (int j = 0;j < 10;j++)
            {
                if (num[j] == n)
                {
                    if (n == 6)
                    {
                        cout<<6<<"\n";
                        break;
                    }
                    cout<<j<<"\n";
                    break;
                }
            }
            continue;
        }
        else if (n % 7 == 0)
        {
            long long ans = 0;
            for (int j = 0;j < n / 7;j++)
            {
                ans += 8 *  pow(10,j);

            }
            cout<<ans<<"\n";
            continue;
        }
        else
        {
            long long ans =0,j = 0;
            while(n > 14)
            {
                ans = ans * 10 + 8;
                n-=7;
                j++;
            }
            if (n == 14)
            {
                ans = (ans * 10 + 8) * 10 + 8;
            }
            else
            {
                for (int k = 1;k <= 9;k++)
                {
                    if (n - num[k] <= 7)
                    {
                        if (k != 0){
                        ans += k * pow(10,j+1);
                        ans += num1[n-num[k]] * pow(10,j);
                        break;
                        }
                        else
                        {
                            ans += 6 * pow(10,j+1);
                            ans += (num1[n-num[k]] * pow(10,j));
                            break;
                        }
                    }
                }
                cout<<ans<<"\n";
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
