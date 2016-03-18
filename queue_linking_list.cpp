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

//建構子 
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
		
	if(IsEmpty() == true){				//先判斷是否為第一個節點								
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
	
	if(IsEmpty() == true){								//先判斷是否為空的
		printf("鏈結串列目前是空的!!\n") ;
		
	}
	else{		
		front = curnode->next;
		tempnode = curnode;
		printf("Delete的資料為：%d\n",tempnode->data);		
	}
	return tempnode;
}




//Show
void MyQueue::Show()
{
	MyData *tempnode ;	
	
	if(IsEmpty()==true){
			printf("鏈結串列目前是空的!!");		
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
	
	
	
	
	printf("1.Add一筆資料至鏈結串列\n\n");
	printf("2.從鏈結串列Delete資料\n\n");
	printf("3.顯示鏈結串列\n\n\n");
	
	while(true){

		
		printf("choose:");
		scanf("%d",&c);	
		fflush(stdin);
		switch (c)
			{	
				//
				case 1:	
				
				printf("請輸入要Add數據：");
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
