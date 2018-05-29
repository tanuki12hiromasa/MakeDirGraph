#include <stdio.h>

//例題3の町を有向グラフにして.csvで出力する。
int main(){
	int w[81][81];
	int i,j;
	for(i=0;i<81;i++)
		for(j=0;j<81;j++)
			w[i][j]=0;
	for(i=0;i<81;i++){
		if(i>=9){
			if(i%9==1||i%9==4&&i>=40||i%9==7) w[i][i-9]=1;
			else w[i][i-9]=2;  }
		if(i<72){
			if(i%9==1||i%9==4&&i>31||i%9==7) w[i][i+9]=1;
			else w[i][i+9]=2;}
		if(i%9!=0){
			if(i>=27&&i<36)w[i][i-1]=1;
			else w[i][i-1]=2;}
		if(i%9!=8){
			if(i>=27&&i<36)w[i][i+1]=1;
			else w[i][i+1]=2;}
	}
	printf("done calc\n");
	FILE* fp = fopen("neighbor_mat3.csv","w");
	for(i=0;i<81;i++){
		for(j=0;j<80;j++){
			fprintf(fp,"%d,",w[i][j]);
		}
		fprintf(fp,"%d\n",w[i][j]);
	}
	fclose(fp);
}
