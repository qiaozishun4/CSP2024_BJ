#include<bits/stdc++.h>
using namespace std;
int n=0;
int T=0;
vector<int> number;
vector<int> temp;

void veceq(int len)
{
    for(int i=0;i<len;i++)
        number[i]=temp[i];
}

int searchnum(int m,int len)
{
    if(m==0) return len;
    if(m<0) return -1;
    int reslen=100000;
    int curres;
    if(len==1)
    {
        temp[len-1]=1;
        curres=searchnum(m-2,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }

        temp[len-1]=2;
        curres=searchnum(m-5,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }

        temp[len-1]=4;
        curres=searchnum(m-4,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }

        temp[len-1]=6;
        curres=searchnum(m-6,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }

        temp[len-1]=7;
        curres=searchnum(m-3,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }

        temp[len-1]=8;
        curres=searchnum(m-7,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }


        if(reslen==100000) return -1;
        else return reslen;
    }
    else
    {
        temp[len-1]=0;
        curres=searchnum(m-6,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }
        temp[len-1]=1;
        curres=searchnum(m-2,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }

        temp[len-1]=2;
        curres=searchnum(m-5,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }

        temp[len-1]=4;
        curres=searchnum(m-4,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }

        temp[len-1]=7;
        curres=searchnum(m-3,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }

        temp[len-1]=8;
        curres=searchnum(m-7,len+1);
        if(curres!=-1 && curres<reslen)
        {
            reslen=curres;
            veceq(reslen);
        }


        if(reslen==100000) return -1;
        else return reslen;
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    int ans;
    for(int t=0;t<T;t++)
    {
        cin>>n;
        ans=searchnum(n,1);
        if(ans==-1)
        {
            cout<<-1<<endl;
        }
        else
        {
            for(int i=ans-1;i>=0;i--)
                cout<<number[i];
            cout<<endl;
        }
    }
    return 0;
}