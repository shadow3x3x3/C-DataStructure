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
	int i,j;
	int counts=0,lines=0;
	
	//�ˬdrows
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
	
	//�ˬdcols
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
	
	//�ˬd���W�k�U�׽u
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
		
	//�ˬd�k�W���U�׽u	
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

//�Y�}�C���s�bv�ȡA�h�^��true�A�_�h�^��false�C
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

//�^�ǰ}�C����r�C�B��c�檺���e�ȡC
int Dimesion2D::Dimesion2DElementAt(int r, int c)
{
	return value[r][c];
}

//�N�}�C����r�C�B��c�ƪ����e�ȧ�אּv�C
void Dimesion2D::SetDimesion2D(int r, int c, int v)
{
	value[r][c] = v;
}

//�N�}�C�����e��ܨ�ù����C
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
	
	printf("********�{������********\n");
	printf("�Х���J�@�ӼƦr�@��Bingo�C�����j�p\n\n");
	printf("���ۿ�J�n��諸�Ʀr\n\n");
	printf("��諸�Ʀr�|�аO��0\n\n");
	printf("�i�P�_���u�B��u�M�׽u\n\n");
	printf("��u�Ƥj�󵥩󤭮ɧY�����{��\n\n");
	printf("P.S. �Y��Dev C�n���L�k��J�W�L5����}�A���j�������i�H\n(�ҡG64�줸����Dev C�|����)\n");
	printf("*******�{����������*******\n\n\n");
		
	
	printf("�п�J�A����}�j�p(N*N):");
	scanf("%d",&n);

	printf("\n");
	//Creat Bingo
	bingo.Dimesion2DCreate(n,n);
	//Show Bingo
	printf("�H�����ͪ���}��\n");
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
	printf("������Mark��}���G\n");
	markbingo.ShowDimesion2D();
	
	//markbingo line
	while(n){
		printf("�а�︹�X:");
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
				printf("�ثe�� %d ���u\n",line);
			}	
		
			if(line >= 5){
				printf("�z��ӤF�I\n");
				//Destroy
				bingo.Dimesion2DDestroy();
				markbingo.Dimesion2DDestroy();
				
				system("pause") ;
				return 0 ;
			}
		}	
		else{
			printf("�èS���o�ӼƦr,�μƦr�w�Q���\n\n");
		}
		
	}
	


}
