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

//回傳dim之中共有幾條連線。
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

//產生r個列、c個排的二維陣列。
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

//刪除二維陣列。
void Dimesion2D::Dimesion2DDestroy()
{
	int i;
		
	for(i=0 ;i<rows ;i++ ){ 
		free(value[i]);
	}
	free(value);
}

//將二維陣列中的值全部設為0
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
//若陣列中存在v值，則回傳true，否則回傳false。
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
//回傳陣列中第r列、第c行的內容值。
{
	return value[r][c];
}

void Dimesion2D::SetDimesion2D(int r, int c, int v)
//將陣列中第r列、第c排的內容值更改為v。
{
	value[r][c] = v;
}

void Dimesion2D::ShowDimesion2D()
//將陣列的內容顯示到螢幕中。
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
	
	printf("請輸入所要的賓果矩陣大小(N*N):");
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
		printf("請輸入數字:");
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
