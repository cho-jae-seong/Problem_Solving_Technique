#include<stdio.h>

int main(void){
	int px1,py1;
	int px2,py2;
	int px3,py3;
	int movex,movey;
	int check;
	scanf("%d%d",&px1,&py1);
	scanf("%d%d",&px2,&py2);
	scanf("%d%d",&px3,&py3);
	movex=0-px1;
	movey=0-py1;
	px1+=movex;py1+=movey;
	px2+=movex;py2+=movey;
	px3+=movex;py3+=movey;
	check=px2*py3-py2*px3;
	if(check>0)printf("L");
	else if(check<0)printf("R");
	else printf("C");
	return 0;
}
