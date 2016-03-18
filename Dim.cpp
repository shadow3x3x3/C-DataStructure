#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct  Dimesion2D
{
	int **value ;
	int rows ;
	int cols ;

	Dimesion2D() ;
	void Dimesion2DCreate(int, int) ;
	void Dimesion2DDestroy() ;
	void Dimesion2DSetToZero() ;
	bool Dimesion2DIsExist(int) ;
	int Dimesion2DElementAt(int, int) ;
	void SetDimesion2D(int, int, int) ;	
	void ShowDimesion2D() ;
};

//�^��dim�����@���X���s�u�C
int CheckConnect(Dimesion2D dim)
{
	if(dim.)
	
	
	
	
	
}


//Constructor
Dimesion2D::Dimesion2D()
{
	rows = -1 ;
	cols = -1 ;
}

//����r�ӦC�Bc�ӱƪ��G���}�C�C
void Dimesion2D::Dimesion2DCreate(int r, int c)
{
	int i,j,temp;
	srand(time(NULL));
	//set
	rows = r;
	cols = c;
	
	//malloc
	value=(int **)malloc(r*sizeof(int)); 
	for(i=0 ;i<r ;i++ ){
		value[i]=(int *)malloc(c*sizeof(int));
	}
	//set
	Dimesion2DSetToZero();
	//random number	
	for(i=0 ;i<r ;i++){
		for(j=0 ;j<c ;j++ ){
			do{
				temp = rand()%(r*c)+1;
			}while(Dimesion2DIsExist(temp) == true);
			
			value[i][j] = temp;
		}
	}		
	
}

//�R���G���}�C�C
void Dimesion2D::Dimesion2DDestroy()
{
	int i;
		
	for(i=0 ;i<rows ;i++ ){ 
		free(value[i]);
	}
	free(value);
}

//�N�G���}�C�����ȥ����]��0
void Dimesion2D::Dimesion2DSetToZero()
{
	int i,j;
	
	for(i=0 ;i<rows ;i++ ){
		for(j=0 ;j<cols ;j++ ){
			value[i][j]=0;
		}
	}
}

bool Dimesion2D::Dimesion2DIsExist(int v)
//�Y�}�C���s�bv�ȡA�h�^��true�A�_�h�^��false�C
{
	int i,j;
	
	for(i=0 ;i<rows ;i++ ){
		for(j=0 ;j<cols ;j++ ){
				if(value[i][j]==v){
					return true;
				}
			}
	}
	return false ;
}

int Dimesion2D::Dimesion2DElementAt(int r, int c)
//�^�ǰ}�C����r�C�B��c�檺���e�ȡC
{
	return value[r][c];
}

void Dimesion2D::SetDimesion2D(int r, int c, int v)
//�N�}�C����r�C�B��c�ƪ����e�ȧ�אּv�C
{
	value[r][c] = v;
}

void Dimesion2D::ShowDimesion2D()
//�N�}�C�����e��ܨ�ù����C
{
	int i,j;
	
	for(i=0 ;i<cols ;i++ ){
		for(j=0 ;j<rows ;j++ ){
			printf("%4d ",value[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//Main
int main()
{
	Dimesion2D bingo, markbingo ;
	int n,i,j,temp;
	
	printf("�п�J�ҭn�����G�x�}�j�p(N*N):");
	scanf("%d",&n);


	//Creat Bingo
	bingo.Dimesion2DCreate(n,n);
	//Show Bingo
	bingo.ShowDimesion2D();
	
	//markbingo-malloc
	markbingo.rows = n;
	markbingo.cols = n;
	temp = 0;
	markbingo.value=(int **)malloc(n*sizeof(int)); 
	for(i=0 ;i<n ;i++ ){
		markbingo.value[i]=(int *)malloc(n*sizeof(int));
	}
	for(i=0 ;i<n ;i++ ){
		for(j=0 ;j<n ;j++ ){
			temp++;
			markbingo.value[i][j]=temp;
		}
	}
	//Show markbingo
	markbingo.ShowDimesion2D();
	
	//markbingo line
	while(n){
		printf("�п�J�Ʀr:");
		scanf("%d",&n);
		
		//set markbingo
		for(i=0 ;i<bingo.rows ;i++){
			for(j=0 ;j<bingo.cols ;j++ ){
				if(bingo.value[i][j] == n){
					markbingo.SetDimesion2D(i,j,0);
				}
			}
		}
		//Show markbingo
		markbingo.ShowDimesion2D();
		
		
		
		
		
	}
	
	
	system("pause") ;
	return 0 ;

}
