#include<iostream>
using namespace std;

int fight[100001];
bool deth[100001];
bool kill[100001];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n,tem,ans = 0;

    cin>>n;

    for(int i = 0;i < n;i++)
    {
        cin>>fight[i];
        deth[i] = false;
        kill[i] = true;
    }

    for(int i = 0;i < n;i++)
    {
        for(int j = i;j < n;j++)
        {
            if(fight[i] >= fight[j])
            {
                tem = fight[i];
                fight[i] = fight[j];
                fight[j] = tem;
            }
        }
    }

    for(int i = 0;i < n;i++)
    {
        for(int j = i;j < n;j++)
        {
            if(fight[i] < fight[j]&&kill[j] == true)
            {
                deth[i] = true;
                kill[j] = false;
                break;
            }
        }

    }

    for(int i = 0;i < n;i++)
    {
        if(deth[i] == false)
        {
            ans+= 1;
        }
    }

    cout<<ans;

    return 0;
}
