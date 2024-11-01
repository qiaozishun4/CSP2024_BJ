#include<bits/stdc++.h>
using namespace std;
struct stu{
    int ge;
    string num;
}a[100050]={{0,"0"},{0,"0"},{1,"1"},{1,"7"},{1,"4"},{1,"2"},{1,"6"},{1,"8"}};
int mu(int x){
    switch(x)
    {
        case 0:return 6;
        case 1:return 2;
        case 2:return 5;
        case 3:return 5;
        case 4:return 4;
        case 5:return 5;
        case 6:return 6;
        case 7:return 3;
        case 8:return 7;
        case 9:return 6;
    }
}
string fu(char x){
    switch(x)
    {
        case '0':return "0";
        case '1':return "1";
        case '2':return "2";
        case '3':return "3";
        case '4':return "4";
        case '5':return "5";
        case '6':return "6";
        case '7':return "7";
        case '8':return "8";
        case '9':return "9";
    }
}
void jin(int i,int x){
    int k=mu(x);
    string f=fu(x+'0');
    if(a[i].ge+1<a[i+k].ge||a[i+k].ge==0)
    {
        a[i+k].ge=a[i].ge+1;
        a[i+k].num=a[i].num+f;
        return;
    }
    if(a[i].ge+1==a[i+k].ge&&a[i].num+f<a[i+k].num){
        a[i+k].ge=a[i].ge+1;
        a[i+k].num=a[i].num+f;
        return;
    }
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=2;i<=10000;i++){
        if(i+6<=10000) jin(i,0);
        if(i+2<=10000) jin(i,1);
        if(i+5<=10000) jin(i,2);
        if(i+4<=10000) jin(i,4);
        if(i+3<=10000) jin(i,7);
        if(i+7<=10000) jin(i,8);
    }
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        if(n==1)
            printf("-1\n");
        else
        {
            if(n<=100)
                cout<<a[n].num<<"\n";
            else
            {
                int x=n/7;
                x-=10;
                cout<<a[n-x*7].num;
                for(int i=1;i<=x;i++)
                    printf("8");
                printf("\n");
            }
        }

    }
    return 0;
}
