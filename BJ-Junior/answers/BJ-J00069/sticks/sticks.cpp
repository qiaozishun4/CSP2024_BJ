#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    scanf("%d",&T);
    while(T--){
		scanf("%d",&n);
		if(n<7){
			if(n<=1) printf("-1");
			else if(n==2) printf("1");
			else if(n==3) printf("7");
			else if(n==4) printf("4");
			else if(n==5) printf("2");
			else printf("6");
			printf("\n");
		}
		else{
            if(n%7==0){
                for(int i=1;i<=n/7;i++) putchar('8');
                putchar('\n');
            }
            else {
                int s=n%7+7;
                if(s==8) printf("10");
                else if(s==9) printf("18");
                else if(s==10) printf("23");
                else if(s==11) printf("20");
                else if(s==12) printf("28");
                else if(s==13) printf("68");
                for(int i=1;i<=(n/7-1);i++) putchar('8');
                putchar('\n');
            }
		}
	}
	    return 0;
}
