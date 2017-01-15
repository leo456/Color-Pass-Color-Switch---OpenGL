//Jeff Chastinelude <Windows.h>   //  Standard Input\Output C Library
#include <stdarg.h>   //  To use functions with variables arguments
//#include <GL/glut.h>
#include <Windows.h>
#include <GL/glut.h>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include <dos.h >
#include "SOIL.h"
/*#include <allegro5\allegro.h>
#include<allegro5\allegro_native_dialog.h>
#include<allegro5\allegro_audio.h>
#include<allegro5\allegro_acodec.h>
*/
#define M_PI 3.1415926535897932384626433832795
using namespace std;
//ALLEGRO_SAMPLE *soundEffect = al_load_sample("bgsound.wav");
int x=0 , u=0 ,o1,o2 ,b1,b2 ,p1,p2,pp1,pp2,x1,sc=1,ntc;
int my = 0;

char o ,cls , bc;//b = 'p' ;
float up= 0.0 ,bf=10;
float u1 ;
boolean detect = false , pressed = false;
GLuint wicket ,wicket1 ,wicket2,wicket3,back; 
int n = 40 ,n2,y=60 ,col = 1 , p = 0;
float angle =40.0;
double b= 0;

void drawsnow() {
	glBegin(GL_POLYGON);                /* start a new polygon */
	glVertex2f(-0.5, -0.5);             /* vertices of polygon ... */
	glVertex2f(-0.5,  0.5);
	glVertex2f( 0.5,  0.5);
	glVertex2f( 0.5, -0.5);
	glEnd();    
}
void drawstrip()
{
	glLineWidth(170);
	glBegin(GL_LINE);
	glVertex2f(4.00, 10.00);
	glVertex2f(4.00, 40.00);

	glEnd();	
}

static void Timer(int value){

//	if(detect == true)
//	{
//		my+=1;
//	}

	x += 1;
	angle+=10;
	//x1 += 5;
	glutPostRedisplay();
	// 100 milliseconds
	glutTimerFunc(30, Timer, 0);
}

static void Timer2(int value){
	//x1 += 5;
	glutPostRedisplay();
	// 100 milliseconds
	glutTimerFunc(170, Timer, 0);
}

void key(int key ,int x,int y)
{
	if(key =='f')
	{
		glutFullScreen();
	}
	if(key=='g')
	{
		exit(0);
	}
	if(key==GLUT_KEY_UP)
	{
		u+=15;	
		pressed = true;
		// sndPlaySound( NULL, SND_SYNC );
	sndPlaySound( TEXT("jump.wav"), SND_ASYNC );
		//glutPostRedisplay();
	}

}

void drawBitmapText(char *string,float x,float y) 
{  
	char *c;
	glRasterPos2f(x,y);

	for (c=string; *c!='\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}


void cold(char c)
{

/*	if( u+0.0f >=10 && u+0.0f <=17)
	{
		for(int i = 16 ; i<=35 ; i++)
		{
			if(i==o2)
			{
				if(c==b)
				{	 exit(0);
				sc+=1;}
			}
			//	glutFullScreen();
		}
		//	glutFullScreen();
	}*/
	if(u1 >=10 && u1 <=17)//20==b1 && u+0.0f >=10)
	{
		for(int i = 16 ; i<=35 ; i++)
		{
			if(i==b2)
			{
				if(c==b)
				{	 exit(0);
                detect = true;
				sc+=1;
				}
			}
			//	glutFullScreen();
		}
	}
	else if(u1 >=10 && u1 <=17)
	{
		for(int i = 16 ; i<=35 ; i++)
		{
			if(i==p2)
			{
//				if(c==b)
				//{	 
				//	exit(0);
				sc+=1;
				//}
			}
			//	glutFullScreen();
		}
		//	glutFullScreen();
	}
	if( u1 >=10 && u1 <=17)//  (33 == pp2 || 30 == pp2 || ) // pp1>=20 && 20 <=pp2 && u+0.0f >=10  )// || 20==pp1 ||20==pp2 ||
	{	
		//exit(0);
		for(int i = 16 ; i<=35 ; i++)
		{
			if(i==pp2)
			{
				if(c == b)
				{//exit(0);
				sc+=1;}
				//glColor3f(0,  0 , 1);
				//glLoadIdentity();
				//drawBitmapText("hello",50,50);
				//printw(50, 50, 0, "%s", "printw helps you print characters");
				//glutSwapBuffers();
				//char a = 'a';
				//glutStrokeCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(int)a);
			}
		}
		//
	}
}

// level 1
void rectPurp(int y,int sp)
{
	//glColor3f(128,0,128);
	glBegin(GL_QUADS);
//	glColor3f(128,0,128);
	glColor3f(0.73,0.16, 0.96);
	glVertex2f(-55+x+sp, y-u);
	glVertex2f(-30+x+sp, y-u);
	glVertex2f(-30+x+sp, y+3-u);
	glVertex2f(-55+x+sp, y+3-u);
	glEnd();
	pp1 = -55+x;
	pp2 = -30+x;
	char c = 'p';
	cold(c);
}
void rectblue(int y,int sp)
{ 
	
	//glColor3f(128,0,128);
	glBegin(GL_QUADS);
	glColor3f(0 , 240 ,246);
	glVertex2f(-30+x+sp, y-u);
	glVertex2f(-5+x+sp, y-u);
	glVertex2f(-5+x+sp, y+3-u);
	glVertex2f(-30+x+sp, y+3-u);

	glEnd();
	b1 = -30+x;
	b2 = -5+x;
	char c = 'b';
	cold(c);
}

void rectorange(int y,int sp)
{
	//glColor3f(128,0,128);
	glBegin(GL_QUADS);
	glColor3f(255 , 215 ,0);
	//You can set RGB color for you vertex
	//glColor3f(0.73,0.16, 0.96); 
	glVertex2f(-5+x+sp, y-u);
	glVertex2f(20+x+sp, y-u);
	glVertex2f(20+x+sp, y+3-u);
	glVertex2f(-5+x+sp, y+3-u);
	glEnd();
	o1 = -5+x;
	o2 = 20+x;
	char c = 'o';
	cold(c);
}

void rectPink(int y,int sp)
{
	//glColor3f(128,0,128);
	glBegin(GL_QUADS);
	// glColor3f(0 , 240 ,246);
	//You can set RGB color for you vertex
	//glColor3f(0.73,0.16, 0.96); 
	glColor3f(128,0,128);
	glVertex2f(20+x+sp, y-u);
	glVertex2f(45+x+sp, y-u);
	glVertex2f(45+x+sp, y+3-u);
	glVertex2f(20+x+sp, y+3-u);
	glEnd();
	p1 = 20+x;
	p2 = 55;
	if(x%10==0)
	{
		detect = true;
		 ntc = x;
	}
	else 
	detect = false;
	
	char c = 'k';
	cold(c);

}

void circle()
{
	int n = 100 ,v; 
	float r = 10.0f ;
	up +=u;
	float pi = 2.0*3.1452423;
	//glMatrix(Mode(Gl_MODELVIEW));
	//glLoadIdentity
	glBegin(GL_TRIANGLE_FAN);

	glColor3d(0,0,1);
	if(sc%4==0)
	{
		v = rand() % 4 + 1;
		if(v==1)//purple
		{
			glColor3f(1,0,1);
			b='p';
		}

		else if(v==2) // orange
		{
			glColor3f(255 , 215 ,0);
			b='o';
		}
		else if(v==3) // blue
		{
			glColor3f(0 , 240 ,246);
			b = 'b';
		} 
		else if(v==4)
		{
			glColor3f(0.73,0.16, 0.96); // pink
			b='k';
		}
	}
	//float u1 = u+(-40.0);
if(u1>0)
{}
else
	u1 = u+(-40.0);
	
	glVertex2f(10,u1);

	for(int i = 0; i<=n ; i++)
	{
		glVertex2f(bf+r/2.5*cosf(i*pi/n),u1+r/2*sinf(i*pi/n));
	}
	//cold();
	glEnd();
	//glFlush();
}

void draw(int f , int z)
{
    rectPink(f,-15-z);
	rectorange(f,-15-z);
    rectblue(f,-15-z);
    rectPurp(f,-15-z);
}
//void banja_yar()
//{
//	for(int i = 0 ; i < 50 ; i+9)
//draw(10+i,0);
//}

void blue()
{
	glColor3f(0 , 240 ,246);
}
void pink()
{
	glColor3f(128,0,128);
}

void orange()
{
	glColor3f(255 , 215 ,0);
}

void purple()
{
	glColor3f(0.73,0.16, 0.96);
}
void colorS()
{
	void blue();
}
void texture1()
{
	glEnable(GL_TEXTURE_2D);	
	//	glClear(GL_COLOR_BUFFER_BIT);

	wicket = SOIL_load_OGL_texture(
		"pink.png",
	        SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wicket);
	
	glPushMatrix();
	
	//if(pressed)
	//{y+=10;}
	glTranslatef(n,0,0);
    
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex2i(0,0);

	glTexCoord2d(0,1);
	glVertex2i(0, 2);

    
	glTexCoord2d(1, 1);
	glVertex2i(30, 2);

	glTexCoord2d(1, 0);
	glVertex2i(30, 0);
	
	glEnd();
	glPopMatrix();

//glEnable(GL_TEXTURE_2D);	
	//	glClear(GL_COLOR_BUFFER_BIT);

	wicket1 = SOIL_load_OGL_texture(
		"yellow.png",
	        SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wicket1);
	
	glPushMatrix();

	glTranslatef(n,0,0);
    
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex2i(30,0);

	glTexCoord2d(0,1);
	glVertex2i(30, 2);

    
	glTexCoord2d(1, 1);
	glVertex2i(60, 2);

	glTexCoord2d(1, 0);
	glVertex2i(60, 0);
	
	glEnd();
	glPopMatrix();


	wicket2 = SOIL_load_OGL_texture(
		"blue.png",
	        SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wicket2);
	
	glPushMatrix();

	glTranslatef(n,0,0);
    
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex2i(60,0);

	glTexCoord2d(0,1);
	glVertex2i(60, 2);

    
	glTexCoord2d(1, 1);
	glVertex2i(90, 2);

	glTexCoord2d(1, 0);
	glVertex2i(90, 0);
	
	glEnd();
	glPopMatrix();



	wicket3 = SOIL_load_OGL_texture(
		"purple.png",
	        SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wicket3);
	
	glPushMatrix();

	glTranslatef(n,0,0);
    
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex2i(90,0);

	glTexCoord2d(0,1);
	glVertex2i(90, 2);

    
	glTexCoord2d(1, 1);
	glVertex2i(120, 2);

	glTexCoord2d(1, 0);
	glVertex2i(120, 0);
	
	glEnd();
	glPopMatrix();

//pressed = false;
}

void texball()
{
	glEnable(GL_TEXTURE_2D);	
		//glClear(GL_COLOR_BUFFER_BIT);

	wicket = SOIL_load_OGL_texture(
		"ballw copy12.png",
	        SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	//glColor3f(1, 1, 1);
	//colorS();
		if(col == 1)
	{blue();
	bc='b';}
	else if(col == 2)
	{pink();
		bc='k';}
	else if(col == 3)
	{orange();
	bc='o';}
	else if(col==4)
	{purple();
	bc='p';}
	//bc = 'b';
	glBindTexture(GL_TEXTURE_2D, wicket);
	
	glPushMatrix();
	if(u>40)
	{glTranslatef(10,40,0);
	u-=1.85;
	glTranslatef(10,u,0);
	//u-=2;
	//glTranslatef(0,u,0);
	}
	else

	{glTranslatef(10,u-8,0);
	  //	glTranslatef(0,u-6,0);
		//glTranslatef(0,u-4,0);
	// glTranslatef(0,u-6,0);
	//uy+=u
    u-=1.85;
   glTranslatef(0,u,0);
   //u-=2;
	//glTranslatef(0,u,0);
	}
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex2i(31,0);

	glTexCoord2d(0,1);
	glVertex2i(31, 8);

    
	glTexCoord2d(1, 1);
	glVertex2i(40, 8);

	glTexCoord2d(1, 0);
	glVertex2i(40, 0);
	
	glEnd();
	glPopMatrix();

}

void texbox()
{
	glEnable(GL_TEXTURE_2D);	
		//glClear(GL_COLOR_BUFFER_BIT);

	wicket = SOIL_load_OGL_texture(
		"box1w copy.png",
	        SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
//	glColor3f(1, 0, 0);
	if(x>1&&x<=8)
	{blue();
	cls ='b';}
	else if(x>8&&x<=15)
	{pink();
	cls ='k';}
	else if(x>15&&x<=20)
	{orange();
	cls ='o';}
	else if(x>20&&x<25)
	{purple();
	cls ='p';}
	
	//pink();
	glBindTexture(GL_TEXTURE_2D, wicket);
	
	glPushMatrix();
	
//	glTranslatef(150,0,0);
    	glTranslatef(200,110,0);
     //glTranslatef(0.5,0.5,0.0);
  glRotatef(angle-4,0.0,0.0,1.0);

	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex2i(-13,-13);

	glTexCoord2d(0,1);
	glVertex2i(-13, 13);

    
	glTexCoord2d(1, 1);
	glVertex2i(13, 13);

	glTexCoord2d(1, 0);
	glVertex2i(13, -13);
	
	glEnd();
	glPopMatrix();

}

void textCircle()
{
	glEnable(GL_TEXTURE_2D);	
	//	glClear(GL_COLOR_BUFFER_BIT);

	wicket = SOIL_load_OGL_texture(
		"objectw copy.png",
	        SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
//	glColor3f(1, 1, 0);
	//colorS();
	//blue();
		if(x>1&&x<=10)
	{blue();
	cls ='b';}
	else if(x>10&&x<=20)
	{pink();
	cls ='k';}
	else if(x>10&&x<=20)
	{orange();
	cls ='o';}
	else if(x>20&&x<25)
	{purple();
	cls ='p';}

	glBindTexture(GL_TEXTURE_2D, wicket);
	
	glPushMatrix();

	glTranslatef(150,0,0);
    
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex2i(31,0);

	glTexCoord2d(0,1);
	glVertex2i(65, 0);

    
	glTexCoord2d(1, 1);
	glVertex2i(65, 30);

	glTexCoord2d(1, 0);
	glVertex2i(31, 30);
	
	glEnd();
	glPopMatrix();
}

void textCross()
{
	glEnable(GL_TEXTURE_2D);	
	//	glClear(GL_COLOR_BUFFER_BIT);

	wicket = SOIL_load_OGL_texture(
		"cross1w.png",
	        SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	//glColor3f(1, 1, 0);
	if(x>1&&x<=6)
	{blue();
	cls ='b';}
	else if(x>6&&x<=12)
	{pink();
	cls ='k';}
	else if(x>12&&x<=19)
	{orange();
	cls ='o';}
	else if(x>19&&x<25)
	{purple();
	cls ='p';}
	
	glBindTexture(GL_TEXTURE_2D, wicket);
	
	glPushMatrix();

	glTranslatef(190,60,0);
     //glTranslatef(0.5,0.5,0.0);
  glRotatef(angle,0.0,0.0,1.0);
 //glTranslatef(-0.5,-0.5,0.0);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex2i(-12,-14);

	glTexCoord2d(0,1);
	glVertex2i(12, -14);

    
	glTexCoord2d(1, 1);
	glVertex2i(12, 14);

	glTexCoord2d(1, 0);
	glVertex2i(-12, 14);
	
	glEnd();
 //glTranslatef(-150,-40,0.0);
	//glTranslatef(-0.5,-0.5,0.0);
	//glTranslatef(-0.5,-0.5,0.0);
	glPopMatrix();
}

void texStar()
{
	glEnable(GL_TEXTURE_2D);	
	//	glClear(GL_COLOR_BUFFER_BIT);

	wicket = SOIL_load_OGL_texture(
		"star1.png",
	        SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	//glColor3f(1, 0, 0);
	//blue();
	pink();
	glBindTexture(GL_TEXTURE_2D, wicket);
	
	glPushMatrix();

	glTranslatef(200,140,0);
     //glTranslatef(0.5,0.5,0.0);
  //glRotatef(angle,0.0,0.0,1.0);
 //glTranslatef(-0.5,-0.5,0.0);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex2i(-5,-5);

	glTexCoord2d(0,1);
	glVertex2i(5, -5);

    
	glTexCoord2d(1, 1);
	glVertex2i(5, 5);

	glTexCoord2d(1, 0);
	glVertex2i(-5, 5);
	
	glEnd();
 //glTranslatef(-150,-40,0.0);
	//glTranslatef(-0.5,-0.5,0.0);
	//glTranslatef(-0.5,-0.5,0.0);
	glPopMatrix();
}

void texCs()
{
	glEnable(GL_TEXTURE_2D);	
	//	glClear(GL_COLOR_BUFFER_BIT);

	wicket = SOIL_load_OGL_texture(
		"cs1.png",
	        SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wicket);
	
	glPushMatrix();

	glTranslatef(200,150,0);
     //glTranslatef(0.5,0.5,0.0);
  //glRotatef(angle,0.0,0.0,1.0);
 //glTranslatef(-0.5,-0.5,0.0);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex2i(-3,-3);

	glTexCoord2d(0,1);
	glVertex2i(3, -3);

    
	glTexCoord2d(1, 1);
	glVertex2i(3, 3);

	glTexCoord2d(1, 0);
	glVertex2i(-3, 3);
	
	glEnd();
 //glTranslatef(-150,-40,0.0);
	//glTranslatef(-0.5,-0.5,0.0);
	//glTranslatef(-0.5,-0.5,0.0);
	glPopMatrix();
}
void t1()
{
	if(pressed)
	{
		y = y -8.5;
	}
    
	glPushMatrix();
	glTranslatef(-150,y,0);
	//texture1();
	textCircle();
	texbox();
	textCross();
	texStar();
	texCs();
	pressed = false;
	n = n-15;
	glPopMatrix();
	/*glPushMatrix();
	glTranslatef(-40,0,0);
	texture1();
	n = n-10;
	glPopMatrix();*/
	//n2 = n+5;
	
}
void drawCircle(GLfloat x, GLfloat y, GLfloat r) {
    static const double inc = M_PI / 12;
    static const double max = 2 * M_PI;
	glLineWidth(5.0);
	glColor3f(1, 0, 0.96);
	glBegin(GL_LINE_LOOP);
    for(double d = 0; d < max; d += inc) {
        glVertex2f(cos(d) * r + x, sin(d) * r + y);
    }
    glEnd();
}

void backtex() {


	back = SOIL_load_OGL_texture(
		"beanback.png",
		SOIL_LOAD_RGBA,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

}

void background(double b) {
	
	//backtex();
	back = SOIL_load_OGL_texture(
		"intr2.png",
		SOIL_LOAD_RGBA,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	

	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, b);
	glVertex2d(0, 0);
	glTexCoord2d(1 , b);
	glVertex2d(100, 0);
	glTexCoord2d(1 , 1+b);
	glVertex2d(100, 100);
	glTexCoord2d(0, 1+b);
	glVertex2d(0, 100);
	glEnd();
	
}

void background2() {

	background(b);
	b=b+0.03;
	if (b >= 1)
		b = 0;
		
}

/*void blue()
{
	glColor3f(0 , 240 ,246);
}*/


void colide()
{
	p=u;
	//printf("\p = %d",p);
	int d = p%40;
	if(d == 0 && p!=0)
	{//printf("d = %d",d);
		if(cls != bc)
		{
			//exit(0);
			printf("true");
		}
		else
			printf("false");
	}
}
void display() {
	glEnable(GL_TEXTURE_2D);
	glClear(GL_COLOR_BUFFER_BIT); // Fills the scene with blue.
	//update();
	glLoadIdentity();
	//glColor3d(205, 100, 0);
	glOrtho(0,100, 0, 100, 100,-100);
	if(n<40)
	{
	n = 200;
	}

if(y <-100)
{
	y = 80;
	col+=1;
	if(col > 4)
		col = 1;
}
if(x>25)
{
	x=1;
}
	//	background2();
	
//	background2();
	//blue();
	//texbox();
	t1();
	//drawCircle(20,40,10);
	texball();
	colide();
	circle();
	//textCircle();
	//circle();
	//drawCircle(20,40,10);
	

	/*if(n<-20)
	{
	n = 200;
	
	}*/
	//background2();
	
//drawCircle(20,40,10);	
	//draw(20,0);
/*


	circle();
	//	cold();
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glFlush();
	//glutKeyboardFunc(key);
	
	//background2();
	glutSwapBuffers();
}
*/glutSwapBuffers();
	}

/*
* This method is called from main() to initialize OpenGL.
*/
void init() 
{
	glClearColor(0.21f, 0.21f, 0.21, 1);
	// The next three lines set up the coordinates system.
	
//	glClearColor(0.75, 0.75, 0.75, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//
	//glOrtho(0, 500, 0, 500, 500, -500);
}


int main(int argc, char** argv) {
	
	sndPlaySound( TEXT("bgsound.wav"), SND_ASYNC|SND_LOOP );
	glutInitWindowSize(500, 600);
	//al_install_audio();
	//al_init_acodec_addon();

	//al_reserve_samples(1);
	//al_play_sample(soundEffect,1.0f,0.0f,1.0f,ALLEGRO_PLAYMODE_LOOP,0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Hierarchical Modeling 2D Example");
	//init();

	
	glutDisplayFunc(display);
   //glutDisplayFunc(draw);
	Timer(0);
	//glutPostRedisplay();
	//glutKeyboardFunc(key);

	glutSpecialFunc(key);
	//al_destroy_sample(soundEffect);
	init();
	glutMainLoop();
	return 0;
}