# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void radix_sort(char **,int);
void count_sort(char **input,int n,int index)
{
	int i,count[26]={0};
	for(i=0;i<n;i++){
		if(strlen(input[i]) > index){
			count[input[i][index]-'a']++;
		}
	}

	for(i=1;i<26;i++){
		count[i] += count[i-1];
	}

	char output[n][100];
	int j=0;
	for(i=0;i<n;i++){
		if(strlen(input[i])<=index){
			strcpy(output[j++],input[i]);
		}
	}

	for(i=n-1;i>=0;i--){
		if(strlen(input[i])>index){
			strcpy(output[count[input[i][index]-'a']-1+j],input[i]);
			count[input[i][index]-'a']--;
		}
	}

	for(i=0;i<n;i++){
		strcpy(input[i],output[i]);
	}
}



int main()
{
	char **input;
	char ch=' ';
	int n,i,j;
	scanf("%d",&n);
	input = (char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++)
	{
		input[i]=(char *)malloc((100)*sizeof(char));
		scanf("%s",input[i]);
	}
	radix_sort(input,n);
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}

	return 0;
}

void radix_sort(char **input,int n)
{
	int i,max=0;
	for(i=0;i<n;i++){
		if(max<strlen(input[i])){
			max=strlen(input[i]);
		}
	}
	for(i=max-1;i>=0;i--){
		count_sort(input,n,i);
	}
}
