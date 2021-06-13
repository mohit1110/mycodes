/*
  TIC TAC TOE GAME
  created by * MOHIT *
  Date:5-12-2020

*/
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
void outline(int);
void head(int,int,char*,int);
void subhead(int,int,char*,int);
void AI();
int ns,tu=0,pnt=1,modechoice,playchoice,i,j;
 char cs;
 char ox[9];
 char pn1[25],pn2[25],buffer[5];
 char pn1s=NULL,pn2s=NULL;
int main()
{

 register int arrow=0;
 clrscr();
 textcolor(2);
 outline(0);
 gotoxy(25,8);
 printf("Enter player 1 name: ");
 gets(pn1);

 psymbol:
 gotoxy(25,10);
 printf("Player 1 symbol [ X , O ]: ");
   scanf(" %c",&pn1s);
   if(pn1s!='X'&&pn1s!='O')
     {
	gotoxy(30,20);
	printf("Enter valid symbol.");
	gotoxy(52,10);
	printf("    ");
	goto psymbol;
     }

   if(pn1s=='X')
     {pn2s='O';}
   else
     {pn2s='X';}

	clrscr();
	outline(1);

	subhead(30,7,"Play with other Player",11);
	subhead(30,10,"Play with Computer",14);
	subhead(30,13,"Exit",12);


	j=0;
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
			if(j<2)
			j++;
		}
		if(j==0)
		{
			modechoice=1;
			gotoxy(28,14);
			printf(" ");
			gotoxy(28,11);
			printf(" ");

			gotoxy(28,8);
			textcolor(11);
			cprintf("%c",16);
		}
		if(j==1)
		{
			modechoice=2;
			gotoxy(28,8);
			printf(" ");
			gotoxy(28,14);
			printf(" ");

			gotoxy(28,11);
			textcolor(14);
			cprintf("%c",16);
		}
		if(j==2)
		{
			modechoice=3;
			gotoxy(28,8);
			printf(" ");
			gotoxy(28,11);
			printf(" ");

			gotoxy(28,14);
			textcolor(12);
			cprintf("%c",16);
		}
		if(arrow==13)
		  break;
	}

 if(modechoice==1)
   {
	clrscr();
	outline(0);
	gotoxy(25,8);
	printf("Enter player 2 name: ");
	gets(buffer);
	gets(pn2);
   }
 else if(modechoice==2)
   {
	strcpy(pn2,"Computer");
   }
 else
 goto exit;

 srand(time(NULL));
 pnt=rand()%365;
 printf("%d",pnt);

 rev:
 if(tu==0)
   {
	clrscr();
	outline(0);
   }

 if(tu==9){goto draw;}

gotoxy(34,15);
 printf(" 1 %c 2 %c 3",179,179);
gotoxy(34,16);
 printf("____________");
gotoxy(34,17);
 printf(" 4 %c 5 %c 6",179,179);
gotoxy(34,18);
 printf("____________");
gotoxy(34,19);
 printf(" 7 %c 8 %c 9",179,179);

 if(pnt%2==0)
 {
    gotoxy(27,13);
    printf("Player 1 %s's turn",pn1);
    cs=pn1s;
 }
 if(pnt%2!=0)
 {
   if(modechoice==1)
     {
	gotoxy(27,13);
	printf("Player 2 %s's turn",pn2);
     }
   cs=pn2s;
 }

 readblockno:
 if((modechoice==2)&&(pnt%2!=0))
 {
    gotoxy(27,21);
     printf("Computer Thinking its turn. . .");
    srand(time(NULL));
   if(tu<8)
    ns=rand()%9+1;
   if(ox[ns-1]!=NULL&&tu<8)
    goto readblockno;

   if(tu==8)
     {
	if(ox[0]==NULL)
		{ns=1;}
	if(ox[1]==NULL)
		{ns=2;}
	if(ox[2]==NULL)
		{ns=3;}
	if(ox[3]==NULL)
		{ns=4;}
	if(ox[4]==NULL)
		{ns=5;}
	if(ox[5]==NULL)
		{ns=6;}
	if(ox[6]==NULL)
		{ns=7;}
	if(ox[7]==NULL)
		{ns=8;}
	if(ox[8]==NULL)
		{ns=9;}

     }
   if(tu<8)
      AI();
 }

 if((modechoice==2&&pnt%2==0)||modechoice==1)
 {
	gotoxy(51,14);
	 printf("    ");
	gotoxy(27,14);
	 printf("Enter your block number: ");

	scanf("%d",&ns);
 }

  if((ns>1&&ns>9)||(ns<1&&ns<9))
  {
	if((modechoice==2&&pnt%2==0)||modechoice==1)
	{
		gotoxy(27,21);
		 printf("Enter block number 1 to 9 only.");
		gotoxy(51,14);
		 printf("     ");
		goto readblockno;
	}
  }

 if(ns==1)
  {
    if(ox[0]==pn1s||ox[0]==pn2s){  gotoxy(28,21);printf("Oops! this block is filled");goto rev;}

    clrscr();
    textcolor(14);
    outline(0);

    ox[0]=cs;
    gotoxy(34,5);
     printf(" %c %c %c %c %c",ox[0],179,ox[1],179,ox[2]);
    gotoxy(34,6);
     printf("____________");
    gotoxy(34,7);
      printf(" %c %c %c %c %c",ox[3],179,ox[4],179,ox[5]);
    gotoxy(34,8);
      printf("____________");
    gotoxy(34,9);
      printf(" %c %c %c %c %c",ox[6],179,ox[7],179,ox[8]);

    tu++;
    pnt++;
      if
	(
		(ox[0]==ox[4]&&ox[0]==ox[8])||
		(ox[0]==ox[1]&&ox[0]==ox[2])||
		(ox[0]==ox[3]&&ox[0]==ox[6])

	){ if(ox[0]==pn1s)
			{
			  gotoxy(28,11);
			   printf("Player 1 %s wins",pn1);
			  if(modechoice==1)
			    {
				gotoxy(28,12);
				 printf("Try Hard %s",pn2);
			    }
			}
	   if(ox[0]==pn2s)
			{
			   gotoxy(28,11);
			    printf("Player 2 %s wins",pn2);
			   gotoxy(28,12);
			    printf("Try Hard %s",pn1);
			}
	    goto end;
	 }
    goto rev;
  }
 if(ns==2)
  {
    if(ox[1]==pn1s||ox[1]==pn2s){ gotoxy(28,21); printf("Oops! this block is filled");goto rev;}

    clrscr();
    textcolor(13);
    outline(0);

    ox[1]=cs;
     gotoxy(34,5);
     printf(" %c %c %c %c %c",ox[0],179,ox[1],179,ox[2]);
    gotoxy(34,6);
     printf("____________");
    gotoxy(34,7);
      printf(" %c %c %c %c %c",ox[3],179,ox[4],179,ox[5]);
    gotoxy(34,8);
      printf("____________");
    gotoxy(34,9);
      printf(" %c %c %c %c %c",ox[6],179,ox[7],179,ox[8]);
    tu++;
    pnt++;
     if
  (
     (ox[1]==ox[0]&&ox[1]==ox[2])||
     (ox[1]==ox[4]&&ox[1]==ox[7])


  ) { if(ox[1]==pn1s)
			{
			   gotoxy(28,11);
			   printf("Player 1 %s wins",pn1);
			  if(modechoice==1)
			    { gotoxy(28,12);
			       printf("Try Hard %s",pn2);
			    }
			}
	   if(ox[1]==pn2s)
			{
			  gotoxy(28,11);
			    printf("Player 2 %s wins",pn2);
			   gotoxy(28,12);
			    printf("Try Hard %s",pn1);
			}
	    goto end;
	 }
    goto rev;
  }
  if(ns==3)
  {
    if(ox[2]==pn1s||ox[2]==pn2s){ gotoxy(28,21); printf("Oops! this block is filled");goto rev;}

    clrscr();
    textcolor(12);
    outline(0);

    ox[2]=cs;
     gotoxy(34,5);
     printf(" %c %c %c %c %c",ox[0],179,ox[1],179,ox[2]);
    gotoxy(34,6);
     printf("____________");
    gotoxy(34,7);
      printf(" %c %c %c %c %c",ox[3],179,ox[4],179,ox[5]);
    gotoxy(34,8);
      printf("____________");
    gotoxy(34,9);
      printf(" %c %c %c %c %c",ox[6],179,ox[7],179,ox[8]);
    tu++;
    pnt++;
     if
  (
     (ox[2]==ox[1]&&ox[2]==ox[0])||
     (ox[2]==ox[4]&&ox[2]==ox[6])||
     (ox[2]==ox[5]&&ox[2]==ox[8])

  ) { if(ox[2]==pn1s)
			{
			    gotoxy(28,11);
			   printf("Player 1 %s wins",pn1);
			  if(modechoice==1)
			    { gotoxy(28,12);
			       printf("Try Hard %s",pn2);
			    }
			}
	   if(ox[2]==pn2s)
			{
			  gotoxy(28,11);
			    printf("Player 2 %s wins",pn2);
			   gotoxy(28,12);
			    printf("Try Hard %s",pn1);
			}
	    goto end;
	 }
    goto rev;
  }

  if(ns==4)
  {
    if(ox[3]==pn1s||ox[3]==pn2s){ gotoxy(28,21); printf("Oops! this block is filled");goto rev;}

    clrscr();
    textcolor(11);
    outline(0);

    ox[3]=cs;
     gotoxy(34,5);
     printf(" %c %c %c %c %c",ox[0],179,ox[1],179,ox[2]);
    gotoxy(34,6);
     printf("____________");
    gotoxy(34,7);
      printf(" %c %c %c %c %c",ox[3],179,ox[4],179,ox[5]);
    gotoxy(34,8);
      printf("____________");
    gotoxy(34,9);
      printf(" %c %c %c %c %c",ox[6],179,ox[7],179,ox[8]);
    tu++;
    pnt++;
    if
  (
     (ox[3]==ox[0]&&ox[3]==ox[6])||
     (ox[3]==ox[4]&&ox[3]==ox[5])


  ) { if(ox[3]==pn1s)
			{
			    gotoxy(28,11);
			   printf("Player 1 %s wins",pn1);
			  if(modechoice==1)
			    { gotoxy(28,12);
			       printf("Try Hard %s",pn2);
			    }
			}
	   if(ox[3]==pn2s)
			{
			  gotoxy(28,11);
			    printf("Player 2 %s wins",pn2);
			   gotoxy(28,12);
			    printf("Try Hard %s",pn1);
			}
	    goto end;
	 }
    goto rev;
  }
  if(ns==5)
  {
    if(ox[4]==pn1s||ox[4]==pn2s){ gotoxy(28,21); printf("Oops! this block is filled");goto rev;}

    clrscr();
    textcolor(10);
    outline(0);

    ox[4]=cs;
     gotoxy(34,5);
     printf(" %c %c %c %c %c",ox[0],179,ox[1],179,ox[2]);
    gotoxy(34,6);
     printf("____________");
    gotoxy(34,7);
      printf(" %c %c %c %c %c",ox[3],179,ox[4],179,ox[5]);
    gotoxy(34,8);
      printf("____________");
    gotoxy(34,9);
      printf(" %c %c %c %c %c",ox[6],179,ox[7],179,ox[8]);
    tu++;
    pnt++;
    if
  (
	(ox[4]==ox[1]&&ox[4]==ox[7])||
	(ox[4]==ox[3]&&ox[4]==ox[5])||
	(ox[4]==ox[2]&&ox[4]==ox[6])||
	(ox[4]==ox[0]&&ox[4]==ox[8])


  )  { if(ox[4]==pn1s)
			{
			    gotoxy(28,11);
			   printf("Player 1 %s wins",pn1);
			  if(modechoice==1)
			    { gotoxy(28,12);
			       printf("Try Hard %s",pn2);
			    }
			}
	   if(ox[4]==pn2s)
			{
			  gotoxy(28,11);
			    printf("Player 2 %s wins",pn2);
			   gotoxy(28,12);
			    printf("Try Hard %s",pn1);
			}
	    goto end;
	 }
    goto rev;
  }
  if(ns==6)
  {
    if(ox[5]==pn1s||ox[5]==pn2s){ gotoxy(28,21); printf("Oops! this block is filled");goto rev;}

    clrscr();
    textcolor(9);
    outline(0);

    ox[5]=cs;
     gotoxy(34,5);
     printf(" %c %c %c %c %c",ox[0],179,ox[1],179,ox[2]);
    gotoxy(34,6);
     printf("____________");
    gotoxy(34,7);
      printf(" %c %c %c %c %c",ox[3],179,ox[4],179,ox[5]);
    gotoxy(34,8);
      printf("____________");
    gotoxy(34,9);
      printf(" %c %c %c %c %c",ox[6],179,ox[7],179,ox[8]);
    tu++;
    pnt++;
    if
  (
	(ox[5]==ox[2]&&ox[5]==ox[8])||
	(ox[5]==ox[4]&&ox[5]==ox[3])


  )  { if(ox[5]==pn1s)
			{
			     gotoxy(28,11);
			   printf("Player 1 %s wins",pn1);
			  if(modechoice==1)
			    { gotoxy(28,12);
			       printf("Try Hard %s",pn2);
			    }
			}
	   if(ox[5]==pn2s)
			{
			  gotoxy(28,11);
			    printf("Player 2 %s wins",pn2);
			   gotoxy(28,12);
			    printf("Try Hard %s",pn1);
			}
	    goto end;
	 }
    goto rev;
  }
  if(ns==7)
  {
    if(ox[6]==pn1s||ox[6]==pn2s){ gotoxy(28,21); printf("Oops! this block is filled");goto rev;}

    clrscr();
    textcolor(6);
    outline(0);

    ox[6]=cs;
     gotoxy(34,5);
     printf(" %c %c %c %c %c",ox[0],179,ox[1],179,ox[2]);
    gotoxy(34,6);
     printf("____________");
    gotoxy(34,7);
      printf(" %c %c %c %c %c",ox[3],179,ox[4],179,ox[5]);
    gotoxy(34,8);
      printf("____________");
    gotoxy(34,9);
      printf(" %c %c %c %c %c",ox[6],179,ox[7],179,ox[8]);
    tu++;
    pnt++;
    if
  (
	(ox[6]==ox[3]&&ox[6]==ox[0])||
	(ox[6]==ox[4]&&ox[6]==ox[2])||
	(ox[6]==ox[7]&&ox[6]==ox[8])

  )  { if(ox[6]==pn1s)
			{
			    gotoxy(28,11);
			   printf("Player 1 %s wins",pn1);
			  if(modechoice==1)
			    { gotoxy(28,12);
			       printf("Try Hard %s",pn2);
			    }
			}
	   if(ox[6]==pn2s)
			{
			  gotoxy(28,11);
			    printf("Player 2 %s wins",pn2);
			   gotoxy(28,12);
			    printf("Try Hard %s",pn1);
			}
	    goto end;
	 }
    goto rev;
  }
  if(ns==8)
  {
    if(ox[7]==pn1s||ox[7]==pn2s){ gotoxy(28,21); printf("Oops! this block is filled");goto rev;}

    clrscr();
    textcolor(5);
    outline(0);

    ox[7]=cs;
     gotoxy(34,5);
     printf(" %c %c %c %c %c",ox[0],179,ox[1],179,ox[2]);
    gotoxy(34,6);
     printf("____________");
    gotoxy(34,7);
      printf(" %c %c %c %c %c",ox[3],179,ox[4],179,ox[5]);
    gotoxy(34,8);
      printf("____________");
    gotoxy(34,9);
      printf(" %c %c %c %c %c",ox[6],179,ox[7],179,ox[8]);
    tu++;
    pnt++;
    if
  (
	(ox[7]==ox[4]&&ox[7]==ox[1])||
	(ox[7]==ox[6]&&ox[7]==ox[8])


  )  { if(ox[7]==pn1s)
			{
			    gotoxy(28,11);
			   printf("Player 1 %s wins",pn1);
			  if(modechoice==1)
			    { gotoxy(28,12);
			       printf("Try Hard %s",pn2);
			    }
			}
	   if(ox[7]==pn2s)
			{
			  gotoxy(28,11);
			    printf("Player 2 %s wins",pn2);
			   gotoxy(28,12);
			    printf("Try Hard %s",pn1);

			}
	    goto end;
	 }
    goto rev;
  }
  if(ns==9)
  {
    if(ox[8]==pn1s||ox[8]==pn2s){ gotoxy(28,21); printf("Oops! this block is filled");goto rev;}

    clrscr();
    textcolor(4);
    outline(0);

    ox[8]=cs;
     gotoxy(34,5);
     printf(" %c %c %c %c %c",ox[0],179,ox[1],179,ox[2]);
    gotoxy(34,6);
     printf("____________");
    gotoxy(34,7);
      printf(" %c %c %c %c %c",ox[3],179,ox[4],179,ox[5]);
    gotoxy(34,8);
      printf("____________");
    gotoxy(34,9);
      printf(" %c %c %c %c %c",ox[6],179,ox[7],179,ox[8]);
    tu++;
    pnt++;
    if
  (
	(ox[8]==ox[4]&&ox[8]==ox[0])||
	(ox[8]==ox[5]&&ox[8]==ox[2])||
	(ox[8]==ox[7]&&ox[8]==ox[6])

  ) { if(ox[8]==pn1s)
			{
			    gotoxy(28,11);
			   printf("Player 1 %s wins",pn1);
			  if(modechoice==1)
			    { gotoxy(28,12);
			       printf("Try Hard %s",pn2);
			    }
			}
	   if(ox[8]==pn2s)
			{
			  gotoxy(28,11);
			    printf("Player 2 %s wins",pn2);
			   gotoxy(28,12);
			    printf("Try Hard %s",pn1);
			}
	    goto end;
	 }
    goto rev;
  }

 draw:
 gotoxy(29,12);
  printf("Match Draw");
end:
 gotoxy(29,13);
  printf("Match finish");
 playchoice=0;

 subhead(31,15,"PLAY AGAIN",10);
 subhead(31,18,"EXIT",12);

 gotoxy(26,21);
 textcolor(8);
 cprintf("Use UP/DOWN Arrow key to select");

  j=0;
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
	      if(j<1)
	      j++;
	  }
	if(j==0)

	  {
		playchoice=1;
		gotoxy(29,19);
		  printf(" ");

		gotoxy(29,16);
		textcolor(10);
		  cprintf("%c",16);
	  }
	if(j==1)
	  {
		 playchoice=2;
		 gotoxy(29,16);
		   printf(" ");

		 gotoxy(29,19);
		 textcolor(12);
		   cprintf("%c",16);
	  }

	if(arrow==13)
		break;
}

   if(playchoice==1)
      {
	for(i=0;i<9;i++)
	  {
	    ox[i]=NULL;
	  }
	  tu=0;
	  goto rev;
      }
   else
   goto exit;

exit:
clrscr();
return 0;
}

void AI()
{
  if(

		ox[0]==ox[4]||ox[0]==ox[8]||      //1
		ox[0]==ox[1]||ox[0]==ox[2]||        //1
		ox[0]==ox[3]||ox[0]==ox[6]||          //1
	 /////////////////////////////////////////////////////////
		ox[1]==ox[0]||ox[1]==ox[2]||      //2
		ox[1]==ox[4]||ox[1]==ox[7]||        //2
	 /////////////////////////////////////////////////////////
		ox[2]==ox[0]||ox[2]==ox[1]||      //3
		ox[2]==ox[4]||ox[2]==ox[5]||        //3
		ox[2]==ox[6]||ox[2]==ox[8]||          //3
	 /////////////////////////////////////////////////////////
		ox[3]==ox[0]||ox[3]==ox[4]||      //4
		ox[3]==ox[6]||ox[3]==ox[5]||       //4
	 /////////////////////////////////////////////////////////
		ox[4]==ox[1]||ox[4]==ox[8]||      //5
		ox[4]==ox[7]||ox[4]==ox[0]||        //5
		ox[4]==ox[3]||ox[4]==ox[6]||          //5
		ox[4]==ox[5]||ox[4]==ox[2]||	        //5
	 /////////////////////////////////////////////////////////
		ox[5]==ox[4]||ox[5]==ox[8]||      //6
		ox[5]==ox[3]||ox[5]==ox[2]||        //6
	 /////////////////////////////////////////////////////////
		ox[6]==ox[4]||ox[6]==ox[8]||      //7
		ox[6]==ox[0]||ox[6]==ox[2]||        //7
		ox[6]==ox[3]||ox[6]==ox[7]||          //7
	 /////////////////////////////////////////////////////////
		ox[7]==ox[4]||ox[7]==ox[8]||      //8
		ox[7]==ox[1]||ox[7]==ox[6]||        //8
	 /////////////////////////////////////////////////////////
		ox[8]==ox[4]||ox[8]==ox[7]||      //9
		ox[8]==ox[0]||ox[8]==ox[2]||        //9
		ox[8]==ox[5]||ox[8]==ox[6]            //9
	 /////////////////////////////////////////////////////////


    )
     {
	    if(ox[0]!=NULL)
	      {
		if(ox[0]==ox[1]&&ox[2]==NULL)   //  1
		{ns=3; }                          //  1
		if(ox[0]==ox[2]&&ox[1]==NULL)       //  1
		{ns=2; }                              //  1
		if(ox[0]==ox[3]&&ox[6]==NULL)           //  1
		{ns=7; }                                  //  1
		if(ox[0]==ox[6]&&ox[3]==NULL)               //  1
		{ns=4; }                                      //  1
		if(ox[0]==ox[4]&&ox[8]==NULL)                   //  1
		{ns=9; }                                          //  1
		if(ox[0]==ox[8]&&ox[4]==NULL)                       //  1
		{ns=5; }
	      }
      ////////////////////////////////////////////////////////////////////////////
	    if(ox[1]!=NULL)
	      {
		if(ox[1]==ox[0]&&ox[2]==NULL)   //  2
		{ns=3; }                          //  2
		if(ox[1]==ox[2]&&ox[0]==NULL)       //  2
		{ns=1; }                              //  2
		if(ox[4]==ox[3]&&ox[7]==NULL)           //  2
		{ns=8; }                                  //  2
		if(ox[7]==ox[6]&&ox[4]==NULL)               //  2
		{ns=5; }                                      //  2
	      }
      ////////////////////////////////////////////////////////////////////////
	    if(ox[2]!=NULL)
	      {
		if(ox[2]==ox[1]&&ox[0]==NULL)   //  3
		{ns=1; }                          //  3
		if(ox[2]==ox[0]&&ox[1]==NULL)       //  3
		{ns=2; }                              //  3
		if(ox[2]==ox[4]&&ox[6]==NULL)           //  3
		{ns=7; }                                  //  3
		if(ox[2]==ox[6]&&ox[4]==NULL)               //  3
		{ns=5; }                                      //  3
		if(ox[2]==ox[5]&&ox[8]==NULL)                   //  3
		{ns=9; }                                          //  3
		if(ox[2]==ox[8]&&ox[5]==NULL)                       //  3
		{ns=6; }
	      }
     ////////////////////////////////////////////////////////////////////////////
	    if(ox[3]!=NULL)
	      {
		if(ox[3]==ox[5]&&ox[4]==NULL)   //  4
		{ns=5; }                          //  4
		if(ox[3]==ox[4]&&ox[5]==NULL)       //  4
		{ns=6; }                              //  4
		if(ox[3]==ox[0]&&ox[6]==NULL)           //  4
		{ns=7; }                                  //  4
		if(ox[3]==ox[6]&&ox[0]==NULL)               //  4
		{ns=1; }                                      //  4
	      }
     ////////////////////////////////////////////////////////////////////////////////////
	    if(ox[4]!=NULL)
	      {
		if(ox[4]==ox[1]&&ox[7]==NULL)   //  5
		{ns=8; }                          //  5
		if(ox[4]==ox[7]&&ox[1]==NULL)       //  5
		{ns=2; }                              //  5
		if(ox[4]==ox[3]&&ox[5]==NULL)           //  5
		{ns=6; }                                  //  5
		if(ox[4]==ox[6]&&ox[2]==NULL)               //  5
		{ns=3; }                                      //  5
		if(ox[4]==ox[5]&&ox[3]==NULL)                   //  5
		{ns=4; }                                          //  5
		if(ox[4]==ox[8]&&ox[0]==NULL)                       //  5
		{ns=1; }                                              //  5
		if(ox[4]==ox[0]&&ox[8]==NULL)                            // 5
		{ns=9; }                                                   // 5
		if(ox[4]==ox[2]&&ox[6]==NULL)                                // 5
		{ns=7; }
	      }
      ////////////////////////////////////////////////////////////////////////////////////
	    if(ox[5]!=NULL)
	      {
		if(ox[5]==ox[2]&&ox[8]==NULL)   //  6
		{ns=9; }                          //  6
		if(ox[5]==ox[8]&&ox[2]==NULL)       //  6
		{ns=3; }                              //  6
		if(ox[5]==ox[3]&&ox[4]==NULL)           //  6
		{ns=5; }                                  //  6
		if(ox[5]==ox[4]&&ox[3]==NULL)               //  6
		{ns=4; }                                      //  6
	      }
     //////////////////////////////////////////////////////////////////////////////////////
	    if(ox[6]!=NULL)
	      {
		if(ox[6]==ox[3]&&ox[0]==NULL)   //  7
		{ns=1; }                          //  7
		if(ox[6]==ox[0]&&ox[3]==NULL)       //  7
		{ns=4; }                              //  7
		if(ox[6]==ox[7]&&ox[8]==NULL)           //  7
		{ns=9; }                                  //  7
		if(ox[6]==ox[8]&&ox[7]==NULL)               //  7
		{ns=8; }                                      //  7
		if(ox[6]==ox[4]&&ox[2]==NULL)                   //  7
		{ns=3; }                                          //  7
		if(ox[6]==ox[2]&&ox[4]==NULL)                       //  7
		{ns=5; }
	      }
    ///////////////////////////////////////////////////////////////////////////////////////
	    if(ox[7]!=NULL)
	      {
		if(ox[7]==ox[4]&&ox[1]==NULL)   //  8
		{ns=2; }                          //  8
		if(ox[7]==ox[1]&&ox[4]==NULL)       //  8
		{ns=5; }                              //  8
		if(ox[7]==ox[6]&&ox[8]==NULL)           //  8
		{ns=9; }                                  //  8
		if(ox[7]==ox[8]&&ox[6]==NULL)               //  8
		{ns=7; }                                      //  8
	      }
      //////////////////////////////////////////////////////////////////////////////////
	    if(ox[8]!=NULL)
	      {
		if(ox[8]==ox[7]&&ox[6]==NULL)   //  9
		{ns=7; }                          //  9
		if(ox[8]==ox[6]&&ox[7]==NULL)       //  9
		{ns=8; }                              //  9
		if(ox[8]==ox[5]&&ox[2]==NULL)           //  9
		{ns=3; }                                  //  9
		if(ox[8]==ox[2]&&ox[5]==NULL)               //  9
		{ns=6; }                                      //  9
		if(ox[8]==ox[4]&&ox[0]==NULL)                   //  9
		{ns=1; }                                          //  9
		if(ox[8]==ox[0]&&ox[4]==NULL)                       //  9
		{ns=5; }
	      }
    ///////////////////////////////////////////////////////////////////////////////////

     }


}


void outline(int ud)
{
  int r,c;

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
		     printf(" ");
	       }
	 printf("\n");

       }
head(32,1,"TIC TAC TOE",9);
gotoxy(26,21);
if(ud!=0)
  {
	textcolor(8);
	cprintf("Use UP/DOWN Arrow key to select");
  }

}
void head(int x,int y,char *str,int col)
{
   int r,c,len;

   len=strlen(str);
   len+=4;
   gotoxy(x,y);

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
gotoxy(x+2,y+1);
textcolor(col);
cprintf("%s",str);

}
void subhead(int x,int y,char*str,int col)
{
   int r,c,len;

   len=strlen(str);
   len+=4;
   gotoxy(x,y);
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

gotoxy(x+2,y+1);
textcolor(col);
cprintf("%s",str);

}
