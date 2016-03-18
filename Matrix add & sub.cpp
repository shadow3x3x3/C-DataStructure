#include <stdio.h>
#include <stdlib.h>
#define Col 10
#define Row 10

struct Matrix
{
	int Cols, Rows ;
	int array[Col][Row];
	Matrix Add(Matrix B) ; 
	Matrix Mult(Matrix B) ;
	void ShowMatrix() ;
};
//Add
Matrix Matrix::Add(Matrix B)
{
	int i,j;	
	struct Matrix C;
	
	
	if(Cols==B.Cols && Rows==B.Rows){
		for(i=0 ;i<Cols ;i++ ){
			for(j=0 ;j<Rows ;j++ ){
				C.array[i][j]=array[i][j]+B.array[i][j];				
			}
		}
		return C;	
	}
	else{
		printf("Add Fail(Cols or Rows not the same)\n\n\n");
		C.Cols = 0;

		return C;		
	}
}
//Mult
Matrix Matrix::Mult(Matrix B)
{
	int i,j,k;
	struct Matrix C;
	
	if(Rows==B.Cols){	
		for (i=0; i<Cols; i++) {
        	for (j=0; j<Rows; j++) {
            	C.array[i][j]=0; 
            	for(k = 0; k < B.Cols; k++) {
                	C.array[i][j] = C.array[i][j] +array[i][k] * B.array[k][j];             		
				}    
        	}
    	}
    	return C;
	}
	else{	
		printf("Mult Fail(First Cols not equal Second Rows)\n\n\n");
		C.Cols = 0;
		
		return C;
	}


}
//ShowMatrix
void Matrix::ShowMatrix()
{
	int i,j;
	
	for(i=0 ;i<Cols ;i++ ){
		
		for(j=0 ;j<Rows ;j++){
			printf("%3d",array[i][j]);
			}
		printf("\n");
	}
}

//Main
int main(int argc, char *argv[])
{
  	FILE *fptr;
	struct Matrix A;
	struct Matrix B;
  	struct Matrix C;
	int i,j;
  	char m;
  	
	fptr=fopen("3.txt","r"); 
	
	//Read txt
	if(fptr!=NULL) 
	{
		//A to 0	
		for(i=0 ;i<Col ;i++ ){
			for(j=0 ;j<Row ;j++){
				A.array[i][j]=0;
			}
		}
		
		//B to 0	
		for(i=0 ;i<Col ;i++ ){
			for(j=0 ;j<Row ;j++){
				B.array[i][j]=0;
			}
		}
		
		//C to 0
		for(i=0 ;i<Col ;i++ ){
			for(j=0 ;j<Row ;j++){
				C.array[i][j]=0;
			}
			
		}
		
		//Read Matrix A
		fscanf(fptr,"%d",&A.Cols);
		fscanf(fptr,"%d",&A.Rows);
		
		
		for(i=0 ;i<A.Cols ;i++ ){
			for(j=0 ;j<A.Rows ;j++){
				fscanf(fptr,"%d",&A.array[i][j]);
		
			}
		}
		//Read Matrix B
		fscanf(fptr,"%d",&B.Cols);
		fscanf(fptr,"%d",&B.Rows);
		
		
		for(i=0 ;i<B.Cols ;i++ ){
			for(j=0 ;j<B.Rows ;j++){
				fscanf(fptr,"%d",&B.array[i][j]);
			
			}
		}
		
		
		//Read Math
		fscanf(fptr," %c",&m);

		
		//Show two Matrix
		
		printf("---------Matrix A---------\n");
		A.ShowMatrix();
		printf("\n");
		printf("---------Matrix B---------\n");
		B.ShowMatrix();
		printf("\n");
		printf("-----------Math-----------\n\n\n");
		printf("           %c\n\n\n",m);
		
		//Add in main
		if(m=='+'){
		C=A.Add(B);
		C.Cols = A.Cols;
		C.Rows = A.Rows;
		printf("----------Result----------\n");
		C.ShowMatrix();		
		}
		
		//Mult in main
		else if(m=='*'){
		C=A.Mult(B);
		C.Cols = A.Cols;
		C.Rows = B.Rows;
		printf("----------Result----------\n");		
		C.ShowMatrix();
		}

	}
	//Read txt Fail
	else
	{
		printf("Load 3.txt Fail.");
	}
  	
  
  	system("PAUSE");	
  	return 0;
}
