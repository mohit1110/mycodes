/*
 * SAFEX program *
  Created by *MOHIT*
  Date:30-01-2021
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
void outline(int);
void head(int,int,char*);
void subhead(int,int,char*,int);
void delet(char username[]);

 char name[30],uname[35],pass[50],buffer[5],fnames[10000],*fsrurnme;  //create account
 char lname[30],lpass[50],lbuffer[5],*logvn=NULL,*logvp=NULL,flogunsr1[70]="+vtfs:",flogupsr1[70]="gbtt:",*flogunsr=NULL,*flogupsr=NULL;  //login    ,fser[3000]
 char userdataname[70]="+vtfs`obnf:",fcpuserdname[3000],*fsruserdname=NULL;            // user name data(name)
 char writenotesptr[1000],fcopyuserpldata[10000],*fsrnotesptr=NULL,fsrusernotes[80]="~+vobnf:",fsrusernotes2[80]=">vqmebub:";    //for user notes
 char fn[]="C:\\TC\\BIN\\LOGINREC.txt",fn2[]="C:\\TC\\BIN\\USERDATA.txt",fn3[]="C:\\TC\\BIN\\USERPLDA.txt";  //file name


 char forvun[3]={'$',173,'\0'};    //for verify username
 int i=0,j=0,lstrlen=0,pc=0,uc=0,nuc=0;//lc=0; //for wrong password counter
 int chlown,flagnotes=0;    //after login choice

 FILE *logrec=NULL;       //file pointer to write new user data
 FILE *readrec=NULL;      //file pointer to read existing user records
 FILE *userdata=NULL;     //file pointer to read user save data(name)
 FILE *userpldata=NULL;   //file pointer to write user personal data
 FILE *userpldatar=NULL;  //file pointer to read user personal data

 int r,c,ay=0,curserx,cursery;       //for outline
  char *bye="GOOD BYE";

int main()
{
  register int arrow=0;
 strcpy(flogupsr1,forvun);
 strcat(flogupsr1,"gbtt:");

 clrscr();
outline(1);
 //choice
 choice:	//choice label


gotoxy(33,8);
//printf("LOGIN\n");
subhead(33,8,"LOGIN",2);

gotoxy(33,10);
//printf("CREATE ACCOUNT");
subhead(33,11,"CREATE ACCOUNT",9);

gotoxy(33,12);
//printf("EXIT");
subhead(33,14,"EXIT",12);

//getch();
arrow=0;
i=0;
while(1)
   {

	arrow=getch();
	if(arrow==72)
	  {
	      if(i>0)
	      i--;
	  }
	if(arrow==80)
	  {
	      if(i<2)
	      i++;
	  }
	if(i==0)
	  {
		ay=8;
		gotoxy(31,12);
		  printf(" ");
		 gotoxy(31,15);
		  printf(" ");

		gotoxy(31,9);
		textcolor(2);
		  cprintf("%c",16);
	  }
	if(i==1)
	  {
		 ay=10;
		 gotoxy(31,9);
		   printf(" ");
		 gotoxy(31,15);
		   printf(" ");

		 gotoxy(31,12);
		 textcolor(9);
		   cprintf("%c",16);
	  }
	if(i==2)
	   {
	      ay=12;
	      gotoxy(31,9);
		printf(" ");
	      gotoxy(31,12);
		printf(" ");

	      gotoxy(31,15);
	      textcolor(12);
		cprintf("%c",16);
	   }
	if(arrow==13)
		break;
   }

 if(ay==8)
   {    arrow=0;
	clrscr();
	outline(0);
      //	gotoxy(35,4);
	subhead(35,5,"LOGIN",2);
	goto login;
   }
 if(ay==10)
   {  arrow=0;
      clrscr();
      outline(0);
      subhead(31,5,"CREATE ACCOUNT",9);
      goto cracc;
   }
 if(ay==12)
   {
     arrow=0;
     goto exit;

   }
 //choice end

 //create account
 cracc:                    //create account label
// clrscr();
// outline();
 subhead(31,5,"CREATE ACCOUNT",9);
if(logrec!=NULL)fclose(logrec);
 logrec=fopen(fn,"a+");             //open file
     if(logrec==NULL)        //for records not open
       {
	  clrscr();
	  outline(0);
	  gotoxy(18,21);
	  printf("Something went wrong Please try again164");
	  goto choice;
       }


textcolor(9);
cprintf("");
gotoxy(33,8);
 printf("Enter Name:");
//      printf("\n*buffer*2\n");          //buffer
  //gets(buffer);
   //   printf("*buffer clear*2\n");      //buffer

 gets(name);     //name
 nuc=0;
 username:
 textcolor(9);
 cprintf("");
 nuc++;
subhead(31,5,"CREATE ACCOUNT",9);
 gotoxy(33,10);
  printf("Enter username:");
   scanf("%s",uname);         //username

  for(i=0;i<strlen(uname);i++)
     {
	uname[i]+=11;
     }

  readrec=fopen(fn,"r");		   //open file
     if(readrec==NULL)           //for records not open
       {
	    clrscr();
	    outline(0);
	    gotoxy(15,20);
	    printf("Something went wrong Please try again199");
	    fclose(logrec);
	    goto choice;
       }

  fgets(fnames,10000,readrec);	     //copy records

  strcat(flogunsr1,uname);
  strcat(flogunsr1,forvun);

  fsrurnme=strstr(fnames,flogunsr1);            //search username
  strcpy(flogunsr1,"+vtfs:");

     if(fsrurnme!=NULL)
       {
	  clrscr();
	  outline(0);
	  gotoxy(15,20);
	  textcolor(4);
	  cprintf("Username already exists Please try another username");
	  gotoxy(33,8);
	  textcolor(9);
	  printf("Enter Name:");cprintf("%s",name);

	  if(nuc<3)
	    goto username;
	  else
	   {
	     clrscr();
	     outline(1);
	     goto choice;
	   }

       }

gotoxy(33,12);
 printf("Password:");              //password
     for(i=0;i<50;i++)
	{
	   pass[i]=getch();
	   if(pass[i]==8)
	     {
		printf("\b \b");
		pass[i]=NULL;
		if(i>0)
		  i-=2;
		if(i==0)
		  i--;
		continue;
	     }
	   else if(pass[i]==13)
		   break;
	   else
	    {
	      textcolor(9);
	      cprintf("*");
	      pass[i]+=11;
	    }
	}
  pass[i]='\0';



 userdata=fopen(fn2,"a+");  //open file user data
    if(userdata==NULL)
      {
	 clrscr();
	 outline(0);
	 gotoxy(15,20);
	 printf("Something went wrong Please try again268");
	 fclose(logrec);
	 fclose(readrec);
	 goto choice;
      }

  for(i=0;i<strlen(name);i++)
    {
       name[i]+=11;
    }

 fprintf(userdata,"+vtfs`obnf:%s>%s/]",uname,name);    //user's name  save in file
 fprintf(logrec,"+vtfs:%s%sgbtt:%s%s!\\n",uname,forvun,uname,pass);    //save username and password in file

 fclose(logrec);
 fclose(readrec);
 fclose(userdata);      //close file

 clrscr();
 outline(1);

 gotoxy(27,20);
 textcolor(14);
 cprintf("Account created Login Now");
 goto choice;
 //create account end

 //login
 login:                        //login lable
// clrscr();
 //outline();
subhead(35,5,"LOGIN",2);
if(readrec!=NULL) fclose(readrec);
 readrec=fopen(fn,"r");       //open file in read mode
    if(readrec==NULL)
      {
	 clrscr();
	 outline(0);
	 gotoxy(15,20);
	 printf("Something went wrong Please try again306");
	 goto choice;
      }

  fgets(fnames,10000,readrec);    //copy records     //fser->fnames


  usernamep:
  textcolor(2);
  cprintf("");
  subhead(35,5,"LOGIN",2);
  gotoxy(31,9);                            //username lable
   printf("Enter username:");
   scanf("%s",lname);        //read name
      //  printf("\n*buffer*3\n");            //buffer
     gets(lbuffer);
     //   printf("*clear buffer3\n");       //buffer
  for(i=0;i<strlen(lname);i++)
     {
	lname[i]+=11;
     }

  password:
  textcolor(2);
  cprintf("");
  subhead(35,5,"LOGIN",2);                      //password lable
   gotoxy(31,11);
   printf("Enter password:");
      for(i=0;i<50;i++)
	 {
	    lpass[i]=getch();
	    if(lpass[i]==8)
	      {
		 printf("\b \b");
		 lpass[i]=NULL;
		 if(i>0)
		  i-=2;
		 if(i==0)
		  i--;
		 continue;
	      }

	    else if(lpass[i]==13)
		     break;
	    else
	     {
	       textcolor(2);
	       cprintf("*");
	       lpass[i]+=11;
	     }
	 }
     lpass[i]='\0';

    flogunsr=strcat(flogunsr1,lname);    //copy username
    flogunsr=strcat(flogunsr,forvun);
 // printf("\nok");
  // printf("\n%s",flogunsr);

  logvn=strstr(fnames,flogunsr);        //verify userename           //fser->fnames
  strcpy(flogunsr1,"+vtfs:");
     if(logvn!=NULL)
       { //1
	   flogupsr=strcat(flogupsr1,lname);
	   flogupsr=strcat(flogupsr1,lpass);    //copy password
	   flogupsr=strcat(flogupsr,"!\\n");

	   logvp=strstr(fnames,flogupsr);    //verify password    //fser->fnames
	   strcpy(flogupsr1,forvun);
	   strcat(flogupsr1,"gbtt:");
	      if(logvp!=NULL)
		{//2
		   clrscr();
		   outline(1);
		   gotoxy(32,20);
		   textcolor(10);
		   cprintf("LOGIN SUCCESSFUL");

		   if(userdata!=NULL)fclose(userdata);
		   userdata=fopen(fn2,"r");    //open file in read mode for userdata(name)
		     if(userdata==NULL)
		       { //3
			  clrscr();
			  outline(1);
			  gotoxy(25,20);
			  printf("Users data not found388");
			   goto choice;
		       }  //3
		     else
		       {   //4
			     fgets(fcpuserdname,3000,userdata);       //copy user data

			     strcat(userdataname,lname);
			     strcat(userdataname,">");
				//  printf("%s\n",userdataname);

			     fsruserdname=strstr(fcpuserdname,userdataname);     //search user data in file

			     strcpy(userdataname,"+vtfs`obnf:");
				 if(fsruserdname==NULL)
				   { //5
					clrscr();
					outline(1);
					gotoxy(25,20);

					printf("User data not found408");
					 goto choice;
				   }  //5
				 else
				   {//6
					fsruserdname=strstr(fsruserdname,lname);
					       //	printf("%s\n",fsruserdname);
					lstrlen=strlen(lname);
					lstrlen++;

					fsruserdname+=lstrlen;
					gotoxy(3,3);
					textcolor(12);
					cprintf("Hi");
					gotoxy(4,4);
					textcolor(13);
						for(i=0;((fsruserdname[i]=='/')&&(fsruserdname[i+1]==']'))==0;i++)
						    { //7
							  cprintf("%c",fsruserdname[i]-11);
						    }//7
				       //	printf("");
				       //	gotoxy(31,5);
					//printf("Your Notes",15,15);       //print user notes
					goto userlogwrnt;
					usernotes:            //for user notes
					clrscr();
					outline(0);

					subhead(33,4,"Your Notes",6);
					if(userpldatar!=NULL)fclose(userpldatar);
					userpldatar=fopen(fn3,"r");      //open file for user notes data
					   if(userpldatar==NULL)
					     {  //8
						 gotoxy(15,20);
						 printf("User data not found447");
					     } //8
					   else
					     {  //9
						   // fcopyuserpldata=(char*)calloc(5000,sizeof(char));
						    /* if(0)//fcopyuserpldata==NULL)
						       { //10
							     clrscr();
							     outline(1);
							     gotoxy(10,20);
							     printf("Memory not available Please try again457");
							     fclose(userpldatar);
							     goto choice;
						       }  //10     */
							 // else
						       //{ //11
							     fgets(fcopyuserpldata,10000,userpldatar);    //copy user personal notes

							     strcat(fsrusernotes,lname);
							     strcat(fsrusernotes,"?~>");

							     fsrnotesptr=strstr(fcopyuserpldata,fsrusernotes);
							     strcpy(fsrusernotes,"~+vobnf:");
							     if(fsrnotesptr==NULL)
							       {//12
								  gotoxy(6,7);
								   printf("You don't have any notes");
								 //  free(fcopyuserpldata);
								   flagnotes=0;
							       }//12
							     else
							       { //13
								    i=1;
								    curserx=4;
								    cursery=6;

								    searchingusernotes1:   // searchingusernotes1  lable
								     if(i>1)
								       { //26
									     strcat(fsrusernotes,lname);
									     strcat(fsrusernotes,"?~>");

									     fsrnotesptr=strstr(fsrnotesptr,fsrusernotes);

									      strcpy(fsrusernotes,"~+vobnf:");
									      if(fsrnotesptr==NULL)
										{//27
										   // free(fcopyuserpldata);
										    goto exitshownotes;
										} //27
								       }//26
								     strcat(fsrusernotes2,lname);
								     strcat(fsrusernotes2,"|");

								     fsrnotesptr=strstr(fsrnotesptr,fsrusernotes2);

								     strcpy(fsrusernotes2,">vqmebub:");

								     if(fsrnotesptr==NULL)
								       { //14
									    if(i==1)
									      {
										  gotoxy(20,20);
										  printf("User data not found504");
										 // free(fcopyuserpldata);
									       }
									    else
									      {
										  clrscr();
										  outline(1);
										 // free(fcopyuserpldata);
										  goto userlogwrnt;
									      }
								       }  //14
								     else
								       {  //15
									    i++;
									    searchingusernotes2:   //searchingusernotes2 lable

									    fsrnotesptr=strstr(fsrnotesptr,lname);    //search user notes
									    fsrnotesptr+=lstrlen;

									    gotoxy(4,cursery+1);
									    printf("%c ",175);
									       for(;((fsrnotesptr[0]=='!')&&(fsrnotesptr[1]=='`')&&(fsrnotesptr[2]==']'))==0;fsrnotesptr++)        //print user notes
										  {//16
											if(fsrnotesptr[0]==103&&fsrnotesptr[1]==121)
											  {//17
											      curserx=wherex();
											      cursery=wherey();
											      gotoxy(6,cursery+1);
											      // printf(" ");
											       fsrnotesptr++;
												continue;
											  } //17

											printf("%c",fsrnotesptr[0]-11);
										  }//16

										  curserx=wherex();
										  cursery=wherey();
									   // printf("\n");
									    flagnotes=1;
									    goto searchingusernotes1;


								       }//15
							       }//13
						     //  free(fcopyuserpldata);
						      // }//11
					   //   free(fcopyuserpldata);

					     }//9

					exitshownotes:
					fclose(userpldatar);
					gotoxy(22,20);
					printf("Press                          to Exit");
					subhead(27,19,"         SPACE        ",15);
					while(1)
					     {
						 arrow=getch();
						 if(arrow==32)
						   break;

					     }

					clrscr();
					outline(1);
					userlogwrnt:    //user logout choice lable

					chlown=0;
					j=0;
					gotoxy(3,3);
					textcolor(11);
					cprintf("Hi");
					gotoxy(4,4);
					textcolor(13);
						for(i=0;((fsruserdname[i]=='/')&&(fsruserdname[i+1]==']'))==0;i++)
						    { //7
							  cprintf("%c",fsruserdname[i]-11);
						    }//7

					/*
					gotoxy(3,17);
					printf("1 for Write Notes");
					gotoxy(3,18);
					printf("2 for LOGOUT");        //for user logout or write notes
					 gotoxy(3,19);
					 scanf("%d",&chlown);   */
					 subhead(30,8,"SHOW NOTES",9);
					 subhead(30,11,"WRITE NOTES",5);
					 subhead(30,14,"DELETE NOTES",14);
					 subhead(30,17,"LOGOUT",6);
					 while(1)
						{

							arrow=getch();
							if(arrow==72)
							  {
								if(j>0)
								j--;
							  }
							if(arrow==80)
							  {
								if(j<=2)
								j++;
							  }
							if(j==0)
							  {
								chlown=8;
								gotoxy(28,12);
								printf(" ");
								gotoxy(28,15);
								printf(" ");
								gotoxy(28,18);
								printf(" ");

								gotoxy(28,9);
								textcolor(9);
								cprintf("%c",16);
							  }
							if(j==1)
							  {
								chlown=11;
								gotoxy(28,9);
								printf(" ");
								gotoxy(28,15);
								printf(" ");
								gotoxy(28,18);
								printf(" ");

								gotoxy(28,12);
								textcolor(5);
								cprintf("%c",16);
							  }
							if(j==2)
							  {
								chlown=14;
								gotoxy(28,9);
								printf(" ");
								gotoxy(28,12);
								printf(" ");
								gotoxy(28,18);
								printf(" ");


								gotoxy(28,15);
								textcolor(14);
								cprintf("%c",16);
							  }
							if(j==3)
							  {
								chlown=17;
								gotoxy(28,9);
								printf(" ");
								gotoxy(28,12);
								printf(" ");
								gotoxy(28,15);
								printf(" ");

								gotoxy(28,18);
								textcolor(6);
								cprintf("%c",16);
							  }

							if(arrow==13)
								break;

						}


					if(chlown==11)        //for write notes
					  {//18
					      if(userpldata!=NULL)fclose(userpldata);
					      userpldata=fopen(fn3,"a+");     //open file in write mode
					      if(userpldata==NULL)
						{//19
						      clrscr();
						      outline(1);
						      gotoxy(10,20);
						      printf("Something went wrong Please try again680");
						      goto choice;
						} //19
					      else
						{ //20
						      //writenotesptr=(char*)calloc(1000,sizeof(char));          //memory for write notes
						      /*if(writenotesptr==NULL)
							{//21
							       gotoxy(5,20);
							       printf("Memory not available Please try again696");
							       fclose(userpldata);
							       goto userlogwrnt;
							} //21  */
						     // else                     //write notes
						       //	{ //22
								  // printf("\n*buffer290\n");   //290
							      // gets(buffer);
								 // printf("clear buffer290\n");

							       clrscr();
							       outline(0);
							       subhead(35,4,"NOTES",1);
							       gotoxy(26,20);
							       printf("Press             to Save");
							       subhead(31,19,"  ENTER  ",15);

							       gotoxy(3,7);
							       gets(writenotesptr);

							       for(i=0;i<strlen(writenotesptr);i++)
								  {
								      writenotesptr[i]+=11;
								  }

							       fprintf(userpldata,"~+vobnf:%s?~>vqmebub:%s|%s!`]",lname,lname,writenotesptr);     //save user personal data in file


							       fclose(userpldata);
							      // free(writenotesptr);
							       clrscr();
							       outline(1);
							       gotoxy(33,20);
							       textcolor(10);
							       cprintf("NOTE SAVED");
							       goto userlogwrnt;
						       //	} //22

						}//20
					  }//18
					  if(chlown==8)
					    {goto usernotes;}
					if(chlown==17)
					  { //23
					      clrscr();
					      outline(1);

					      gotoxy(32,20);
					      textcolor(10);
					      cprintf("LOGOUT SUCCESSFULLY");
					      goto choice;
					  }//23
					if(chlown==14)
					  {

					    if(userpldatar!=NULL)fclose(userpldatar);
					    userpldatar=fopen(fn3,"r");      //open file for user notes data

					   if(userpldatar==NULL)
					     {  //8,

					       printf("file not open742");

					       flagnotes=0;

					     } //8,
					   else
					     {  //9,


							     fgets(fcopyuserpldata,10000,userpldatar);    //copy user personal notes

							     strcat(fsrusernotes,lname);
							     strcat(fsrusernotes,"?~>");

							     fsrnotesptr=strstr(fcopyuserpldata,fsrusernotes);
							     strcpy(fsrusernotes,"~+vobnf:");
							     if(fsrnotesptr==NULL)
							       {//12,
								  // free(fcopyuserpldata);
								   flagnotes=0;
							       }//12,
							     else
							       { //13,
								  // free(fcopyuserpldata);
								   flagnotes=1;
							       }//13,
							     fclose(userpldatar);

					     }//9,
					   if(flagnotes==1)
					     {
						delet(lname);
						//fclose(userpldatar);
					       //	free(fcopyuserpldata);
						goto userlogwrnt;
					     }

					   if(flagnotes==0)
					      {

						//fclose(userpldatar);
					       //	free(fcopyuserpldata);
						goto userlogwrnt;
					      }
					  }

				   //fclose(userpldatar);
				   }//6

		       }//4


		}//2
	      else
		{ //24

		   clrscr();
		   outline(0);

		   gotoxy(31,9);
		   textcolor(2);
		   printf("Enter username:");
		   for(i=0;i<strlen(lname);i++)
		      {
			   cprintf("%c",lname[i]-11);
		      }
		    gotoxy(26,20);
		    textcolor(4);
		    cprintf("Incorrect Password Try again");
		    if(pc==3)
		      {
			clrscr();
			outline(1);
			goto choice;

		      }
		    pc++;
		    goto password;
		}//24
       }//1
     else
       { //25
	    clrscr();
	    outline(0);

	    gotoxy(26,20);
	    textcolor(4);
	    cprintf("Incorrect username Try again");
	    if(uc==3)
	      {
		clrscr();
		outline(1);
		goto choice;
	      }
	    uc++;
	    goto login;
       } //25
//login end

end:
 fclose(readrec);    //close file
 fclose(userdata);
 fclose(userpldata);
 getch();
exit:
clrscr();
outline(0);

gotoxy(35,11);
textcolor(10);
while(bye[0]!=NULL)
{
   delay(180);
   cprintf("%c",bye[0]);
   bye++;

}
delay(200);
return 0;
}

void outline(int a)
{
  int r,c;

 // textcolor(6);
   printf("\n");
  for(r=1;r<=21;r++)
       {
	    for(c=1;c<=79;c++)
	       {
		  if(r==1)
		    {
			if(c==1)
			  cprintf("%c",201);
			if(c==78)
			  cprintf("%c",187);
			if(c<78)
			  cprintf("%c",205);
		    }

		  if(r>1&&r<21)
		    {
			if(c==1)
			  cprintf("%c",186);
			if(c==79)
			  cprintf("%c",186);
		    }
		  if(r==21)
		    {
			if(c==1)
			  cprintf("%c",200);
			if(c==78)
			  cprintf("%c",188);
			if(c<78)
			cprintf("%c",205);
		    }

		  if(r>1&&r<21&&c>1&&c<79)
		     cprintf(" ");
	       }
	 printf("\n");

       }
head(35,1,"SAFEX");
if(a==1)
  {
	gotoxy(25,21);
	textcolor(8);
	cprintf("Use UP/DOWN Arrow key to select");
  }

}

void head(int x,int y,char *str)
{
   int r,c,len;

   len=strlen(str);
   len+=4;
   gotoxy(x,y);      // printf("%c%c%c\n%c%c%c",201,205,187,200,205,188);
 //  textcolor(6);
   for(r=1;r<=3;r++)
      {
	   if(r==2)
	   gotoxy(x,y+1);
	   if(r==3)
	     gotoxy(x,y+2);
	    for(c=1;c<=len;c++)
	       {
		     if(r==1)
		       {
			    if(c==1)
			       cprintf("%c",201);
			    if(c>1&&c<len)
			       cprintf("%c",205);
			    if(c==len)
			       cprintf("%c",187);
		       }
		     if(r==2)
		       {
			    if(c==1)
			       cprintf("%c",186);
			    if(c==len)
			       cprintf("%c",186);
			    else if(c>1)
			      cprintf(" ");

		       }
		     if(r==3)
		       {
			    if(c==1)
			       cprintf("%c",200);
			    if(c>1&&c<len)
			      cprintf("%c",205);
			    if(c==len)
			      cprintf("%c",188);

		       }
	       }


      }
      textcolor(11);
gotoxy(x+2,y+1);
cprintf("%s",str);

}
void subhead(int x,int y,char*str,int cl)
{
   int r,c,len;

   len=strlen(str);
   len+=4;
   gotoxy(x,y);          // printf("%c%c%c\n%c%c%c",169,196,170,192,196,217);    179
   for(r=1;r<=3;r++)
      {
	   if(r==2)
	   gotoxy(x,y+1);
	   if(r==3)
	     gotoxy(x,y+2);
	    for(c=1;c<=len;c++)
	       {
		     if(r==1)
		       {
			    if(c==1)
			       printf("%c",218);
			    if(c>1&&c<len)
			       printf("%c",196);
			    if(c==len)
			       printf("%c",191);
		       }
		     if(r==2)
		       {
			    if(c==1)
			       printf("%c",179);
			    if(c==len)
			       printf("%c",179);
			    else if(c>1)
			      printf(" ");

		       }
		     if(r==3)
		       {
			    if(c==1)
			       printf("%c",192);
			    if(c>1&&c<len)
			      printf("%c",196);
			    if(c==len)
			      printf("%c",217);

		       }
	       }


      }
      textcolor(cl);
gotoxy(x+2,y+1);
cprintf("%s",str);

}
void delet(char username[])       //delete function
{
 FILE *delptr=NULL,*rewriteptr=NULL;
 char fn4[]="C:\\TC\\BIN\\USERPLDA.txt";
 char *fsrurdata=NULL,*record=NULL,*temp=NULL;
 char urname[30],*flagptr=NULL;
 int i=0,j=0,k=0,m=0,ncount=0,dataindex[25]={0},len=0,deleteflag=0;
 int arrowd=0,cl=0,clr=0;
 int cmpflag=1,cury=0;


 record=(char*)calloc(4000,sizeof(char));
 if(record==NULL){printf("Memory not available");getch();}
 temp=(char*)calloc(2500,sizeof(char));
 if(temp==NULL){printf("Memory not available");getch();}

 delptr=fopen(fn4,"r+");
 if(delptr==NULL){printf("File not open1040");getch();}

// fsrurdata=(char*)calloc(5000,sizeof(char));
 //if(fsrurdata==NULL){printf("Memory not available1043");getch();}
 fgets(fnames,10000,delptr);      //fsrurdata-->fnames
 fsrurdata=fnames;
  fsrurdata=strstr(fsrurdata,"~+vobnf:");

 if(fsrurdata==NULL)
   {
	gotoxy(32,20);
	printf("Data not found1050");
	//getch();
   }
 else
   {  clrscr();
      outline(0);
      do
      {
	 fsrurdata=strstr(fsrurdata,"~+vobnf:");
	strcpy(urname,username);
	strcat(urname,"?~>");

	 fsrurdata+=8;
	 len=strlen(username);
	 cmpflag=strncmp(fsrurdata,urname,len+3);
	 fsrurdata-=8;

	flagptr=strstr(fsrurdata,urname);
       //	printf("FLPTR==%s\n\n",flagptr);
      //	printf("FD==%s\n\n",fsrurdata);

	if(cmpflag!=0)
	  {
	    record[i]='~';
	    i++;
	    record[i]='+';
	    i++;
	    record[i]='v';
	    i++;
	    fsrurdata+=3;
	    for(;((fsrurdata[-3]=='!')&&(fsrurdata[-2]=='`')&&(fsrurdata[-1]==']'))==0||i==4000;fsrurdata++,i++)
	       {
			record[i]=fsrurdata[0];
	       }
	  }
	if(cmpflag==0)
	  {
	    temp[j]='~';
	    j++;
	    temp[j]='+';
	    j++;
	    temp[j]='v';
	    j++;
	    fsrurdata+=3;
	    for(;((fsrurdata[-3]=='!')&&(fsrurdata[-2]=='`')&&(fsrurdata[-1]==']'))==0||j==2500;fsrurdata++,j++)
	       {
			temp[j]=fsrurdata[0];
	       }
	  }
	flagptr=strstr(fsrurdata,"~+vobnf:");

       }while(flagptr!=NULL);
   }

  ncount=0;
 if(temp[0]!=NULL)
   {
	//printf("OK1094");
	for(i=0;i<2500;i++)
	   {
		if(temp[i]=='~'&&temp[i+1]=='+'&&temp[i+2]=='v')
		  {
			dataindex[ncount++]=i;
		  }
	   }

	arrowd=144;
	clrscr();
	outline(1);
	//subhead(33,5,"DELETE NOTES",5);


	k=0;
	while(1)
	  {
		if(arrowd!=144)
		arrowd=getch();
		else
		 {
			arrowd=72;
			 subhead(33,4,"Your Notes",6);
		     gotoxy(28,16);
		      printf("Press             to Delete");
		      subhead(33,15,"  ENTER  ",9);
		     gotoxy(22,19);
		      printf("Press                          to Exit");
		      subhead(27,18,"         SPACE        ",12);

		     gotoxy(4,8);
		      printf("%c ",175);

		 }

		if(arrowd==72)
		  {
			if(k>0)
			k--;
		  }
		if(arrowd==80)
		  {
			if(k<ncount-1)
			k++;
		  }

		if(k>=0&&k<ncount)
		  {

		   // clrscr();
		   // outline(1);
		   for(cl=1;cl<=4;cl++)
		      {
				for(clr=6;clr<78;clr++)
				   {
					if(cl==1&&clr==6)
					{
						gotoxy(5,8);
					}
					if(cl==2&&clr==6)
					{
						gotoxy(5,9);
					}
					if(cl==3&&clr==6)
					{
						gotoxy(5,10);
					}
					if(cl==4&&clr==6)
					{
						gotoxy(5,11);
					}

					printf(" ");
				   }
		      }

		    /* subhead(33,4,"Your Notes",6);
		     gotoxy(28,16);
		      printf("Press             to Delete");
		      subhead(33,15,"  ENTER  ",9);
		     gotoxy(22,19);
		      printf("Press                          to Exit");
		      subhead(27,18,"         SPACE        ",12);

		     gotoxy(4,8);
		      printf("%c ",175);   */

		     gotoxy(6,8);
		     m=dataindex[k];
		     len=strlen(username);
		     len+=len;
		     len+=20;
		     for(i=m+len;(temp[i]=='!'&&temp[i+1]=='`'&&temp[i+2]==']')==0||i==2500;i++)
			{
				if(temp[i]!=NULL)
				  {
					if((temp[i]-11)=='\\'&&(temp[i+1]-11)=='n')
					  {
						cury=wherey();
						gotoxy(6,cury+1);
						i++;
						continue;
					  }
					printf("%c",temp[i]-11);
				  }
			}
		  }

		if(arrowd==13)
		  {
			deleteflag=1;
			break;
		  }
		if(arrowd==32)
		  {
		    deleteflag=0;
		    break;
		  }
	  }

   }

 if(deleteflag==1&&ncount>0)
   {
      rewriteptr=fopen(fn4,"w");
      for(j=0;j<4000;j++)
	 {      if(record[j]!=NULL)
		fputc(record[j],rewriteptr);
	 }
      fclose(rewriteptr);
      rewriteptr=fopen(fn4,"a+");
      for(i=0;i<ncount;i++)
	 {
		if(i==k)
		  {
			continue;
		  }
		j=dataindex[i];
		for(;(temp[j]=='!'&&temp[j+1]=='`'&&temp[j+2]==']')==0||j==2500;j++)
		   {
		       fputc(temp[j],rewriteptr);
		   }
		fputc(temp[j],rewriteptr);
		fputc(temp[j+1],rewriteptr);
		fputc(temp[j+2],rewriteptr);

	 }
       clrscr();
       outline(1);
       gotoxy(30,20);
       textcolor(12);
       cprintf("NOTE DELETED");

   }
 if(deleteflag==0)
   {
	 clrscr();
	 outline(1);
   }

 fclose(rewriteptr);
 free(record);
 free(temp);
 free(fsrurdata);

}
