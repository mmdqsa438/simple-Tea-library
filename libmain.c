#include <stdio.h>
#include "wellcome.h"
#define TRUE 1
#define MAXLEN 20
int get_line(char str[] , int maxlen ){
    int index=0 ,character ;
    for(index=0;index<maxlen-1 && (character=getchar())!='\n';index++){
        str[index]=character;
    } str[index]='\0';
    if(character=='\n' && index==0){
        return 0 ;
    } return 1 ;
}
int commandchecker( char command[] , char sorce[] ){
    int index ;
    for(index=0 ; command[index]!='\0';index++ ){
        if(command[index]!=sorce[index]){
            return 0 ;
        }
    } return 1 ;
}
int main(void){
    char teainfo[]="TeaInfo" , findtea[]="FindTea", addtea[]="AddTea", exit[]="Exit" ;
    char bookname[MAXLEN] ,writername[MAXLEN],date[MAXLEN], command[MAXLEN] ;
    wellcome();
    while(TRUE){
        printf("Please Enter Your command : ");
        if(get_line(command,MAXLEN)){
            if(commandchecker(command,teainfo)){
                printbydilay( "OK Please realax and enjoy!\n " , 60 , 1000 );

                //TeaInfo() >>> from tea library modulu [ call without parameters ; can print in program .

            } else if (commandchecker(command,findtea)){
                printf("Please Enter The Name Of The Book You Want : ");
                if(!get_line(bookname , MAXLEN)){
                    printf("\nOh! sorry you must enter book name !\n");
                    continue;
                } printf("Please Enter The Name Of Auther : ");
                if(!get_line(writername,MAXLEN)){
                    printf("\n! sorry you must enter the auther name !\n");
                    continue;  
                } printf("Please Specify The Publication Date : ");
                if(!get_line(date,MAXLEN)){
                    printf("\nOh! sorry you must enter Date !\n");
                    continue;
                }

                //if(FindTea( bookname , writername , date , MAXLEN )){ //>>> from tea library [ return 0 ,1 .
                    
                    printf("\n\tCongradulation, The Book %s By %s wrote in %s find in our library.\n\tby your student card you can use it ...\n",bookname,writername,date);
                
                //} else{

                    printf("\nsorry , we have not found searched book right here ...\n");
                
                //}
            } else if ( commandchecker(command,addtea)){
                printf("Please Enter The Name Of The Your Book : ");
                if(!get_line(bookname , MAXLEN)){
                    printf("\nOh! sorry you must enter book name !\n");
                    continue;
                } printf("Please Enter The Name Of Auther : ");
                if(!get_line(writername,MAXLEN)){
                    printf("\n! sorry you must enter the auther name !\n");
                    continue;  
                } printf("Please Specify The Publication Date : ");
                if(!get_line(date,MAXLEN)){
                    printf("\nOh! sorry you must enter Date !\n");
                    continue;
                }

                //if(AddTea( bookname , writername , date , MAXLEN)){ >>> from tea lib [ return 0 if lib overflowed .

                    printf("\n\tCongradulation, The Book %s By %s wrote in %s has added to our library.\n",bookname,writername,date);
                //}else{
                    printf("sorry there is no empty place for your book right now ...\n");
                //}
            } else if ( commandchecker(command,exit)){
                break ;
            } else{
                printf("Invalid Command, Please Retry ...\n");
            }
        } else{
            printf("Invalid Command, Please Retry ...\n");
        }
    }
    return 0 ;
}
