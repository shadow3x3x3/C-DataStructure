#include <stdio.h>
#include <stdlib.h>
//HT Structure
struct TreeNode
{
		int key ;
		struct TreeNode *left ;
		struct TreeNode *right ;
		struct TreeNode *father ;
};
struct Heap_tree
{
		struct TreeNode *root ;
		Heap_tree();
		void Insert(int key) ;
		int Delete( ) ;
		void Levelorder( ) ;
};

//Queue Structure
struct QueueNode
{
	TreeNode *Data ;
	struct QueueNode *next;
};
struct MyQueue
{
	struct QueueNode *front ;
	struct QueueNode *rear ;

	MyQueue() ;
	bool Is_Empty() ;
	void AddQ(struct TreeNode*) ;
	struct TreeNode* DelQ() ;	
};

//other Fuction
void NodeSwap(TreeNode *first,TreeNode *second)
{	
	TreeNode *temp;
	//A
	if(first->father->left){
		first->father->left = second;
	}
	else{
		first->father->right = second;
	}
	
	if(second->father->left){
		second->father->left = first;
	}
	else{
		second->father->right = first;
	}
	//B
	temp = first->father;
	first->father = second->father;
	second->father = temp;
	//C
	first->left->father = second;
	second->left->father = first;
	temp = first->left;
	first->left = second->left;
	second->left = temp;
	//D
	first->right->father = second;
	second->right->father = first;
	temp = first->right;
	first->right = second->right;
	second->right = temp;
	
}
//Fuction in Queue
//建構子 
MyQueue::MyQueue()
{
	front = NULL;
	rear = NULL;
}


//IsEmpty
bool MyQueue::Is_Empty()
{
	if(front == NULL){
		return true ;
	}
	else{ 
		return false ;
	}
}

//Add
void MyQueue::AddQ(struct TreeNode *newdata)
{
	struct QueueNode *newnode ;
	newnode = (struct QueueNode*)malloc(sizeof(struct QueueNode)) ;
	newnode->Data = newdata ;
	newnode->next = NULL ;

	if(Is_Empty())
	{
		front = newnode ;
		rear = newnode ;
	}
	else
	{
		rear->next = newnode ;
		rear = newnode ;
	}
}

//Delete
struct TreeNode* MyQueue::DelQ()
{
	struct TreeNode *retvalue ;
	struct QueueNode *temp ;

	if(Is_Empty())
	{
		printf("Queue is empty\n") ;
		retvalue = NULL ;
	}
	else
	{
		retvalue = front->Data ;
		
		temp = front ;
		front = front->next ;
		free(temp) ;
	}
	return retvalue ;
}

//Fuction in CBT
//建構子 
Heap_tree::Heap_tree()
{
	root = NULL;		
}

//Insert
void Heap_tree::Insert(int key)
{	
	int i;
	
	TreeNode *temp,*newNode,*tempNode;
	MyQueue S;
	newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->key = key;
	newNode->right = NULL;
	newNode->left = NULL;
	
	temp = root;
	
	//root is empty
	if(root == NULL){
		root = newNode;
		newNode->father = NULL;	
	}
	//root isn't empty
	else{		
		S.AddQ(temp);	
		while(true){
			temp = S.DelQ();
			//LeftNode is empty 
			if(temp->left == NULL){
				temp->left = newNode;
				newNode->father = temp;
				break;
			}
			//RightNode is empty
			else if(temp->right == NULL){
				temp->right = newNode;
				newNode->father = temp;
				break;
			}
			else{
				S.AddQ(temp->right);
				S.AddQ(temp->left);
				continue;					
			}			
		}
		//remake
		if(newNode->key > newNode->father->key){
			NodeSwap(newNode,newNode->father);
		}
	}
	
	
	
		
}

//Delete
int Heap_tree::Delete()
{	
	/*
	if(temp->left->key > temp->right->key){
		//swap(temp)	
	}
	else{
				
	}*/
}

//Levelorder
void Heap_tree::Levelorder()
{	
	TreeNode *temp;	
	MyQueue S;
	
	temp = root;
	
	if(temp == NULL){
		printf("Tree is empty.\n");
	}
	else{
		S.AddQ(temp);
		while(true){
			temp = S.DelQ();			
			if(temp != NULL){
				printf("%d ",temp->key);
				if(temp->left != NULL){
					S.AddQ(temp->left);
				}
				if(temp->right != NULL){
					S.AddQ(temp->right);
				}		
			}
			else{
				break;
			}					
		}			
	}
}






//Main
int main()
{
	Heap_tree T;
	
	int i,j,c,temp,delData;
	
		printf("1.Input Data\n");
		printf("2.Delete\n");
		printf("3.Level Order\n\n");

	
	while(true){

		
		printf("choose:");
		scanf("%d",&c);	
		fflush(stdin);
		switch (c)
			{	
				//
				case 1:	
				printf("Data:");
				scanf("%d",&temp);
				fflush(stdin);
				T.Insert(temp);
								
				break;

				//			
				case 2:
				delData = T.Delete();
				printf("Deleted data is %d\n",delData);

				break;
				
				case 3:
				T.Levelorder();
				
				break;						
			}
	
	
	}
	system("pause") ;
	return 0 ;

}
