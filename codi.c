#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 512
float Mat[N][N], MatDD[N][N];
float V1[N], V2[N], V3[N], V4[N];
void InitData() {
int i,j;
srand(334411);
for( i = 0; i < N; i++ )
 for( j = 0; j < N; j++ ){
 Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
 if ( (abs(i - j) <= 3) && (i != j))
 MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
 else if ( i == j )
 MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
 else MatDD[i][j] = 0.0;
 }
for( i = 0; i < N; i++ ){
 V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
}
}

//Problema 1
void PrintVect( float vect[N], int from, int numel ) { 
if(from<N && numel<=N-from){
	for (int i=from; i < numel+from; i++) {
		printf("%f ", vect[i]);
}
	printf("\n");
}
else{
	printf("Error\n");
}
}

//Problema 2
void PrintRow( float mat[N][N], int row, int from, int numel ){
if (from<N && numel<=N-from && row<N){
	for(int i= from;i<numel+from; i++){
		printf("%f ",mat[row][i]);
}
	printf("\n");
}
else{
	printf("Error\n");
}
}
 
//Problema 3
void  MultEscalar( float vect[N], float vectres[N], float alfa ){

for(int i=0; i<N; i++){
	vectres[i]=vect[i]*alfa;
}
}

//Problema 4
float Scalar( float vect1[N], float vect2[N] ){
float x=0;
for (int i=0; i<N; i++){
	x=x+(vect1[i]*vect2[i]);
}
printf("%f\n",x);
}

//Problema 5
float Magnitude( float vect[N] ){
float x=0;
for(int i=0; i<N; i++){
	x=x+(vect[i]*vect[i]);
}
x=sqrt(x);
printf("%f\n",x);
}

//Problema 6
int Ortogonal( float vect1[N], float vect2[N] ){
float x=0;
int y=0;
for (int i=0; i<N; i++){
        x=x+(vect1[i]*vect2[i]);
}
if (x==0){
	y=1;
}else{
	y=0;
}
return y;
}

//Problema 7
void  Projection( float vect1[N], float vect2[N], float vectres[N] ){
float numerador=0;
float denominador=0;
float denominador1=0;
float fraccio=0;
float x=0;
for (int i=0; i<N; i++){
        numerador=numerador+(vect1[i]*vect2[i]);
}
for(int i=0; i<N; i++){
        x=x+(vect2[i]*vect2[i]);
}
denominador=sqrt(x);
if (denominador==0){
	printf("Error");
}else{
	fraccio=(numerador/denominador);
}
for(int i=0; i<N; i++){
        vectres[i]=vect2[i]*fraccio;
}
}

//Problema 8
float Infininorm( float M[N][N] ){
float x=0;
float suma=0;
for (int i=0; i<N; i++){
	for (int j=0; j<N; j++){
		suma+=fabs(M[i][j]);
	}
	if (x<suma){
		x=suma;
	}
	suma=0;
}
return x;
}


//Problema 9
float Onenorm( float M[N][N] ){
float x=0;
float suma=0;
for (int j=0; j<N; j++){
        for (int i=0; i<N; i++){
                suma+=fabs(M[i][j]);
        }
        if (x<suma){
                x=suma;
        }
        suma=0;
}
return x;
}

//Problema 10
float NormFrobenius(float M[N][N])
{
    float sumatori = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            sumatori += (M[i][j]) * (M[i][j]);
    }
    float final = sqrt(sumatori);
    return final;
}

//Problema 11
int DiagonalDom( float M[N][N] )
{
    float final=0;
    float diagonal=0;
    float sumatori = 0;
    for (int i = 0; i < N; i++){
        diagonal=fabs(M[i][i]);
	for (int j = 0; j < N; j++)
            sumatori += fabs(M[i][j]);
    sumatori=sumatori-diagonal;
    if (sumatori<=diagonal){
	final = 1; 
    }
    else{
	final=0;
    }
    sumatori=0;
    }
    return final;
}


//Problema 12
void Matriu_x_Vector( float M[N][N], float vect[N], float vectres[N] ){
float final=0;
float sumatori=0;
for (int i=0; i<N; i++){
	sumatori=0;
	for (int j=0; j<N; j++){
		sumatori+=(M[i][j]);
		
	}
final=sumatori*vect[i];
vectres[i]=final;
}
}

int main(){
InitData();
printf("Comprovació A:\n");
PrintVect(V1, 0, 10);
PrintVect(V1, 256, 10);
PrintVect(V2, 0, 10);
PrintVect(V2, 256, 10);
PrintVect(V3, 0, 10);
PrintVect(V3, 256, 10);

printf("Comprovació B:\n");
PrintRow(Mat, 0, 0, 10);
PrintRow(Mat, 100, 0, 10);

printf("Comprovació C:\n");
PrintRow(MatDD, 0, 0, 10);
PrintRow(MatDD, 100, 95, 10);

printf("Comprovació D:\n");
printf("Infininorma:\n");
printf("%f\n",Infininorm(Mat));
printf("%f\n",Infininorm(MatDD));
printf("Norma ú:\n");
printf("%f\n",Onenorm(Mat));
printf("%f\n",Onenorm(MatDD));
printf("Frobenius:\n");
printf("%f\n",NormFrobenius(Mat));
printf("%f\n",NormFrobenius(MatDD));
printf("Diagonal dominant:\n");
if (DiagonalDom(Mat)==0){
	printf("Mat no és diagonal dominant\n");
}
if (DiagonalDom(Mat)==1){
	printf("Mat és diagonal dominant\n");
}
if (DiagonalDom(MatDD)==0){
        printf("MatDD no és diagonal dominant\n");
}
if (DiagonalDom(MatDD)==1){
        printf("MatDD és diagonal dominant\n");
}

printf("Comprovació E:\n");
Scalar(V1,V2);
Scalar(V1,V3);
Scalar(V2,V3);

printf("Comprovació F:\n");
Magnitude(V1);
Magnitude(V2);
Magnitude(V3);

printf("Comprovació G:\n");
if(Ortogonal(V1,V2)==1){
	printf("V1 i V2 són ortogonals\n");
}if (Ortogonal(V1,V2)==0){
	printf("V1 i V2 no són ortogonals\n");
}
if(Ortogonal(V1,V3)==1){
        printf("V1 i V3 són ortogonals\n");
}if (Ortogonal(V1,V3)==0){
        printf("V1 i V3 no són ortogonals\n");
}
if(Ortogonal(V2,V3)==1){
        printf("V2 i V3 són ortogonals\n");
}if (Ortogonal(V2,V3)==0){
        printf("V2 i V3 no són ortogonals\n");
}

printf("Comprovació H:\n");
float Vres[N];
MultEscalar(V3,Vres,2.0);
PrintVect(Vres,0,10);
PrintVect(Vres,256,10);

printf("Comprovació I:\n");
float Vres1[N];
Projection(V2,V3,Vres1);
PrintVect(Vres1,0,10);
Projection(V1,V2,Vres1);
PrintVect(Vres1,0,10);

printf("Comprovació J:\n");
float Vres2[N];
Matriu_x_Vector(Mat,V2,Vres2);
PrintVect(Vres2,0,10);


}

