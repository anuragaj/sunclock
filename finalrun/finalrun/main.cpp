#include<math.h>			/*Header files required*/
#include<string.h>
#include <GL/glut.h>

#define Welcomescreen 0		/* Used for toe implementation of Menu*/
#define SideView 1
#define TopView 2
#define QUIT 3

int screen_width=1250;		/*Deafult Screen Size*/
int screen_height=700;

int filling=1;				/* variable that specifies solid(filled) or wired objects,1 for Solid and 0 for Wired*/

int tv,sv,ws=1;				/* variable that specify topview(tv=1),sideview(sv=1) or welcome screen(ws=1)*/

float xshadow=10.0,yshadow=6.0,q1=1,q2,q3,q4; /* parameters that are used to implement top view*/

GLdouble x=-30.0,y=10.0,r=5.0,z1=3.0,sunvalue=0; /* parameters that are used to implement the movement of sun*/


char header[]={"A mini Computer Graphics project on"};
char title[]={"\"Demonstration of Sun Clock using OpenGL\""};
char name1[]={"Submitted by"};
char name2[]={"Name: Anurag A Joshi"};						/* strings that are displayed in the welcome screen*/
char name3[]={"USN: 1SV10CS004"};
char guide1[]={"Under the guidance of"};
char guide2[]={"Mr. SHIVANNA K  B.E.,M.Tech.,MISTE.,"};
char guide3[]={"Sr. LECTURER, Dept of CSE, SIET"};
char guide4[]={"Mr. NOOR BASHA B.E,M.Tech.,MISTE.,"};
char guide5[]={"Sr. LECTURER, Dept of CSE, SIET"};
char note1[]={"NOTE:"};
char note2[]={"Press 'w' or 'W' for Welcome Screen"};
char note3[]={"Press 's' or 'S' for Side View"};
char note4[]={"Press 't' or 'T' for Top View"};
char note5[]={"Press 'r' or 'R' for Wired image"};
char note6[]={"Press 'q' or 'Q' to quit"};
char college1[]={"Department of Computer Science and Engineering"};
char college2[]={"SHRIDEVI  INSTITUTE OF ENGINEERING AND TECHNOLOGY"};
char college3[]={"(Affiliated To Visvesvaraya Technological University)"};
char college4[]={"Sira Road, Tumkur – 572 106, Karnataka"};
char clocknumber1[]={"I"};
char clocknumber2[]={"II"};
char clocknumber3[]={"III"};
char clocknumber4[]={"IV"};
char clocknumber5[]={"V"};
char clocknumber6[]={"VI"};
char clocknumber7[]={"VII"};
char clocknumber8[]={"VII"};
char clocknumber9[]={"VIII"};



void WriteToScreen(char temp[],float r,float g,float b,float font,float x,float y)
{
	int i;
	double length=strlen(temp);

glColor3f(r,g,b);						/*this is a function that takes an array along with color parameters,font and 
										coordinates and display them on the screen as specified*/
glRasterPos2f(x,y);

for(i=0;i<length;i++)
	if(font==24)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,temp[i]);
	else if(font==18)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,temp[i]);
	else if(font==12)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,temp[i]);
	else if(font==10)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,temp[i]);

}


void sun()
{
	if(x>=150.0)					/*this is function which create a sun like object on screen.
									The movement of the sun is also implemented in this function*/
	{
		x=-30.0;
		y=10.0;
		sunvalue=0;
	}
  	x+=0.4;
	if(sunvalue)
		y-=0.2;
	else
		y+=0.2;
if(x>=30.0)
    sunvalue=1;
	
float i;
	
    glColor3d(1.0,1.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3d(x,y,z1);
		for (i=0;i<360;i++)
			glVertex3d(x + sin(i) * r, y + cos(i) * r,z1);
	glEnd();
}
void resize (int width, int height)
{
    screen_width=width; 
    screen_height=height;				/* This function is used to change the camera position according to 
										the size of the screen*/
	
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,screen_width,screen_height); 
    
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
		
	if(screen_width<=screen_height)	
		glOrtho(-40.0,40.0,-50.0*(GLfloat)screen_height/screen_width,50.0*(GLfloat)screen_height/screen_width,-80.0,100.0);
	else
		glOrtho(-40.0*(GLfloat)screen_width/screen_height,40.0*(GLfloat)screen_width/screen_height,-50.0,50.0,-80.0,100.0);
    
	glutPostRedisplay ();
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key)
    {
  
        case 'r': case 'R':					/*This function is used to interface keyboard with the OpenGL window*/
            if (filling==0)
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); 
                filling=1;
            }   
            else 
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_LINE); // Polygon rasterization mode (polygon outlined)
                filling=0;
            }
        break;
		case 's':case 'S':
			sv=1;
			tv=0;
			ws=0;
			break;
		case 'w':case 'W':
			ws=1;
			sv=0;
			tv=0;
			break;
		case 't':case 'T':
			tv=1;
			sv=0;
			ws=0;
			break;
		case 27:
		case 'q':case 'Q':
			exit(0);
		

    }
}
void mountain(float a,float b)
{
	glBegin(GL_TRIANGLES);									/*This function draws mountain like structures
															using triangle,parameter a is mapped to x and b is mapped to z*/
	glColor3f(0.647059,0.164706,0.164706);
	glVertex3f(-a,-10.0,b);
	glVertex3f(-a+10.0,10.0,b);
	glVertex3f(-a+20.0,-10.0,b);
    glEnd();
   
}

void cube(double topwid,double topthick,double legthick,double leglen)
{
	//base cube
  glPushMatrix();
  glColor3f(.50,.50,0.5);						
  glTranslated(30,-50,-15.0);
  glScaled(3.6,topthick+4,5);
  glutSolidCube(4);
  glColor3f(0,0,0);
  glutWireCube(4);
  glPopMatrix();
  
  //top cube
  glPushMatrix();
  glColor3f(.7,.7,.7);
  glTranslated(30,-30,20.0);
  glScaled(0.6,topthick-1,.5);
  glutSolidCube(1);
  glColor3f(0,0,0);
  glutWireCube(1);
  glPopMatrix();
 
}

void sky()
{      
	glBegin(GL_POLYGON); 
	glColor3f(0.5,0.5,0.7);		/* This function draws sky like object*/
	glVertex3f(-60,-9.0,10.0);
	glVertex3f(150.0,-9.0,10.0);
	glVertex3f(150.0,80.0,10.0);
	glVertex3f(-60.0,80.0,10.0);
    glEnd();
}
void grass(){
	
	glBegin(GL_POLYGON); 
	glColor3f(0.0,0.9,0.0);
	glVertex3f(-60,-90.0,10.0);
	glVertex3f(150.0,-90.0,10.0);			/* This function draws grass like object*/
	glVertex3f(150.0,-10.0,10.0);
	glVertex3f(-60.0,-10.0,10.0);
    glEnd();

}
void circle(float a,float b,float z,float r11,float cr,float cg,float cb)
{
	float i;
	
	glColor3d(cr,cg,cb);				/* This is the function which draws cirlce with specified parameters
										a(x),b(y),c(z),r11(radius),cr(red),cg(green),cb(blue)*/
	glBegin(GL_TRIANGLE_FAN);
		glVertex3d(a,b,z);
		for (i=0;i<360;i++)
			glVertex3d(a + sin(i) * r11, b + cos(i) * r11,z);
	glEnd();
}
void clouds1()
{
	glColor3f(1.0,1.0,1.0);
	circle(5,35,5.0,4.0,1.0,1.0,1.0);
	circle(9,36,5.0,5.0,1.0,1.0,1.0);			/*This function draws cloud like structure using cirlce()*/

	circle(13,36,5.0,5.0,1.0,1.0,1.0);
	circle(17,35,5.0,4.0,1.0,1.0,1.0);

	
}
void clouds2()
{
	circle(50,29,-30.0,6.0,1.0,1.0,1.0);
	circle(58,30,-30.0,7.0,1.0,1.0,1.0);			/*This function draws cloud like structure using cirlce()*/

	circle(62,30,-30.0,7.0,1.0,1.0,1.0);
	circle(67,29,-30.0,6.0,1.0,1.0,1.0);

}

void tree()
{
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(-5.0,-40.0);
glVertex2f(-3.0,-40.0);					/*Draws tree like structure*/
glVertex2f(-3.0,-30.0);
glVertex2f(-5.0,-30.0);
glEnd();

circle(-8,-28,0.0,3.0,0.0,0.5,0);
circle(-4,-27,0,4.0,0.0,0.5,0);
circle(0,-28,0.0,3.0,0.0,0.5,0);
circle(-7,-24,0.0,2.0,0.0,.5,0);
circle(-4,-22,0,2.0,0.0,0.5,0);
circle(-1,-24,0.0,2.0,0.0,0.5,0);
circle(-4,-21,0.0,3.0,0.0,0.5,0);

}
void  display(void)
{
    glClearColor(1.0,1.0,1.,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
	if(tv==1){
		
		// grass
		glColor3f(0.0,0.9,0.0);
		glBegin(GL_POLYGON);
		glVertex3f(-80,-80,2.0);
		glVertex3f(120,-80,2.0);
		glVertex3f(120,120,2.0);
		glVertex3f(-80,120,2.0);
		glEnd();

		//base cube
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_POLYGON);
		glVertex3f(-25.0,-25.0,0.0);
		glVertex3f(25.0,-25.0,0.0);
		glVertex3f(25.0,25.0,0.0);
		glVertex3f(-25.0,25.0,0.0);
		glEnd();
		
		//angle
		glPushMatrix();
		glColor3f(.7,.7,.7);
		glTranslated(0.0,2.0,-15.0);
		glScaled(0.6,4,.5);
		glutSolidCube(1);
		glColor3f(0,0,0);
		glutWireCube(1);
		glPopMatrix();

		//shadow
        glColor3f(0.0,0.0,0.0);
		glLineWidth(2.0);
		glBegin(GL_LINES);
		glVertex3f(0.0,0.0,2.0);
		glVertex3f(xshadow,yshadow,2.0);
		glEnd();
	
		if(q1)
		{
			yshadow-=0.02;
			xshadow=10.0;
		}
		else if(q2)
		{
			yshadow-=0.02;
			xshadow-=0.02;
		}
		else if(q3)
		{
			xshadow-=0.02;
			yshadow+=0.02;
		}
		else if(q4)
		{
			double garbage=99999;
			while(--garbage!=0);
			xshadow=10.0;
			yshadow=6.0;
			q1=1;
			q2=q3=q4=0;
		}
		if(yshadow<=-6.0)
		{
			q1=0;
			q2=1;
		}
		if(xshadow<=0.0)
		{
			q1=0;
			q2=0;
			q3=1;
		}
		if(xshadow<=0 && yshadow>=2.0)
		{
			q1=q2=q3=0;
			q4=1;
		}
		WriteToScreen(clocknumber1,0.0,0.0,0.0,18,20,0);
	WriteToScreen(clocknumber2,0.0,0.0,0.0,18,17,-10);
	WriteToScreen(clocknumber3,0.0,0.0,0.0,18,12,-20);
	WriteToScreen(clocknumber4,0.0,0.0,0.0,18,-1,-20);
	WriteToScreen(clocknumber5,0.0,0.0,0.0,18,-12,-20);
	WriteToScreen(clocknumber6,0.0,0.0,0.0,18,-17,-10);
	WriteToScreen(clocknumber7,0.0,0.0,0.0,18,-20,0);
		
}
	else if(sv==1)
	{

	glTranslatef(-33.0,0.0,-50);
	 
	sky();
	clouds1();
    grass();
	sun();
	clouds2();
   
	mountain(-53.0,-30.0);
	mountain(-43.0,-30.0);
	mountain(-33.0,-30.0);
	mountain(-16.0,-30.0);
	mountain(-6.0,-30.0);
	mountain(6.0,-30.0);
	mountain(16.0,-30.0);
	mountain(-63.0,-30.0);
	mountain(-73.0,-30.0);
	mountain(16.0,-30.0);
	mountain(26.0,-30.0);
	mountain(36.0,-25.0);
	mountain(-83.0,-30.0);
	mountain(40.0,-30.0);
	
	tree();
	 
	cube(10,5,3,5);
	
	 

	}
	else if(ws==1)
	{

     
	  WriteToScreen(header,0.0,0.0,0.0,24,-22,40);
	 
	  WriteToScreen(title,0.0,0.0,0.0,18,-21,35);
	 
	  WriteToScreen(name1,0.0,0.0,0.0,18,-7,25);
	  WriteToScreen(name2,0.0,0.0,0.0,12,-7,23);
	  WriteToScreen(name3,0.0,0.0,0.0,12,-7,21);
	  
	  WriteToScreen(guide1,0.0,0.0,0.0,18,-10,12);
	  WriteToScreen(guide2,0.0,0.0,0.0,12,-30,9);
	  WriteToScreen(guide3,0.0,0.0,0.0,12,-30,7);
	  WriteToScreen(guide4,0.0,0.0,0.0,12,8,9);
	  WriteToScreen(guide5,0.0,0.0,0.0,12,8,7);
	 
	 WriteToScreen(note1,0.0,0.0,0.0,12,-64,-30);
	 WriteToScreen(note2,0.0,0.0,0.0,12,-64,-32);
	 WriteToScreen(note3,0.0,0.0,0.0,12,-64,-34);
	 WriteToScreen(note4,0.0,0.0,0.0,12,-64,-36);
	 WriteToScreen(note5,0.0,0.0,0.0,12,-64,-38);
	 WriteToScreen(note6,0.0,0.0,0.0,12,-64,-40);
	 
	 WriteToScreen(college1,0.0,0.0,0.0,18,-20,-30);
	 WriteToScreen(college2,0.0,0.0,0.0,18,-27,-34);
	 WriteToScreen(college3,0.0,0.0,0.0,18,-21,-38);
	 WriteToScreen(college4,0.0,0.0,0.0,18,-14,-42);
	}

    glFlush(); 
    glutSwapBuffers(); 
}
void menu_select(int item)
{
  if (item == QUIT)
    exit(0);
  else if(item==SideView)			/*This function interfaces mouse menu*/
  {
	  sv=1;
	  tv=0;
	  ws=0;
  }
  else if(item==TopView)
  {
	  tv=1;
	  sv=0;
	  ws=0;
  }
  else if(item==Welcomescreen)
  {
	  ws=1;
	  tv=0;
	  sv=0;
  }
  glutPostRedisplay();
}
int main(int argc, char **argv)
{
   
    glutInit(&argc, argv);    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screen_width,screen_height);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Demonstration of SUN CLOCK using OpenGL");
    
	glutDisplayFunc(display);		/* callback functions*/
    glutIdleFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
	
	glutCreateMenu(menu_select);
	glutAddMenuEntry("Welcome Screen",Welcomescreen);
    glutAddMenuEntry("Side View",SideView);
    glutAddMenuEntry("Top View",TopView);				// menu
    glutAddMenuEntry("Quit", QUIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutFullScreen();
   
	
	glutMainLoop();

    return(0);    
}
