#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>

#define __Space
#include "GAME.H"

struct stars {
	int x,y,c;
};

void story() {
	cleardevice();
	int tc=getcolor();
	int y,i,n=39;
	char ST[39][100];

	i=0;
	strcpy(ST[i],"It's the year 3986...");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i],"Earth was at the forefront of technology...");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i],"The World was at harmony...");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i],"Until the aliens had started invading us...");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i],"Harmony Was disturbed...");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i],"It is upto you now to save the world and restore harmony and peace...");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i]," ");
	i++;
	strcpy(ST[i],"All The Best... !!!");
	i=0;

	y=getmaxy();
	settextstyle(0,0,1);

	while(y>=(-(16*n))) {
		cleardevice();
		if(kbhit())
			break;
		for(i=0;i<n;i++)
			outtextxy((getmaxx()/2)-(textwidth(ST[i])/2),y+(i*12),ST[i]);
		y-=1;
		delay(1000/25);
	}

	setcolor(tc);
}

void help() {
	cleardevice();
	int tc = getcolor();
	int x,y,dx,dy,px,py,a;
	setcolor(15);

	settextstyle(0,0,2);

	x=(getmaxx()/2)-64;
	y=-30;
	py=y;
	dy=2;

	while(y<=10) {
		setcolor(getbkcolor());
		outtextxy(x,py,"Space War");
		outtextxy(x-16,py+18,"-----------");

		setcolor(15);
		outtextxy(x,y,"Space War");
		outtextxy(x-16,y+18,"-----------");

		py=y;
		y+=dy;

		delay(1000/25);
	}

	x=0;
	px=x;
	dx=1;

	while(x<=10) {
		setcolor(getbkcolor());
		outtextxy(px,51,"Objectives");
		outtextxy(px,69,"----------");
		outtextxy(px,85,"* Destroy Maximum Aliens");
		outtextxy(px,105,"* Earn Maximum Points");
		outtextxy(px,125,"* Don't Get Killed");
		outtextxy(px,189,"Controls");
		outtextxy(px,207,"--------");
		outtextxy(px,223,"* Use Mouse For Moving Around");
		outtextxy(px,243,"* Mouse-Click For Shooting");
		outtextxy(px,263,"* Press Esc To Exit To Menu");

		setcolor(15);
		outtextxy(x,51,"Objectives");
		outtextxy(x,69,"----------");
		outtextxy(x,85,"* Destroy Maximum Aliens");
		outtextxy(x,105,"* Earn Maximum Points");
		outtextxy(x,125,"* Don't Get Killed");
		outtextxy(x,189,"Controls");
		outtextxy(x,207,"--------");
		outtextxy(x,223,"* Use Mouse For Moving Around");
		outtextxy(x,243,"* Mouse-Click For Shooting");
		outtextxy(x,263,"* Press Esc To Exit To Menu");

		px=x;
		x+=dx;

		delay(1000/25);
	}

	y=getmaxy();
	py=y;
	dy=0;
	a=1;

	while(y>=(getmaxy()-46)) {
		setcolor(getbkcolor());
		outtextxy((getmaxx()/2)-(13*16),py,"Press Any Key To Exit Help");

		setcolor(15);
		outtextxy((getmaxx()/2)-(13*16),y,"Press Any Key To Exit Help");

		py=y;
		y-=dy;
		dy+=a;

		delay(1000/25);
	}

	outtextxy((getmaxx()/2)-64,10,"Space War");
	outtextxy((getmaxx()/2)-80,28,"-----------");
	outtextxy(10,51,"Objectives");
	outtextxy(10,69,"----------");
	outtextxy(10,85,"* Destroy Maximum Aliens");
	outtextxy(10,105,"* Earn Maximum Points");
	outtextxy(10,125,"* Don't Get Killed");
	outtextxy(10,189,"Controls");
	outtextxy(10,207,"--------");
	outtextxy(10,223,"* Use Mouse For Moving Around");
	outtextxy(10,243,"* Mouse-Click For Shooting");
	outtextxy(10,263,"* Press Esc To Exit To Menu");
	outtextxy((getmaxx()/2)-(13*16),getmaxy()-46,"Press Any Key To Exit Help");

	getch();

	setcolor(tc);
	settextstyle(0,0,1);
}

void Credits() {
	int x,x1,y1,x2,y2,dx1,dx2,a,li=0;
	int pts[8];
	int tc=getcolor();

	delay(1000);

	x=(getmaxx()/2)-40;
	setcolor(2);
	setfillstyle(1,2);

	while(x<=((getmaxx()/2)+40)) {
		cleardevice();
		outtextxy((getmaxx()/2)-(textwidth("Loading...")/2),(getmaxy()/2)-24,"Loading...");

		pts[0]=(getmaxx()/2)-40;
		pts[1]=(getmaxy()/2)-4;
		pts[2]=x;
		pts[3]=(getmaxy()/2)-4;
		pts[4]=x;
		pts[5]=(getmaxy()/2)+4;
		pts[6]=(getmaxx()/2)-40;
		pts[7]=(getmaxy()/2)+4;

		rectangle((getmaxx()/2)-48,(getmaxy()/2)-8,(getmaxx()/2)+48,(getmaxy()/2)+8);
		fillpoly(4,pts);

		x+=10;

		delay(1000/5);
	}

	cleardevice();
	delay(750);

	randomize();
	x=0;
	int cltr=0;
	while(x<=getmaxx()) {
		cltr=random(getmaxcolor()+1)-1;
		if(cltr==0)
			cltr=1;
		setcolor(cltr);
		line(x,0,x,getmaxy());
		x+=getmaxx()/25;
		delay(1000/100);
	}
	x=0;
	while(x<=getmaxx()) {
		setcolor(getbkcolor());
		line(x,0,x,getmaxy());
		x+=getmaxx()/25;
		delay(1000/100);
	}
	x=0;
	while(x<=getmaxx()) {
		cltr=random(getmaxcolor()+1)-1;
		if(cltr==0)
			cltr=1;
		setcolor(cltr);
		line(x,0,x,getmaxy());
		x+=getmaxx()/25;
		delay(1000/100);
	}
	x=0;
	while(x<=getmaxx()) {
		setcolor(getbkcolor());
		line(x,0,x,getmaxy());
		x+=getmaxx()/25;
		delay(1000/100);
	}

	delay(250);

	setcolor(tc);

	y1=getmaxy()/2;
	y2=y1;
	y1-=80;
	x1=0;
	x2=getmaxx();
	y2-=55;
	dx1=1;
	dx2=dx1;
	a=2;
	setcolor(2);
	settextstyle(10,0,2);
	while(x1<((getmaxx()/2)-120)) {
		if(kbhit())
			break;
		cleardevice();
		outtextxy(x1,y1,"Abhishek Arts");
		outtextxy(x2,y2,"Presents...");
		x1+=dx1;
		x2-=dx2;
		dx1+=a;
		dx2+=a;
		delay(1000/25);
	}
	dx1=dx2=1;
	x=0;
	while(x1<(getmaxx()/2)-50) {
		if(kbhit())
			break;
		cleardevice();

		x=0;
		for(li=0;li<25;li++) {
			setcolor(getbkcolor());
			line(x,0,x,getmaxy());
			cltr=random(getmaxcolor()+1)-1;
			if(cltr==0)
				cltr=1;
			setcolor(cltr);
			line(x,0,x,getmaxy());
			x+=getmaxx()/25;
		}

		setcolor(2);
		outtextxy(x1,y1,"Abhishek Arts");
		outtextxy(x2,y2,"Presents...");
		x1+=dx1;
		x2-=dx2;
		delay(1000/25);
	}
	a=4;
	while(x1<getmaxx()+200) {
        	if(kbhit())
                	break;
		cleardevice();
		outtextxy(x1,y1,"Abhishek Arts");
		outtextxy(x2,y2,"Presents...");
		x1+=dx1;
		x2-=dx2;
		dx1+=a;
		dx2+=a;
		delay(1000/25);
	}
	settextstyle(0,0,1);
}

void Menu(int ch,Game g) {
		int y=0,dy=1,a=1,i;
		int p,c=0,pc=0,key=0,k=10;
		int pin = 80,s=2,tc=0,pk=0;
		int posi;
		int pts[8];
		char name[25],ke[1],kee,scr[50],temp[10];
	if(ch==0 || ch==2) {
		settextstyle(2,0,10);

		if(ch==0) {
			while(y<getmaxy()/4) {
				if(kbhit())
					break;
				cleardevice();
				outtextxy(getmaxx()/2-80,y,"Space War");
				y+=dy;
				dy+=a;
				delay(1000/25);
			}
		}

		y=getmaxy()/4;
		cleardevice();
		outtextxy(getmaxx()/2-80,y,"Space War");

		delay(1000/3);
		settextstyle(0,0,s);
		p=getmaxx()/2-(s*8*5);
		outtextxy(p,y+pin+(20*c),"START");
		c++;
		delay(1000/3);
		p=getmaxx()/2-(s*8*4);
		outtextxy(p,y+pin+(20*c),"HELP");
		c++;
		delay(1000/3);
		p=getmaxx()/2-(s*8*6);
		outtextxy(p,y+pin+(20*c),"High Scores");
		c++;
		delay(1000/3);
		p=getmaxx()/2-(s*8*5);
		outtextxy(p,y+pin+(20*c),"Story");
		c++;
		delay(1000/3);
		p=getmaxx()/2-(s*8*5);
		outtextxy(p,y+pin+(20*c),"Reset Game");
		c++;
		delay(1000/3);
		p=getmaxx()/2-(s*8*4);
		outtextxy(p,y+pin+(20*c),"EXIT");
		c=0;
		delay(1000/3);
		k=(s*8*5);
		while(key!=27) {
			p=getmaxx()/2-pk;
			tc=getcolor();
			setcolor(getbkcolor());
			rectangle(p-2,y+pin-2+(pc*20),p+(2*pk)+2,y+pin+2+(pc*20)+(s*8));
			setcolor(tc);
			p=getmaxx()/2-k;
			rectangle(p-2,y+pin-2+(c*20),p+(2*k)+2,y+pin+2+(c*20)+(s*8));
			pk=k;
			pc=c;
			key=getch();
			if(key==72)
				c--;
			if(key==80)
				c++;
			if(key==27)
				break;
			if(key==13 && c==0)
				break;
			if(key==13 && c==1) {
				help();
				cleardevice();
				Menu(2,g);
				break;
			}
			if(key==13 && c==2) {
				if(g.dispScore()==0) {
					cleardevice();
					settextstyle(0,0,1);
					setcolor(2);
					outtextxy(((getmaxx()/2)-(11*8)),(getmaxy()/2)-8,"No Scores Saved Yet...");
					getch();
				}
				cleardevice();
				Menu(2,g);
				break;
			}
			if(key==13 && c==3) {
				story();
				cleardevice();
				Menu(2,g);
				break;
			}
			if(key==13 && c==4) {
				cleardevice();
				settextstyle(0,0,1);
				setcolor(2);
				outtextxy(((getmaxx()/2)-(16*8)),(getmaxy()/2)-8,"Are You Sure? (ESC to CANCEL)...");
				key=getch();
				if(key!=27)
					remove("Scores.sav");
				Menu(2,g);
				break;
			}
			if(key==13 && c==5)
				exit(0);
			if(c>5)
				c=0;
			if(c<0)
				c=5;
			if(c==0 || c==3 || c==4)
				k=(s*8*5);
			else if(c==2)
				k=(s*8*6);
			else
				k=(s*8*4);
		}
		if(key==27)
			exit(0);
		settextstyle(0,0,1);
	}
	else if(ch==1) {
		setcolor(1);
		settextstyle(0,0,1);
		strcpy(scr,"Your Score : ");
		itoa(g.Get(0),temp,10);
		strcat(scr,temp);
		outtextxy((getmaxx()/2)-98,(getmaxy()/2)-25,scr);
		outtextxy((getmaxx()/2)-98,(getmaxy()/2)-15,"Enter Your Name :-");
		rectangle((getmaxx()/2)-98,(getmaxy()/2)-2,(getmaxx()/2)+106,(getmaxy()/2)+10);
		k=0;
		kee=0;
		pin=0;
		posi=(getmaxx()/2)-96;
		strcpy(ke," ");
		pts[1]=getmaxy()/2;
		pts[3]=pts[1];
		pts[5]=pts[3]+8;
		pts[7]=pts[5];
		while(kee!=13) {
			kee=getch();
			strset(ke,kee);
			if(kee==8 && posi>((getmaxx()/2)-96)) {
				posi-=8;
				pts[0]=posi;
				pts[2]=posi+8;
				pts[4]=pts[2];
				pts[6]=pts[0];
				pin=getcolor();
				setcolor(getbkcolor());
				setfillstyle(1,getbkcolor());
				line(posi,getmaxy()/2,posi,(getmaxy()/2)+8);
				fillpoly(4,pts);
				setcolor(pin);
				setfillstyle(1,pin);
				k--;
				name[k]=' ';
			}
			else if((isalnum(kee) || kee==' ' || kee=='_') && pk==0) {
				pin=getcolor();
				setcolor(getbkcolor());
				line(posi,getmaxy()/2,posi,(getmaxy()/2)+8);
				setcolor(pin);
				outtextxy(posi,getmaxy()/2,ke);
				posi+=8;
				name[k]=kee;
				k++;
			} else
				continue;
			if(posi>=(((getmaxx()/2)-96)+(8*25)))
				pk=1;
			else
				pk=0;

			pin=getcolor();
			setcolor(1);
			line(posi,getmaxy()/2,posi,(getmaxy()/2)+8);
			setcolor(pin);
			setfillstyle(1,pin);
		}
		for(i=k;i<25;i++)
			name[i]=' ';

		g.saveScore(name);
		setcolor(2);
	} else
		exit(0);
}

void TXTr(int op,stars S[]) {
	int x,y,dx,dy,i,a=1;
	int pts[8];

	if(op==0) {
		delay(1000);

		x=(getmaxx()/2)-40;
		setcolor(2);
		setfillstyle(1,2);

		while(x<=((getmaxx()/2)+40)) {
			cleardevice();
			outtextxy((getmaxx()/2)-(textwidth("Loading...")/2),(getmaxy()/2)-24,"Loading...");

			pts[0]=(getmaxx()/2)-40;
			pts[1]=(getmaxy()/2)-4;
			pts[2]=x;
			pts[3]=(getmaxy()/2)-4;
			pts[4]=x;
			pts[5]=(getmaxy()/2)+4;
			pts[6]=(getmaxx()/2)-40;
			pts[7]=(getmaxy()/2)+4;

			rectangle((getmaxx()/2)-48,(getmaxy()/2)-8,(getmaxx()/2)+48,(getmaxy()/2)+8);
			fillpoly(4,pts);

			x+=10;

			delay(1000/5);
		}

		cleardevice();
		delay(750);

		settextstyle(0,0,3);
		y=getmaxy()/2;
		y-=24;
		x=0;
		dx=0;
		dy=0;
		a=2;

		for(i=0;i<1000;i++) {
			putpixel(S[i].x, S[i].y, S[i].c);
			delay(1);
		}
		while(x<=((getmaxx()/2)-(24*3)-6)) {
			cleardevice();
			for(i=0;i<1000;i++) {
				putpixel(S[i].x, S[i].y, S[i].c);
			}
			dx+=a;
			x+=dx;
			outtextxy(x,y,"Wave");
			outtextxy(getmaxx()-x,y,"One!");
			delay(1000/25);
		}
		delay(500);
		cleardevice();
		a=3;
		dx=0;
		while(x>=0) {
			cleardevice();
			for(i=0;i<1000;i++) {
				putpixel(S[i].x, S[i].y, S[i].c);
			}
			dx+=a;
			x-=dx;
			outtextxy(x,y,"Wave");
			outtextxy(getmaxx()-x,y,"One!");
			delay(1000/25);
		}
		settextstyle(0,0,5);
		delay(100);
		cleardevice();
		y=getmaxy()/2-16;
		x=getmaxx()/2;
		x-=32*2;
		x-=16;
		a=1;
		while(a<=10) {
			delay(50);
			outtextxy(x,y,"START");
			delay(50);
			cleardevice();
			for(i=0;i<1000;i++) {
				putpixel(S[i].x, S[i].y, S[i].c);
			}
			a++;
		}
		delay(100);
	}
	else if(op==1) {
		settextstyle(0,0,3);
		y=getmaxy()/2;
		y-=24;
		x=0;
		dx=0;
		dy=0;
		a=2;
		while(x<=((getmaxx()/2)-(24*3)-6)) {
			cleardevice();
			for(i=0;i<1000;i++) {
				putpixel(S[i].x, S[i].y, S[i].c);
			}
			dx+=a;
			x+=dx;
			outtextxy(x,y,"GAME");
			outtextxy(getmaxx()-x,y,"OVER");
			delay(1000/25);
		}
		delay(1000);
		cleardevice();
		a=3;
		dx=0;
		while(x>=0) {
			cleardevice();
			for(i=0;i<1000;i++) {
				putpixel(S[i].x, S[i].y, S[i].c);
			}
			dx+=a;
			x-=dx;
			outtextxy(x,y,"GAME");
			outtextxy(getmaxx()-x,y,"OVER");
			delay(1000/25);
		}
		settextstyle(0,0,5);
		delay(1000);
		cleardevice();
	}
	settextstyle(0,0,1);
}

void main() {
	clrscr();
        int gdriver = DETECT, gmode, errorcode;
	int midx, midy;
	int maxx,maxy;
	int started=0;
        int key = 0;
	int x=0,y=0,px,py,c;
	int Frame_Rate=25;
	int i,j,b=0;
	int clt = 0;
	char BGIP[50],temp[3][20];

	Game G;
	G.set(0,"Player 1",3);

	cout<<"Error = "<<G.error<<"\n\n";

	/* initialize graphics and local variables */
	cout<<"Enter BGI Path => ";
	gets(BGIP);
	if(strlen(BGIP)<1)
		strcpy(BGIP,"C:\\TURBOC3\\BGI");
	initgraph(&gdriver, &gmode, BGIP);
	cleardevice();

	/* read result of initialization */
	errorcode = graphresult();
	if (errorcode != grOk) {
		cout<<"Graphics error: \n"<<grapherrormsg(errorcode);
		cout<<"\nPress any key to halt:";
		getch();
		exit(1); /* terminate with an error code */
	}

	setcolor(getmaxcolor());
	maxx = getmaxx();
	maxy = getmaxy();
	midx = maxx / 2;
	midy = maxy / 2;
	y=((maxy*7)/8);
	Ship P(midx,y,6);
	Bullet B[20];
	Enemy E[8];
	stars St[1000];

	delay(1000);
	Credits();
	cleardevice();
	Menu(0,G);

	for(i=0;i<20;i++)
		B[i].Type(4,4,2,1);
	for (i=0;i<1000;i++) {
		St[i].x=random(getmaxx());
		St[i].y=random(getmaxy());
		St[i].c=random(getmaxcolor()-1)+1;
	}

	int ps=-1,pl=-1,ics=0,icl=0;
	int tpc=0;

	cleardevice();
	G.callMouse();
	do{
	if(started==0) {
		story();
		cleardevice();
		started=1;
	}
	TXTr(0,St);
	cleardevice();
	for(i=0;i<8;i++) {
		E[i].set(random(getmaxx()-14)+7,random(30)+10,random(getmaxcolor()-1)+1,random(8)+1);
	}

	while(key!=27) {
		ics=G.Get(0);
		icl=G.Get(1);
		if(clt>50) {
			//cleardevice();
			clt=0;
		} else {
			clt++;
		}

		if(kbhit())
			key=getch();
		px=x;
		py=y;
		G.getMouse(x,y,c);
		if(y<((getmaxy()*3)/4)) {
			y = ((getmaxy()*3)/4);
			G.setPos(x,y);
		}
		if(y>(getmaxy()-20)) {
			y = (getmaxy()-20);
			G.setPos(x,y);
		}

		//Collisions
		for(i=0;i<20;i++) {
			for(j=0;j<8;j++) {
				if(E[j].collide(B[i])==1 && B[i].flag==1) {
					G.Hit(10);
					E[j].alive=0;
					E[j].draw();
					B[i].flag=0;
					B[i].draw();
					B[i].killd();
				}
				if(E[j].collide(P)) {
					G.Hit();
					P.move(getmaxx()/2,getmaxy());
					G.setPos(getmaxx()/2,getmaxy());
					P.shield=50;
					P.draw();
				}
			}
		}

		if(icl<=0)
			break;

		if(c==1) {
			for(i=0;i<20;i++) {
				if(B[i].flag==0) {
					if(b==0) {
						B[i].set(x,y-15);
						b++;
					}
					break;
				}
			}
		}
		if(b>0) {
			b++;
			if(b>4)
				b=0;
		}

		for(i=0;i<1000;i++) {
			putpixel(St[i].x, St[i].y, St[i].c);
		}

		for(i=0;i<8;i++) {
			if(E[i].alive==0)
				E[i].set(random(getmaxx()-14)+7,random(30)+10,random(getmaxcolor()-1)+1,random(8)+1);
			else {
				E[i].move();
				E[i].draw();
			}
		}
		for(i=0;i<20;i++) {
			if(B[i].flag==1) {
				B[i].move();
				B[i].draw();
			}
		}
		if(px!=x) {
			P.move(x,y);
			P.draw();
		}
		if(P.shield>0)
			P.draw();

		if(ps!=ics || pl!=icl) {
			tpc=getcolor();
			setcolor(2);
			itoa(icl,temp[0],10);
			itoa(ics,temp[1],10);
			strcpy(temp[2],"Lives : ");
			strcat(temp[2],temp[0]);
			strcat(temp[2],", Score : ");
			strcat(temp[2],temp[1]);
			outtextxy(20,20,temp[2]);

			setcolor(getbkcolor());
			setfillstyle(1,getbkcolor());
			fillellipse(getmaxx()/4,0,getmaxx()/4,getmaxy()/6);

			ps = ics;
			pl = icl;
			setcolor(tpc);
		} else {
			tpc=getcolor();
			setcolor(2);
			itoa(icl,temp[0],10);
			itoa(ics,temp[1],10);
			strcpy(temp[2],"Lives : ");
			strcat(temp[2],temp[0]);
			strcat(temp[2],", Score : ");
			strcat(temp[2],temp[1]);
			outtextxy(20,20,temp[2]);
			setcolor(tpc);
		}
		setfillstyle(1,4);
		delay(1000/Frame_Rate);
	}
	delay(750);
	cleardevice();
	TXTr(1,St);
	setcolor(2);
	Menu(1,G);
	Menu(2,G);
	key=0;
	G.reset();
	G.set(0,"Player 1",3);
	cleardevice();
	}while(key!='x');
	closegraph();
}

