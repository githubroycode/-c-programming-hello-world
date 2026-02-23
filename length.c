#include <stdio.h>
int main(){
	int i = 0;
	char str[20];
	printf("Enter any string:");
	int gets(str);
	while(str[i]!='\0')
	{
		i++;
	}
	printf("Length of given string: %d",i);
	}
