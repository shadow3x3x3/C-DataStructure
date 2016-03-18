#include <stdio.h>
#include <stdlib.h>
#define MAX 8


struct  MyStack
{
	char S[MAX] ;
	int top ;
	
	MyStack() ;
	bool IsEmpty() ;
	bool IsFull() ;
	void Push(char) ;
	char Pop() ;
	char Peek() ;
	void ShowStack() ;
};

//�غc�l 
MyStack::MyStack()
{
	top = -1;	
}

//�P�_�O�_���� 
bool MyStack::IsEmpty()
{
	if (top < 0){
		return true;
	}
	else{
		return false;
	}
}

//�P�_�O�_���� 
bool MyStack::IsFull()
{
	if (top >= 7){
		return true;
	}
	else{
		return false;
	}
}

//Push�Jstack 
void MyStack::Push(char c)
{
	if(top >= 7 ){
		printf("Stack is Full.");
	}
	else{
		S[++top] = c;
	}
}

//Pop�Xstack 
char MyStack::Pop()
{
	if(top < 0 ){
		printf("Stack is Empty.");
	}
	else{
		return S[top--];
	}
}

//Peek
char MyStack::Peek()
{
	return S[top];
}

//���stack���e 
void MyStack::ShowStack()
{
	int i;
	
	printf("Stack :");
	for(i=top ;i>=0 ;i-- ){
		printf("%c ",S[i]);
		}
	printf("\n");
	
}



//Main
int main()
{
	MyStack number;
	
	int i,j,c;
	char temp;
	bool empty,full;
	
		printf("1.Input Data\n");
		printf("2.Pop\n");
		printf("3.Peek\n");
		printf("4.Show Stack\n\n");
	
	while(true){

		
		printf("choose:");
		scanf("%d",&c);	
		fflush(stdin);
		switch (c)
			{	
				//
				case 1:	
				printf("Data:");
				scanf("%c",&temp);
				fflush(stdin);				
				empty = number.IsEmpty();	
				if(empty=true){
					
					number.Push(temp);		
				}
				
				break;

				//			
				case 2:
				printf("Pop data : %c\n",number.Pop());
				
				break;
				
				//				
				case 3:
				printf("Peek : %c\n",number.Peek());
				
				break;
				
				//				
				case 4:
				number.ShowStack();
				
				break;
			
			
			}
	
	
	}
	system("pause") ;
	return 0 ;

}
