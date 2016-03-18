#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define HashSize 13

struct Node
{
	Node();
	char string[MAX] ;
	int count ;
	struct Node *next ;
};
struct HashTable
{
	struct Node *table[HashSize] ;
	HashTable() ;
	int HashFunction(char str[MAX]) ;
	Node* Search(char str[MAX]) ;
	void Add(char str[MAX]) ;
	void ShowHashTable() ;
};


//Constructor
HashTable::HashTable()
{	
	int i;
	for(i=0 ; i<HashSize ; i++){
		table[i] = NULL;	
	}
}

Node::Node()
{
	int i;
	
	count = 0;
	for(i=0 ; i<MAX ; i++){
		string[i] = 0;	
	}	
}

//HashFunction
int HashTable::HashFunction(char *str){
	
	printf("--Into HashFunction--\n");
	
	int i,num;
	
	for(i=0 ; str[i]!=0 ;i++){
		num = num + str[i];
	}	
	return num % HashSize;
	
}

//Search
Node* HashTable::Search(char *str){
	
	printf("--Into Search--\n");
	
	Node *curnode;
	int i,j;
	
	for(i=0 ; i<HashSize ; i++){
		curnode = table[i];
		printf("--Into for--\n");
		for(j=0 ; str[j]!=0 ;j++){
			if(table[i]->string[j]==str[i]){
				continue;
			}
			else{
				printf("--break for\n--");
				break;
			}
			printf("--return curnode--\n");
			return curnode;
		}	
	}
	printf("--return NULL--\n");
	return NULL;
}

//Add
void HashTable::Add(char *str){
	
	printf("--Into Add--\n");
	
	Node *newnode ,*curnode;
	int i,l_hash;
	
	//newnode
	newnode =(Node*) malloc(sizeof(Node));
	for(i=0 ; str[i]!=0 ; i++){
			newnode->string[i] = str[i];
		}
	
	curnode = Search(str);
	if(curnode == NULL){		
		l_hash = HashFunction(str);
		curnode = table[l_hash];
		for(i=0 ; str[i]!=0 ; i++){
			curnode->string[i] = str[i];
		}
		curnode->count ++ ;
		curnode->next = NULL;
		
	}
	else{
		while(curnode->next != NULL){  
			curnode = curnode->next;
		}
		newnode->next = curnode->next;
		curnode->next = newnode;
		newnode->count ++ ;
	}
	
}

//Show
void HashTable::ShowHashTable(){
	
	Node *tempnode;
	int i,j;
		
	for(i=0 ; table ; i++){	
		tempnode = table[i];
		while(tempnode != NULL){
			printf("table[%d]",i);
			for(j=0 ; tempnode->string[j]!=0 ; j++){
				printf("%c",tempnode->string[j]);
			}
			printf(",times: %d",tempnode->count);
			printf("->");
			tempnode = tempnode->next;
		}
		printf("\n");
	}
}



int main()
{	
	FILE *fptr; 
	HashTable test;
	
	int i,j,c;
	char temp[MAX];
	
	printf("1.Read 3.txt\n");
	printf("2.Show HashTable\n");
	
	
	while(true){
		
		printf("choose:");
		scanf("%d",&c);	
		fflush(stdin);
		switch (c)
			{	
				//
				case 1:	
				fptr=fopen("3.txt","r");
				
				while( !feof(fptr) ){
                	fscanf(fptr,"%s",&*temp);
                	printf("%s\n",temp);
                	
                	for(i=0 ; temp[i] != ' ' ; i++ ){
						if(temp[i]==',' || temp[i]=='.'){
							temp[i] = temp[i-1];
						}
					}					
					test.Add(temp);					
				}     
				fclose(fptr);
								
				break;

				//			
				case 2:
				test.ShowHashTable();
				
				break;							
			}
	
	
	}
	system("pause") ;
	return 0 ;

}
