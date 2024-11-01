#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005]={0};
/*
a:
a[i]=x: i's attack & defense is x

b:
b[i]=0: i can attack
b[i]=1: i cannot attack
b[i]=2: i is dead


1 2 3 4

2>>1
3>>1
    3>>2
4>>1
    4>>2
        4>>3
*/
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    /*
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<endl;
    }
    */
    /*
    atk:
    atk=1:there are monsters can attack
    atk=0:there aren't any monster can attack
    */
    bool atk=1;
    //gamestart
    while(atk)
    {
        //min1:is attacked
        //min2:attack min1
        //num1:num of min1
        //num2:num of min2
        int min1=100005,min2=100005,num1=0,num2=0;
        //get min1
        for(int i=1;i<=n;i++)
        {
            if(a[i]<min1&&b[i]!=2)
                min1=a[i];
        }
        //cout<<min1<<endl;
        //get num1
        for(int i=1;i<=n;i++)
        {
            if(a[i]==min1)
            {
                b[i]=1;
                num1++;
            }
        }
        //cout<<num1<<endl;
        //get min2
        for(int i=1;i<=n;i++)
        {
            if(a[i]<min2&&b[i]==0)
                min2=a[i];
        }
        //cout<<min2<<endl;
        //get num2
        for(int i=1;i<=n;i++)
        {
            if(a[i]==min2)
            {
                num2++;
            }
        }
        //cout<<num2<<endl;
        int times;
        //times:how many times min1s is attacked
        //get times
        if(num1>num2)
            times=num2;
        else
            times=num1;
        //attacking
        for(int i=1;times>0;i++)
        {
            if(a[i]==min2)
            {
                b[i]=1;
                times--;
            }
        }
        times=min(num1,num2);
        //dying
        for(int i=1;times>0;i++)
        {
            if(a[i]==min1)
            {
                b[i]=2;
                times--;
            }
        }
        //make sure if the game is end
        atk=0;
        for(int i=1;i<=n;i++)
        {
            if(b[i]==0)
            {
                atk=1;
                break;
            }
        }
    }
    /*
    ans:
    ans=x:there are x monsters alive
    */
    int ans=0;
    //get ans
    for(int i=1;i<=n;i++)
    {
        if(b[i]!=2)
            ans++;
    }
    cout<<ans;
    return 0;
}
