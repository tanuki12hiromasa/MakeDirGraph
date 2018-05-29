#include <stdio.h>

//例題1の町を有向グラフにして.csvで出力する。
int main(){
	int w[81][81];
	int i,j;
	for(i=0;i<81;i++)
		for(j=0;j<81;j++)
			w[i][j]=0;
	for(i=0;i<81;i++){
		if(i>=9) w[i][i-9]=1;
		if(i<72) w[i][i+9]=1;
		if(i%9!=0) w[i][i-1]=1;
		if(i%9!=8) w[i][i+1]=1;
	}
	FILE* fp = fopen("neighbor_mat.csv","w");
	for(i=0;i<81;i++){
		for(j=0;j<80;j++){
			fprintf(fp,"%d,",w[i][j]);
		}
		fprintf(fp,"%d\n",w[i][j]);
	}
	fclose(fp);
}
