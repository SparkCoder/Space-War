#include <iostream.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

union REGS in,out;

int callMouse() {
	in.x.ax = 0;
        int86(51,&in,&out);
        return out.x.ax;
}

void getMouse(int &xpos,int &ypos,int &clk) {
	in.x.ax = 3;
        int86(51,&in,&out);
        clk = out.x.bx;
        xpos = out.x.cx;
        ypos = out.x.dx;
}

void showMouse() {
	in.x.ax = 1;
        int86(51,&in,&out);
}

void hideMouse() {
	in.x.ax = 2;
        int86(51,&in,&out);
}

void setPos(int &xpos,int &ypos) {
	in.x.ax = 4;
        in.x.cx = xpos;
        in.x.dx = ypos;
        int86(51,&in,&out);
}

void rectMouse(int x1,int y1,int x2,int y2) {
	in.x.ax = 7;
        in.x.cx = x1;
        in.x.dx = y1;
        int86(51,&in,&out);
        in.x.ax = 8;
        in.x.cx = x2;
        in.x.dx = y2;
        int86(51,&in,&out);
}

void ship(int x,int y,int c,int c2) {
        int poly[22];
	int clr[8] = {(x-14),(y-9),(x+14),(y-9),(x-14),(y+8),(x+14),(y+8)};

        poly[0]=x;
        poly[1]=y-8;
        poly[2]=x-4;
        poly[3]=y;
        poly[4]=x-6;
        poly[5]=y;
        poly[6]=x-10;
        poly[7]=y-6;
        poly[8]=x-14;
        poly[9]=y;
	poly[10]=x-12;
        poly[11]=y+7;
        poly[12]=x+12;
        poly[13]=y+7;
        poly[14]=x+14;
        poly[15]=y;
        poly[16]=x+10;
        poly[17]=y-6;
        poly[18]=x+6;
        poly[19]=y;
        poly[20]=x+4;
        poly[21]=y;

        setcolor(c2);
        setfillstyle(1,c);
        fillellipse(x,y,14,9);
        setcolor(0);
        setfillstyle(1,0);
	fillpoly(4,clr);
        setcolor(c);
        setfillstyle(1,c);
        fillpoly(11,poly);
}

struct bullet {
	int x;
        int y;
        int dy;
        int px;
        int py;
        int acc;
        int col;
        int flag;
};

struct enemy {
	int x;
        int y;
        int dy;
        int col;
        int flag;
};

void main() {
	clrscr();

	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
        int maxx,maxy;
        int x,y,px,py;
        int mx,my,mpx = 0,mpy = 0;
        int key = 0;
        int dy = 0, dx = 0;
        char temp[50];
        int c = 0;
        int i;
        char BGIP[50];

	/* initialize graphics and local variables */
        cout<<"Enter BGI Path => ";
        gets(BGIP);
	initgraph(&gdriver, &gmode, "C:\\TC\\TC\\BGI\\");
        cleardevice();

	/* read result of initialization */
	errorcode = graphresult();
	if (errorcode != grOk) {
		cout<<"Graphics error: \n"<<grapherrormsg(errorcode);
		cout<<"\nPress any key to halt:";
      		getch();
      		exit(1); /* terminate with an error code */
   	}

        maxx = getmaxx();
        maxy = getmaxy();
   	midx = maxx / 2;
   	midy = maxy / 2;
   	setcolor(getmaxcolor());

        setbkcolor(0);
        callMouse();
        hideMouse();

        for (i=0;i<1000;i++)
    		putpixel(random(getmaxx()), random(getmaxy()), random(getmaxcolor()-1)+1);

        int bl = 0;
        bullet b[50];

        for(i=0;i<50;i++)
        	b[i].flag=0;

   	/* draw the circle */
        while(key != 27) {
        	if(kbhit())
                	key = getch();
                getMouse(mx,my,c);

                //cleardevice();
                x+=dx;
                y+=dy;

                if(mpx != mx) {
			setcolor(0);
                	setfillstyle(1,0);
   			fillellipse(mpx,((getmaxy() * 7) / 8),20,20);
                        setcolor(getmaxcolor());
                	setfillstyle(1,getmaxcolor());
                	ship(mx,((getmaxy() * 7) / 8),6,12);
                }

                mpx = mx;
                // mpy = my;

                if(c == 1) {
                        if(bl == 0) {
                        	for(i=0;i<50;i++) {
                        		if(b[i].flag == 0)
                 		              	break;
                        	}

                        	b[i].x = mx;
                        	b[i].y = ((getmaxy() * 7) / 8)-12;
                        	b[i].dy = 2;
                        	b[i].acc = 4;
                                b[i].col = 4;
                        	b[i].flag = 1;
                                bl++;
                	}
                }

                if(bl>0) {
                	bl++;
                	if(bl>=5)
                		bl = 0;
                }

                for(i=0;i<50;i++) {
                	if(b[i].flag == 1) {
                                b[i].y-=b[i].dy;
                                b[i].dy+=b[i].acc;
                                if(b[i].y < 0)  {
                                	b[i].flag = 0;
                                }

                                setcolor(0);
                		setfillstyle(1,0);
   				fillellipse(b[i].px,b[i].py,2,2);
				setcolor(b[i].col);
                		setfillstyle(1,b[i].col);
   				fillellipse(b[i].x,b[i].y,2,2);

                                b[i].px = b[i].x;
                                b[i].py = b[i].y;
				setcolor(getmaxcolor());
                		setfillstyle(1,getmaxcolor());
                        }

        	}
                delay(1000/25);
        }

   	/* clean up */
   	//getch();
   	closegraph();
}
