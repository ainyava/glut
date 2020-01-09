#include<math.h>
#include<GL/glut.h>
int i=750;
bool day=true;
float h=1050;
int engine=1;
int mark[]={0,50,150,250,350,450,550,650,750,850,950,1015};
int build[]={0,10,110,230,350,450,600,700,800,1000};
int car_y=20;
static int mainmenu, submenu1, submenu2;

float buildcolor[3][3] = {
	{0.4, 0.4, 0.48},
	{0, 0.8 , 0.5},
	{0.8, 0.3, 0.3}
};

float carcolor[] = {0, 1, 0};

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
void draw_ring(float x1, float y1, double radius)
{
	float x2,y2, angle;
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
void car()
{
	glColor3f(carcolor[0], carcolor[1], carcolor[2]);
	glBegin(GL_POLYGON);
	int car_x=0;
	if(engine==1)
		 car_x = 0;
	else if(engine==-1)
		 car_x = 600;
	glVertex2f(abs(car_x-100),car_y+30);
	glVertex2f(abs(car_x-100),car_y+80);
	glVertex2f(abs(car_x-105),car_y+95);
	glVertex2f(abs(car_x-115),car_y+100);
	glVertex2f(abs(car_x-145),car_y+100);
	glVertex2f(abs(car_x-160),car_y+140);
	glVertex2f(abs(car_x-260),car_y+140);
	glVertex2f(abs(car_x-265),car_y+135);
	glVertex2f(abs(car_x-320),car_y+100);
	glVertex2f(abs(car_x-400),car_y+90);
	glVertex2f(abs(car_x-405),car_y+85);
	glVertex2f(abs(car_x-415),car_y+30);
	glEnd();
	glColor3f(0, 0, 0);
	draw_ring(abs(car_x-160), 30+car_y, 28);
	glColor3f(1, 1, 1);
	draw_ring(abs(car_x-160), 30+car_y, 20);
	glColor3f(0, 0, 0);
	draw_ring(abs(car_x-300), 30+car_y, 28);
	glColor3f(1, 1, 1);
	draw_ring(abs(car_x-300), 30+car_y, 20);
	if(!day)
	{
		glBegin(GL_POLYGON);
		glColor4f(1,1,0,0.5);
		glVertex2f(abs(car_x-405),75+car_y);
		glVertex2f(abs(car_x-410),65+car_y);
		glColor4f(1,1,1,0.5);
		glVertex2f(abs(car_x-500),50+car_y);
		glVertex2f(abs(car_x-500),90+car_y);
		glEnd();
	}
}
void star(int starpos1,int starpos2)
{
	glColor3f(1,1,1);
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
	star(50,350);
	star(70,450);
	star(100,300);
	star(300,250);
	star(225,400);
	star(600,375);
	star(750,270);
	star(800,390);
	star(950,420);
}
void baseline()
{
	int p;
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2i(0,15);
	glVertex2i(1000,15);
	glVertex2i(1000,75);
	glVertex2i(0,75);
	glEnd();
	glColor3f(0.15,0.15,0.15);
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
	glColor3f(1,1,1);
	for(int i=1;i<=11;i++)
	{
		if(mark[i]<=0)
			mark[i]+=1050;
		else if(mark[i]>1050)
			mark[i]-=1050;
		glBegin(GL_POLYGON);
		glVertex2i(mark[i],35);
		glVertex2i(mark[i],45);
		glVertex2i(mark[i]-50,45);
		glVertex2i(mark[i]-50,35);
		glEnd();
	}
	
	if(engine==1)
		for(p=1;p<=11;p++) mark[p]-=3;
	else if(engine==-1)
		for(p=1;p<=11;p++) mark[p]+=3;
}
void sun()
{
	glColor3f(1, 1, 0);
	draw_ring(500, 375, 45);
}
void building(int a,int b,int c,int d)
{
	glBegin(GL_POLYGON);
	glVertex2i(a,c);
	glVertex2i(b,c);
	glVertex2i(b,d);
	glVertex2i(a,d);
	glEnd();
	if(!day)
		glColor3f(1,1,0);
	else
		glColor3f(0.8,0.8,0.8);

	for(int i=10; i<=180; i+=60) {
		glBegin(GL_POLYGON);
		glVertex2i(a+10,c+i);
		glVertex2i(a+10,c+i+30);
		glVertex2i(a+40,c+i+30);
		glVertex2i(a+40,c+i);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2i(a+60,c+i);
		glVertex2i(a+60,c+i+30);
		glVertex2i(a+90,c+i+30);
		glVertex2i(a+90,c+i);
		glEnd();;
	}
}
void city()
{
	int p;
	for(p=1;p<=9;p++)
	{
		if(build[p]<=-100)
			build[p]+=1100;
		else if(build[p]>1200)
			build[p]-=1100;
	}
	for(int i=1;i<=9;i++)
	{
		int colorIndex=i%3;
		glColor3f(buildcolor[colorIndex][0], buildcolor[colorIndex][1], buildcolor[colorIndex][2]);
		building(build[i],build[i]+100,75,250);
	}
	
	if(engine==1)
		for(p=1;p<=9;p++) build[p]--;
	else
		for(p=1;p<=9;p++) build[p]++;
}
void background()
{
	if(day)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.3, 0.3, 1);
		glVertex2i(0,75);
		glVertex2i(0,500);
		glVertex2i(1000,500);
		glVertex2i(1000,75);
		glEnd();
		sun();
	}
	else
	{
		glBegin(GL_POLYGON);
		glColor3f(0, 0, 0);
		glVertex2i(0,75);
		glVertex2i(0,500);
		glVertex2i(1000,500);
		glVertex2i(1000,75);
		glEnd();
		nightsky();
	}
}
void obj(int i)
{
	int lamppost=i;
	if(i<890)
		lamppost+=1000;
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
	if(!day)
		glColor3f(1,1,0);
	else
		glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2i(lamppost-915,160);
	glVertex2i(lamppost-935,160);
	glVertex2i(lamppost-950,195);
	glVertex2i(lamppost-900,195);
	glEnd();
	if(!day)
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
	glEnd();
	car();
	glFlush();
}
void keyboard(int key, int x, int y)
{
	 switch(key)
	 {
		case GLUT_KEY_LEFT:
			engine=-1;
			break;
		case GLUT_KEY_RIGHT:
			engine=1;
			break;
		case GLUT_KEY_UP:
			if(car_y < 40)
				car_y+=10;
			break;
		case GLUT_KEY_DOWN:
			if(car_y > 0)
				car_y-=10;
			break;
	 }
	 glutPostRedisplay();
}
void disp()
{
	background();
	baseline();
	if(engine==1)
		i-=3;
	else
		i+=3;
	city();
	obj(i);
	glutSwapBuffers();
	glutPostRedisplay();
}

void menu(int selected)
{
	switch(selected)
	{
		case 1:
			day = true;
			break;
		case 2:
			day = false;
			break;
		case 3:
			carcolor[0]=1; carcolor[1]=0; carcolor[2]=0;
			break;
		case 4:
			carcolor[0]=0; carcolor[1]=1; carcolor[2]=0;
			break;
		case 5:
			carcolor[0]=0; carcolor[1]=0; carcolor[2]=1;
			break;
		case 6:
			carcolor[0]=1; carcolor[1]=1; carcolor[2]=0;
			break;
	}
}
void createmenu()
{
	submenu1 = glutCreateMenu(menu);
	glutAddMenuEntry("Day", 1);
	glutAddMenuEntry("Night", 2);
	submenu2 = glutCreateMenu(menu);
	glutAddMenuEntry("Red", 3);
	glutAddMenuEntry("Green", 4);
	glutAddMenuEntry("Blue", 5);
	glutAddMenuEntry("Yellow", 6);
	mainmenu = glutCreateMenu(menu);
	glutAddSubMenu("Day/Night", submenu1);
	glutAddSubMenu("Car Color", submenu2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000,500);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Cargame | Hamed Mahmoudkhani");
	createmenu();
	myinit();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glutDisplayFunc(disp);
	glutSpecialFunc(keyboard);
	glutMainLoop();
	return 0;
}
