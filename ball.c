
#include<math.h>

#include<stdio.h>

#include <GL/glut.h>

#include <stdlib.h>
struct sphere
{
    float xvel;
    float yvel;
    float x;
    float y;
    int count;
    int r;
}s[50]={5,7,0.0,0.0,0,0};
int n=0,hello=0,array[100],ai=0;
float f=0.0002,temp=0,g=0,F=.1;
float cx=-1.3,cy=-1.3,k=0;
int inp=1;
void init(void)
{
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat light_position[] = { 1.0, 1.0, 2.5, 0.0 };
GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
glClearColor(0.0, 0.0, 0.0, 0.0);
glShadeModel(GL_SMOOTH);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (w <= h)
glOrtho(-1.5, 1.5, -1.5,1.5, -10.0, 10.0);
else
glOrtho(-1.5,1.5, -1.5, 1.5, -10.0, 10.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void input(char key)
{
    switch(key)
    {
        case 'w':   if(cy<1.3)
                    cy+=0.1;
                    break;
         case 's':   if(cy>-1.3)
                    cy-=0.1;
                    break;
         case 'd':   if(cx<1.3)
                    cx+=0.1;
                    break;
         case 'a':   if(cx>-1.3)
                    cx-=0.1;
                    break;
        default:break;
    }
}

void display(void)
{
     g+=F*2;
    int m,i,j;
    float x1,x2,y1,y2,dist=0.16,dist2;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
for(m=0;m<=n;m++)
{
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(s[m].x,s[m].y,-cx);
    glutSolidSphere(0.075, 20, 16);
    glPopMatrix();
}
for(m=0;m<=n;m++)
{
    if(s[m].x<=-1.4)
    {

        if(s[m].r==0)
        {
            n=n+1;
            s[n].x=0.0;
            s[n].y=1.4;
            s[n].yvel=n%10;
            s[n].xvel=10-n%10;
            s[m].r=1;
        }
        s[m].xvel=-s[m].xvel;
    }
    if(s[m].x>=1.4)
    {
        s[m].xvel=-s[m].xvel;
    }
    if(s[m].y<=-1.4)
    {
        s[m].yvel=-s[m].yvel;
    }
    if(s[m].y>=1.4)
    {
        s[m].yvel=-s[m].yvel;
    }
    s[m].x+=f*s[m].xvel;
    s[m].y+=f*s[m].yvel;
}
glPushMatrix();
glTranslatef(cx,cy,cx);
glColor3f(.0,.0,.0);
glutSolidSphere(0.15,40,16);
glPopMatrix();




for(i=0;i<=n;i++)
{
    dist2=sqrt((cx-s[i].x)*(cx-s[i].x)+(cy-s[i].y)*(cy-s[i].y));
    if((0.15+0.075)>dist2)
    {
    exit(0);
        
    }
    for(j=0;j<=n;j++)
    {
        if(i!=j)
        {
         x1=s[i].x;
         x2=s[j].x;
         y1=s[i].y;
         y2=s[j].y;
         dist2=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
         
         if(dist>dist2)
         {
             
             
             if(hello!=j&&temp!=i)
             {
             s[i].xvel=-s[i].xvel;
             s[j].xvel=-s[j].xvel;
             s[i].yvel=-s[i].yvel;
             s[j].yvel=-s[j].yvel;
             hello=j;
             temp=i;
             }
             
             
         }
          
        }
    }

}


glFlush();
glutPostRedisplay();

}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(750, 750);
glutInitWindowPosition(100, 25);
glutCreateWindow("krrish");
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(input);
glutMainLoop();
return 0;
}


