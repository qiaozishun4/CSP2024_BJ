#include<bits/stdc++.h>
using namespace std;
int n[55],s[10];
int stick(int a)
{
    if(a<2)
    {
        return -1;
    }
    else if(a<8)
    {
        for(int j=1;j<10;j++)
        {
            if(a==s[j])
            {
                return j;
            }
        }
    }
    else if(a<15)
    {
        for(int j=1;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(s[j]+s[k]==a)
                {
                    return 10*j+k;
                }
            }
        }
    }
    else if(a<22)
    {
        for(int j=1;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<10;l++)
                {
                    if(s[j]+s[k]+s[l]==a)
                    {
                        return 100*j+10*k+l;
                    }
                }
            }
        }
    }
    else if(a<29)
    {
        for(int j=1;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<10;l++)
                {
                    for(int m=0;m<10;m++)
                    {
                        if(s[j]+s[k]+s[l]+s[m]==a)
                        {
                            return 1000*j+100*k+10*l+m;
                        }
                    }
                }
            }
        }
    }
    else if(a<36)
    {
        for(int j=1;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<10;l++)
                {
                    for(int m=0;m<10;m++)
                    {
                        for(int o=0;o<10;o++)
                        {
                            if(s[j]+s[k]+s[l]+s[m]+s[o]==a)
                            {
                                return 10000*j+1000*k+100*l+10*m+o;
                            }
                        }
                    }
                }
            }
        }
    }
    else if(a<43)
    {
        for(int j=1;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<10;l++)
                {
                    for(int m=0;m<10;m++)
                    {
                        for(int o=0;o<10;o++)
                        {
                            for(int p=0;p<10;p++)
                            {
                                if(s[j]+s[k]+s[l]+s[m]+s[o]+s[p]==a)
                                {
                                    return 100000*j+10000*k+1000*l+100*m+10*o+p;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(a<50)
    {
        for(int j=1;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<10;l++)
                {
                    for(int m=0;m<10;m++)
                    {
                        for(int o=0;o<10;o++)
                        {
                            for(int p=0;p<10;p++)
                            {
                                for(int q=0;q<10;q++)
                                {
                                    if(s[j]+s[k]+s[l]+s[m]+s[o]+s[p]+s[q]==a)
                                    {
                                        return 1000000*j+100000*k+10000*l+1000*m+100*o+10*p+q;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(a<57)
    {
        for(int j=1;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<10;l++)
                {
                    for(int m=0;m<10;m++)
                    {
                        for(int o=0;o<10;o++)
                        {
                            for(int p=0;p<10;p++)
                            {
                                for(int q=0;q<10;q++)
                                {
                                    for(int r=0;r<10;r++)
                                    {
                                        if(s[j]+s[k]+s[l]+s[m]+s[o]+s[p]+s[q]+s[r]==a)
                                        {
                                            return 10000000*j+1000000*k+100000*l+10000*m+1000*o+100*p+10*q+r;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int t;
    cin>>t;
    s[0]=6;
    s[1]=2;
    s[2]=5;
    s[3]=5;
    s[4]=4;
    s[5]=5;
    s[6]=6;
    s[7]=3;
    s[8]=7;
    s[9]=6;
    for(int i=1;i<=t;i++)
    {
        cin>>n[i];
    }
    for(int i=1;i<=t;i++)
    {
        cout<<stick(n[i])<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
