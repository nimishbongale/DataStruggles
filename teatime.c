#include<stdio.h>
#include<string.h>

struct teatime
{
	char snackname[30];
	int price;
}obj1,obj2;

void insert1(struct teatime obj)
{
	scanf("%s",obj.snackname);	
	scanf("%d",&obj.price);
}

void insert2(struct teatime *obj)
{
	scanf("%s",obj->snackname);
	scanf("%d",&obj->price);
}

void display(struct teatime o)
{
	puts(o.snackname);
	printf("%d",o.price);
}

int main()
{
	printf("\nEnter the details of obj1 (snackname,price)\n");
	scanf("%s",obj1.snackname);
	scanf("%d",&obj1.price);
	printf("\nEnter details of obj1 again (snackname,price)\n");
	insert1(obj1);
	printf("\nCurrent values of obj1(Call by value) (snackname,price)\n");
	display(obj1);

	printf("\nEnter the details of obj2 (snackname,price)\n");
	scanf("%s",obj2.snackname);
	scanf("%d",&obj2.price);
	printf("\nEnter details of obj2 again (snackname,price)\n");
	insert2(&obj2);
	printf("\nCurrent values of obj2(Call by reference) (snackname,price)\n");
	display(obj2);

	return 0;
}


