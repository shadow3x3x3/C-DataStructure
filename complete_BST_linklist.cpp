#include <stdio.h>
#include <stdlib.h>
//CBT Structure
struct TreeNode
{
	int key ;
	struct TreeNode *left ;
	struct TreeNode *right ;
};
struct BS_Tree
{
	struct TreeNode *root ;
	BS_Tree();
	void Insert(int key) ;										
	void Levelorder() ;	
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
		printf("Queue is empty!!!!\n") ;
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
BS_Tree::BS_Tree()
{
	root = NULL;		
}

//Insert
void BS_Tree::Insert(int key)
{	
	int i;
	
	TreeNode *temp,*newNode;
	MyQueue S;
	newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->key = key;
	newNode->right = NULL;
	newNode->left = NULL;
	
	temp = root;
	
	//root is empty
	if(root == NULL){
		root = newNode;	
	}
	//root isn't empty
	else{		
		S.AddQ(temp);	
		while(true){
			temp = S.DelQ();
			//LeftNode is empty 
			if(temp->left == NULL){
				temp->left = newNode;
				break;
			}
			//RightNode is empty
			else if(temp->right == NULL){
				temp->right = newNode;
				break;
			}
			else{
				S.AddQ(temp->right);
				S.AddQ(temp->left);
				continue;					
			}			
		}		
	}	
}

//Levelorder
void BS_Tree::Levelorder()
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
	BS_Tree T;
	
	int i,j,c,temp;
	bool s_result;
	
		printf("1.Input Data\n");
		printf("2.Level Order\n");

	
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
				T.Levelorder();

				break;						
			}
	
	
	}
	system("pause") ;
	return 0 ;

}
