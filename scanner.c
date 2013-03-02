#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef BUFFSIZE
#define  BUFFSIZE 10
#endif

int main(int argc, char const *argv[])
{
	char buffer[2][BUFFSIZE+1], identifier[BUFFSIZE];
	int buf_num = 0, ptr1, ptr2, cur_buf_num,i, id_len_count=0, bytes_read, error_flag=0;
	FILE *fp;
	fp = fopen(argv[1],"r");
	if (fp==NULL){
		printf("File does not exist! Exiting...");
		exit(0);
	}
	buffer[0][BUFFSIZE]=EOF;
	buffer[1][BUFFSIZE]=EOF;
	ptr1 = 0;
	ptr2 = 0;
	while(1){
		cur_buf_num = buf_num%2;
		bytes_read = fread(buffer[cur_buf_num], 1, BUFFSIZE, fp);
		if(bytes_read<BUFFSIZE)
			buffer[cur_buf_num][bytes_read] = EOF;
		/* Iterating over buffer.*/
		for(i=0;i<BUFFSIZE;i++){
			if(buffer[cur_buf_num][i]==EOF)
				exit(0);
			/* Checking for arithmetic operators. */
			else if(buffer[cur_buf_num][i]=='/'|| buffer[cur_buf_num][i]=='*'||buffer[cur_buf_num][i]=='%'){
				if(buffer[cur_buf_num][i]=='/')
					printf("/ Arithmetic operator\n");
				else if (buffer[cur_buf_num][i]=='*')
					printf("* Arithmetic operator\n");
				else
					printf("Mod Arithmetic operator\n");
				ptr1=ptr2=i+1;
			}
			else if(buffer[cur_buf_num][i]=='+'){
				if (buffer[cur_buf_num][i+1]=='+'){
					printf("++ Arithmetic operator\n");
				}
				else{
					printf("+ Arithmetic operator\n");
				}
			}
			else if(buffer[cur_buf_num][i]=='-'){
				if (buffer[cur_buf_num][i+1]=='-'){
					printf("-- Arithmetic operator\n");
				}
				else{
					printf("- Arithmetic operator\n");
				}
			}
			/* Checking for relational operators. */
			else if(buffer[cur_buf_num][i]=='<'||buffer[cur_buf_num][i]=='>'||buffer[cur_buf_num][i]=='='||buffer[cur_buf_num][i]=='!'){
				if(buffer[cur_buf_num][i]=='<'){
					if(buffer[cur_buf_num][i]=='='){
						printf("<= Relational operator\n");
					}
					else{
						printf("< Relational operator\n");
					}
				}
				else if(buffer[cur_buf_num][i]=='>'){
					if(buffer[cur_buf_num][i]=='='){
						printf(">= Relational operator\n");
					}
					else{
						printf("> Relational operator\n");
					}
				}
				else if (buffer[cur_buf_num][i]=='='){
					if(buffer[cur_buf_num][i+1]=='='){	
						printf("== Relational operator\n");
					}
				}
				else{
					if(buffer[cur_buf_num][i+1]=='='){
						printf("!= Relational operator\n");
					}
					else{
						printf("Error Invalid Symbol '!'");
					}
				}
			}
			/*Checking for identifiers*/
			else if(id_len_count==0){
				if(isdigit(buffer[cur_buf_num][i])  && (isalpha(buffer[cur_buf_num][i+1]) || buffer[cur_buf_num][i+1]=='_')){
					error_flag = 1;
					identifier[id_len_count++] = buffer[cur_buf_num][i];
				}
				else if(isalpha(buffer[cur_buf_num][i]) || buffer[cur_buf_num][i]=='_'){
					error_flag = 0;
					identifier[id_len_count++] = buffer[cur_buf_num][i];
				}
			}
			else if (isalpha(buffer[cur_buf_num][i]) || isdigit(buffer[cur_buf_num][i]) || buffer[cur_buf_num][i]=='_'){
				identifier[id_len_count++] = buffer[cur_buf_num][i];
			}
			if(id_len_count!=0 && (!isalpha(buffer[cur_buf_num][i]) && !isdigit(buffer[cur_buf_num][i]) && buffer[cur_buf_num][i]!='_')){
				identifier[id_len_count]='\0';
				if (error_flag==0){
					printf("%s Identifier\n", identifier);
				}
				else{
					printf("%s Error\n", identifier);
				}
				id_len_count = 0;
			}
		}
		buf_num++;
	}
	return 0;
}