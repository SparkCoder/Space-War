#ifndef __cplusplus
#error Executable only in C++ Programs.
#endif

#ifndef __Space
#error To Be Used Specifically for Space Wars Game.
#endif

#ifndef __GAME_H
#define __GAME_H

#if !defined( __GRAPHICS_H )
#include <graphics.h>
#endif

#if !defined( __FSTREAM_H )
#include <fstream.h>
#endif

#if !defined( __DOS_H )
#include <dos.h>
#endif

#if !defined( __CONIO_H )
#include <conio.h>
#endif

#if !defined( __STRING_H )
#include <string.h>
#endif

union REGS in,out;

/*void showMouse() {
	in.x.ax = 1;
	int86(51,&in,&out);
}*/

struct ScoreSav {
	char name[25];
	int score;
};

class Game {
	char name[25];
	int score,life;

        int checkScore(ScoreSav);

	public:
		int error;
		int callMouse();
		void hideMouse();
		void getMouse(int &,int &,int &);
		void setPos(int,int);
		void rectMouse(int x1,int y1,int x2,int y2);
		void Hit(int s);
		void Hit();
		int Get(int cs);
		void saveScore(char []);
		int dispScore();
		Game() {
			error = callMouse() + 1;
			hideMouse();
			score = 0;
			strcpy(name,"");
			randomize();
		}
		void reset() {
			score = 0;
			strcpy(name,"");
			randomize();
		}

		void set(int s,char n[],int li) {
			if(strlen(n)>25)
				error=1;
			else {
				error=0;
				score = s;
				strcpy(name,n);
			}
			life=li;
		}
		void get(char n[]) {
			strcpy(n,name);
		}
};

int Game::checkScore(ScoreSav So) {
	fstream sav("Scores.sav",ios::binary|ios::out|ios::nocreate|ios::app);
        ScoreSav Sr;
        int pos=-1,small;
        int i=0;
        small=So.score;
        while(sav.read((char *) &Sr,sizeof(Sr))) {
                if(Sr.score<small) {
                	small=Sr.score;
                        pos=i;
                }
        	i++;
                if(i>9) {
                	sav.close();
                	return -1;
                }
	}
        if(i<9 && pos==-1) {
        	sav.close();
        	return i;
        }
        sav.close();
        return -2;
}

void Game::saveScore(char n[]) {
	int sco,status=0;

	if(strlen(n)>25)
		error=1;
	else {
		sco=score;
		strcpy(name,n);

		ScoreSav Sc;
		fstream sav("Scores.sav",ios::binary|ios::out|ios::nocreate|ios::app);
		if(!sav) {
			sav.close();
			sav.open("Scores.sav",ios::binary|ios::out);
		}
		strcpy(Sc.name,name);
		Sc.score=sco;

                status=checkScore(Sc);

                if(status!=-1) {
                	if(status!=-2)
                        	sav.seekp(status*sizeof(Sc));
			sav.write((char *) &Sc,sizeof(Sc));
                }
		sav.close();
	}
}

int Game::dispScore() {
	ScoreSav Sc,Scs[10],temps;
	int i,j,x,y,l;
	char temp[32],temp2[8];

	cleardevice();

	fstream sav("Scores.sav",ios::binary|ios::in);
	if(!sav) {
			sav.close();
			return 0;
	}
	y=getmaxy()-330;
	cleardevice();
	outtextxy((getmaxx()/2)-40,getmaxy()-360,"Top Scores");
	outtextxy((getmaxx()/2)-48,getmaxy()-350,"------------");

	i=0;
	while(sav.read((char *) &Sc,sizeof(Sc))) {
		settextstyle(0,0,1);
		setcolor(2);

		Scs[i]=Sc;

		i++;
		if(i>10)
			break;
	}
	l=i;
        for(i=0;i<n;i++) {
        	for(j=0;j=(n-i-1);j++) {
                	if(Scs[j].score>Scs[j+1].score) {
                        	temps=Scs[j];
                                Scs[j]=Scs[j+1];
                                Scs[j+1]=temps;
                        }
                }
        }
	for(i=0;i<l;i++) {
		x=(getmaxx()/2)-(156/2);
		strcpy(temp,"Name = ");
                for(j=7;j<32;j++)
			temp[j]=Scs[i].name[j-7];
		outtextxy(x,y,temp);
		y+=12;
		itoa(Scs[i].score,temp2,10);
		strcpy(temp,"Score = ");
		strcat(temp,temp2);
		outtextxy(x,y,temp);
		y+=12;

		delay(1000/5);
	}
	getch();
	sav.close();
	return 1;
}

void Game::Hit(int sc) {
	score+=sc;
}

void Game::Hit() {
	life--;
}

int Game::Get(int cs) {
	switch(cs) {
		case 0:
			return score;
		case 1:
			return life;
	}
	return -1;
}

int Game::callMouse() {
	in.x.ax = 0;
	int86(51,&in,&out);
	return out.x.ax;
}

void Game::getMouse(int &xpos,int &ypos,int &clk) {
	in.x.ax = 3;
        int86(51,&in,&out);
        clk = out.x.bx;
        xpos = out.x.cx;
        ypos = out.x.dx;
}
void Game::hideMouse() {
	in.x.ax = 2;
        int86(51,&in,&out);
}
void Game::rectMouse(int x1,int y1,int x2,int y2) {
	in.x.ax = 7;
	in.x.cx = x1;
	in.x.dx = y1;
	int86(51,&in,&out);
	in.x.ax = 8;
	in.x.cx = x2;
	in.x.dx = y2;
	int86(51,&in,&out);
}
void Game::setPos(int xpos,int ypos) {
	in.x.ax = 4;
	in.x.cx = xpos;
	in.x.dx = ypos;
	int86(51,&in,&out);
}

class Ship {
	int px,py;
	int color;
	int energy;

	public:
		int x,y;
		int shield;
		Ship() {
			x=0;
			y=0;
			px=x;
			py=y;
			shield=50;
			energy=100;
		}
		Ship(int ix,int iy,int c) {
			x=ix;
			y=iy;
			px=x;
			py=y;
			shield=50;
			energy=100;
			color=c;
		}
		void move(int nx,int ny) {
			px=x;
			py=y;
			x=nx;
			y=ny;
		}
		void draw();
		void ship(int,int,int);
};

void Ship::draw() {
	ship(px,py,getbkcolor());
	ship(x,y,color);
}

void Ship::ship(int x,int y,int c) {
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

	setcolor(c);
	setfillstyle(1,c);
	fillellipse(x,y,14,9);
	setcolor(0);
	setfillstyle(1,0);
	fillpoly(4,clr);
	setcolor(c);
	setfillstyle(1,c);
	fillpoly(11,poly);
	if(shield>0) {
		circle(x,y,30);
		shield--;
	}
	if(shield==0) {
		setcolor(getbkcolor());
		circle(x,y,30);
		setcolor(c);
		shield--;
	}

}

class Bullet {
	int py;
	int dy,acc;
	int col,rad,imp;
	int tc;

	public:
		int flag;
		int x,y;

        	Bullet() {
                        x=0;
                        y=0;
                        dy=0;
                        flag=0;
                }
                void Type(int a,int c,int r,int im) {
                        acc=a;
                        col=c;
                        rad=r;
                        imp=im;
                }
                void set(int ix,int iy) {
                	x=ix;
                        py=y=iy;
                        dy=0;
                        flag=1;
                }
                void move() {
                	py=y;
                	dy+=acc;
                        y-=dy;
                        if(y<(-rad)) {
                        	flag=0;
                        }
		}
		void killd() {
			tc = getcolor();
			setcolor(getbkcolor());
			setfillstyle(1,getbkcolor());
			fillellipse(x,y,rad+2,rad+2);
			setcolor(tc);
		}
		void draw() {
			tc = getcolor();
			setcolor(col);
			setfillstyle(1,col);
			fillellipse(x,y,rad,rad);
			setcolor(getbkcolor());
			setfillstyle(1,getbkcolor());
			fillellipse(x,py,rad+2,rad+2);
			setcolor(tc);
                }
};

class Enemy {
        int px,py,x,y;
	int tc,col,r;
	int m;
	int speed;

	public:
	       int alive;

	       Enemy() {
			col=px=py=x=y=alive=speed=0;
			r=20;
			m=1;
	       }
	       int collide(Ship);
	       int collide(Bullet);
	       void set(int ix,int iy,int c,int s) {
			x=ix;
			y=iy;
			col=c;
			speed=s;
			alive=1;
	       }
	       void move();
	       void draw();
};

int Enemy::collide(Bullet b) {
	if((b.x>(x-r)) && (b.x<(x+r)) && (b.y>(y-r)) && (b.y<(y+r)))
		return 1;
	return 0;
}

int Enemy::collide(Ship p) {
	if(p.shield<=0) {
		if((p.x-14>(x-15)) && (p.x-14<(x+15)) && (p.y-10>(y-15)) && (p.y-10<(y+15)))
			return 1;
		if((p.x-14>(x-15)) && (p.x-14<(x+15)) && (p.y+10>(y-15)) && (p.y+10<(y+15)))
			return 1;
		if((p.x+14>(x-15)) && (p.x+14<(x+15)) && (p.y-10>(y-15)) && (p.y-10<(y+15)))
			return 1;
		if((p.x+14>(x-15)) && (p.x+14<(x+15)) && (p.y+10>(y-15)) && (p.y+10<(y+15)))
			return 1;
	}
	return 0;
}

void Enemy::move() {
	px=x;
	py=y;
	y+=speed;
	x+=(speed*m);
	if(x>getmaxx()-10)
		m=-1;
	if(x<10)
		m=1;
	if(y>(getmaxy()+(2*r)+2))
		alive=0;
}

void Enemy::draw() {
	if(alive==1) {
		tc=getcolor();

		setcolor(getbkcolor());
		setfillstyle(SOLID_FILL,getbkcolor());
		fillellipse(px, py, r, (r/3)+2);
		ellipse(px, py-4, 190, 357, r, r/3);
		line(px+7, py-6, px+10, py-12);
		circle(px+10, py-12, 2);
		line(px-7, py-6, px-10, py-12);
		circle(px-10, py-12, 2);

		setcolor(col);
		setfillstyle(SOLID_FILL,col);
		fillellipse(x, y, r, (r/3)+2);
		ellipse(x, y-4, 190, 357, r, r/3);
		line(x+7, y-6, x+10, y-12);
		circle(x+10, y-12, 2);
		line(x-7, y-6, x-10, y-12);
		circle(x-10, y-12, 2);

		setcolor(tc);
		setfillstyle(SOLID_FILL,tc);
	} else {
		setcolor(getbkcolor());
		setfillstyle(SOLID_FILL,getbkcolor());
		fillellipse(px, py, (3*r)/2, (3*r)/2);
		setcolor(tc);
		setfillstyle(SOLID_FILL,tc);
	}
}

#endif