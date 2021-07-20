#include <stdlib.h>
#include <stdio.h>

int main()
{
  char coordenada[3][1]= {"x","y","z"};
int pontoA[1][3],pontoB[1][3],pontoC[1][3], vetor_ap[1][3],vetor_AB[1][3],vetor_AC[1][3],vetor_Det[1][3],x,y,z,soma=0,aux_1,aux_2,sair=0;
FILE *arq,*arq2;
arq = fopen("Trabalho.txt","r");
arq2 = fopen("Equação geral do plano.txt","w");
if(arq==NULL|| arq2==NULL){
  printf("Erro de abrir o arquivo\n");
  system("pause");
  exit(1);
}
fscanf(arq,"A(%d,%d,%d)\n",&pontoA[0][0],&pontoA[0][1],&pontoA[0][2]);
fseek(arq,0,SEEK_CUR);
fscanf(arq,"B(%d,%d,%d)\n",&pontoB[0][0],&pontoB[0][1],&pontoB[0][2]);
fseek(arq,0,SEEK_CUR);
fscanf(arq,"C(%d,%d,%d)\n",&pontoC[0][0],&pontoC[0][1],&pontoC[0][2]);
fclose(arq);
for (int i = 0; i < 1; i++) {
for (int j = 0; j < 3; j++) {
vetor_ap[i][j] = (-pontoA[i][j]);
}
}
for (int i = 0; i < 1; i++) {
for (int j = 0; j < 3; j++) {
vetor_AB[i][j] = ((pontoB[i][j])-(pontoA[i][j]));
}
}
for (int i = 0; i < 1; i++) {
for (int j = 0; j < 3; j++) {
vetor_AC[i][j] = ((pontoC[i][j])-(pontoA[i][j]));
}
}
aux_1 = (vetor_AB[0][1]*vetor_AC[0][2]);
aux_2 = -(vetor_AB[0][2]*vetor_AC[0][1]);
vetor_Det[0][0]= aux_1+aux_2;
aux_1 = (vetor_AB[0][0]*vetor_AC[0][2]);
aux_2 = -(vetor_AB[0][2]*vetor_AC[0][0]);
vetor_Det[0][1]=(aux_1 + aux_2)*(-1);
aux_1 = (vetor_AB[0][0]*vetor_AC[0][1]);
aux_2 = -(vetor_AB[0][1]*vetor_AC[0][0]);
vetor_Det[0][2]=aux_1 + aux_2;
for (int i = 0; i < 1; i++) {
  for (int j = 0; j < 3; j++) {
soma += (vetor_ap[i][j]*vetor_Det[i][j]);
}
}
if(vetor_Det[0][0]<0){
for (int i = 0; i < 3; i++) {
vetor_Det[0][i] *= -1;
soma *= -1;
}
}
x=vetor_Det[0][0];
y=vetor_Det[0][1];
z=vetor_Det[0][2];
do{
if(x%2==0 && y%2==0 && z%2==0 && soma%2==0){
x = x/2;
y = y/2;
z = z/2;
soma = soma/2;
}
else if(x%3==0 && y%3==0 && z%3==0 && soma%3==0){
  x = x/3;
  y = y/3;
  z = z/3;
  soma = soma/3;
}
else if(x%5==0 && y%5==0 && z%5==0 && soma%5==0){
  x = x/5;
  y = y/5;
  z = z/5;
  soma = soma/5;
}
else if(x%7==0 && y%7==0 && z%7==0 && soma%7==0){
  x = x/7;
  y = y/7;
  z = z/7;
  soma = soma/7;
}else{
  sair++;
}
}while(!sair);

if(y<0 && z<0 && soma<0)
fprintf(arq2,"A equção geral do plano:\n %ix%iy%iz%i=0\n",x,y,z,soma);
else if(y<0 && z<0)
fprintf(arq2,"A equção geral do plano:\n %ix%iy%iz+%i=0\n",x,y,z,soma);
else if(y<0 && soma<0)
fprintf(arq2,"A equção geral do plano:\n %ix%iy+%iz%i=0\n",x,y,z,soma);
else if(z<0 && soma<0)
fprintf(arq2,"A equção geral do plano:\n %ix+%iy%iz%i=0\n",x,y,z,soma);
else if(y<0)
fprintf(arq2,"A equção geral do plano:\n %ix%iy+%iz+%i=0\n",x,y,z,soma);
else if(z<0)
fprintf(arq2,"A equção geral do plano:\n %ix%+iy%iz+%i=0\n",x,y,z,soma);
else if(soma<0)
fprintf(arq2,"A equção geral do plano:\n %ix+%iy+%iz%i=0\n",x,y,z,soma);
else
fprintf(arq2,"A equção geral do plano:\n %ix+%iy+%iz+%i=0\n",x,y,z,soma);

 fprintf(arq2,"\n");
 fprintf(arq2,"Equações parametricas\n");
for (int j = 0; j < 3; j++) {
if(vetor_AB[0][j]<0 && vetor_AC[0][j]<0){
fprintf(arq2,"%c= %i%ih%it \n",coordenada[0][j],pontoA[0][j],vetor_AB[0][j],vetor_AC[0][j]);
}
else if(vetor_AB[0][j]<0){
fprintf(arq2,"%c= %i%ih+%it \n",coordenada[0][j],pontoA[0][j],vetor_AB[0][j],vetor_AC[0][j]);
}
else if (vetor_AC[0][j]<0){
fprintf(arq2,"%c= %i+%ih%it \n",coordenada[0][j],pontoA[0][j],vetor_AB[0][j],vetor_AC[0][j]);
}else
fprintf(arq2,"%c= %i+%ih+%it \n",coordenada[0][j],pontoA[0][j],vetor_AB[0][j],vetor_AC[0][j]);
}
fclose(arq2);


return 0;
}
