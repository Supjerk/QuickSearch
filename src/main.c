#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int argc, char *argv[]) {
	if (argc<2) { throwUsage(argv[0]); return 1; }
	char buf[512];

	memset(buf,0,512);

	if(strcmp(argv[1],"google")==0) {
		if (argc<3) { throwError(E_SYNTAX,"Syntax Error: You can't search on google if argc under 3\n"); throwUsage(argv[0]); return 1; }
		strncat(buf,BASE_GOOGLE,strlen(BASE_GOOGLE));
		strncat(buf,argv[2],510-strlen(BASE_GOOGLE));
		strncat(buf,"\"",1);
		system(buf);
	}
	else if(strcmp(argv[1],"calc")==0) { system("gnome-calculator"); }
	else if(strcmp(argv[1],"help")==0) { puts(help_man); }

  return 0;
}
