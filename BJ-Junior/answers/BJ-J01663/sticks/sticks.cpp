#include <bits/stdc++.h>
#include <iostream>

int num[101]={0};
int arr[11]={0};
int ans=100,p,temp,a=0;

int comp()
{
    for (int i=1;i<=p;i++)
    {
        for (int j=0;j<(p-i);j++)
        {
            temp*=10;
        }
        a+=num[i]*temp;
    }
    if (a<ans)
    {
        ans=a;
    }
    return 0;
}

int dp(int n,int p,int k)
{
    if (n==0)
    {
        if (k==p+1)
        {

            comp();
            return 0;
        }
        else{
            return 0;
        }
    }
    if (k>p&&n>0)
    {
        return 0;

    }

   for (int i=k;i<=p;i++)
    {
        if (i==1)
        {
            for (int j=1;j<=9;j++)
            {
                if (n>=arr[j])
                {
                    num[i]=j;
                    dp(n-arr[j],p,k+1);

                }
            }
        }
        else
        {
            for (int j=0;j<=9;j++)
            {
                if (n>=arr[j])
                {
                    num[i]=j;
                    dp(n-arr[j],p,k+1);

                }
            }

        }
   }


}
int main()
{

    arr[0]=6;
    arr[1]=2;
    arr[2]=5;
    arr[3]=5;
    arr[4]=4;
    arr[5]=5;
    arr[6]=6;
    arr[7]=3;
    arr[8]=7;
    arr[9]=6;
    int t,n;
    std::cin>>t;

    for (int i=0;i<t;i++)
    {
        std::cin>>n;
        if (n%7==0)
        {
            p=n/7;
        }
        else
        {
            p=n/7+1;
        }
        dp(n,p,1);
        std::cout<<ans<<std::endl;
        ans=100;
        a=0;

    }


}
