#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

	printf("Enter the number of terms: ");
	scanf("%d", &num);

	printf("1 to %d:\n", num);
	display(num);

	return 0;
}

void display(int num)
{
	if (num)
		display(num - 1);
	else
		return;

	printf("%d ", num);
}
