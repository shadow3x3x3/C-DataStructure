#include <stdio.h>
#include <stdlib.h>



struct node
{
	int key ;
	struct node *left ;
	struct node *right ;
};

struct BS_Tree
{
	struct node *root ;
	BS_Tree();
	void insert(int key) ;						
	bool search(int key) ;				
	void inorder() ;	
};

BS_Tree::BS_Tree()
{
	root = NULL;		
}


void BS_Tree::insert(int key)
{	
	int i;
	//printf("%d\n",key);
	node *temp,*newNode;
	newNode = (node*) malloc(sizeof(node));
	newNode->key = key;
	newNode->right = NULL;
	newNode->left = NULL;
	
	temp = root;
	
	if(root==NULL){
		root = newNode;	
	}
	else{	//root isn't empty
		while(true){
			if(key > temp->key){
								
				if(temp->right == NULL){	//InsertRight
					
					temp->right = newNode;
					//printf("%d in right\n",key);
					break;
				}
				else{						//InsertRightFail
					temp = temp->right;
					continue;
				}
			}
			else if(key < temp->key){
				
				if(temp->left == NULL){		//InsertLeft
					temp->left = newNode;
					//printf("%d in left\n",key);
					break;
				}
				else{						//InsertLeftFail
					temp = temp->left;
					continue;
				}
			}
			else{
				printf("重複的數字!");
				break;	
			}
		}
		
	}
	
	
}

bool BS_Tree::search(int key)
{	
	node *temp;
	temp = root;
	
	if(root->key == key){
		return true;
	}
	else{
		while(true){
			if(key > temp->key){
				if(temp->right == NULL){
						return false;
					}
				else{
					if(temp->right->key == key){						
						return true;
					}
					else{																																//SearchMove
							temp = temp->right;
							continue;						
					}
				}			
			}
			
			if(key < temp->key){
				if(temp->left == NULL){
						return false;
					}
				else{
					if(temp->left->key == key){							
						return true;
					}
					else{																									//SearchMove
							temp = temp->left;
							continue;						

					}
				}			
			}
		}			
	}	
}

void r_inorder(node *ptr)
{
	if(ptr){
		r_inorder(ptr->left);
		printf("%d ",ptr->key);
		r_inorder(ptr->right);
	}	
	
}

void BS_Tree::inorder()
{		
	r_inorder(root);	
}






//Main
int main()
{
	BS_Tree T;
	
	int i,j,c,temp;
	bool s_result;
	
		printf("1.Input Data\n");
		printf("2.Search\n");
		printf("3.Inorder\n\n\n");

	
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
				T.insert(temp);
								
				break;

				//			
				case 2:
				printf("Data:");
				scanf("%d",&temp);
				fflush(stdin);
				s_result = T.search(temp);
				if(s_result == true){
					printf("%d 有存在於樹中\n",temp);
				}
				else{
					printf("%d 沒有存在於樹中\n",temp);
				}
				
				break;
				
				//				
				case 3:
				T.inorder();
				printf("\n");
				
				break;
				
				//							
			}
	
	
	}
	system("pause") ;
	return 0 ;

}
