#include <stdio.h>
#include <GL/glut.h>

#define putpixel(x, y, COLOR) do { \
		glBegin(GL_POINTS); \
		glVertex2i(x,y); \
		glEnd(); \
} while(0);

float xc, yc, r;

// Function to put pixels
// at subsequence points
void drawCircle(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, RED);
	putpixel(xc-x, yc+y, RED);
	putpixel(xc+x, yc-y, RED);
	putpixel(xc-x, yc-y, RED);
	putpixel(xc+y, yc+x, RED);
	putpixel(xc-y, yc+x, RED);
	putpixel(xc+y, yc-x, RED);
	putpixel(xc-y, yc-x, RED);
	glFlush();
}

// Function for circle-generation
// using Bresenham's algorithm
void display(void)
{
	int x = 0, y = r;
	int d = 3 - 2 * r;
	drawCircle(xc, yc, x, y);
	while (y >= x)
	{
		// for each pixel we will
		// draw all eight pixels
		
		x++;

		// check for decision parameter
		// and correspondingly
		// update d, x, y
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawCircle(xc, yc, x, y);
	}
}

void init(void) {
	glClearColor(0.7,0.7,0.7,0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char **argv) {
	printf("Enter xc, yc, r: ");
	scanf("%f %f %f", &xc, &yc, &r);;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham Circle Algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


