#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>

#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

double alpha = 0.0;
double beta = 0.0;
double gama = 0.0;

double depth = 8.0;
double xpos = 0.0;
double ypos = 0.0;
double zpos = depth;

double nx = 0.0;
double ny = 1.0;
double nz = 0.0;

double eyeposi[] = {0.0,0.0,depth};
double upposi[] = {0.0,1.0,0.0};
const float piover180 = 0.01745329f;
int ite = 1, width = 400, height = 400;
bool captureMode = false;

typedef GLbyte* bytePt;
int arrLen = width * height * 3;
GLbyte* colorArr = new GLbyte[arrLen];

void init_light(void)
{
    GLfloat mat_specular [ ] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess [ ] = { 50.0 };
    GLfloat light_position [ ] = { 5.0, 5.0, 5.0, 1.0 };
    glClearColor ( 0.0, 0.0, 0.0, 0.0 );
    glShadeModel ( GL_SMOOTH );
    glMaterialfv ( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv ( GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv ( GL_LIGHT0, GL_POSITION, light_position);
    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);
    glEnable (GL_DEPTH_TEST);
}


void display(void)
{
	GLdouble eyevect[] = { eyeposi[0], eyeposi[1], eyeposi[2] };
	GLdouble upvect[] = { upposi[0], upposi[1], upposi[2] };
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// glColor3f(0, 0, 1.0); 
	glLoadIdentity(); 
	gluLookAt(eyevect[0], eyevect[1], eyevect[2], 0, 0, 0, upvect[0], upvect[1], upvect[2]);
	glutSolidTeapot(2);
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0, (GLfloat)w / (GLfloat)h, 2, 800.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void saveColorData(bytePt& _pt, string _str) {
	FILE* pFile = fopen(_str.c_str(), "wt");
	if (pFile == NULL) { fprintf(stderr, "error \n"); exit(-1); }

	// for (int i = 0; i<width * height * 3; i++) {
	// 	if (colorArr[i] == -1) { colorArr[i] = 255; }
	// }

	for (int i = 0; i<width * height * 3; i++) {
		fprintf(pFile, "%d\n", colorArr[i]);
	}
	fclose(pFile);
	// printf("color data saved! \n");
}

void saveColorData_img(bytePt& _pt, string _str) {
	Mat img(height, width, CV_8UC3);
    vector<cv::Mat> imgPlanes;
    cv::split(img, imgPlanes);
    
    for(int i = 0; i < height; i ++) {
        uchar* plane0Ptr = imgPlanes[0].ptr<uchar>(i);
        uchar* plane1Ptr = imgPlanes[1].ptr<uchar>(i);
        uchar* plane2Ptr = imgPlanes[2].ptr<uchar>(i);
        for(int j = 0; j < width; j ++) {
        int k = 3 * (i * width + j);
            plane2Ptr[j] = _pt[k];
            plane1Ptr[j] = _pt[k+1];
            plane0Ptr[j] = _pt[k+2];
        }
    }
    cv::merge(imgPlanes, img);
    cv::flip(img, img ,0); 
    cv::imwrite(_str.c_str(), img);

}

void captureImage(void) {

	GLint viewPort[4] = { 0 };
	glGetIntegerv(GL_VIEWPORT, viewPort);
	glReadPixels(viewPort[0], viewPort[1], viewPort[2], viewPort[3], GL_RGB, GL_UNSIGNED_BYTE, colorArr);
	// printf("color data read !\n");
	string base = "../output/tmpcolor";
	string ext = ".png";
	stringstream ss;
	ss << base << ite << ext;
	string filename = ss.str();
	cout << filename << endl;
	saveColorData_img(colorArr, filename);
	ite++;

}

void keys(unsigned char key, int x, int y)
{

	if (key == 'a' || key == 'A') {
		alpha -= 2;
		cout << "alpha: " << alpha << "   beta: " << beta << "   depth: " << depth << endl;
		xpos = (double)sin(alpha*piover180) * (double)cos(beta*piover180) * depth;
        ypos = (double)sin(beta*piover180) * depth;
		zpos = (double)cos(alpha*piover180) * (double)cos(beta*piover180) * depth;

        nx = (double)sin((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;
        ny = (double)sin((90-beta)*piover180) * 0.1;
		nz = (double)cos((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;

		eyeposi[0] = xpos;
        eyeposi[1] = ypos;
		eyeposi[2] = zpos;
        upposi[0] = nx;
        upposi[1] = ny;
        upposi[2] = nz;
		display();
		if (captureMode) {
			captureImage();
		}
	}
	if (key == 'd' || key == 'D') {
		alpha += 2;
		cout << "alpha: " << alpha << "   beta: " << beta << "   depth: " << depth << endl;
		xpos = (double)sin(alpha*piover180) * (double)cos(beta*piover180) * depth;
        ypos = (double)sin(beta*piover180) * depth;
		zpos = (double)cos(alpha*piover180) * (double)cos(beta*piover180) * depth;

        nx = (double)sin((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;
        ny = (double)sin((90-beta)*piover180) * 0.1;
		nz = (double)cos((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;

		eyeposi[0] = xpos;
        eyeposi[1] = ypos;
		eyeposi[2] = zpos;
        upposi[0] = nx;
        upposi[1] = ny;
        upposi[2] = nz;
		display();
		if (captureMode) {
			captureImage();
		}
	}
    if (key == 'w' || key == 'W') {
		beta += 1;
        beta < -90 ? beta = -90 : beta;
        beta > 90 ? beta = 90 : beta;
		cout << "alpha: " << alpha << "   beta: " << beta << "   depth: " << depth << endl;
		xpos = (double)sin(alpha*piover180) * (double)cos(beta*piover180) * depth;
        ypos = (double)sin(beta*piover180) * depth;
		zpos = (double)cos(alpha*piover180) * (double)cos(beta*piover180) * depth;

        nx = (double)sin((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;
        ny = (double)sin((90-beta)*piover180) * 0.1;
		nz = (double)cos((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;

		eyeposi[0] = xpos;
        eyeposi[1] = ypos;
		eyeposi[2] = zpos;
        upposi[0] = nx;
        upposi[1] = ny;
        upposi[2] = nz;
		display();
		if (captureMode) {
			captureImage();
		}
	}
    if (key == 's' || key == 'S') {
		beta -= 1;
        beta < -90 ? beta = -90 : beta;
        beta > 90 ? beta = 90 : beta;
		cout << "alpha: " << alpha << "   beta: " << beta << "   depth: " << depth << endl;
		xpos = (double)sin(alpha*piover180) * (double)cos(beta*piover180) * depth;
        ypos = (double)sin(beta*piover180) * depth;
		zpos = (double)cos(alpha*piover180) * (double)cos(beta*piover180) * depth;

        nx = (double)sin((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;
        ny = (double)sin((90-beta)*piover180) * 0.1;
		nz = (double)cos((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;

		eyeposi[0] = xpos;
        eyeposi[1] = ypos;
		eyeposi[2] = zpos;
        upposi[0] = nx;
        upposi[1] = ny;
        upposi[2] = nz;
		display();
		if (captureMode) {
			captureImage();
		}
	}
    if (key == 'q' || key == 'Q') {
		depth -= 0.1;
        depth < 6.0 ? depth = 6.0 : depth;
        depth > 15.0 ? depth = 15.0 : depth;
		cout << "alpha: " << alpha << "   beta: " << beta << "   depth: " << depth << endl;
		xpos = (double)sin(alpha*piover180) * (double)cos(beta*piover180) * depth;
        ypos = (double)sin(beta*piover180) * depth;
		zpos = (double)cos(alpha*piover180) * (double)cos(beta*piover180) * depth;

        nx = (double)sin((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;
        ny = (double)sin((90-beta)*piover180) * 0.1;
		nz = (double)cos((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;

		eyeposi[0] = xpos;
        eyeposi[1] = ypos;
		eyeposi[2] = zpos;
        upposi[0] = nx;
        upposi[1] = ny;
        upposi[2] = nz;
		display();
		if (captureMode) {
			captureImage();
		}
	}
    if (key == 'e' || key == 'E') {
		depth += 0.1;
        depth < 6.0 ? depth = 6.0 : depth;
        depth > 15.0 ? depth = 15.0 : depth;
		cout << "alpha: " << alpha << "   beta: " << beta << "   depth: " << depth << endl;
		xpos = (double)sin(alpha*piover180) * (double)cos(beta*piover180) * depth;
        ypos = (double)sin(beta*piover180) * depth;
		zpos = (double)cos(alpha*piover180) * (double)cos(beta*piover180) * depth;

        nx = (double)sin((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;
        ny = (double)sin((90-beta)*piover180) * 0.1;
		nz = (double)cos((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;

		eyeposi[0] = xpos;
        eyeposi[1] = ypos;
		eyeposi[2] = zpos;
        upposi[0] = nx;
        upposi[1] = ny;
        upposi[2] = nz;
		display();
		if (captureMode) {
			captureImage();
		}
	}

	if (key == 'c' || key == 'C') {
		captureImage();
	}
	if (key == '1') {
		ite = 1;
        for(beta = -90; beta <= 90; beta+= 10)
            for (alpha = 0; alpha < 360; alpha+= 10) {

                cout << "alpha: " << alpha << "   beta: " << beta << "   depth: " << depth << endl;
                xpos = (double)sin(alpha*piover180) * (double)cos(beta*piover180) * depth;
                ypos = (double)sin(beta*piover180) * depth;
                zpos = (double)cos(alpha*piover180) * (double)cos(beta*piover180) * depth;

                nx = (double)sin((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;
                ny = (double)sin((90-beta)*piover180) * 0.1;
                nz = (double)cos((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;

                eyeposi[0] = xpos;
                eyeposi[1] = ypos;
                eyeposi[2] = zpos;
                upposi[0] = nx;
                upposi[1] = ny;
                upposi[2] = nz;
                display();
                captureImage();
            }
	}
	if (key == 'p' || key == 'P') {
		captureMode = !captureMode;
	}
    if (key == 27)
        exit(0);

}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);

	glutInitWindowSize(width, height);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("gluPerspective ( X, , 4,10 )");
    init_light();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keys);
	glutMainLoop();
	return 0;
}

