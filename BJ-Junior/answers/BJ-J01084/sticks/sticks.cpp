#include<bits/stdc++.h>
using namespace std;
int n;
int c[100010];
int numb[10] = {6,2,5,5,4,5,6,3,7,6};
unsigned long long minn = 1e11;
int minstep = 100001;
void dfs(int step,int sum)
{
    if(step > minstep)
    {
        return;
    }
    if(step <= minstep && sum == n)
    {
        minstep = step;
        unsigned long long a = 0;
        for(int i = 0;i < step;i++)
        {
            a = a * 10 + c[i];
        }
        if(a < minn)
        {
            minn = a;
        }
        return;
    }
    if(step == 0)
    {
        for(int i = 1;i <= 9;i++)
        {
            c[step] = i;
            dfs(step+1,sum+numb[i]);
        }
    }
    else
    {
        for(int i = 0;i <= 9;i++)
        {
            c[step] = i;
            dfs(step+1,sum+numb[i]);
        }
    }
    return;
}
int main()
{
    int t;
    cin>>t;
    for(int c = 1;c <= t;c++)
    {
        cin>>n;
        if(n == 1)
        {
            cout<<-1<<endl;
        }
        else if(n == 2)
        {
            cout<<1<<endl;
        }
        else if(n == 3)
        {
            cout<<7<<endl;
        }
        else if(n == 4)
        {
            cout<<4<<endl;
        }
        else if(n == 5)
        {
            cout<<2<<endl;
        }
        else if(n == 6)
        {
            cout<<6<<endl;
        }
        else if(n == 7)
        {
            cout<<8<<endl;
        }
        else if(n == 8)
        {
            cout<<10<<endl;
        }
        else if(n == 9)
        {
            cout<<18<<endl;
        }
        else if(n == 10)
        {
            cout<<22<<endl;
        }
        else if(n == 11)
        {
            cout<<20<<endl;
        }
        else if(n == 12)
        {
            cout<<28<<endl;
        }
        else if(n == 13)
        {
            cout<<68<<endl;
        }
        else if(n == 14)
        {
            cout<<88<<endl;
        }
        else if(n == 15)
        {
            cout<<108<<endl;
        }
        else if(n == 16)
        {
            cout<<188<<endl;
        }
        else if(n == 17)
        {
            cout<<200<<endl;
        }
        else if(n == 18)
        {
            cout<<208<<endl;
        }
        else if(n == 19)
        {
            cout<<288<<endl;
        }
        else if(n == 20)
        {
            cout<<688<<endl;
        }
        else
        {
            dfs(0,0);
            cout<<minn<<endl;
            minn = 1e11;
            minstep = 100001;
        }
    }
    return 0;
}