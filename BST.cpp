#include <stdio.h>
#include <stdlib.h>
#define MAX 65

//structure
struct T_Node
{
	bool Is_Empty ;
	int Key ;
};

struct BST
{
	T_Node MyTree[MAX] ;

	BST() ;
	bool InsertNode(int) ;
	void ShowBST() ;
	void Inorder(int) ;
};

struct BST T;

//InsertNode
bool BST::InsertNode(int n)
{	
	int i,temp;
	int h=1;
	
	//root isn't empty
	if(T.MyTree[1].Is_Empty == false){
		for(i=1 ;h<6 ;i=temp ){
			if(n > T.MyTree[i].Key){
				if(T.MyTree[2*i+1].Is_Empty == 1){
					T.MyTree[2*i+1].Key = n;
					T.MyTree[2*i+1].Is_Empty = false;
					return 0;					
				}
				else{
					temp = 2*i+1;
					h++;
				}
			}
			else if(n < T.MyTree[i].Key){
				if(T.MyTree[2*i].Is_Empty == 1){
					T.MyTree[2*i].Key = n;
					T.MyTree[2*i].Is_Empty = false;
					return 0;					
				}
				else{
					temp = 2*i;
					h++;
				}					
			}
		}
		printf("���ƭȶW�L�𪺰���\n");
		return false ;
	}

	//root is empty
	else{
	T.MyTree[1].Key = n;
	T.MyTree[1].Is_Empty = false;		
	}
}
//ShowBST
void BST::ShowBST()
{	
	int i;
	printf("�s�J�𵲺c���}�C���G\n");
	for(i=1 ;i<MAX ;i++){
		if(T.MyTree[i].Key==0){
			printf("_ ");	
		}
		else{	
			printf("%d ",T.MyTree[i].Key);		
		}
	}
	printf("\n\n");

			
}

//Inorder
void BST::Inorder(int i)
{	
	if(T.MyTree[i].Is_Empty == false && i<65){
		Inorder(2*i);
		printf("%d ",T.MyTree[i].Key);
		Inorder(2*i+1);
	}
}

//BST
BST::BST()
{
	int i ;
	for(i = 0 ; i < MAX ; i++)
	{
		MyTree[i].Is_Empty = 1;
	}
}
//Main
int main()
{	
	//�ŧi
	int i=1,n;
	int output[MAX];
	bool test=1;
	
	//set output to 0
	for(i=1 ;i<MAX ;i++){
		output[i]=0;
	}
	for(i=1 ;i<MAX ;i++){
		T.MyTree[i].Key=0;
	}	
 	
	
	
	//Introduction

	printf("*********�ϥλ���********\n\n");
	printf("��J�@�Ӽƭȫ�Ы�Enter\n\n");
	printf("�̦h�i��J64�Ӽƭ� (�𪺳̰����׬�6)\n\n");
	printf("�p�w��J��������J-1\n\n"); 
	printf("�Фſ�J�ۦP���ƭȡA�_�h�{���N�|�X��\n\n"); 
	printf("*************************\n\n");

	//Input 			
	for(i=1 ;i!=-1 ;i++){
		printf("Input values:");
		scanf("%d",&n);		
		if(n != -1){
			output[i] = n;
			//Insert fuction
			test = T.InsertNode(n);
			if(test == -1){
				system("pause") ;
				return 0 ;
			}
		}
		else{
			i=-2;
		}
	}
	
	//show 1st
	printf("�w�x�s���ƭȰ}�C���G\n");
	for(i=1 ;i<MAX ;i++){
		if(output[i]==0){
			printf("_ ");	
		}
		else{	
			printf("%d ",output[i]);		
		}
	}
	printf("\n\n");

	//show BST 
	T.ShowBST();
	
	//show Inorder
	i=1;
	printf("Inoder�����G���G\n");
	T.Inorder(i);
	
	

	
	system("pause") ;
	return 0 ;
}

