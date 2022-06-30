//DrawIT program
//created by MOHIT
//EMAIL- mohitk1110@gmail.com
//date 15-07-21

/* Controls
 use arrow keys to draw

	press C - * Color change mode
		   change color of line
		   use UP DOWN keys to change color
		   press C again to exit change color mode *

	press D - * Load previous save file *

	press E - * Eraser mode
		     press E again to exit Eraser mode *

	press R - * Clear draw screen *

	press S - * Stop mode
		     stop drawing on screen
		     press S again to exit Stop mode *

	press V - * Save current drawing *

	press X - * Exit DrawIT program *



*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

void dwsave(void);
void dwread(void);
int x=100,y=100;
int main()
{
 int gd=DETECT,gm,i=72,pc=12,gpc;
 char *gp="C:\\TC\\BGI";
 clrscr();

 initgraph(&gd,&gm,gp);

 while(1)
 {
  i=getch();

  if(i==72)
    {
	putpixel(x,--y,pc);

    }
  if(i==80)
    {
	putpixel(x,++y,pc);

    }
  if(i==75)
    {
	putpixel(--x,y,pc);

    }
  if(i==77)
    {
	putpixel(++x,y,pc);

    }
  if(i==88)     //EXIT      X
    {

	break;
    }
  if(i==82)    //RESET       R
	cleardevice();

  if(i==86)    //SAVE TO FILE   V
	dwsave();
  if(i==68)
	dwread(); //READ FROM FILE   D
  if(i==67)     //COLOR       C
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

  if(i==83)        //STOP DRAW     S
    {
      gpc=getpixel(x,y);
      while(1)
       {
	i=getch();

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

   if(i==69)        //ERASER    E
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
closegraph();
return 0;
}

void dwsave(void)
{

 int iy,jx,pv=0;
 FILE *savefp=fopen("DWSFILE.txt","w+");

 if(savefp==NULL)
   printf("File not open\n");
 else
   {
		for(iy=1;iy<=600;iy++)
		   {
			for(jx=1;jx<=600;jx++)
			   {

				pv=getpixel(jx,iy);
				fprintf(savefp,"%d,",pv);
			   }
		   }
		//printf("file saved\n");
		fclose(savefp);
   }
}  //dwsave function end

void dwread(void)     //function for reading drawit save file
{
 FILE *readfp=fopen("DWSFILE.TXT","r");
 int iy,jx,pv2=1,pv3=1;
 char pv=0;

 if(readfp==NULL)
   printf("file not open\n");
 else
   {
	for(iy=1;iy<=600;iy++)
		   {
			for(jx=1;jx<=600;jx++)
			   {

				fscanf(readfp,"%c",&pv);      //read character from file


				if(pv!=',')
				  {
					if(pv=='0')pv2=0;
					if(pv=='1')pv2=1;
					if(pv=='2')pv2=2;
					if(pv=='3')pv2=3;
					if(pv=='4')pv2=4;
					if(pv=='5')pv2=5;
					if(pv=='6')pv2=6;
					if(pv=='7')pv2=7;
					if(pv=='8')pv2=8;
					if(pv=='9')pv2=9;

					fscanf(readfp,"%c",&pv);

					if(pv!=',')
					  {
						pv3=pv2*10;
						if(pv=='0')pv3=0;
						if(pv=='1')pv2=1;
						if(pv=='2')pv2=2;
						if(pv=='3')pv2=3;
						if(pv=='4')pv2=4;
						if(pv=='5')pv2=5;
						if(pv=='6')pv2=6;
						if(pv=='7')pv2=7;
						if(pv=='8')pv2=8;
						if(pv=='9')pv2=9;

						  pv3+=pv2;
						putpixel(jx,iy,pv3);
						fscanf(readfp,"%c",&pv);

					  }
					else
					  putpixel(jx,iy,pv2);
				  }

			   }
		   }
		fclose(readfp);
   }

}  //dwread function end
