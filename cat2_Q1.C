/*
Muigai kelvin njunge,
CT101/G/24553/24,
PROGRAM:2Darray,
6/11/2025,
*/
#include<stdio.h>
int main(){
int scores[2][2][2]={
{
{65,92},
{84,72}
}  ,
{
{35,70},
{59,69}
}
};
int i,j,k;
for(i=0;i<2;i++){
for(j=0;j<2;j++){
for(k=0;k<2;k++){
printf("%d\n",scores[i][j][k]);
}
}
}
return 0;
}
