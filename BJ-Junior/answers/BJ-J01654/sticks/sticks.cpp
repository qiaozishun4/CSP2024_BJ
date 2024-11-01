#include <bits/stdc++.h>
using namespace std;
int t,n,wei;
long long ans;
string ans7;
map <int,int> ma;
map <int,int> mb;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ma[1]=-1;
    ma[2]=1;
    ma[3]=7;ma[4]=4;ma[5]=2;ma[6]=6;ma[7]=8;
    ma[8]=10;ma[9]=18;
    ma[10]=22;ma[11]=20;ma[12]=28;ma[13]=68;
    ma[14]=88;ma[15]=108;ma[16]=188;ma[17]=228;
    ma[18]=208;ma[19]=288;ma[20]=688;
    mb[0]=6;mb[1]=2;mb[2]=5;mb[3]=5;mb[4]=4;
    mb[5]=5;mb[6]=6;mb[7]=3;mb[8]=7;mb[9]=6;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=20)
        {
            cout<<ma[n]<<endl;
            continue;
        }
        if(n%7==0)
        {
            wei=n/7;
            ans7="8";
            wei--;
            while(wei)
            {
                //ans=ans*10+8;
                ans7=ans7+"8";
                wei--;
            }
            cout<<ans7<<endl;
            continue;
        }
        int flag=0;
        if(n>21&&n<=50)
        {
            if(n>21&&n<=28)
            {
                for(int i=1;i<=9;i++)
                {
                    for(int j=0;j<=9;j++)
                    {
                        for(int k=0;k<=9;k++)
                        {
                            for(int w=0;w<=9;w++)
                            {
                                if(mb[i]+mb[j]+mb[k]+mb[w]==n)
                                {
                                    flag=1;
                                    cout<<i<<j<<k<<w<<endl;
                                    break;
                                }
                            }
                            if(flag==1) break;
                        }
                         if(flag==1) break;
                    }
                     if(flag==1) break;
                }

            }
            if(n>28&&n<=35)
            {
                flag=0;
                for(int i=1;i<=9;i++)
                {
                    for(int j=0;j<=9;j++)
                    {
                        for(int k=0;k<=9;k++)
                        {
                            for(int w=0;w<=9;w++)
                            {
                                for(int q=0;q<=9;q++)
                                {
                                    if(mb[i]+mb[j]+mb[k]+mb[w]+mb[q]==n)
                                    {
                                        flag=1;
                                        cout<<i<<j<<k<<w<<q<<endl;
                                        break;
                                    }

                                }
                                if(flag==1) break;
                            }
                            if(flag==1) break;
                        }
                         if(flag==1) break;
                    }
                     if(flag==1) break;
                }

            }
            if(n>35&&n<=42)
            {
                flag=0;
                for(int i=1;i<=9;i++)
                {
                    for(int j=0;j<=9;j++)
                    {
                        for(int k=0;k<=9;k++)
                        {
                            for(int w=0;w<=9;w++)
                            {
                                for(int q=0;q<=9;q++)
                                {
                                    for(int p=0;p<=9;p++)
                                    {
                                        if(mb[i]+mb[j]+mb[k]+mb[w]+mb[q]+mb[p]==n)
                                    {
                                        flag=1;
                                        cout<<i<<j<<k<<w<<q<<p<<endl;
                                        break;
                                    }
                                    }
                                    if(flag==1) break;

                                }
                                if(flag==1) break;

                            }
                            if(flag==1) break;
                        }
                         if(flag==1) break;
                    }
                     if(flag==1) break;
                }

            }
            if(n>42&&n<=49)
            {
                flag=0;
                for(int i=1;i<=9;i++)
                {
                    for(int j=0;j<=9;j++)
                    {
                        for(int k=0;k<=9;k++)
                        {
                            for(int w=0;w<=9;w++)
                            {
                                for(int q=0;q<=9;q++)
                                {
                                    for(int p=0;p<=9;p++)
                                    {
                                        for(int o=0;p<=9;p++)
                                        {
                                            if(mb[i]+mb[j]+mb[k]+mb[w]+mb[q]+mb[p]+mb[o]==n)
                                            {
                                                flag=1;
                                                cout<<i<<j<<k<<w<<q<<p<<o<<endl;
                                                break;
                                            }
                                        }
                                         if(flag==1) break;
                                    }
                                    if(flag==1) break;

                                }
                                if(flag==1) break;
                            }
                            if(flag==1) break;
                        }
                         if(flag==1) break;
                    }
                     if(flag==1) break;
                }

            }
            if(n>49&&n<=50)
            {
                flag=0;
                for(int i=1;i<=9;i++)
                {
                    for(int j=0;j<=9;j++)
                    {
                        for(int k=0;k<=9;k++)
                        {
                            for(int w=0;w<=9;w++)
                            {
                                for(int q=0;q<=9;q++)
                                {
                                    for(int p=0;p<=9;p++)
                                    {
                                        for(int o=0;p<=9;p++)
                                        {
                                            for(int s=0;s<=9;s++)
                                            {
                                               if(mb[i]+mb[j]+mb[k]+mb[w]+mb[q]+mb[p]+mb[o]+mb[s]==n)
                                            {
                                                flag=1;
                                                cout<<i<<j<<k<<w<<q<<p<<o<<s<<endl;
                                                break;
                                            }
                                            }
                                            if(flag==1) break;
                                        }
                                         if(flag==1) break;
                                    }
                                    if(flag==1) break;

                                }
                                if(flag==1) break;
                            }
                            if(flag==1) break;
                        }
                         if(flag==1) break;
                    }
                     if(flag==1) break;
                }

            }
        }
        if(flag==0) cout<<-1<<endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
