#include <stdio.h>
 
int N,cnt,target;
int pow2[21],p[21];
void move(int disc, int dst){  
    int src = p[disc]; 
    int aux = 6 - src - dst;      
    if(disc<1) return;
    if(dst!=src){ 
        move(disc-1,aux); 
        cnt = (cnt + pow2[disc-1]); 
    }else  move(disc-1,dst); 
}
  
int main(void){ 
    int i;  
    pow2[0]=1; 
    for(i=1;i<21;++i) pow2[i] = (pow2[i-1]<<1);
    scanf("%d%d",&N,&target);
    int a,b,c,x;
    scanf("%d",&a);     
    for(i=1;i<=a;++i) {  scanf("%d",&x); p[x]=1; }
    scanf("%d",&b);
    for(i=1;i<=b;++i) {  scanf("%d",&x); p[x]=2; }
    scanf("%d",&c);
    for(i=1;i<=c;++i) {  scanf("%d",&x); p[x]=3; }  
    cnt=0;      
    move(N,target);  
    printf("%d",cnt); 
    return 0;
}
