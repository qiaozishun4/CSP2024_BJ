#include<bits/stdc++.h>
using namespace std;

int n;
int dis[]={6,2,5,5,4,5,6,3,7,6};
int sum[15];

void dfs(int step)
{
    if (step<=13)
    {
        if (step==13)
        {
            sum[6]++;
            sum[8]++;
        }
        else if (step==12)
        {
            sum[2]++;
            sum[8]++;
        }
        else if (step==11)
        {
            sum[0]++;
            sum[2]++;
        }
        else if (step==10)
        {
            sum[2]=sum[2]+2;
        }
        else if (step==9)
        {
            sum[1]++;
            sum[8]++;
        }
        else if (step==8)
        {
            sum[0]++;
            sum[1]++;
        }
        else if (step==7) sum[8]++;
        //for (int i=0;i<=9;i++)
        //    cout << sum[i] << " ";
        //cout << endl;
        for (int i=1;i<=9;i++)
            if (sum[i])
            {
                sum[i]--;
                cout << i;
                break;
            }
        for (int i=0;i<=9;i++)
            for (int j=1;j<=sum[i];j++)
                cout << i;
        cout << endl;
        return;
    }
    sum[8]++;
    dfs(step-7);
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(sum,0,sizeof(sum));
        cin >> n;
        if (n==1) cout << -1 << endl;
        else if (n==2) cout << 1 << endl;
        else if (n==3) cout << 7 << endl;
        else if (n==4) cout << 4 << endl;
        else if (n==5) cout << 2 << endl;
        else if (n==6) cout << 6 << endl;
        else if (n==7) cout << 8 << endl;
        else if (n==8) cout << 10 << endl;
        else if (n==9) cout << 18 << endl;
        else if (n==10) cout << 22 << endl;
        else if (n==11) cout << 20 << endl;
        else if (n==12) cout << 28 << endl;
        else if (n==13) cout << 68 << endl;
        else dfs(n);
    }

    return 0;
}
