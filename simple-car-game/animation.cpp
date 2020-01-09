#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<string.h>
int showmenu=0;
int i=750;
int day=225;
float h=1050;
int engine=1;
int speed=1;
int mark[]={0,50,150,250,350,450,550,650,750,850,950,1015};
int build[]={0,10,110,230,350,450,600,700,800,1000};
int citymov=0;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,1000,0,500);
}
void startscreen()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
}
void car()
{
	//car body
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(162,32);
	glVertex2f(164,58);
	glVertex2f(158,68);
	glVertex2f(142,68);
	glVertex2f(136,58);
	glVertex2f(138,32);
	glVertex2f(126,32);
	glVertex2f(112,50);
	glVertex2f(120,50);
	glVertex2f(120,60);
	glVertex2f(115,76);

	glVertex2f(190,90);
	glVertex2f(250,90);
	glVertex2f(300,70);
	glVertex2f(315,70);
	glVertex2f(360,55);
	glVertex2f(355,45);
	glVertex2f(360,32);
	glVertex2f(312,32);
	glVertex2f(314,58);
	glVertex2f(306,68);
	glVertex2f(292,68);
	glVertex2f(285,58);
	glVertex2f(288,32);
	glEnd();
	//rear tyre place
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(162,32);
	glVertex2f(164,58);
	glVertex2f(158,68);
	glVertex2f(142,68);
	glVertex2f(136,58);
	glVertex2f(138,32);
	glEnd();
	//front tyre space
	glBegin(GL_POLYGON);
	glVertex2f(312,32);
	glVertex2f(314,58);
	glVertex2f(306,68);
	glVertex2f(292,68);
	glVertex2f(285,58);
	glVertex2f(288,32);
	glEnd();
	//headlights
	if(day<250 || day>800)
	{
	glBegin(GL_POLYGON);
	glColor4f(1,1,0,0.5);
	glVertex2f(360,55);
	glVertex2f(355,45);
	glColor4f(1,1,1,0.5);
	glVertex2f(450,30);
	glVertex2f(450,70);
	glEnd();
	}
}
void star1(int starpos1,int starpos2)
{
	glColor3f(1,1,1);
	//star
	glBegin(GL_POLYGON);
	glVertex2i(starpos1+3,starpos2+0);
	glVertex2i(starpos1+12,starpos2+3);
	glVertex2i(starpos1+6,starpos2+9);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(starpos1+12,starpos2+3);
	glVertex2i(starpos1+21,starpos2+0);
	glVertex2i(starpos1+18,starpos2+9);
	glVertex2i(starpos1+24,starpos2+15);
	glVertex2i(starpos1+15,starpos2+15);
	glVertex2i(starpos1+12,starpos2+27);
	glVertex2i(starpos1+9,starpos2+15);
	glVertex2i(starpos1+0,starpos2+15);
	glVertex2i(starpos1+6,starpos2+9);
	glEnd();
	//end of star
}
void star2(int starpos1,int starpos2)
{
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2i(starpos1+1,starpos2+0);
	glVertex2i(starpos1+4,starpos2+2);
	glVertex2i(starpos1+2,starpos2+3);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(starpos1+4,starpos2+2);
	glVertex2i(starpos1+7,starpos2+0);
	glVertex2i(starpos1+6,starpos2+3);
	glVertex2i(starpos1+8,starpos2+5);
	glVertex2i(starpos1+5,starpos2+5);
	glVertex2i(starpos1+4,starpos2+9);
	glVertex2i(starpos1+3,starpos2+5);
	glVertex2i(starpos1+0,starpos2+5);
	glVertex2i(starpos1+2,starpos2+3);
	glEnd();
}
void star3(int starpos1,int starpos2)
{
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2i(starpos1+2,starpos2+0);
	glVertex2i(starpos1+8,starpos2+4);
	glVertex2i(starpos1+4,starpos2+6);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(starpos1+8,starpos2+4);
	glVertex2i(starpos1+14,starpos2+0);
	glVertex2i(starpos1+12,starpos2+6);
	glVertex2i(starpos1+16,starpos2+10);
	glVertex2i(starpos1+10,starpos2+10);
	glVertex2i(starpos1+8,starpos2+18);
	glVertex2i(starpos1+6,starpos2+10);
	glVertex2i(starpos1+0,starpos2+10);
	glVertex2i(starpos1+4,starpos2+6);
	glEnd();
}
void moon()
{
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2i(400,300);
	glVertex2i(470,310);
	glVertex2i(460,330);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(470,310);
	glVertex2i(460,330);
	glVertex2i(470,360);
	glVertex2i(490,380);
	glVertex2i(500,350);
	glEnd();
		glBegin(GL_POLYGON);
	glVertex2i(470,360);
	glVertex2i(490,380);
	glVertex2i(440,400);
	glEnd();
}
void nightsky()
{
	moon();
	star1(50,350);
	star2(70,450);
	star1(100,300);
	star2(300,250);
	star3(225,400);
	star1(600,375);
	star1(750,270);
	star2(850,315);
	star1(800,390);
	star3(850,360);
	star1(950,420);
}
void earlynight()
{
		moon();
	star2(70,450);
	star2(300,250);
	star3(225,400);
	star2(850,315);
	star3(850,360);
}
void earlynightnomoon()
{
	star2(70,450);
	star2(300,250);
	star3(225,400);
	star2(850,315);
	star3(850,360);
}
void baseline()
{
	int p;
	//draw road
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2i(0,15);
	glVertex2i(1000,15);
	glVertex2i(1000,75);
	glVertex2i(0,75);
	glEnd();
	glColor3f(0.15,0.15,0.15);
	//draw footpaths
	glBegin(GL_POLYGON);
	glVertex2i(0,0);
	glVertex2i(0,15);
	glVertex2i(1000,15);
	glVertex2i(1000,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(0,60);
	glVertex2i(0,75);
	glVertex2i(1000,75);
	glVertex2i(1000,60);
	glEnd();
	//draw thw road markers
	glColor3f(1,1,1);
	if(mark[1]<=0)
		mark[1]+=1050;
	glBegin(GL_POLYGON);
	glVertex2i(mark[1],35);
	glVertex2i(mark[1],45);
	glVertex2i(mark[1]-50,45);
	glVertex2i(mark[1]-50,35);
	glEnd();
	if(mark[2]<=0)
		mark[2]+=1050;
	glBegin(GL_POLYGON);
	glVertex2i(mark[2],35);
	glVertex2i(mark[2],45);
	glVertex2i(mark[2]-50,45);
	glVertex2i(mark[2]-50,35);
	glEnd();
	if(mark[3]<=0)
		mark[3]+=1050;
	glBegin(GL_POLYGON);
	glVertex2i(mark[3],35);
	glVertex2i(mark[3],45);
	glVertex2i(mark[3]-50,45);
	glVertex2i(mark[3]-50,35);
	glEnd();
	if(mark[4]<=0)
		mark[4]+=1050;
	glBegin(GL_POLYGON);
	glVertex2i(mark[4],35);
	glVertex2i(mark[4],45);
	glVertex2i(mark[4]-50,45);
	glVertex2i(mark[4]-50,35);
	glEnd();
	if(mark[5]<=0)
		mark[5]+=1050;
	glBegin(GL_POLYGON);
	glVertex2i(mark[5],35);
	glVertex2i(mark[5],45);
	glVertex2i(mark[5]-50,45);
	glVertex2i(mark[5]-50,35);
	glEnd();
	if(mark[6]<=0)
		mark[6]+=1050;
	glBegin(GL_POLYGON);
	glVertex2i(mark[6],35);
	glVertex2i(mark[6],45);
	glVertex2i(mark[6]-50,45);
	glVertex2i(mark[6]-50,35);
	glEnd();
	if(mark[7]<=0)
		mark[7]+=1050;
	glBegin(GL_POLYGON);
	glVertex2i(mark[7],35);
	glVertex2i(mark[7],45);
	glVertex2i(mark[7]-50,45);
	glVertex2i(mark[7]-50,35);
	glEnd();
	if(mark[8]<=0)
		mark[8]+=1050;
	glBegin(GL_POLYGON);
	glVertex2i(mark[8],35);
	glVertex2i(mark[8],45);
	glVertex2i(mark[8]-50,45);
	glVertex2i(mark[8]-50,35);
	glEnd();
	if(mark[9]<=0)
		mark[9]+=1050;
	glBegin(GL_POLYGON);
	glVertex2i(mark[9],35);
	glVertex2i(mark[9],45);
	glVertex2i(mark[9]-50,45);
	glVertex2i(mark[9]-50,35);
	glEnd();
	if(mark[10]<=0)
		mark[10]+=1050;
	glBegin(GL_POLYGON);
	glVertex2i(mark[10],35);
	glVertex2i(mark[10],45);
	glVertex2i(mark[10]-50,45);
	glVertex2i(mark[10]-50,35);
	glEnd();
	if(mark[11]<=0)
		mark[11]+=1050;
	glBegin(GL_POLYGON);
	glVertex2i(mark[11],35);
	glVertex2i(mark[11],45);
	glVertex2i(mark[11]-35,45);
	glVertex2i(mark[11]-35,35);
	glEnd();
	if(engine==1)
	{
	if(speed==0)
	{
		for(p=1;p<=11;p++) mark[p]--;
	}
	else if(speed==1)
	{
		for(p=1;p<=11;p++) mark[p]-=2;
	}
	else if(speed==2)
	{
		for(p=1;p<=11;p++) mark[p]-=3;
	}
	}
}
void sun(int h)
{
float x1,y1,x2,y2;
float angle;
double radius=45;
x1=h;
y1=375;
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x1,y1);
for(angle=1.0f;angle<361.0f;angle+=0.2)
{
    x2=x1+sin(angle)*radius;
    y2=y1+cos(angle)*radius;
    glVertex2f(x2,y2);
}
glEnd();
glFlush();
}
void sun_effects()
{
	if(day==250)
		h=1050;
	if(day>=250 && day <=325)
	{
		glColor3f(1,0.5,0);
		sun(h-=2);
	}
	else if(day>325 && day<=675)
	{
		glColor3f(1,1,0);
		sun(h-=2);
	}
	else if(day>675 && day<800)
	{
		glColor3f(1,0.5,0);
		sun(h-=2);
	}
}
void nite_mrng()
{
	if(day<125)
	{
		glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	nightsky();
	}
	else if(day<150)
	{
		glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glColor3f(0.32,0.32,0.32);
	glVertex2i(1000,500);
	glColor3f(0,0,0);
	glVertex2i(1000,75);
	glEnd();
	nightsky();
	}
	else if(day<175)
	{
		glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glColor3f(0.32,0.32,0.32);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	nightsky();
	}
	else if(day<200)
	{
		glBegin(GL_POLYGON);
	glColor3f(0.32,0.32,0.32);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glColor3f(0.13,0.13,0.55);
	glVertex2i(1000,500);
	glColor3f(0.32,0.32,0.32);
	glVertex2i(1000,75);
	glEnd();
	earlynight();
	}
	else if(day<225)
	{
	glBegin(GL_POLYGON);
	glColor3f(0.13,0.13,0.55);
	glVertex2i(0,75);
	glColor3f(0.32,0.32,0.32);
	glVertex2i(0,500);
	glColor3f(0.13,0.13,0.55);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	earlynight();
	}
	else
	{
	glBegin(GL_POLYGON);
	glColor3f(0.13,0.13,0.55);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	}
	glFlush();
}
void mrng_noon()
{
	if(day<275)
	{
		glBegin(GL_POLYGON);
	glColor3f(0.13,0.13,0.55);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glColor3f(1,0.5,0);
	glVertex2i(1000,500);
	glColor3f(0.13,0.13,0.55);
	glVertex2i(1000,75);
	glEnd();
	}
	else if(day<300)
	{
	glBegin(GL_POLYGON);
	glColor3f(0.13,0.13,0.55);
	glVertex2i(0,75);
	glColor3f(1,0.5,0);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	}
	else if(day<325)
	{
	glBegin(GL_POLYGON);
	glColor3f(.22,.67,.89);
	glVertex2i(0,75);
	glColor3f(1,0.25,0);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glColor3f(.22,.67,.89);
	glVertex2i(1000,75);
	glEnd();
	}
	else if(day<350)
	{
	glBegin(GL_POLYGON);
	glColor3f(.22,.67,.89);
	glVertex2i(0,75);
	glColor3f(1,0.25,0);
	glVertex2i(0,500);
	glColor3f(.22,.67,.89);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	}
	else
	{
	glBegin(GL_POLYGON);
	glColor3f(0.22,0.67,0.89);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	}
	glFlush();
}
void noon_eve()
{
	if(day>=500 && day<650)
	{
	glBegin(GL_POLYGON);
	glColor3f(0.22,0.67,0.89);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	}
	else if(day>=650 && day<675)
	{
	glBegin(GL_POLYGON);
	glColor3f(0.22,0.67,0.89);
	glVertex2i(0,75);
	glColor3f(1,0.7,0);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glColor3f(0.22,0.67,0.89);
	glVertex2i(1000,75);
	glEnd();
	}
	else
	{
	glBegin(GL_POLYGON);
	glColor3f(1,0.7,0);
	glVertex2i(0,75);
	glColor3f(1,0.25,0);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	}
	glFlush();
}
void even_nite()
{
	if(day>=750 && day<775)
	{
		glBegin(GL_POLYGON);
	glColor3f(1,0.25,0);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glColor3f(0.13,0.13,0.13);
	glVertex2i(1000,75);
	glEnd();
	}
	else if(day>=775 && day<800)
	{
	glBegin(GL_POLYGON);
	glColor3f(1,0.25,0);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glColor3f(0.13,0.13,0.13);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	earlynightnomoon();
	}
	else if(day>=800 && day<=850)
	{
	glBegin(GL_POLYGON);
	glColor3f(0.13,0.13,0.13);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	}
	else
	{
		glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2i(0,75);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(1000,75);
	glEnd();
	}
	if(day>800 && day<850)
		earlynight();
	else if(day>850)
		nightsky();
	glFlush();
}
void big_building(int a,int b,int c,int d)
{
	glBegin(GL_POLYGON);
	glVertex2i(a,c);
	glVertex2i(b,c);
	glVertex2i(b,d);
	glVertex2i(a,d);
	glEnd();
	//left side windows
	if(day>800 || day<250)
		glColor3f(1,1,0);
	else
		glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+10,c+10);
	glVertex2i(a+10,c+40);
	glVertex2i(a+40,c+40);
	glVertex2i(a+40,c+10);
	glEnd();
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+10,c+70);
	glVertex2i(a+10,c+100);
	glVertex2i(a+40,c+100);
	glVertex2i(a+40,c+70);
	glEnd();
	if(day>800 || day<250)
		glColor3f(1,1,0);
	else
		glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+10,c+130);
	glVertex2i(a+10,c+160);
	glVertex2i(a+40,c+160);
	glVertex2i(a+40,c+130);
	glEnd();
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+10,c+180);
	glVertex2i(a+10,c+210);
	glVertex2i(a+40,c+210);
	glVertex2i(a+40,c+180);
	glEnd();
	//right side windows
	if(day>800 || day<250)
		glColor3f(1,1,0);
	else
		glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+60,c+10);
	glVertex2i(a+60,c+40);
	glVertex2i(a+90,c+40);
	glVertex2i(a+90,c+10);
	glEnd();
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+60,c+70);
	glVertex2i(a+60,c+100);
	glVertex2i(a+90,c+100);
	glVertex2i(a+90,c+70);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(a+60,c+130);
	glVertex2i(a+60,c+160);
	glVertex2i(a+90,c+160);
	glVertex2i(a+90,c+130);
	glEnd();
	if(day>800 || day<250)
		glColor3f(1,1,0);
	else
		glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+60,c+180);
	glVertex2i(a+60,c+210);
	glVertex2i(a+90,c+210);
	glVertex2i(a+90,c+180);
	glEnd();
}
void small_building(int a,int b,int c,int d)
{
	glBegin(GL_POLYGON);
	glVertex2i(a,c);
	glVertex2i(b,c);
	glVertex2i(b,d);
	glVertex2i(a,d);
	glEnd();
	//left side windows
	if(day>800 || day<250)
		glColor3f(1,1,0);
	else
		glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+10,c+10);
	glVertex2i(a+10,c+40);
	glVertex2i(a+40,c+40);
	glVertex2i(a+40,c+10);
	glEnd();
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+10,c+70);
	glVertex2i(a+10,c+100);
	glVertex2i(a+40,c+100);
	glVertex2i(a+40,c+70);
	glEnd();
	//right side windows
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+60,c+10);
	glVertex2i(a+60,c+40);
	glVertex2i(a+90,c+40);
	glVertex2i(a+90,c+10);
	glEnd();
	if(day>800 || day<250)
		glColor3f(1,1,0);
	else
		glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+60,c+70);
	glVertex2i(a+60,c+100);
	glVertex2i(a+90,c+100);
	glVertex2i(a+90,c+70);
	glEnd();
}
void med_building(int a,int b,int c,int d)
{
	glBegin(GL_POLYGON);
	glVertex2i(a,c);
	glVertex2i(b,c);
	glVertex2i(b,d);
	glVertex2i(a,d);
	glEnd();
	//left side windows
	if(day>800 || day<250)
		glColor3f(1,1,0);
	else
		glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+10,c+10);
	glVertex2i(a+10,c+40);
	glVertex2i(a+40,c+40);
	glVertex2i(a+40,c+10);
	glEnd();
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+10,c+70);
	glVertex2i(a+10,c+100);
	glVertex2i(a+40,c+100);
	glVertex2i(a+40,c+70);
	glEnd();
	if(day>800 || day<250)
		glColor3f(1,1,0);
	else
		glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+10,c+130);
	glVertex2i(a+10,c+160);
	glVertex2i(a+40,c+160);
	glVertex2i(a+40,c+130);
	glEnd();
	//right side windows
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+60,c+10);
	glVertex2i(a+60,c+40);
	glVertex2i(a+90,c+40);
	glVertex2i(a+90,c+10);
	glEnd();
	if(day>800 || day<250)
		glColor3f(1,1,0);
	else
		glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+60,c+70);
	glVertex2i(a+60,c+100);
	glVertex2i(a+90,c+100);
	glVertex2i(a+90,c+70);
	glEnd();
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2i(a+60,c+130);
	glVertex2i(a+60,c+160);
	glVertex2i(a+90,c+160);
	glVertex2i(a+90,c+130);
	glEnd();
}
void city()
{
	int p;
	for(p=1;p<=9;p++)
		if(build[p]<=-100)
			build[p]+=1100;
	glColor3f(0.3,0.3,0.5);
	med_building(build[1],build[1]+100,75,250);
	glColor3f(0.72,0.45,0.20);
	big_building(build[2],build[2]+100,75,300);
	glColor3f(1,0.7,0.3);
	med_building(build[3],build[3]+100,75,250);
	glColor3f(0.85,0.57,0.43);
	small_building(build[4],build[4]+100,75,200);
	glColor3f(0.3,0.3,0.5);
	big_building(build[5],build[5]+100,75,300);
	glColor3f(0.85,0.57,0.43);
	big_building(build[6],build[6]+100,75,300);
	glColor3f(1,0.7,0.3);
	med_building(build[7],build[7]+100,75,250);
	glColor3f(0.3,0.3,0.5);
	big_building(build[8],build[8]+100,75,300);
	glColor3f(0.85,0.57,0.43);
	big_building(build[9],build[9]+100,75,300);
	if(engine==1)
	{
	++citymov%16;
	if(speed==0)
	{
		if(citymov%15==0)
		for(p=1;p<=9;p++) build[p]--;
	}
	else if(speed==1)
	{
		if(citymov%10==0)
		for(p=1;p<=9;p++) build[p]--;
	}
	else if(speed==2)
	{
		if(citymov%5==0)
		for(p=1;p<=9;p++) build[p]--;
	}
	}
}
void background()
{
	if(day<250)
		nite_mrng();
	else if(day<500)
		mrng_noon();
	else if(day<750)
		noon_eve();
	else
		even_nite();
}
void obj(int i)
{
	int lamppost=i;
	if(i<890)
		lamppost+=1000;
	//draws lamp post
	glColor3f(0.18,0.30,0.30);
	glBegin(GL_POLYGON);
	glVertex2i(lamppost-900,75);
	glVertex2i(lamppost-950,75);
	glVertex2i(lamppost-940,100);
	glVertex2i(lamppost-910,100);
	glEnd();
	glColor3f(0.56,0.56,0.73);
	glBegin(GL_POLYGON);
	glVertex2i(lamppost-900,75);
	glVertex2i(lamppost-950,75);
	glVertex2i(lamppost-945,80);
	glVertex2i(lamppost-905,80);
	glEnd();
	glColor3f(0.18,0.30,0.30);
	glBegin(GL_POLYGON);
	glVertex2i(lamppost-910,100);
	glVertex2i(lamppost-940,100);
	glVertex2i(lamppost-940,150);
	glVertex2i(lamppost-910,150);
	glEnd();
	glColor3f(0.56,0.56,0.73);
	glBegin(GL_POLYGON);
	glVertex2i(lamppost-910,125);
	glVertex2i(lamppost-940,125);
	glVertex2i(lamppost-940,130);
	glVertex2i(lamppost-910,130);
	glEnd();
	glColor3f(0.56,0.56,0.73);
	glBegin(GL_POLYGON);
	glVertex2i(lamppost-910,100);
	glVertex2i(lamppost-940,100);
	glVertex2i(lamppost-940,105);
	glVertex2i(lamppost-910,105);
	glEnd();
	glColor3f(0.18,0.30,0.30);
	glBegin(GL_POLYGON);
	glVertex2i(lamppost-910,150);
	glVertex2i(lamppost-915,150);
	glVertex2i(lamppost-915,155);
	glVertex2i(lamppost-910,155);
	glEnd();
	glColor3f(0.18,0.30,0.30);
	glBegin(GL_POLYGON);
	glVertex2i(lamppost-940,150);
	glVertex2i(lamppost-935,150);
	glVertex2i(lamppost-935,155);
	glVertex2i(lamppost-940,155);
	glEnd();
	glColor3f(0.56,0.56,0.73);
	glBegin(GL_POLYGON);
	glVertex2i(lamppost-915,150);
	glVertex2i(lamppost-935,150);
	glVertex2i(lamppost-935,155);
	glVertex2i(lamppost-915,155);
	glEnd();
	glColor3f(0.18,0.30,0.30);
	glBegin(GL_POLYGON);
	glVertex2i(lamppost-910,155);
	glVertex2i(lamppost-940,155);
	glVertex2i(lamppost-960,200);
	glVertex2i(lamppost-890,200);
	glEnd();
	//lamp bulb color
	if(day<250 || day>800)
		glColor3f(1,1,0);
	else
		glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2i(lamppost-915,160);
	glVertex2i(lamppost-935,160);
	glVertex2i(lamppost-950,195);
	glVertex2i(lamppost-900,195);
	glEnd();
	//lamp light on or off
	if(day<200 || day>800)
	{
		glColor4f(1,1,1,0.4);
		glBegin(GL_POLYGON);
		glVertex2f(lamppost-910,155);
		glVertex2f(lamppost-895,200);
		glVertex2f(lamppost-810,225);
		glVertex2f(lamppost-810,125);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(lamppost-940,155);
		glVertex2f(lamppost-955,200);
		glVertex2f(lamppost-1040,225);
		glVertex2f(lamppost-1040,125);
		glEnd();
	}
	int bush;
	bush=i;
	if(bush<100)
		bush+=1000;
	//draw bush 1
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex2i(bush-150,75);
	glVertex2i(bush-130,75);
	glVertex2i(bush-140,110);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(bush-130,75);
	glVertex2i(bush-110,75);
	glVertex2i(bush-120,125);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(bush-110,75);
	glVertex2i(bush-90,75);
	glVertex2i(bush-100,110);
	glEnd();
	//draw tree trunk
		glColor3f(0.36,0.25,0.20);
	int correcttree=i;
	if(correcttree<500)
		correcttree+=1000;
	glBegin(GL_POLYGON);
	glVertex2i(correcttree-500,75);
	glVertex2i(correcttree-450,75);
	glVertex2i(correcttree-450,125);
	glVertex2i(correcttree-500,125);
	glEnd();
	glColor3f(0.18,0.30,0.18);
	glBegin(GL_POLYGON);
	glVertex2i(correcttree-550,125);
	glVertex2i(correcttree-400,125);
	glVertex2i(correcttree-475,250);
	glEnd();//draw tree ends
	car();
	glFlush();
}
void incspeed()
{
	speed++;
	if(speed>2)
		speed=2;
}
void decspeed()
{
	speed--;
	if(speed<0)
		speed=0;
}
void keyboard(unsigned char key,int x,int y)
{
	if(key=='S')
		engine=1;
	else if(key=='s')
		engine=0;
	else if(key=='q')
		exit(0);
	else if(key=='a')
		incspeed();
	else if(key=='z')
		decspeed();
	glutPostRedisplay();
}
void sleep1()
{
	int i,j,k;
	for(i=0;i<300;i++)
		for(j=0;j<300;j++)
			for(k=0;k<200;k++);
}
//draws larger font
void drawText(int x,int y,char *string)
{
    int i, len;
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(x,y);
    for (i=0,len=strlen(string);i<len;i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)string[i]);
}
//draw smaller font
void drawText1(int x,int y,char *string)
{
    int i, len;
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(x,y);
    for (i=0,len=strlen(string);i<len;i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, (int)string[i]);
}
void menu()
{
	char str1[]="Animation Illustrating Phases of a day";
	char str11[]="with Simulation of car";
	char str12[]="action buttons ";
	char str2[]="a-accelerate";
	char str3[]="z-brake";
	char str4[]="s-stop engine";
	char str5[]="S-start engine";
	char str8[]="q-quit";
	char str6[]="-project done by Sharath";
	char str7[]="with help of Kamat sir";
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	drawText(300,400,str1);
	drawText(375,375,str11);
	drawText(600,350,str6);
	drawText(625,325,str7);
	drawText(300,275,str12);
	drawText1(300,255,str2);
	drawText1(300,240,str3);
	drawText1(300,225,str4);
	drawText1(300,210,str5);
	drawText1(300,195,str8);
	glFlush();
	glutSwapBuffers();
	++showmenu;
	glutPostRedisplay();
}
void disp()
{
	if(day==1000)
		day=0;
	if(i<=2)
		i=1000;
	background();
	baseline();
	if(engine==1)
	{
	if(speed==0)
		i-=1;
	if(speed==1)
		i-=2;
	if(speed==2)
		i-=3;
	}
	else
		i=i;
	city();
	obj(i);
	sun_effects();
	++day;
	sleep1();
	glutSwapBuffers();
	glutPostRedisplay();
}
void display()
{
	if(showmenu<150)
	{
		menu();
		sleep1();
	}
	else
		disp();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000,500);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Car Animation | Hamed Mahmoudkhani");
	myinit();
	startscreen();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
