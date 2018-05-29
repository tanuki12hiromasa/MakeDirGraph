#include <stdio.h>

//例題2の町を有向グラフにして.csvで出力する。
int main(){
	int w[81][81];
	int i,j;
	for(i=0;i<81;i++)
		for(j=0;j<81;j++)
			w[i][j]=0;
	for(i=0;i<81;i++){
		if(i>=9){
			if(i%9==1||i%9==4||i%9==7) w[i][i-9]=1;
			else w[i][i-9]=3;  }
		if(i<72){
			if(i%9==1||i%9==4||i%9==7) w[i][i+9]=1;
			else w[i][i+9]=3;}
		if(i%9!=0){
			if(i>=9&&i<=17||i>=45&&i<=53)w[i][i-1]=1;
			else w[i][i-1]=3;}
		if(i%9!=8){
			if(i>=9&&i<=17||i>=45&&i<=53)w[i][i+1]=1;
			else w[i][i+1]=3;}
	}
	printf("done calc\n");
	FILE* fp = fopen("neighbor_mat2.csv","w");
	for(i=0;i<81;i++){
		for(j=0;j<80;j++){
			fprintf(fp,"%d,",w[i][j]);
		}
		fprintf(fp,"%d\n",w[i][j]);
	}
	fclose(fp);
}
