#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void mygrep(FILE*, char*); 
void myreplace(FILE *fp,char *find, char * replace);

int  main(int argc,char *argv[])
{
	int behaviour;
	FILE *fp;
	char *filename=argv[1];
	char *find=argv[2];
	char * replace;

	if( strcmp(argv[0],"./mygrep") == 0 )
	{
		if(argc != 3)
		{
			printf("usage\t./mygrep filename <string-to-search>\n");
			exit(1);
		}

		behaviour = 0;
	}
	else if( strcmp(argv[0],"./myreplace") == 0 )
	{
		if(argc != 4)
		{
			printf("\t./myreplace filename  <string-to-search> <string-to-replace>\n");
			exit(1);
		}
		behaviour = 1;
		replace = argv[3];
	}
	else
	{
		behaviour = -1;
	}

	fp=fopen(filename,"rt");

	if(behaviour == 0)
	{
		mygrep(fp,find);		
	}
	else if ( behaviour == 1 )
	{
		myreplace(fp,find,replace);
	}
	
	return 0;
}

void mygrep(FILE *fp,char *find)
{
	char c1[500];

	if (fp == NULL)
	{
        printf("File can't be opened...");
    }
    	
	else
	{
		while (fgets(c1, 500, fp) != NULL)
		{	
			if(strstr(c1,find) != NULL)
				printf("%s",c1);
		}
	}
}

void myreplace(FILE *fp,char *find, char * replace)
{
	char c1[500], *position;
	int flen = strlen(find);
	int a=0, i=0, j=0, start=0;

	while( fgets(c1, 500, fp) != NULL )
	{
		if(a == 0)
		{
			position = strstr(c1,find);
			if( position != NULL)
			{
				for(i=0;i<strlen(c1);i++)
				{
					if(position == &c1[i])
						start=i;
				}
				printf("Old =  %s",c1);
				position=position-flen;
				for(j=start,i=0; j<start+flen; j++,i++)
				{
					c1[j]=replace[i];
				}
				printf("New =  %s",c1);
				a=1;
			}
		}
	}
}
