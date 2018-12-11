#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
#include <assert.h>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

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
int ite = 1;
bool captureMode = false;

typedef vector<double> Vect;

Vect crossProduct(const Vect& x, const Vect& y)
{
    
    return Vect{x[1]*y[2]-x[2]*y[1], 
                x[2]*y[0]-x[0]*y[2],
                x[0]*y[1]-x[1]*y[0]};
            // uniform initialization, C++11新特性
}
double norm(const Vect& x)
{
    double val = 0.;
    for(auto elem: x)
        val += elem*elem;
    return sqrt(val);
                    // #include <cmath>
}

Vect normVec(const Vect& x){
	double normval = norm(x);
	return Vect{x[0]/normval,x[1]/normval,x[2]/normval};
}

Vect calBaseVec(const double *x, const Vect& yv){
	vector<double> xv;
	for (int i=0;i < sizeof(x);i++){
		xv.push_back(x[i]);
	}
	// vector<double> yv;
	// for (int i=0;i < sizeof(y);i++){
	// 	yv.push_back(y[i]);
	// }
	Vect xyv = crossProduct(xv, yv);
	Vect xyvNorm = normVec(xyv);
	return xyvNorm;
}

void calNewUpposi(void){

	xpos = (double)sin(alpha*piover180) * (double)cos(beta*piover180) * depth;
    ypos = (double)sin(beta*piover180) * depth;
	zpos = (double)cos(alpha*piover180) * (double)cos(beta*piover180) * depth;

    nx = (double)sin((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;
    ny = (double)sin((90-beta)*piover180) * 0.1;
	nz = (double)cos((alpha+180)*piover180) * (double)cos((90-beta)*piover180) * 0.1;

	eyeposi[0] = xpos;
    eyeposi[1] = ypos;
	eyeposi[2] = zpos;

	Vect nxyz;
	nxyz.push_back(nx);
	nxyz.push_back(ny);
	nxyz.push_back(nz);
	Vect veupnorm = calBaseVec(eyeposi,nxyz);
	Vect normupposi;
	normupposi = normVec(nxyz);

	upposi[0] = (double)cos(gama*piover180) * normupposi[0] + (double)sin(gama*piover180) * veupnorm[0];
	upposi[1] = (double)cos(gama*piover180) * normupposi[1] + (double)sin(gama*piover180) * veupnorm[1];
	upposi[2] = (double)cos(gama*piover180) * normupposi[2] + (double)sin(gama*piover180) * veupnorm[2];
}

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

typedef GLbyte* bytePt;
int winWidth = 400;
int winHeight = 400;
int arrLen = winWidth * winHeight * 3;
GLbyte* colorArr = new GLbyte[arrLen];

void saveColorData_img(bytePt& _pt, string _str) {
	Mat img(winHeight, winWidth, CV_8UC3);
    vector<cv::Mat> imgPlanes;
    cv::split(img, imgPlanes);
    
    for(int i = 0; i < winHeight; i ++) {
        uchar* plane0Ptr = imgPlanes[0].ptr<uchar>(i);
        uchar* plane1Ptr = imgPlanes[1].ptr<uchar>(i);
        uchar* plane2Ptr = imgPlanes[2].ptr<uchar>(i);
        for(int j = 0; j < winWidth; j ++) {
        int k = 3 * (i * winWidth + j);
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
	string base = "../output/teapot";
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
		cout << "alpha: " << alpha << "   beta: " << beta <<"	gama: "<< gama << "   depth: " << depth << endl;		
		calNewUpposi();
		display();
		if (captureMode) {
			captureImage();
		}
	}
	if (key == 'd' || key == 'D') {
		alpha += 2;
		cout << "alpha: " << alpha << "   beta: " << beta <<"	gama: "<< gama << "   depth: " << depth << endl;
		calNewUpposi();


		display();
		if (captureMode) {
			captureImage();
		}
	}
    if (key == 'w' || key == 'W') {
		beta += 1;
        beta < -90 ? beta = -90 : beta;
        beta > 90 ? beta = 90 : beta;
		cout << "alpha: " << alpha << "   beta: " << beta <<"	gama: "<< gama << "   depth: " << depth << endl;
		calNewUpposi();
		display();
		if (captureMode) {
			captureImage();
		}
	}
    if (key == 's' || key == 'S') {
		beta -= 1;
        beta < -90 ? beta = -90 : beta;
        beta > 90 ? beta = 90 : beta;
		cout << "alpha: " << alpha << "   beta: " << beta <<"	gama: "<< gama << "   depth: " << depth << endl;
		calNewUpposi();
		display();
		if (captureMode) {
			captureImage();
		}
	}
    if (key == 'q' || key == 'Q') {
		depth -= 0.1;
        depth < 6.0 ? depth = 6.0 : depth;
        depth > 15.0 ? depth = 15.0 : depth;
		cout << "alpha: " << alpha << "   beta: " << beta <<"	gama: "<< gama << "   depth: " << depth << endl;
		calNewUpposi();
		display();
		if (captureMode) {
			captureImage();
		}
	}
    if (key == 'e' || key == 'E') {
		depth += 0.1;
        depth < 6.0 ? depth = 6.0 : depth;
        depth > 15.0 ? depth = 15.0 : depth;
		cout << "alpha: " << alpha << "   beta: " << beta <<"	gama: "<< gama << "   depth: " << depth << endl;
		calNewUpposi();
		display();
		if (captureMode) {
			captureImage();
		}
	}

	if (key == 'r' || key == 'R') {
		gama -= 2;
		gama = gama < -360? (gama + 360):gama;
		cout << "alpha: " << alpha << "   beta: " << beta <<"	gama: "<< gama << "   depth: " << depth << endl;
		calNewUpposi();
		display();
		if (captureMode) {
			captureImage();
		}
	}
	if (key == 't' || key == 'T') {
		gama += 2;
		gama = gama > 360? (gama - 360):gama;
		cout << "alpha: " << alpha << "   beta: " << beta <<"	gama: "<< gama << "   depth: " << depth << endl;
		calNewUpposi();
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
        for(beta = -90; beta <= 90; beta+=10)
            for (alpha = 0; alpha < 360; alpha+=10){
				
				cout << "alpha: " << alpha << "   beta: " << beta <<"	gama: "<< gama << "   depth: " << depth << endl;
				// calEyeAndOriginUPposi();
				for (gama = 0; gama < 360; gama+=10){
					calNewUpposi();
					display();
					captureImage();
				}
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
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("gluPerspective ( X, , 4,10 )");
    init_light();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keys);
	glutMainLoop();
	return 0;
}

