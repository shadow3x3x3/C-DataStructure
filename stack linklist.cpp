#include <stdio.h>
#include <stdlib.h>

struct Node
{
	char key ;
	struct Node* next ;
};

struct Stack
{
	Node *top ;

	Stack();
	bool IsEmpty() ;
	void Push(char) ;
	char Pop() ;
	void ShowStack() ;

};

//«Øºc¤l 
Stack::Stack()
{
	top = NULL;
}

bool Stack::IsEmpty()
{
	if(top == NULL){
		return true ;
	}
	else{ 
		return false ;
	}
}

void Stack::Push(char c)
{
	Node *newnode ;
	
	newnode =(Node*) malloc(sizeof(Node));
	newnode->key = c ;
	newnode->next = top; 

	top = newnode ;
}

char Stack::Pop()
{
	char tempchar = '\0' ;
	Node *delnode ;

	if(IsEmpty() == true)
	{
		printf("Stack is Empty!!\n") ;
	}
	else
	{
		tempchar = top->key ;
		delnode = top ;

		top = top->next;

		free(delnode) ;	
	}

	return tempchar ;
}

void Stack::ShowStack()
{
	Node *tempnode ;

	tempnode = top ;

	while(tempnode != NULL)
	{
		printf("%c\n", tempnode->key ) ;
		tempnode = tempnode->next;
	}
}

int main()
{	
	Stack s ;
	
	printf("%d\n", s.IsEmpty()) ;

	s.Push('1') ;
	s.Push('2') ;
	s.Push('3') ;
	s.Push('4') ;
	s.Push('5') ;
	s.Push('6') ;

	s.ShowStack() ;

	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	
	printf("%d\n", s.IsEmpty()) ;

	s.Push('1') ;
	s.Push('2') ;
	s.Push('3') ;
	s.Push('4') ;
	s.Push('5') ;
	s.Push('6') ;

	s.ShowStack() ;

	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;
	printf("%c\n", s.Pop()) ;

	system("pause") ;
	return 0 ;
}
