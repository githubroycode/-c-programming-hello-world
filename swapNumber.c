#include <stdio.h>

int main(){

int x, y, temp;

	printf("Enter the value of x and y:");
	scanf("%d%d",&x,&y);



printf("Before Swappingx= %dy= %d ",x,y);
	temp = x;
	x = y;
	y = temp;

printf("After Swapping x = %d y = %d ",x,y);

return 0;
	}
