//Project 2

//Scott Nearing
//sn379745

//Description:
//This file contains the main function of a program that reads
//from either a text or binary file and converts to the 
//other form. The Program can also read a binary file and 
//determine some statistics. The input and output files
//are specified by command line arguments as is the mode.

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//headers
#include "constants.h"
#include "struct_def.h" 
#include "globals.h"
#include "prototypes.h"


//main function that accepts command line arguments and returns an int
int main(int argc, const char * argv[]){

  //flags
    char t[] = "-t";
    char b[] = "-b";
    char s[] = "-s";


  if(argc <MINARG || argc > MAXARG){//if # of arguments isn't 3 or 4
    fprintf(stderr, "Wrong number of arguments.\n");//print error
    return 1;} // exit program


  if(argc == MAXARG ){//if user input 4 arguments
    if(strcmp(argv[FLAGPOS],t)==0){ //if flag is "-t"
     
      in = fopen(argv[INPOS], "r");// open input file for reading
        if(in == NULL){//if input file failed to open
          fprintf(stderr, "The input file failed to open.\n");}//error message
     
      out = fopen(argv[OUTPOS], "w"); //open output file for writing
        if(out == NULL){ //if output file didn't open correctly
          fprintf(stderr, "The output file failed to open.\n");}//error message
     
      text(); //calls text() function in funct.c
      fclose(out); //close output file
      fclose(in); //close input file
      return(0); //exit program
    }//end if strcmp(argv[FLAGPOS],t)==0

    if(strcmp(argv[FLAGPOS],b)==0){ //if flag is "-b" 
    
      in = fopen(argv[INPOS], "r");//open input file for reading
        if(in == NULL){//if input failed to open
          fprintf(stderr, "The input file failed to open.\n");}//error message
     
      out = fopen(argv[OUTPOS], "w");//open output file for writing
        if(out == NULL){//if output failed to open
          fprintf(stderr, "The output file failed to open.\n");}//error message
     
      binary();//calls binary() function in funct.c
      fclose(in);//close input file
      fclose(out);//close output file
      return(0);//exit program  

    }//end if strcmp(argv[FLAGPOS], b)==0
  }//end if argc == 4

  if(argc == MINARG){
    if(strcmp(argv[FLAGPOS],s)==0){
      in = fopen(argv[INPOS], "r");
      if(in==NULL){fprintf(stderr, "The input file failed to open.\n");}
      stats();
      fclose(in);
      return 0;

    }//end if strcmp(argv[FLAGPOS], s)==0

  }//end if argc == 3


//at this point the user has input 3 or 4 arguments, but the wrong flag was
//was used. Print a suitable error message.
  fprintf(stderr, "Incorrect flag.\n");
  return(1);
}//end main
