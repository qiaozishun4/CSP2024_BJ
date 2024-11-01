#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    int sum;
    sum = n;
    int he=0;
    int cishu=0;
    int list[n]={};
    int atk[n]={};
    int max2;
    int p;
    for(int i = 0 ;i<n;i++)
    {
        cin >> list[i];//输入数据
        atk[i]=1;
        he=he+list[i];
    }
    sort(list,list+n);
    max2=list[n-1];
    for(int i = 0;i<n;i++)
    {
        sort(list,list+n);
        if((list[0]*sum) == he)
        {
            cout << sum;
            return 0;
        }
        if(list[i]>list[0])
        {
            if(atk[i]==1)
            {
                he=he-list[0];
                sum--;
                list[0]=1000000;
                cishu=cishu+1;
                atk[i]=0;
                p=atk[0];
                for(int j = 0;j<n;j++)
                {
                    atk[j]=atk[j+1];
                }
                atk[n-1]=p;
                i=0;
                }
        }
        if(list[i+1]>max2)
        {
            cout<<sum;
            return 0;
        }


    }
    return 0;
}

