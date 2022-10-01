#include<stdio.h>
#include<string.h>
#include "slova.h"

char decode(char *slovo,int vel){
    char slova[26][5]={A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};
    char brojevi[10][6]={nula,jedan,dva,tri,cetiri,pet,sest,sedam,osam,devet};
    if(vel<5){
        int i;
        for(i=0;i<26 && strcmp(slova[i],slovo)!=0;i++);
        return 'A'+i;
    }
    int i;
    for(i=0;i<10 && strcmp(brojevi[i],slovo)!=0;i++);
    return '0'+i;
}

void dekodiraj(){
    FILE* pok1=fopen("morze.txt","r");
    FILE* upisi=fopen("decode.txt","w");
    //FILE* pok2=fopen("morze.txt","r");
    if(pok1==NULL){
        printf("Datoteka %s ne postoji","morze.txt");

    }
    else{
    int c;
    
    while((c=fgetc(pok1))!=EOF){
        int razmaci=1;
        for(;c==' ' && c!=EOF;c=fgetc(pok1),razmaci++);
        if(razmaci>1)fputc(' ',upisi);
        int brojac=0;
        char slovo[6]="";
        for(;c!=' ' && c!=EOF;slovo[brojac]=(char)c,brojac++,c=fgetc(pok1));
        fputc(decode(slovo,brojac),upisi);
    }
      fclose(pok1);
      fclose(upisi);
    }
}

int is_letter(char c){
  return (c>='A' && c<='Z') || (c>='a' && c<='z');
}
int is_number(char c){
  return (c>='0' && c<='9');
}
char to_upper(char c){
  if(c>='A' && c<='Z') return c;
  return c+'A'-'a';
}

void zakodiraj(){
  char slova[26][5]={A,B,C,D,E,F,G,H,I,J,K,L,
  M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};
  char brojevi[10][6]={nula,jedan,dva,tri,cetiri,pet,sest,sedam,osam,devet};
  FILE* pok1=fopen("tekst.txt","r");
  FILE* upisi=fopen("morze.txt","w");
  int c;
  while((c=fgetc(pok1))!=EOF){
    if(is_letter(c))
      fputs(slova[(int)(to_upper(c)-'A')],upisi);
    else if(is_number(c))
      fputs(brojevi[(int)(c-'0')],upisi);
    
    fputc(' ',upisi);
  }
  fclose(pok1);
  fclose(upisi);
}
int main(){
  zakodiraj();
  dekodiraj();
  return 0;
}
