#include <stdio.h>
#include <stdlib.h>

//structure
struct Node{
	int data ;
	struct Node *next ;
	struct Node *pre ;
};

struct linklist{
	struct Node *head ;
	linklist();
	bool IsEmpty() ;
	void Add(int number) ; 						//在鏈結串列的後面新增一筆資料number。
	void Delete(int Position) ;				 	//將int位置的資料刪除。
	void Insert(int number, int Postition) ; 	//將一筆資料number插入於Postition的位置。
	void Inverse() ; 							//將目前的鏈結串列反轉。
	void ShowLinkList() ; 						//顯示串列內容，由頭至尾
};

//建構子 
linklist::linklist()
{
	head = NULL;
}


//IsEmpty
bool linklist::IsEmpty()
{
	if(head == NULL){
		return true ;
	}
	else{ 
		return false ;
	}
}

//Add
void linklist::Add(int n)
{
	Node *prenode, *newnode ,*curnode;
	
	newnode =(Node*) malloc(sizeof(Node));
	
	curnode = head;	
	newnode->data = n ;
	
	
	if(IsEmpty() == true){				//先判斷是否為第一個節點
		newnode->next = NULL;
		newnode->pre = NULL;
		head = newnode;			
	}
	else{	
		while(curnode->next != NULL){  //移動鏈結串列到最後一個節點
			curnode = curnode->next;
		}
		prenode = curnode;
		newnode->next = curnode->next;
		newnode->pre = prenode;
		curnode->next = newnode;
	}
	


}

//Delete
void linklist::Delete(int p)
{
	Node *prenode ,*curnode ,*nextnode;
	int i;
	
	curnode = head;	
	
	if(IsEmpty() == true){								//先判斷是否為空的
		printf("鏈結串列目前是空的!!\n") ;
	}
	else if(p <= 0){									//位置除錯
		printf("請輸入大於0的位置!\n");
	}
	else if(p == 1){									//如果是第一個節點就直接刪掉
		head = curnode->next;
		free(curnode);									
	}
	else{
		for(i=1 ; i<p-1 ; i++){							//移動鏈結串列到指定的前一個節點
			if(curnode->next->next == NULL){			//判斷是否超出串列大小
				printf("數值超出鏈結串列極限!\n");
				return;
			}
			curnode = curnode->next;
		}
		prenode = curnode;
		curnode = curnode->next;
		nextnode = curnode->next;
		prenode->next = nextnode;
		nextnode->pre = prenode;
		free(curnode);	
		
	}

}

//Insert
void linklist::Insert(int n, int p)
{
	Node *newnode ,*prenode ,*curnode ,*nextnode;
	int i;
	
	newnode =(Node*) malloc(sizeof(Node));
	
	curnode = head;	
	newnode->data = n;

	if(IsEmpty() == true){								//先判斷是否為空的
		printf("鏈結串列目前是空的!!\n") ;
	}
	else if(p <= 0){									//位置除錯
		printf("請輸入大於0的位置!\n");
	}
	else if(p == 1){									//如果是第一個節點就當成head
		newnode->next = head;
		head = newnode;
		
	}
	else{
		for(i=1 ; i<p-1 ; i++){							//移動鏈結串列到指定的前一個節點
			if(curnode->next->next == NULL){			//判斷是否超出串列大小
				printf("數值超出鏈結串列極限!\n");
				return;
			}
			curnode = curnode->next;
		}
		nextnode = curnode->next;
		curnode->next = newnode;		
		newnode->next = nextnode;
		
	}


}

//Inverse
void linklist::Inverse(){
	Node *curnode, *tempnode;
	
	curnode = head;
	tempnode = NULL;
	
	if(IsEmpty() == true){				//先判斷是否為空的
		printf("鏈結串列目前是空的!!\n") ;	
	}
	else{	
		while(curnode->next != NULL){ 
			head = curnode->next;
			curnode->next = tempnode;
			tempnode = curnode;
			curnode = head;
		}
		curnode->next = tempnode;
	}

}


//Show
void linklist::ShowLinkList()
{
	Node *tempnode ;

	tempnode = head ;
	printf("正向的鏈結串列：");	
	while(tempnode != NULL)
	{
		printf("%d->", tempnode->data ) ;
		tempnode = tempnode->next;
	}
	printf("\n");
	printf("反向的鏈結串列：");
	tempnode = head ;
	while(tempnode->next != NULL)
	{
		tempnode = tempnode->next;		
	}
	
	while(tempnode->pre != NULL){
		printf("%d->", tempnode->data ) ;
		tempnode = tempnode->pre;
	}
	printf("%d->", tempnode->data ) ;
	tempnode = tempnode->pre;
	
}

//Main
int main()
{	
	linklist l;
	
	
	int i,j,c,d,p;
	
	printf("1.增資料至鏈結串列的最後\n\n");
	printf("2.從鏈結串列刪除資料\n\n");
	printf("3.插入一筆資料至鏈結串列\n\n");
	printf("4.將鏈結串列反轉\n\n");
	printf("5.顯示鏈結串列\n\n\n");
	
	while(true){

		
		printf("choose:");
		scanf("%d",&c);	
		fflush(stdin);
		switch (c)
			{	
				//
				case 1:	
				printf("請輸入數據：");
				scanf("%d",&d);
				l.Add(d);
				
				break;

				//			
				case 2:
				printf("請輸入要刪除的位置：");
				scanf("%d",&p);
				l.Delete(p);
				
				break;
				
				//				
				case 3:
				printf("請輸入要插入的位置：");
				scanf("%d",&p);
				printf("請輸入要插入的數據：");
				scanf("%d",&d);
				l.Insert(d,p);
				
				break;
				
				//				
				case 4:
				printf("進行翻轉...\n");
				l.Inverse();
				printf("翻轉完成!\n");
				
				break;
				
				//
				case 5:				
				l.ShowLinkList();
				printf("\n");
				
				break;
			
			}
	
	
	}

	system("pause") ;
	return 0 ;
}
