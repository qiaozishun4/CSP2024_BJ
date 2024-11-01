#include <bits/stdc++.h>
using namespace std;
//const int zero=6,one=2,two=5,three=5,four=4,five=5,six=6,seven=3,eight=7,nine=6;
int a[100005];

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[i]=x;
    }
    for(int i=1;i<=n;i++){
        if(i==n)
        {
            if(a[i]==1) cout << -1;
            else if(a[i]%7==0){
                for(int j=1;j<=a[i]/7;j++) cout << 8;
            }
            else if((a[i]-1)%7==0){
                cout << 10;
                for(int j=1;j<=((a[i]-1)/7)-1;j++) cout << 8;
            }
            else if(a[i]<=6){
                if(a[i]==2) cout << 1;
                else if(a[i]==3) cout << 7;
                else if(a[i]==4) cout << 4;
                else if(a[i]==5) cout << 2;
                else if(a[i]==6) cout << 6;
            }
        }
        else
        {
            if(a[i]==1) cout << -1 << endl;
            else if(a[i]%7==0){
                for(int j=1;j<=a[i]/7;j++) cout << 8;
                printf("\n");
            }
            else if((a[i]-1)%7==0){
                cout << 10;
                for(int j=1;j<=((a[i]-1)/7)-1;j++) cout << 8;
                printf("\n");
            }
            else if(a[i]<=6){
                if(a[i]==2) cout << 1;
                else if(a[i]==3) cout << 7;
                else if(a[i]==4) cout << 4;
                else if(a[i]==5) cout << 2;
                else if(a[i]==6) cout << 6;
                printf("\n");
            }
        }
    }
    return 0;
}

