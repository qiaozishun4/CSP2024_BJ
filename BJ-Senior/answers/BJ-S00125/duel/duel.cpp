#include<bits/stdc++.h>
using namespace std;

struct HME
{

    int d;
    int b;
    int o;
};
HME a[1145143];
int h[1145143], q;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    long long n;
    cin >>n;
    for(int i = 1;i<=n;i++)
    {
        int f;
        scanf("%d", &f);
        a[i].b=f;a[i].d=f;a[i].o=f;//cout <<a[i].b;
    }
   for(int i = 1;i<=n;i++)
   {
       for(int j = 1;j<i;j++)
       {
           if(a[i].b < a[j].b)
           {
               swap(a[i], a[j]);
           }
       }
   }

    int q=n;

    for(int i = 1;i<=n;i++)
    {
        for(int j = i;j<=n;j++)
        {
            if(a[i].b !=-1 &&a[i].d<a[j].d &&a[j].o!=-2 &&a[j].b !=-1 )
            {
               // cout <<i << ' ' <<j <<' ' <<a[i] << ' ' <<a[j] << endl;

                q--;a[j].o=-2;a[i].b=-1;
            }

        }

    }
    printf("%d", q);
    fclose(stdin);
    fclose(stout);
    return 0;
}
