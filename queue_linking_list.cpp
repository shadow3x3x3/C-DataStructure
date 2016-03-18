#include <stdio.h>
#include <stdlib.h>

//structure
struct MyData{
	int data ;
	MyData *next ;
};

struct MyQueue{
	MyData *front,*rear ;
	MyQueue();
	bool IsEmpty() ;
	void AddQ(MyData *newdata); 				
	MyData* DeleteQ(); 				 			
	void Show() ; 								
};

//�غc�l 
MyQueue::MyQueue()
{
	front = NULL;
	rear = NULL;
}


//IsEmpty
bool MyQueue::IsEmpty()
{
	if(front == NULL){
		return true ;
	}
	else{ 
		return false ;
	}
}

//Add
void MyQueue::AddQ(MyData *newdata) 
{	
		
	if(IsEmpty() == true){				//���P�_�O�_���Ĥ@�Ӹ`�I								
		front = newdata;
		//newdata->next = NULL;		
		rear = newdata;
	}
	else{			
		rear->next = newdata;
		rear = newdata;
	}
		
}

//Delete
MyData* MyQueue::DeleteQ()
{
	MyData *curnode , *tempnode;
	int i;
	
	curnode = front;		
	
	if(IsEmpty() == true){								//���P�_�O�_���Ū�
		printf("�쵲��C�ثe�O�Ū�!!\n") ;
		
	}
	else{		
		front = curnode->next;
		tempnode = curnode;
		printf("Delete����Ƭ��G%d\n",tempnode->data);		
	}
	return tempnode;
}




//Show
void MyQueue::Show()
{
	MyData *tempnode ;	
	
	if(IsEmpty()==true){
			printf("�쵲��C�ثe�O�Ū�!!");		
		}
	else{
		tempnode = front ;	
		while(tempnode != rear->next){	
			printf("%d->", tempnode->data) ;
			tempnode = tempnode->next;
			}
		}
}

//Main
int main()
{	
	MyQueue l;
	
	MyData *tempnode;
	
	int c,d,PopData;
	
	
	
	
	printf("1.Add�@����Ʀ��쵲��C\n\n");
	printf("2.�q�쵲��CDelete���\n\n");
	printf("3.����쵲��C\n\n\n");
	
	while(true){

		
		printf("choose:");
		scanf("%d",&c);	
		fflush(stdin);
		switch (c)
			{	
				//
				case 1:	
				
				printf("�п�J�nAdd�ƾڡG");
				scanf("%d",&d);
				tempnode =(MyData*) malloc(sizeof(MyData));
				tempnode->next = NULL;
				tempnode->data = d;
				l.AddQ(tempnode);
				
				break;

				//			
				case 2:
				tempnode = l.DeleteQ();
				
				
				break;
				
				//				
				case 3:
				l.Show();
				printf("\n");
				
				break;
			
			}
	
	
	}

	system("pause") ;
	return 0 ;
}
