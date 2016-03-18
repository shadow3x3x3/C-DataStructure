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
	void Add(int number) ; 						//�b�쵲��C���᭱�s�W�@�����number�C
	void Delete(int Position) ;				 	//�Nint��m����ƧR���C
	void Insert(int number, int Postition) ; 	//�N�@�����number���J��Postition����m�C
	void Inverse() ; 							//�N�ثe���쵲��C����C
	void ShowLinkList() ; 						//��ܦ�C���e�A���Y�ܧ�
};

//�غc�l 
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
	
	
	if(IsEmpty() == true){				//���P�_�O�_���Ĥ@�Ӹ`�I
		newnode->next = NULL;
		newnode->pre = NULL;
		head = newnode;			
	}
	else{	
		while(curnode->next != NULL){  //�����쵲��C��̫�@�Ӹ`�I
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
	
	if(IsEmpty() == true){								//���P�_�O�_���Ū�
		printf("�쵲��C�ثe�O�Ū�!!\n") ;
	}
	else if(p <= 0){									//��m����
		printf("�п�J�j��0����m!\n");
	}
	else if(p == 1){									//�p�G�O�Ĥ@�Ӹ`�I�N�����R��
		head = curnode->next;
		free(curnode);									
	}
	else{
		for(i=1 ; i<p-1 ; i++){							//�����쵲��C����w���e�@�Ӹ`�I
			if(curnode->next->next == NULL){			//�P�_�O�_�W�X��C�j�p
				printf("�ƭȶW�X�쵲��C����!\n");
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

	if(IsEmpty() == true){								//���P�_�O�_���Ū�
		printf("�쵲��C�ثe�O�Ū�!!\n") ;
	}
	else if(p <= 0){									//��m����
		printf("�п�J�j��0����m!\n");
	}
	else if(p == 1){									//�p�G�O�Ĥ@�Ӹ`�I�N��head
		newnode->next = head;
		head = newnode;
		
	}
	else{
		for(i=1 ; i<p-1 ; i++){							//�����쵲��C����w���e�@�Ӹ`�I
			if(curnode->next->next == NULL){			//�P�_�O�_�W�X��C�j�p
				printf("�ƭȶW�X�쵲��C����!\n");
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
	
	if(IsEmpty() == true){				//���P�_�O�_���Ū�
		printf("�쵲��C�ثe�O�Ū�!!\n") ;	
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
	printf("���V���쵲��C�G");	
	while(tempnode != NULL)
	{
		printf("%d->", tempnode->data ) ;
		tempnode = tempnode->next;
	}
	printf("\n");
	printf("�ϦV���쵲��C�G");
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
	
	printf("1.�W��Ʀ��쵲��C���̫�\n\n");
	printf("2.�q�쵲��C�R�����\n\n");
	printf("3.���J�@����Ʀ��쵲��C\n\n");
	printf("4.�N�쵲��C����\n\n");
	printf("5.����쵲��C\n\n\n");
	
	while(true){

		
		printf("choose:");
		scanf("%d",&c);	
		fflush(stdin);
		switch (c)
			{	
				//
				case 1:	
				printf("�п�J�ƾڡG");
				scanf("%d",&d);
				l.Add(d);
				
				break;

				//			
				case 2:
				printf("�п�J�n�R������m�G");
				scanf("%d",&p);
				l.Delete(p);
				
				break;
				
				//				
				case 3:
				printf("�п�J�n���J����m�G");
				scanf("%d",&p);
				printf("�п�J�n���J���ƾڡG");
				scanf("%d",&d);
				l.Insert(d,p);
				
				break;
				
				//				
				case 4:
				printf("�i��½��...\n");
				l.Inverse();
				printf("½�৹��!\n");
				
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
