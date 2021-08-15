// MADE BY LALIT

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#define DE 120


int main ()
{
 int *gd=DETECT,*gm,i,j;
 char *gp="C:\\TC\\BGI";

 initgraph(gd,gm,gp);
 setcolor(6);
 for(i=180,j=1;i<=400;i+=20,j++)
    {
	delay(120);
	if(j%2!=0)
		arc(i,30,180,0,10);
	else
		arc(i,30,0,180,10);
    }

 for(i=40,j=1;i<=250;i+=20,j++)
    {
	delay(120);
	if(j%2!=0)
		arc(410,i,90,270,10);
	else
		arc(410,i,270,90,10);
    }

 for(i=400,j=1;i>=180;i-=20,j++)
    {
	delay(120);
	if(j%2!=0)
		arc(i,250,180,0,10);
	else
		arc(i,250,0,180,10);
    }

  for(i=240,j=1;i>=30;i-=20,j++)
    {
	delay(120);
	if(j%2!=0)
		arc(170,i,90,270,10);
	else
		arc(170,i,270,90,10);
    }
 setfillstyle(1,14);
 delay(DE);
 floodfill(200,200,6);

 setcolor(0);
 delay(DE);
 circle(260,105,32);
 delay(DE);
 circle(315,105,32);
 setfillstyle(1,15);
 delay(DE);
 floodfill(260,105,0);
 delay(DE);
 floodfill(315,105,0);
 delay(DE);
 floodfill(288,105,0);


 setcolor(0);
 delay(DE);
 circle(265,110,12);
 delay(DE);
 circle(310,110,12);
 setfillstyle(1,9);
 delay(DE);
 floodfill(265,105,0);
 delay(DE);
 floodfill(310,105,0);

 setcolor(0);
 delay(DE);
 circle(265,109,5);
 delay(DE);
 circle(312,110,5);
 setfillstyle(1,0);
 delay(DE);
 floodfill(265,109,0);
 delay(DE);
 floodfill(312,110,0);

 delay(DE);
 line(280,121,284,136);
 delay(DE);
 line(280,121,295,121);
 delay(DE);
 line(295,121,291,136);

 delay(DE);
 arc(290,95,210,330,90);
 delay(DE);
 line(276,184,278,203);
 delay(DE);
 line(278,203,259,203);
 delay(DE);
 line(259,203,262,181);
 setfillstyle(1,15);
 delay(DE);
 floodfill(262,200,0);

 delay(DE);
 line(300,184,298,203);
 delay(DE);
 line(298,203,317,203);
 delay(DE);
 line(317,203,314,181);
 delay(DE);
 floodfill(300,200,0);

 delay(DE);
 line(257,73,257,53);
 delay(DE);
 line(238,82,227,62);
 delay(DE);
 line(277,78,283,58);

 delay(DE);
 line(317,73,317,53);
 delay(DE);
 line(338,82,348,62);
 delay(DE);
 line(296,79,292,59);

 setcolor(6);
 delay(DE);
 line(172,244,192,440);
 delay(DE);
 line(393,257,373,440);

 delay(DE);
 line(180,324,385,324);
 delay(DE);
 line(382,355,183,355);
 setfillstyle(1,4);
 delay(DE);
 floodfill(185,330,6);

 setfillstyle(1,15);
 delay(DE);
 floodfill(190,300,6);

 delay(DE);
 line(240,260,259,277);
 delay(DE);
 line(259,277,280,260);
 delay(DE);
 line(280,260,298,277);
 delay(DE);
 line(298,278,320,260);

 delay(DE);
 line(291,271,288,276);
 delay(DE);
 line(288,276,271,276);
 delay(DE);
 line(271,276,268,271);

 delay(DE);
 line(271,276,264,365);
 delay(DE);
 line(298,365,264,365);
 delay(DE);
 line(288,276,298,365);

 setfillstyle(1,12);
 delay(DE);
 floodfill(280,268,6);
 delay(DE);
 floodfill(280,293,6);
 floodfill(280,337,6);
 delay(DE);
 floodfill(280,360,6);

 setcolor(12);
 delay(DE);
 line(267,324,294,324);
 delay(DE);
 line(265,355,297,355);
 setcolor(6);

 delay(DE);
 arc(195,275,133,220,50);
 delay(DE);
 arc(367,275,320,50,51);
 delay(DE);
 line(157,307,178,307);
 delay(DE);
 line(407,307,386,307);

 delay(DE);
 line(400,307,394,369);
 delay(DE);
 line(394,369,381,369);
 delay(DE);
 line(164,308,170,369);
 delay(DE);
 line(170,369,185,369);
 setfillstyle(1,15);
 delay(DE);
 floodfill(161,272,6);
 delay(DE);
 floodfill(405,286,6);
 delay(DE);
 floodfill(404,244,6);
 setfillstyle(1,14);
 delay(DE);
 floodfill(175,342,6);
 delay(DE);
 floodfill(391,334,6);

getch();
closegraph();
return 0;
}
// MADE BY LALIT

