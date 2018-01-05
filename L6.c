#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct records{

	char name[50];
	int Mmark;
	int Fmark;

};


int main(){

	int k, count1 = 1;
	char name[50], name2[50], mmark[5], fmark[5];

	memset( name, 0, sizeof name);
	memset( name2, 0, sizeof name2);
	memset( mmark, 0, sizeof mmark);
	memset( fmark, 0, sizeof fmark);

	scanf("%d", &k);
//printf("%d\n", k);
	getchar();

	struct records hash[k][9999];
	int hash1[k], l = 0;

	while(l <= k){
	hash1[l] = 0;
	l++;
	}

	memset( hash, 0, sizeof hash);

	FILE *file = fopen("records.txt", "r");

	int r = 0, c = 0, sum = 0, r2;

	while(fgets(name, 50, file) != NULL){
		
		while(name[c] != '\n'){
	
			name2[c] = name[c];
			sum = sum + name[c];
			c++;		

		}	

		r = sum%k;

		hash1[r]++;

		strcpy(hash[r][hash1[r]-1].name, name2);

		fgets(mmark , 5, file);

		fgets(fmark, 5, file);

		hash[r][hash1[r]-1].Mmark = atoi(mmark);
		
		hash[r][hash1[r]-1].Fmark = atoi(fmark);

//printf("%s\n", hash[r][hash1[r]-1].name);
//printf("%d\t%d\n", hash[r].Mmark, hash[r].Fmark);
//printf("%d\t%d\n",sum, r);

		memset( name, 0, sizeof name);
		memset( name2, 0, sizeof name2);
		memset( mmark, 0, sizeof mmark);
		memset( fmark, 0, sizeof fmark);
		
		c = 0, sum = 0;

		count1++;

		
	}

//printf("%s\n",hash[4][1].name);

	memset(name2, 0, sizeof name2);
	int i, j, count;

	
	
	while(fgets(name2, 50, stdin ) != NULL){
	
		c = 0, sum = 0, r = 0, i = 0, j = 0, count = 0;

		while(name2[c] != '\n'){
		c++;
		}
		
		name2[c] = '\0';
//printf("%s\n",name2);
		if(name2[0] == '\0'){
		goto end;
		}

		while(i < c){
	
			sum = sum + name2[i];
			i++;		

		}

		r = sum%k;
//printf("%d\t\t%d\n",sum, r);

		while(j < count1){

			if((strcmp( name2 , hash[r][j].name)) == 0){
			printf("%d %d %d\n", hash[r][j].Mmark, hash[r][j].Fmark, j+1); 
			count++;
			}
			j++;

		}

end:		if(count == 0){
		printf("The name does not exist in the file\n");
		}

	}

}
