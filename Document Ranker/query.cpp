#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct query
{
	int fileno;
	char word[30];
	int position;
};

struct list
{
	int fileno;
	char word[30];
	int position;
};

int main()
{
	FILE *fp;
	char ch[50],*str,querystr[4][15], *querybuf1,*d=" ",*buffer;
	double querybuffer1;
	long file1_size,file2_size,file3_size;
    int i=0,j=0,k=0,x=0,y=0,z=0,ck=0;
	unsigned long filesize;
	struct query Query[20];
	struct list l1[100000];
	int posn0[1000],posn1[1000],posn2[1000],posn3[1000];
	int rank4[3][5],rank3[3][5],rank2[3][5],fileno0[1000],fileno1[1000],fileno2[1000],fileno3[1000];


    /* THE FOLLOWING CODE IS USED TO OPEN A FILE IN WHICH THE QUERY IS STORED "qq.txt". THE QUERY IS TAKEN FROM THE USER. 
	   HERE WE HAVE PUT A CONSTRAINT ON THE USER THAT THE QUERY SHOULD NOT BE MORE THAN 4 WORDS AND NOT LESS THAN ONE WORD
	   I.E. THE QUERY SHOULD BE EITHER 2,3 OR 4 WORDED.*/
	
	fp=fopen("/u0/users/7/kthorat1/IR/Assignment/qq.txt","w");   
	char q[100];
	printf("\nENTER THE QUERY OF NOT MORE THAN FOUR WORDS : \n");
	gets(q);
	fprintf(fp,"%s",q);
	fputc('.',fp);
	fclose(fp);

	int qno;

	/*THE FOLLOWING CODE IS USED TO OPEN THE FILE WHICH CONTAINS THE QUERY AND PARSE THE WHOLE FILE SUCH THAT THE WORDS
	OF THE FILE ARE STORED INTO A STRUCTURE ALONG WITH THE WORD NUMBER.*/

	fp = fopen("/u0/users/7/kthorat1/IR/Assignment/qq.txt","r");                  
	if(fp == NULL)
		printf("Cannot open file");

	i=j=0;

	while(fgetc(fp)!=EOF)                 
	{
		i++;
	}
	filesize=i;

	fseek(fp,0,SEEK_SET);
	
	buffer = (char *)malloc(filesize+1);

	fread(buffer,filesize,1,fp);

	fclose(fp);

	for(i=0;i<filesize;i++)
	{
		if(buffer[i]!=' '&&buffer[i]!='\n'&&buffer[i]!='\t'&&buffer[i]!='.'&&buffer[i]!='_'&&buffer[i]!='"'&&buffer[i]!='`'&&buffer[i]!=','&&buffer[i]!='\''&&buffer[i]!='-')
		{
			Query[j].word[k]=buffer[i];
		}

		if(buffer[i]==' '||buffer[i]=='\n'||buffer[i]=='\t'||buffer[i]=='.'||buffer[i]=='_'||buffer[i]=='"'||buffer[i]=='`'||buffer[i]==','||buffer[i]=='\''||buffer[i]=='-')
		{
			if(buffer[i-1]!=' '&&buffer[i-1]!='\n'&&buffer[i-1]!='\t'&&i!=0&&buffer[i-1]!='.'&&buffer[i-1]!='_'&&buffer[i-1]!='"'&&buffer[i-1]!='`'&&buffer[i-1]!=','&&buffer[i-1]!='\''&&buffer[i-1]!='-')
			{
			//	l1[j].fileno=1;
				Query[j].word[k]='\0';
				Query[j].position=j+1;
				j++;
			}
			if(buffer[i]=='\'')
				i+=2;
			k=-1;
		}
		
		k++;
	}
	
	free(buffer);  //Here

	for(i=0;i<j;i++)
	{	
	//	printf("\nThe word is : %s",Query[i].word);
	//	printf("\nThe word is at %d position\n",Query[i].position);
	}
	
	qno=j;
//	printf("\n The total number of words are %d\n\n",j);

	/* THE FOLLOWING CODE IS USED TO OPEN A FILE IN WHICH WE HAVE TO SEARCH FOR THE QUERY. THE DOCUMENT IS PARSED AND THE WORDS OF THE DOCUMENT 
	   ARE STORED IN A STRUCTURE ALONGWITH THE FILE NUMBER AND THE POSITION OF THE WORD IN THE DOCUMENT.*/

	fp = fopen("/u0/users/7/kthorat1/IR/Assignment/pinochet.txt","r");
	if(fp == NULL)
		printf("\nCannot open file!!!!!!");
	
	i=j=0;
	while(fgetc(fp)!=EOF)
	{
		i++;
	}
	filesize=i;

	fseek(fp,0,SEEK_SET);
	
	buffer = (char *)malloc(filesize+1);

	fread(buffer,filesize,1,fp);

	fclose(fp);

	for(i=0;i<filesize;i++)
	{
		if(buffer[i]!=' '&&buffer[i]!='\n'&&buffer[i]!='\t'&&buffer[i]!='.'&&buffer[i]!='_'&&buffer[i]!='"'&&buffer[i]!='`'&&buffer[i]!=','&&buffer[i]!='\''&&buffer[i]!='-')
		{
			l1[j].word[k]=buffer[i];
		}

		if(buffer[i]==' '||buffer[i]=='\n'||buffer[i]=='\t'||buffer[i]=='.'||buffer[i]=='_'||buffer[i]=='"'||buffer[i]=='`'||buffer[i]==','||buffer[i]=='\''||buffer[i]=='-')
		{
			if(buffer[i-1]!=' '&&buffer[i-1]!='\n'&&buffer[i-1]!='\t'&&i!=0&&buffer[i-1]!='.'&&buffer[i-1]!='_'&&buffer[i-1]!='"'&&buffer[i-1]!='`'&&buffer[i-1]!=','&&buffer[i-1]!='\''&&buffer[i-1]!='-')
			{
				l1[j].fileno=1;
				l1[j].word[k]='\0';
				l1[j].position=j+1;
				j++;
			}
			if(buffer[i]=='\'')
			i+=2;
			k=-1;
		}
		
		k++;
	}
	
	free(buffer);  //Here

	fp = fopen("/u0/users/7/kthorat1/IR/Assignment/pinochet2.txt","r");
	if(fp == NULL)
		printf("\nCannot open file!!!!!!");

	i=k=0;

	while(fgetc(fp)!=EOF)
	{
		i++;
	}
	filesize=i;

	fseek(fp,0,SEEK_SET);
	
	buffer = (char *)malloc(filesize+1);

	fread(buffer,filesize,1,fp);

fclose(fp);
	
	for(i=0;i<filesize;i++)
	{
		if(buffer[i]!=' '&&buffer[i]!='\n'&&buffer[i]!='\t'&&buffer[i]!='.'&&buffer[i]!='_'&&buffer[i]!='"'&&buffer[i]!='`'&&buffer[i]!=','&&buffer[i]!='\''&&buffer[i]!='-')
		{
			l1[j].word[k]=buffer[i];
		}

		if(buffer[i]==' '||buffer[i]=='\n'||buffer[i]=='\t'||buffer[i]=='.'||buffer[i]=='_'||buffer[i]=='"'||buffer[i]=='`'||buffer[i]==','||buffer[i]=='\''||buffer[i]=='-')
		{
			if(i!=0)
			{
				if(buffer[i-1]!=' '&&buffer[i-1]!='\n'&&buffer[i-1]!='\t'&&buffer[i-1]!='.'&&buffer[i-1]!='_'&&buffer[i-1]!='"'&&buffer[i-1]!='`'&&buffer[i-1]!=','&&buffer[i-1]!='\''&&buffer[i-1]!='-')
				{
					l1[j].fileno=2;
					l1[j].word[k]='\0';
					l1[j].position=j+1;
					j++;
				}
			}
			if(buffer[i]=='\'')
			i+=2;
			k=-1;
		}
		k++;
	}

	free(buffer);
	

	fp = fopen("/u0/users/7/kthorat1/IR/Assignment/pinochet3.txt","r");
	if(fp == NULL)
		printf("\nCannot open file!!!!!!");

	i=k=0;

	while(fgetc(fp)!=EOF)
	{
		i++;
	}
	filesize=i;

	fseek(fp,0,SEEK_SET);
	
	buffer = (char *)malloc(filesize+1);

	fread(buffer,filesize,1,fp);

	fclose(fp);
	
	for(i=0;i<filesize;i++)
	{
		if(buffer[i]!=' '&&buffer[i]!='\n'&&buffer[i]!='\t'&&buffer[i]!='.'&&buffer[i]!='_'&&buffer[i]!='"'&&buffer[i]!='`'&&buffer[i]!=','&&buffer[i]!='\''&&buffer[i]!='-')
		{
			l1[j].word[k]=buffer[i];
		}

		if(buffer[i]==' '||buffer[i]=='\n'||buffer[i]=='\t'||buffer[i]=='.'||buffer[i]=='_'||buffer[i]=='"'||buffer[i]=='`'||buffer[i]==','||buffer[i]=='\''||buffer[i]=='-')
		{
			if(i!=0)
			{
				if(buffer[i-1]!=' '&&buffer[i-1]!='\n'&&buffer[i-1]!='\t'&&buffer[i-1]!='.'&&buffer[i-1]!='_'&&buffer[i-1]!='"'&&buffer[i-1]!='`'&&buffer[i-1]!=','&&buffer[i-1]!='\''&&buffer[i-1]!='-')
				{
					l1[j].fileno=3;
					l1[j].word[k]='\0';
					l1[j].position=j+1;
					j++;
				}
			}
			if(buffer[i]=='\'')
			i+=2;
			k=-1;
		}
		k++;
	}

/*  for(i=0;i<j;i++)
	{	
		printf("\nThe word is : %s",l1[i].word);
		printf("\nThe word is at %d position\n",l1[i].position);
	} */
	
//	printf("\n The total number of words are %d\n\n",j);

	free(buffer);


    int count0 = 0;

	for(i=0;i<j;i++)
	{
		if((strcmp(Query[0].word,l1[i].word)) == 0 )//&& (strcmp(querystr[2],l1[i].word)) == 0 && (strcmp(querystr[3],l1[i].word)) == 0)
		{
	//		printf("\n %s    :    File %d    :    Position %d",l1[i].word,l1[i].fileno,l1[i].position);
			fileno0[count0] = l1[i].fileno;
			posn0[count0]=l1[i].position;
//			l1[i].position = posn0[i];
			count0++;
		}
	}
	//	printf("\n\nThe Word is found %d times..",count0);
	//	printf("\n");
	
	
	int count1 = 0;

	for(i=0;i<j;i++)
	{
		if((strcmp(Query[1].word,l1[i].word)) == 0 )//&& (strcmp(querystr[2],l1[i].word)) == 0 && (strcmp(querystr[3],l1[i].word)) == 0)
		{
	//		printf("\n %s    :    File %d    :    Position %d",l1[i].word,l1[i].fileno,l1[i].position);
			fileno1[count1] = l1[i].fileno;
			posn1[count1]=l1[i].position;
			count1++;			
		}
	}
	//	printf("\n\nThe Word is found %d times..",count1);
	//	printf("\n");


//	printf("The %s word   : ",Query[2].word);

	int count2 = 0;

	for(i=0;i<j;i++)
	{
		if((strcmp(Query[2].word,l1[i].word)) == 0 )//&& (strcmp(querystr[2],l1[i].word)) == 0 && (strcmp(querystr[3],l1[i].word)) == 0)
		{
	//		printf("\n %s    :    File %d    :    Position %d",l1[i].word,l1[i].fileno,l1[i].position);
			fileno2[count2] = l1[i].fileno;
			posn2[count2]=l1[i].position;
			count2++;
		}
	}
	//	printf("\n\nThe Word is found %d times..",count2);
	//	printf("\n");

			
	int count3 = 0;

	for(i=0;i<j;i++)
	{
		if((strcmp(Query[3].word,l1[i].word)) == 0 )//&& (strcmp(querystr[2],l1[i].word)) == 0 && (strcmp(querystr[3],l1[i].word)) == 0)
		{
	//		printf("\n %s    :    File %d    :    Position %d",l1[i].word,l1[i].fileno,l1[i].position);
			fileno3[count3] = l1[i].fileno;
			posn3[count3]=l1[i].position;
			count3++;			
		}
	}
	//	printf("\n\nThe Word is found %d times..",count3);
	//	printf("\n");


	int fctr40=0,fctr41=0,fctr42=0;
	int fctr30=0,fctr31=0,fctr32=0;
	int fctr20=0,fctr21=0,fctr22=0;
/*	for(i=0;i<count0;i++)
	{
		printf("\nThe positions of %s Word is %d in file %d",Query[0].word,posn0[i],fileno0[i]);
	}*/

	for(ck=0;ck<count0;ck++)
	{
		for(i=0;i<count1;i++)
		{
			for(x=0;x<count2;x++)
			{
				for(y=0;y<count3;y++)
				{
					if((fileno0[ck]==fileno1[i])&&(fileno0[ck]==fileno2[x])&&(fileno0[ck]==fileno3[y]))
					{ 
						z=fileno0[ck];
							
						if((posn1[i]<=(posn0[ck]+9))&&(posn2[x]<=(posn0[ck]+9))&&(posn3[y]<=(posn0[ck]+9))&&posn1[i]>posn0[ck]&&posn2[x]>posn0[ck]&&posn3[y]>posn0[ck])
						{
							if(z==1)
							rank4[z-1][fctr40++]=posn0[ck];
							if(z==2)
							rank4[z-1][fctr41++]=posn0[ck];
							if(z==3)
							rank4[z-1][fctr42++]=posn0[ck];
						}
						if((posn0[ck]<=(posn1[i]+9))&&(posn2[x]<=(posn1[i]+9))&&(posn3[y]<=(posn1[i]+9))&&posn0[ck]>posn1[i]&&posn2[x]>posn1[i]&&posn3[y]>posn1[i])
						{
							if(z==1)
							rank4[z-1][fctr40++]=posn1[i];
							if(z==2)
							rank4[z-1][fctr41++]=posn1[i];
							if(z==3)
							rank4[z-1][fctr42++]=posn1[i];
						}
						if((posn0[ck]<=(posn2[x]+9))&&(posn1[i]<=(posn2[x]+9))&&(posn3[y]<=(posn2[x]+9))&&posn1[i]>posn2[x]&&posn0[ck]>posn2[x]&&posn3[y]>posn2[x])
						{
							if(z==1)
							rank4[z-1][fctr40++]=posn2[x];
							if(z==2)
							rank4[z-1][fctr41++]=posn2[x];
							if(z==3)
							rank4[z-1][fctr42++]=posn2[x];

						}
						if((posn0[ck]<=(posn3[y]+9))&&(posn1[i]<=(posn3[y]+9))&&(posn2[x]<=(posn3[y]+9))&&posn1[i]>posn3[y]&&posn2[x]>posn3[y]&&posn0[ck]>posn3[y])
						{
							if(z==1)
							rank4[z-1][fctr40++]=posn3[y];
							if(z==2)
							rank4[z-1][fctr41++]=posn3[y];
							if(z==3)
							rank4[z-1][fctr42++]=posn3[y];
						}
					}
				}
			}
		}
	}

	

int temp=0,flag=0;

	for(ck=0;ck<count0;ck++)
	{
		for(i=0;i<count1;i++)
		{
			for(x=0;x<count2;x++)
			{
				if((fileno0[ck]==fileno1[i])&&(fileno0[ck]==fileno2[x]))
					{ 
						z=fileno0[ck];
							
						if((posn1[i]<=(posn0[ck]+6))&&(posn2[x]<=(posn0[ck]+6))&&posn1[i]>posn0[ck]&&posn2[x]>posn0[ck])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn0[ck];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr31++]=posn0[ck];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn0[ck];
								flag=0;
							}
						}
						
						
						if((posn0[ck]<=(posn1[i]+6))&&(posn2[x]<=(posn1[i]+6))&&posn0[ck]>posn1[i]&&posn2[x]>posn1[i])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn1[i];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr31++]=posn1[i];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn1[i];
								flag=0;
							}
						}
						
						if((posn0[ck]<=(posn2[x]+6))&&(posn1[i]<=(posn2[x]+6))&&posn0[ck]>posn2[x]&&posn1[i]>posn2[x])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn2[x];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr31++]=posn2[x];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn2[x];
								flag=0;
							}

						}
					}
				}
			}
		}

	for(ck=0;ck<count0;ck++)
	{
		for(i=0;i<count1;i++)
		{
			for(y=0;y<count3;y++)
				{
					if((fileno0[ck]==fileno1[i])&&(fileno0[ck]==fileno3[y]))
					{ 
						z=fileno0[ck];
							
						if((posn1[i]<=(posn0[ck]+6))&&(posn3[y]<=(posn0[ck]+6))&&posn1[i]>posn0[ck]&&posn3[y]>posn0[ck])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn0[ck];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr31++]=posn0[ck];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn0[ck];
								flag=0;
							}
						}
						
						if((posn0[ck]<=(posn1[i]+6))&&(posn3[y]<=(posn1[i]+6))&&posn0[ck]>posn1[i]&&posn3[y]>posn1[i])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn1[i];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}

								if(flag==0)
								rank3[z-1][fctr31++]=posn1[i];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										
									flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn1[i];
								flag=0;
							}
						}
						
						
						if((posn0[ck]<=(posn3[y]+6))&&(posn1[i]<=(posn3[y]+6))&&posn0[ck]>posn3[y]&&posn1[i]>posn3[y])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn3[y];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr31++]=posn3[y];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn3[y];
								flag=0;
							}
						}
						
					}
				}
			}
	}


for(ck=0;ck<count0;ck++)
	{
		for(x=0;x<count2;x++)
			{
				for(y=0;y<count3;y++)
				{
					if((fileno0[ck]==fileno2[x])&&(fileno0[ck]==fileno3[y]))
					{ 
						z=fileno0[ck];
							
						
						if((posn3[y]<=(posn0[ck]+6))&&(posn2[x]<=(posn0[ck]+6))&&posn3[y]>posn0[ck]&&posn2[x]>posn0[ck])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn0[ck];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr31++]=posn0[ck];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn0[ck];
								flag=0;
							}
						}
						
						if((posn0[ck]<=(posn2[x]+6))&&(posn3[y]<=(posn2[x]+6))&&posn0[ck]>posn2[x]&&posn3[y]>posn2[x])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn2[x];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr31++]=posn2[x];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn2[x];
								flag=0;
							}

						}
						
						if((posn0[ck]<=(posn3[y]+6))&&(posn2[x]<=(posn3[y]+6))&&posn0[ck]>posn3[y]&&posn2[x]>posn3[y])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn3[y];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr31++]=posn3[y];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn3[y];
								flag=0;
							}
						}
						
				}
			}
		}
	}


		for(i=0;i<count1;i++)
		{
			for(x=0;x<count2;x++)
			{
				for(y=0;y<count3;y++)
				{
					if((fileno2[x]==fileno1[i])&&(fileno3[y]==fileno2[x]))
					{ 
						z=fileno0[ck];
							
						
						
						
						if((posn3[y]<=(posn1[i]+6))&&(posn2[x]<=(posn1[i]+6))&&posn3[y]>posn1[i]&&posn2[x]>posn1[i])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn1[i];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr31++]=posn1[i];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn1[i];
								flag=0;
							}
						}
						
						
						if((posn3[y]<=(posn2[x]+6))&&(posn1[i]<=(posn2[x]+6))&&posn3[y]>posn2[x]&&posn1[i]>posn2[x])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn2[x];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr31++]=posn2[x];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn2[x];
								flag=0;
							}

						}
						
						if((posn2[x]<=(posn3[y]+6))&&(posn1[i]<=(posn3[y]+6))&&posn1[i]>posn3[y]&&posn2[x]>posn3[y])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr30++]=posn3[y];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr31++]=posn3[y];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank3[z-1][fctr32++]=posn3[y];
								flag=0;
							}
						}
					}
				}
			}
		}


	

flag=0;
fctr20=0;
fctr21=0;
fctr22=0;

	for(ck=0;ck<count0;ck++)
	{
		for(i=0;i<count1;i++)
		{
					if(fileno0[ck]==fileno1[i])
					{ 
						z=fileno0[ck];
							
						if((posn1[i]<=(posn0[ck]+3))&&posn1[i]>posn0[ck])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn0[ck];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn0[ck];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn0[ck];
								flag=0;
							}
						}
						if((posn0[ck]<=(posn1[i]+3))&&posn0[ck]>posn1[i])
						{
							z=fileno1[i];
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn1[i];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn1[i];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn1[i];
								flag=0;
							}
						}
					}
		}
	}

	for(ck=0;ck<count0;ck++)
	{
		for(x=0;x<count2;x++)
		{
					if(fileno0[ck]==fileno2[x])
					{ 
						z=fileno2[x];
							
						if((posn0[ck]<=(posn2[x]+3))&&posn0[ck]>posn2[x])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn2[x];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn2[x];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn2[x];
								flag=0;
							}

						}
						if((posn2[x]<=(posn0[ck]+3))&&posn2[x]>posn0[ck])
						{
							z=fileno0[ck];
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn0[ck];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn0[ck];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn0[ck];
								flag=0;
							}
						}
					}
		}
	}

	for(ck=0;ck<count0;ck++)
	{
		for(y=0;y<count3;y++)
		{
					if(fileno0[ck]==fileno3[y])
					{ 
						z=fileno3[y];
							
						if((posn0[ck]<=(posn3[y]+3))&&posn0[ck]>posn3[y])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn3[y];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn3[y];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn3[y];
								flag=0;
							}
						}
						if((posn3[y]<=(posn0[ck]+3))&&posn3[y]>posn0[ck])
						{
							z=fileno0[ck];
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn0[ck];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn0[ck];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn0[ck])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn0[ck])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn0[ck];
								flag=0;
							}
						}
					}
		}
	}

	for(i=0;i<count1;i++)
	{
		for(x=0;x<count2;x++)
		{
					if(fileno1[i]==fileno2[x])
					{ 
						z=fileno1[i];
							
						if((posn2[x]<=(posn1[i]+3))&&posn2[x]>posn1[i])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn1[i];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn1[i];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn1[i];
								flag=0;
							}
						}
						if((posn1[i]<=(posn2[x]+3))&&posn1[i]>posn2[x])
						{
							z=fileno2[x];
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn2[x];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn2[x];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn2[x];
								flag=0;
							}

						}
					}
		}
	}

	for(i=0;i<count1;i++)
	{
		for(y=0;y<count3;y++)
		{
					if(fileno1[i]==fileno3[y])
					{ 
						z=fileno1[i];
						if((posn3[y]<=(posn1[i]+3))&&posn3[y]>posn1[i])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn1[i];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn1[i];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn1[i])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn1[i])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn1[i];
								flag=0;
							}
						}
						if((posn1[i]<=(posn3[y]+3))&&posn1[i]>posn3[y])
						{
							z=fileno3[y];
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn3[y];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn3[y];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn3[y];
								flag=0;
							}
						}
							
						
					}
		}
	}

	for(x=0;x<count2;x++)
	{
		for(y=0;y<count3;y++)
		{
					if(fileno2[x]==fileno3[y])
					{ 
						z=fileno2[x];
						
						if((posn3[y]<=(posn2[x]+3))&&posn3[y]>posn2[x])
						{
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn2[x];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn2[x];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn2[x])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn2[x])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn2[x];
								flag=0;
							}

						}
						
						
						if((posn2[x]<=(posn3[y]+3))&&posn2[x]>posn3[y])
						{
							z=fileno3[y];
							if(z==1)
							{
								for(temp=0;temp<fctr20;temp++)
								{
									if(rank2[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr30;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr40;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr20++]=posn3[y];
								flag=0;
							}
							if(z==2)
							{
								for(temp=0;temp<fctr21;temp++)
								{
									if(rank2[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr31;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr41;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr21++]=posn3[y];
								flag=0;
							}
							if(z==3)
							{
								for(temp=0;temp<fctr22;temp++)
								{
									if(rank2[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr32;temp++)
								{
									if(rank3[z-1][temp]==posn3[y])
										flag=1;
								}
								for(temp=0;temp<fctr42;temp++)
								{
									if(rank4[z-1][temp]==posn3[y])
										flag=1;
								}
								if(flag==0)
								rank2[z-1][fctr22++]=posn3[y];
								flag=0;
							}
						}
							
						
				}
		}
	}
					
					


/*	printf("\nthe number of occurences for 4 words of file 1 is %d",fctr40);
	printf("\nthe number of occurences for 4 words of file 2 is %d",fctr41);
	printf("\nthe number of occurences for 4 words of file 3 is %d",fctr42);*/

if(qno==4)
	{

	if(fctr40>=fctr41&&fctr40>=fctr42)
	{
		if(fctr40>=fctr42)
		{
			printf("\nRank 1 is file 1\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr40;z++)
		{
			if(l1[i].position==rank4[0][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		}
		if(fctr41>=fctr42)
	{
			printf("\nRank 2 is file 2\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr41;z++)
		{
			if(l1[i].position==rank4[1][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 3\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr42;z++)
		{
			if(l1[i].position==rank4[2][z])
			{
		//		printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}

goto jump;
	}
	else
		{
		printf("\nRank 2 is file 3\n");
		for(i=0;i<j;i++)
	{
		for(z=0;z<fctr42;z++)
		{
			if(l1[i].position==rank4[2][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 2\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr41;z++)
		{
			if(l1[i].position==rank4[1][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		goto jump;
		}

	}

	


	if(fctr41>=fctr40&&fctr41>=fctr42)
	{
		if(fctr41>=fctr42)
		{
			printf("\nRank 1 is file 2\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr41;z++)
		{
			if(l1[i].position==rank4[1][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		}
		if(fctr40>=42)
		{
			printf("\nRank 2 is file 1\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr40;z++)
		{
			if(l1[i].position==rank4[0][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 3\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr42;z++)
		{
			if(l1[i].position==rank4[2][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump;
		}
		else
		{
			printf("\nRank 2 is file 3\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr42;z++)
		{
			if(l1[i].position==rank4[2][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 1\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr40;z++)
		{
			if(l1[i].position==rank4[0][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump;
		}
	}

	if(fctr42>=fctr40&&fctr42>=fctr41)
	{
		if(fctr42>=fctr41)
		{

printf("\nRank 1 is file 3\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr42;z++)
		{
			if(l1[i].position==rank4[2][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		}
		if(fctr40>=fctr41)
		{
			printf("\nRank 2 is file 1\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr40;z++)
		{
			if(l1[i].position==rank4[0][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 2\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr41;z++)
		{
			if(l1[i].position==rank4[1][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump;
		}
		else
		{
			printf("\nRank 2 is file 2\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr41;z++)
		{
			if(l1[i].position==rank4[1][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 1\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr40;z++)
		{
			if(l1[i].position==rank4[0][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump;
		}
	}



	}

/*jump:	printf("\nthe number of occurences for 3 words of file 1 is %d",fctr30);
	printf("\nthe number of occurences for 3 words of file 2 is %d",fctr31);
	printf("\nthe number of occurences for 3 words of file 3 is %d",fctr32);*/


	
jump: if(qno==3)
	{
	if(fctr30>=fctr31&&fctr30>=fctr32)
	{
		if(fctr30>=fctr32)
		{
			printf("\nRank 1 is file 1\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr30;z++)
		{
			if(l1[i].position==rank3[0][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		}
		if(fctr31>=fctr32)
	{
			printf("\nRank 2 is file 2\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr31;z++)
		{
			if(l1[i].position==rank3[1][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 3\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr32;z++)
		{
			if(l1[i].position==rank3[2][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}

goto jump1;
	}
	else
		{
		printf("\nRank 2 is file 3\n");
		for(i=0;i<j;i++)
	{
		for(z=0;z<fctr32;z++)
		{
			if(l1[i].position==rank3[2][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 2\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr31;z++)
		{
			if(l1[i].position==rank3[1][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		goto jump1;
		}

	}

	


	if(fctr31>=fctr30&&fctr31>=fctr32)
	{
		if(fctr31>=fctr32)
		{
			printf("\nRank 1 is file 2\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr31;z++)
		{
			if(l1[i].position==rank3[1][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		}
		if(fctr30>=32)
		{
			printf("\nRank 2 is file 1\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr30;z++)
		{
			if(l1[i].position==rank3[0][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 3\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr32;z++)
		{
			if(l1[i].position==rank3[2][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump1;
		}
		else
		{
			printf("\nRank 2 is file 3\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr32;z++)
		{
			if(l1[i].position==rank3[2][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 1\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr30;z++)
		{
			if(l1[i].position==rank3[0][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump1;
		}
	}

	if(fctr32>=fctr30&&fctr32>=fctr31)
	{
		if(fctr32>=fctr31)
		{
			printf("\nRank 1 is file 3\n");

	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr32;z++)
		{
			if(l1[i].position==rank3[2][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		}
		if(fctr30>=fctr31)
		{
			printf("\nRank 2 is file 1\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr30;z++)
		{
			if(l1[i].position==rank3[0][z])
			{
	//			printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 2\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr31;z++)
		{
			if(l1[i].position==rank3[1][z])
			{
	//			printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump1;
		}
		else
		{
			printf("\nRank 2 is file 2\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr31;z++)
		{
			if(l1[i].position==rank3[1][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 1\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr30;z++)
		{
			if(l1[i].position==rank3[0][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump1;
		}
	}


	


	}
				
/*	jump1: printf("\nthe number of occurences for 2 words of file 1 is %d",fctr20);
	printf("\nthe number of occurences for 2 words of file 2 is %d",fctr21);
	printf("\nthe number of occurences for 2 words of file 3 is %d",fctr22);*/

jump1:	if(qno==2)
	{
	if(fctr20>=fctr21&&fctr20>=fctr22)
	{
		if(fctr20>=fctr22)
		{
			printf("\nRank 1 is file 1\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr20;z++)
		{
			if(l1[i].position==rank2[0][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		}
		if(fctr21>=fctr22)
	{
			printf("\nRank 2 is file 2\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr21;z++)
		{
			if(l1[i].position==rank2[1][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 3\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr22;z++)
		{
			if(l1[i].position==rank2[2][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}

goto jump2;
	}
	else
		{
		printf("\nRank 2 is file 3\n");
		for(i=0;i<j;i++)
	{
		for(z=0;z<fctr22;z++)
		{
			if(l1[i].position==rank2[2][z])
			{
		//		printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
	printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 2\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr21;z++)
		{
			if(l1[i].position==rank2[1][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		goto jump2;
		}

	}

	


	if(fctr21>=fctr20&&fctr21>=fctr22)
	{
		if(fctr21>=fctr22)
		{
			printf("\nRank 1 is file 2\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr21;z++)
		{
			if(l1[i].position==rank2[1][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		}
		if(fctr20>=22)
		{
			printf("\nRank 2 is file 1\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr20;z++)
		{
			if(l1[i].position==rank2[0][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 3\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr22;z++)
		{
			if(l1[i].position==rank2[2][z])
			{
	//			printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump2;
		}
		else
		{
			printf("\nRank 2 is file 3\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr22;z++)
		{
			if(l1[i].position==rank2[2][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 1\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr20;z++)
		{
			if(l1[i].position==rank2[0][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump2;
		}
	}

	if(fctr22>=fctr20&&fctr22>=fctr21)
	{
		if(fctr22>=fctr21)
		{
			printf("\nRank 1 is file 3\n");

	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr22;z++)
		{
			if(l1[i].position==rank2[2][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
		}
		if(fctr20>=fctr21)
		{
			printf("\nRank 2 is file 1\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr20;z++)
		{
			if(l1[i].position==rank2[0][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 2\n");
	for(i=0;i<j;i++)
	{
		for(z=0;z<fctr21;z++)
		{
			if(l1[i].position==rank2[1][z])
			{
				//printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump2;
		}
		else
		{
			printf("\nRank 2 is file 2\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr21;z++)
		{
			if(l1[i].position==rank2[1][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
	printf("\nRank 3 is file 1\n");
			for(i=0;i<j;i++)
	{
		for(z=0;z<fctr20;z++)
		{
			if(l1[i].position==rank2[0][z])
			{
			//	printf("\n file : %d",l1[i].fileno);
				for(k=0;k<20;k++)
				{
					printf("%s ",l1[i+k-5].word); 
				}
				printf("....\n");
				//printf("\nfile %d : %s %s %s %s %s %s %s",l1[i].fileno,l1[i-3].word,l1[i-2].word,l1[i-1].word,l1[i].word,l1[i+1].word,l1[i+2].word,l1[i+3].word);
			}
		}
	}
			goto jump2;
		}
	}

	}
	jump2: printf("\n");

	return 0;
}






