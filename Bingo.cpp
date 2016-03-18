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
	int i,j;
	int counts=0,lines=0;
	
	//檢查rows
	for(i=0 ;i<dim.rows ;i++ ){
		for(j=0 ;j<dim.cols ;j++ ){
			if (dim.value[i][j]==0){
				counts++;
				if(counts==dim.cols){
					counts=0; 
					lines++;
				}
			}				
		}
		counts=0;
	}
	
	counts = 0;
	
	//檢查cols
	for(i=0 ;i<dim.rows ;i++ ){
		for(j=0 ;j<dim.cols ;j++ ){
			if (dim.value[j][i]==0){
				counts++;
				if(counts==dim.rows){
					counts=0; 
					lines++;
				}
			}		
		}
		counts=0;
	}
	
	//檢查左上右下斜線
	for(i=0 ;i<dim.cols ;i++ ){
		if (dim.value[i][i]==0){
			counts++;
			if(counts==dim.rows){
				counts=0; 
				lines++;
			}
		}		
	}
	counts=0;
		
	//檢查右上左下斜線	
	for(i=0,j=dim.rows-1 ;i<dim.cols ;i++,j-- ){
		if (dim.value[i][j]==0){
			counts++;
			if(counts==dim.rows){
				counts=0; 
				lines++;
			}
		}
	}


	return lines;
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

//若陣列中存在v值，則回傳true，否則回傳false。
bool Dimesion2D::Dimesion2DIsExist(int v)
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

//回傳陣列中第r列、第c行的內容值。
int Dimesion2D::Dimesion2DElementAt(int r, int c)
{
	return value[r][c];
}

//將陣列中第r列、第c排的內容值更改為v。
void Dimesion2D::SetDimesion2D(int r, int c, int v)
{
	value[r][c] = v;
}

//將陣列的內容顯示到螢幕中。
void Dimesion2D::ShowDimesion2D()
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
	int n,i,j,temp,line;
	bool exist; 
	
	printf("********程式說明********\n");
	printf("請先輸入一個數字作為Bingo遊戲的大小\n\n");
	printf("接著輸入要圈選的數字\n\n");
	printf("圈選的數字會標記為0\n\n");
	printf("可判斷直線、橫線和斜線\n\n");
	printf("當線數大於等於五時即結束程式\n\n");
	printf("P.S. 某些Dev C好像無法輸入超過5的方陣，但大部分都可以\n(例：64位元版的Dev C會失敗)\n");
	printf("*******程式說明結束*******\n\n\n");
		
	
	printf("請輸入你的方陣大小(N*N):");
	scanf("%d",&n);

	printf("\n");
	//Creat Bingo
	bingo.Dimesion2DCreate(n,n);
	//Show Bingo
	printf("隨機產生的方陣為\n");
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
	printf("對應的Mark方陣為：\n");
	markbingo.ShowDimesion2D();
	
	//markbingo line
	while(n){
		printf("請圈選號碼:");
		scanf("%d",&n);
		
		if(bingo.Dimesion2DIsExist(n)) {
			//set markbingo
			for(i=0 ;i<bingo.rows ;i++){
				for(j=0 ;j<bingo.cols ;j++ ){
					if(bingo.value[i][j] == n){
						markbingo.SetDimesion2D(i,j,0);
						bingo.SetDimesion2D(i,j,0);
					}
				}
			}
			//Show markbingo
			bingo.ShowDimesion2D();
			
			//how many lines 
			line = CheckConnect(markbingo);
		
			printf("\n");
		
			if(line >= 1){
				printf("目前有 %d 條線\n",line);
			}	
		
			if(line >= 5){
				printf("您獲勝了！\n");
				//Destroy
				bingo.Dimesion2DDestroy();
				markbingo.Dimesion2DDestroy();
				
				system("pause") ;
				return 0 ;
			}
		}	
		else{
			printf("並沒有這個數字,或數字已被圈選\n\n");
		}
		
	}
	


}
