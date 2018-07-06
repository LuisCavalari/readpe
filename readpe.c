#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/petest.h"

#define TAM 32


void error(char *msg){
	fprintf(stderr,"%s \n",msg);
	exit(1);

}

	

int main(int argc,char *argv[]){
	if( argc !=2){
		error("Usage ./readpe [file name]");
	}
	PEFILE pe;

	pe.filepath = argv[1];
	petest_init(&pe);
	if(petest_ispe(&pe))
		printf("ALL ok, continue... \n");
	else
		error("Nao parece ser um arquivo PE");	
	
	printf("FILE: %s\n",pe.filepath);
	printf("MZ header %x \n", pe.hdr_dos->e_magic);
	printf("COFF header %x \n",pe.hdr_dos->e_lfanew);
	
	if(!petest_deinit(&pe))
		error("não possivel desalocar, eh null");
	printf("Desalocando... \n");
	

	return 0;
}
