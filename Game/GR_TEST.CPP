#include <graphics.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <conio.h>

void P3D(int x,int y,int z,int zoom,int &nx,int &ny) {
        nx = ((1*x)/(z*zoom));
        ny = ((1*y)/(z*zoom));
        nx += getmaxx()/2;
        ny += getmaxy()/2;
}

void main()
{
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	int radius = 100;
        int nx[4],ny[4];

   	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "C:\\TC\\TC\\BGI\\");

        /* read result of initialization */
        errorcode = graphresult();
   	if (errorcode != grOk)  /* an error occurred */
   	{
      		printf("Graphics error: %s\n", grapherrormsg(errorcode));
      		printf("Press any key to halt:");
      		getch();
      		exit(1); /* terminate with an error code */
	}

   	setcolor(getmaxcolor());

        midx = getmaxx() / 2;
   	midy = getmaxy() / 2;

        P3D(-30,+5,5,-2,nx[0],ny[0]);
        P3D(30,+5,5,-2,nx[1],ny[1]);
        P3D(-30,-5,20,-2,nx[2],ny[2]);
        P3D(30,-5,20,-2,nx[3],ny[3]);

        line(nx[0],ny[0],nx[1],ny[1]);
        line(nx[1],ny[1],nx[2],ny[2]);
	line(nx[2],ny[2],nx[3],ny[3]);
	line(nx[3],ny[3],nx[0],ny[0]);

        int px=0,py=midy;
        int x,y,z,x3,y3;
        int c;

        randomize();
        while(kbhit()){
        for(int i=-midx;i<midx;i++) {
        	c = random(getmaxcolor());
        	setcolor((c == 0)?random(getmaxcolor()):c);
        	x = i;
                y = ((int) (sin((double) x)*100));
                z = ((i + midx) == 0)?1:(i + midx);

		P3D(x,y,z,1,x3,y3);
                line(px,py,x3,y3);
                px = x3;
                py = y3;
        }
        delay(1000/25);
        }

   	/* clean up */
   	getch();
   	closegraph();
}