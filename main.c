#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
#include "string_func.h"


char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

void remove_from_string(char string[],int index){
    while(string[index]!='\0'){
        string[index]=string[index+1];
        index++;
        
    }
}

int gemetria_seq( char word[], char txt[]){

    printf("Gematria Sequences: ");
    int word_val=0, i=0, j=0, tmp_value=0, k=0, first=0;
    char seq[WORD];
    while (word[i]!='\0'){
        if(word[i]<='Z' && word[i]>='A') {
            word_val += word[i] - 64;
        }
        if(word[i]<='z' && word[i]>='a'){
            word_val+=word[i]-96;
        }
        i++;
    }
    i=0;

    while(txt[i]!='\0'){
        while(txt[j]!='\0'){
            if(txt[j]<='Z' && txt[j]>='A') {
                tmp_value += txt[j] - 64;
                seq[k]=txt[j];
                k++;

            }
            if(txt[j]<='z' && txt[j]>='a'){
                tmp_value+=txt[j]-96;
                seq[k]=txt[j];
                k++;

            }

            if((txt[j]>'z' || txt[j]<'a') && (txt[j]>'Z' || txt[j]<'A') && k==0 && tmp_value==0){
                seq[k]=txt[j];
                i++;
                j=i;
                break;
            }

            if((txt[j]>'z' || txt[j]<'a') && (txt[j]>'Z' || txt[j]<'A') && k!=0){
                seq[k]=txt[j];
                k++;
            }
            if(tmp_value>word_val){
                tmp_value=0;
                i++;
                j=i;
                k=0;
                break;
            }
            if(tmp_value==word_val && first==0){
                first ++;
                seq[k]='\0';
                printf("%s",seq);
                i++;
                j=i;
                k=0;
                tmp_value=0;
                break;
            }
            if(tmp_value==word_val){
                seq[k]='\0';
                printf("~%s",seq);
                i++;
                j=i;
                k=0;
                tmp_value=0;
                break;
            }
            j++;
           
        }
        if(txt[j]=='\0')
            break;
    }


printf("\n");

    return 0;
}

int atbash_seq( char word[], char txt[]){
    int length =0;
    char ans[WORD];
    strcpy(ans,word);

    printf("Atbash Sequences: ");
    int i=0, j=0, k=0, first=0;
   
    while (word[i]!='\0'){
        if(word[i]<='Z' && word[i]>='A') {
            ans[i]=90-(word[i]-65);
            length++;
        }
        if(word[i]<='z' && word[i]>='a'){
            ans[i]=122-(word[i]-97);
            length++;
        }
        i++;
    } ans[i]='\0';
    char ans_rev[WORD];
    strcpy(ans_rev,ans);
   strrev(ans_rev);
    i=0;
    
     char seq[WORD];

    while(txt[i]!='\0'){
        while(txt[j]!='\0'){
            if(txt[j]<='Z' && txt[j]>='A') {
                seq[k]=txt[j];
                k++;

            }
            if(txt[j]<='z' && txt[j]>='a'){
                seq[k]=txt[j];
                k++;

            }

            if((txt[j]>'z' || txt[j]<'a') && (txt[j]>'Z' || txt[j]<'A') && k==0 ){
                i++;
                j=i;
                break;
            }

            if((txt[j]>'z' || txt[j]<'a') && (txt[j]>'Z' || txt[j]<'A') && k!=0){
                seq[k]=txt[j];
                k++;
            }
            
              if(length==k ){
                seq[k]='\0';
                if((strcmp(seq,ans)==0 || strcmp(seq,ans_rev)==0) && first==0){
                    printf("%s",seq);
                        i++;
                  first++;
                    k=0;
                    j=i;
                    
                break;
            }
                   
                }
              
            
            
            if(length==k){
                if(strcmp(seq,ans)==0 || strcmp(seq,ans_rev)==0){
                    printf("~%s",seq);
                    
                }
                  i++;
                    k=0;
                    j=i;
                break;
            }
            
            j++;
                  }
        if(txt[j]=='\0')
            break;
    }


     printf("\n");

    return 0;
}

int angram_seq( char word[], char txt[]){
    char word_ang[WORD];
    strcpy(word_ang,word);
    int j=0, k=0, i=0, first=0, counter=0;
    printf("Anagram Sequences: ");
    int length=strlen(word);
    
    
    char seq[WORD];
    while(txt[i]!='\0'){
    while(txt[j]!='\0'){

               if(txt[j]<='Z' && txt[j]>='A') {
                   for(int a=0;a<length;a++){
                 if(word_ang[a]==txt[j]){
                     remove_from_string(word_ang,a);
                     counter++;
                seq[k]=txt[j];
                k++;
                length--;
                break;
                 }
            }  
               if  ( counter==0){
                 i++;
                 j=i;
                 k=0;
                  length=strlen(word);
                  strcpy(word_ang,word);
                  break;
               }
               }
               else if(txt[j]<='z' && txt[j]>='a'){
                for(int a=0;a<length;a++){
                 if(word_ang[a]==txt[j]){
                     remove_from_string(word_ang,a);
                     counter++;
                seq[k]=txt[j];
                 k++;
                length--;
                break;
               } 
                }if (counter==0){;
                 i++;
                 k=0;
                 j=i;
                  length=strlen(word);
                  strcpy(word_ang,word);
                  break;
                }
               }else if(txt[j]==' ' && k!=0){
                    seq[k]=txt[j];
                    k++;
                    j++;
                    break;
                   
               } else{
                 
               for(int a=0;a<length;a++){
                   if(txt[j]==word_ang[a]){
                       
                        remove_from_string(word_ang,a);
                        k++;
                        length--;
                        break;
                }
               }

                  i++;
                  j=i;
                  k=0;
                  length=strlen(word);
                  strcpy(word_ang,word);
                  break;
               }
               
               if(length==0 && first==0){
                   seq[k]='\0';
                   printf("%s",seq);
                    i++;
                  j=i;
                  k=0;
                  first++;
                  length=strlen(word);
                  strcpy(word_ang,word);
                  break;
               } else if(length==0){
                      seq[k]='\0';
                   printf("~%s",seq);
                    i++;
                  j=i;
                  k=0;
                  length=strlen(word);
                  strcpy(word_ang,word);
                  break;
               }
                   j++;
                   counter=0;
        }
      if(txt[j]=='\0')
            break;
    }
    
    return 0;
}




int main() {
    char word[WORD];
    char txt[TXT];
    scanf("%s",word);
    scanf("%[^~]",txt);
    gemetria_seq(word,txt);
     atbash_seq(word,txt);
     angram_seq(word,txt);
    return 0;
}
