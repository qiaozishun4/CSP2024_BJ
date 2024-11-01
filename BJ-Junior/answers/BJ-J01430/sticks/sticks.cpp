#include<iostream>
using namespace std;

void f(int x){
	int p;
	if(x % 7 == 0) 
	{
		int m = x / 7;
		for(int i = 1; i <= m; i++) printf("8");
		printf("\n");
		return ;
	}
	else if(x % 7 == 1 && x != 1 && x != 8)
	{
		int m = (x - 1) / 7 - 1;
		printf("10");
		for(int i = 1; i <= m; i++) printf("8");
		printf("\n");
		return ;
	}
	else if(x % 7 == 2 && x != 2)
	{
		int m = (x - 2) / 7;
		printf("1");
		for(int i = 1; i <= m; i++) printf("8");
		printf("\n");
		return ;
	}
	else if(x % 7 == 3 && x != 3 && x != 10 && x != 17)
	{
		int m = (x - 3) / 7 - 2;
		printf("200");
		for(int i = 1; i <= m; i++) printf("8");
		printf("\n");
		return ;
	}
	else if(x % 7 == 4 && x != 4 && x != 11)
	{
		int m = (x - 4) / 7 - 1;
		printf("20");
		for(int i = 1; i <= m; i++) printf("8");
		printf("\n");
		return ;
	}
	else if(x % 7 == 5 && x != 5)
	{
		int m = (x - 5) / 7;
		printf("2");
		for(int i = 1; i <= m; i++) printf("8");
		printf("\n");
		return ;
	}
	else if(x % 7 == 6 && x != 6)
	{
		int m = (x - 6) / 7;
		printf("6");
		for(int i = 1; i <= m; i++) printf("8");
		printf("\n");
		return ;
	}
	else if(x == 1) p = -1;
	else if(x == 2) p = 1;
	else if(x == 3) p = 7;
	else if(x == 4) p = 4;
	else if(x == 5) p = 2;
	else if(x == 6) p = 6;
	else if(x == 8) p = 10;
	else if(x == 10) p = 22;
	else if(x == 11) p = 20;
	else if(x == 17) p = 200;
	printf("%d\n", p);
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	scanf("%d", &t);
	int tr[55], count = 1;
	while(t--)
	{
		int n;
		scanf("%d", &n);
		tr[count] = n;
		count++;
	}
	for(int i = 1; i < count; i++) f(tr[i]);
	return 0;
}
