#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int drawit()
{
 int gd=DETECT,gm;
 int i=72,x=100,y=100,pc=12,gpc;
 char *gp="C:\\TC\\BGI";
 FILE *fp=fopen("C:\\POINTREC\\PREC.txt","w+");;
 clrscr();

 initgraph(&gd,&gm,gp);

 while(1)
 {
  i=getch();

  if(i==72)
	putpixel(x,--y,pc);
  if(i==80)
	putpixel(x,++y,pc);
  if(i==75)
	putpixel(--x,y,pc);
  if(i==77)
	putpixel(++x,y,pc);
  if(i==88)     //EXIT
	break;
  if(i==82)    //RESET
	cleardevice();


  if(i==67)     //COLOR
    {
	while(1)
	 {
		setcolor(pc);
		circle(580,15,10);
		i=getch();
		if(i==72)
		 pc--;
		if(i==80)
		pc++;
		if(i==67)
		  {     setcolor(0);
			circle(580,15,10);
			break;
		  }
	 }
    }

  if(i==83)        //STOP DRAW
    {
      gpc=getpixel(x,y);
      while(1)
       {
	i=getch();

	if(i==70)  //TO STORE X,Y COORDINATES
	  {
		fprintf(fp,"\nX=%d,Y=%d",x,y);
	  }

	if(i==72)
	  {
		putpixel(x,y,gpc);
		gpc=getpixel(x,--y);
		putpixel(x,y,pc);
	  }
	if(i==80)
	  {
		putpixel(x,y,gpc);
		gpc=getpixel(x,++y);
		putpixel(x,y,pc);
	  }
	if(i==75)
	  {
		putpixel(x,y,gpc);
		gpc=getpixel(--x,y);
		putpixel(x,y,pc);
	  }
	if(i==77)
	  {
		putpixel(x,y,gpc);
		gpc=getpixel(++x,y);
		putpixel(x,y,pc);
	  }
	if(i==83)
	 break;
       }
    }

   if(i==69)        //ERASER
    {
      gpc=0;

      while(1)
       {
	i=getch();


	if(i==72)
	  {
		putpixel(x,y,gpc);
	       //	gpc=getpixel(x,--y);
		putpixel(x,--y,pc);
	  }
	if(i==80)
	  {
		putpixel(x,y,gpc);
	       //	gpc=getpixel(x,++y);
		putpixel(x,++y,pc);
	  }
	if(i==75)
	  {
		putpixel(x,y,gpc);
	       //	gpc=getpixel(--x,y);
		putpixel(--x,y,pc);
	  }
	if(i==77)
	  {
		putpixel(x,y,gpc);
	       //	gpc=getpixel(++x,y);
		putpixel(++x,y,pc);
	  }
	if(i==69)
	 break;
       }
    }

 } //WHILE LOOP END

//getch();
return 0;
}
