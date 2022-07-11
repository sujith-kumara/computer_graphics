#include<stdio.h>
#include<GL/glut.h>
float x1,x2,y1,y2;
void display(void)
{
int dx = x2-x1,dy = y2-y1,x = x1,y=y1;
int p = 2*dy-dx;
while (x<=x2){
  if(p>=0){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    y++;
    p+=2*(dy-dx);
   }
  else{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    p+=2*dy;
    }
  x++;
}
glFlush();
}
void init(void)
{
glClearColor(0.7,0.7,0.7,0.7);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}
int main(int argc,char** argv){
printf("Enter the value of x1:");
scanf("%f",&x1);
printf("Enter the value of y1:");
scanf("%f",&y1);
printf("Enter the value of x2:");
scanf("%f",&x2);
printf("Enter the value of y2:");
scanf("%f",&y2);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("Bresenham Line Drawing Algorithm");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}


