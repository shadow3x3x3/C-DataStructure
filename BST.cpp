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
		printf("此數值超過樹的高度\n");
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
	printf("存入樹結構的陣列為：\n");
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
	//宣告
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

	printf("*********使用說明********\n\n");
	printf("鍵入一個數值後請按Enter\n\n");
	printf("最多可輸入64個數值 (樹的最高高度為6)\n\n");
	printf("如已輸入完畢請鍵入-1\n\n"); 
	printf("請勿輸入相同的數值，否則程式將會出錯\n\n"); 
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
	printf("已儲存的數值陣列為：\n");
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
	printf("Inoder的結果為：\n");
	T.Inorder(i);
	
	

	
	system("pause") ;
	return 0 ;
}

