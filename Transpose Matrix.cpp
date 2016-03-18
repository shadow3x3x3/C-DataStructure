#include <stdio.h>
#include <stdlib.h>

struct  Dimesion2D
{
	int **value ;
	int rows ;
	int cols ;

	Dimesion2D() ;
	void Dimesion2DCreate(int, int) ;
	void Dimesion2DDestroy() ;
	void Dimesion2DSetToZero() ;
	void SetDimesion2D(int, int, int) ;	
	Dimesion2D transpose() ;
	void ShowDimesion2D() ;
};




Dimesion2D::Dimesion2D()
//�غc�l�C
{
	rows = -1 ;
	cols = -1 ;
}
void Dimesion2D::Dimesion2DCreate(int r, int c)
//����r�ӦC�Bc�ӱƪ��G���}�C�C
{
//malloc
	int i,j;
	value=(int **)malloc(r*sizeof(int)); 
	
	for(i=0 ;i<r ;i++ ){
		value[i]=(int *)malloc(c*sizeof(int));
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
	
	rows = -1 ;
	cols = -1 ;
}

//�N�G���}�C�����ȥ����]��0�C
void Dimesion2D::Dimesion2DSetToZero()

{
	int i,j;
	
	for(i=0 ;i<rows ;i++ ){
		for(j=0 ;j<cols ;j++ ){
			value[i][j]=0;
		}
	}
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
	
	for(i=0 ;i<rows ;i++ ){
		for(j=0 ;j<cols ;j++ ){
			printf("%4d ",value[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//������m�x�}
Dimesion2D Dimesion2D::transpose()
{
	Dimesion2D tempArray ;
	int i,j;
		
	tempArray.Dimesion2DCreate(cols,rows);
	tempArray.cols = rows;
	tempArray.rows = cols;
	
		
	for(i=0 ;i<cols ;i++ ){
		for(j=0 ;j<rows ;j++ ){
			tempArray.value[i][j]=value[j][i]; 			
		}
	}
		
	return tempArray ;
}

//Main
int main()
{	
	FILE *fptr;
	
	Dimesion2D arrayA, arrayB ;
	int i,j,c;
	
	
	fptr=fopen("5.txt","r"); 
	
	if(fptr!=NULL){
		printf("1.Read A\n");
		printf("2.Transpos A save in B\n");
		printf("3.Show A\n");
		printf("4.Show B\n");
		printf("5.delete A and B\n");
		

		
		
		while(true){
			printf("choose:");
			scanf("%d",&c);
			printf("\n");
			switch (c)
			{	
				
				case 1://Read txt(row and cols)
				fscanf(fptr,"%d",&arrayA.rows);
				fscanf(fptr,"%d",&arrayA.cols);
		
				//Creat arrayA and arrayB
				arrayA.Dimesion2DCreate(arrayA.rows,arrayA.cols);
		
				//Set to 0
				arrayA.Dimesion2DSetToZero();
		
				//Read Matrix into arrayA
				for(i=0 ;i<arrayA.rows ;i++ ){
					for(j=0 ;j<arrayA.cols ;j++){
						fscanf(fptr,"%d",&arrayA.value[i][j]);
		
					}
				}
				printf("Read succesful.\n\n");
				break;
			
				case 2://Transpose arrayA and save in arrayB
				arrayB = arrayA.transpose();
				printf("Transpose and save succesful.\n\n");
				break;
			
				case 3://show arrayA and arrayB
				printf("arrayA :\n");
				if(arrayA.rows==-1){
					printf("A is empty\n\n");
					break;
					}
				else{
					arrayA.ShowDimesion2D();
					break;
					}
				
			
				case 4:
				printf("arrayB :\n");
				if(arrayB.rows==-1){
					printf("B is empty\n\n");
					break;
					}
				else{
					arrayB.ShowDimesion2D();
					break;
					}			
							
			
			
				case 5://delete arrayA and arrayB
				arrayA.Dimesion2DDestroy();
				arrayB.Dimesion2DDestroy();
				printf("Delete arrayA and arrayB succesful.\n");
				fptr=fopen("5.txt","r");
				break;
				

			}
		}
			
	}

	system("pause") ;
	return 0 ;

}
