#include <random>
#include <glut.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

void speUp(int k, int x, int y);
void spe(int k, int x, int y);

char* lives[20];

bool killed = false;
bool enemykilled = false;
bool abdo = true;
bool poweruptaken = false;

// co-ordinate for the enemy

int x1 = 600.0f;
int x2 = 900.0f;
int x3 = 700.0f;
int x4 = 800.0f;
int x5 = 750.0f;
int x6 = 780.0f;

int live = 2;
// co-ordinate for the bullet of the enemy
int b1 = 740;
int b2 = 760;
int b3 = 1050;
int b4 = 1030;


// power up
int randx;
int randy;


// live par
int l = 1500;


// time when the power up appear
int t = 0;

bool appear = true;

bool up = false;
bool down = false;
bool right = false;
bool left = false;





int x7 = -100;






// co-ordinates for the player
int p1 = 0;  //y co-ordinate 
int p2 = 50;
int p3 = 100;
int p4 = 150;

int z1 = 650;
int z2 = 850;
int z3 = 725;
int z4 = 775;
int z5 = 740;
int z6 = 760;


//co-ordinate fot the bullet of the player
bool isshoted = false;

int playerbullet1 = 0;
int playerbullet2 = 0;
int playerbullet3 = 0;
int playerbullet4 = 0;


int playerbullet5 = 0; 
int playerbullet6 = 0;
int playerbullet7 = 0;
int playerbullet8 = 0;

void randomly() {
	srand(time(0));
	randx = rand() % 1301 + 100;
	randy = rand() % 701 + 100;
}


void Timer(int value) {

	if (live > 0 && l > 0) {

		// bullet kill player
		if (b4 <= p4 && b3 >= p1 &&
			((b2 > z1 && b2 < z2) ||
				(b1 > z1 && b1 < z2))) {
			if (!poweruptaken) {
				live -= 1;
			}
			killed = true;



		}
		//bullet kill enemy
		if (playerbullet2 >= 950 && playerbullet2 <= 1200 &&
			((playerbullet7 > x1 && playerbullet7 < x2) ||
				(playerbullet1 > x1 && playerbullet1 < x2))) {
			l = l - 350;
			enemykilled = true;
		}

		// player get power up
		if (randy <= p4 && (randy + 30) >= p1 &&
			(((randx + 30) > z1 && (randx + 30) < z2) ||
				(randx > z1 && randx < z2))) {
			appear = false;
			poweruptaken = true;
			randomly();
			t = 0;


		}
		if (t >= 40) {

			appear = true;
			poweruptaken = false;
		}

		x1 = x1 + x7;
		x2 = x2 + x7;
		x3 = x3 + x7;
		x4 = x4 + x7;
		x5 = x5 + x7;
		x6 = x6 + x7;
		b3 = b3 - 50;
		b4 = b4 - 50;
		t = t + 2;

		if (x1 == 0) {
			x7 = x7 * (-1);
		}
		if (x2 == 1500) {
			x7 = x7 * (-1);
		}
		if (b3 == 0 || killed) {
			b3 = 950.0f;
			b4 = 930.0f;
			b1 = x5 - 10;
			b2 = x5 + 10;
			killed = false;
		}
		if (playerbullet8 > 1180 || enemykilled) {
			playerbullet1 = z1 + 40;
			playerbullet2 = p4 + 20;
			playerbullet3 = z1 + 60;
			playerbullet4 = p4;

			playerbullet5 = z2 - 40;
			playerbullet6 = p4 + 20;
			playerbullet7 = z2 - 60;
			playerbullet8 = p4;

			enemykilled = false;
			isshoted = false;
		}
		if (isshoted == true) {
			playerbullet2 += 100;
			playerbullet4 += 100;

			playerbullet6 += 100;
			playerbullet8 += 100;

		}
	}
	/*
	* if (playerbullet4 > 1200 || enemykilled) {
		isshoted = false;
		enemykilled = false;
	}
	*/
	
	
	
	


	glutPostRedisplay();
	glutTimerFunc(200, Timer, 0);




}



void print(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}


void Key(unsigned char key, int x, int y);
void Display() {
	if (up && p4 < 870) {
		p1 = p1 + 20;
		p2 = p2 + 20;
		p3 = p3 + 20;
		p4 = p4 + 20;
	}			  
	if (down && p1 > 0) {
		p1 = p1 - 20;
		p2 = p2 - 20;
		p3 = p3 - 20;
		p4 = p4 - 20;
				  
	}			  
	if (left && z1 > 0) {
		z1 = z1 - 20;
		z2 = z2 - 20;
		z3 = z3 - 20;
		z4 = z4 - 20;
		z5 = z5 - 20;
		z6 = z6 - 20;

	}
	if (right && z2 < 1500) {
		z1 = z1 + 20;
		z2 = z2 + 20;
		z3 = z3 + 20;
		z4 = z4 + 20;
		z5 = z5 + 20;
		z6 = z6 + 20;
	}

	glClearColor(0.0f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	/// <summary>
	/// player
	/// </summary>
	if (live >0 && l>0) {

		//power up
		if (poweruptaken) {
			glBegin(GL_QUADS); // player
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(z1-20, p1-20, 0.0f);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(z1 - 20, p4+20, 0.0f);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(z2 + 20, p4+20, 0.0f);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(z2 + 20, p1-20, 0.0f);
			glEnd();


		}




		// par live of an enemy
		glBegin(GL_QUADS); // player
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0, 1180.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0, 1200.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(l, 1200.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(l, 1180.0f, 0.0f);
		glEnd();
		
		//player

		glBegin(GL_QUADS); // player
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(z1, p2, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(z1, p1, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(z2, p1, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(z2, p2, 0.0f);
		glEnd();


		glBegin(GL_QUADS); // player
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(z1, p3, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(z1, p2, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(z2, p2, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(z2, p3, 0.0f);
		glEnd();

		glBegin(GL_QUADS); // player
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(z1, p4, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(z1, p3, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(z2, p3, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(z2, p4, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLES); // player
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(z1, p1, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(z1, p4, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(z1+50, (p1+p4)/2, 0.0f);
		
		glEnd();



		glBegin(GL_QUADS); // player
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(z1+40, p4+20, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(z1+40, p4, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(z1+60, p4, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(z1+60, p4+20, 0.0f);
		glEnd();


		glBegin(GL_QUADS); // player
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(z2-40, p4+20, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(z2-40, p4, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(z2-60, p4, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(z2-60, p4+20, 0.0f);
		glEnd();


		/// <summary>
		/// enemy
		/// </summary>
		

	
		
		


		glBegin(GL_QUADS); 
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(x1, 1180.0f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(x1, 930.0f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(x2, 930.0f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(x2, 1180.0f, 0.0f);
		glEnd();

		glBegin(GL_QUADS);  
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x1, 980.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x1, 950.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x2, 950.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x2, 980.0f, 0.0f);
		glEnd();

		glBegin(GL_QUADS);  
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x1, 1160.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x1, 1130.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x2, 1130.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x2, 1160.0f, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLES); 
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x3, 1025.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x4, 1025.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x5, 1110.0f, 0.0f);

		glEnd();

		glBegin(GL_TRIANGLES); 
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x3, 1085.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x4, 1085.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x5, 1000.0f, 0.0f);

		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x5 - 10, 910.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x5 - 10, 930.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x5 + 10, 930.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(x5 + 10, 910.0f, 0.0f);
		glEnd();

		//enemy bullet

		glBegin(GL_QUADS); // 
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(b1, b3, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(b1, b4, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(b2, b4, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(b2, b3, 0.0f);
		glEnd();


		

		


		//powerup

		if (t >= 40 && appear) {
			glBegin(GL_QUADS);  
			glColor3f(0.5f, 0.5f, 0.5f);
			glVertex3f(randx, randy, 0.0f);
			glColor3f(0.5f, 0.5f, 0.5f);
			glVertex3f(randx, 30 + randy, 0.0f);
			glColor3f(0.5f, 0.5f, 0.5f);
			glVertex3f(30 + randx, 30 + randy, 0.0f);
			glColor3f(0.5f, 0.5f, 0.5f);
			glVertex3f(30 + randx, randy, 0.0f);
			glEnd();

		}


		// player bullet
		if (isshoted) {
			glBegin(GL_QUADS);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(playerbullet1, playerbullet2, 0.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(playerbullet1, playerbullet4, 0.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(playerbullet3, playerbullet4, 0.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(playerbullet3, playerbullet2, 0.0f);
			glEnd();

			glBegin(GL_QUADS);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(playerbullet5, playerbullet6, 0.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(playerbullet5, playerbullet8, 0.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(playerbullet7, playerbullet8, 0.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(playerbullet7, playerbullet6, 0.0f);
			glEnd();
		}

		glColor3f(0.5f, 0.5f, 0.5f);
		sprintf((char*)lives, "Lives: %d", live);
		print(750, 1100, (char*)lives);



		


	}
	else {
	if (live>0) {
		glColor3f(0.5f, 0.5f, 0.5f);
		sprintf((char*)lives,"Congratulations you killed the occupier  ");
		print(590, 600, (char*)lives);

		sprintf((char*)lives, " press enter to start again ");
		print(660, 570, (char*)lives);
	}
	else {
		glColor3f(0.5f, 0.5f, 0.5f);
		sprintf((char*)lives,"Shame on you ");
		print(660, 600, (char*)lives);

		sprintf((char*)lives, " press enter to start again ");
		print(600, 570, (char*)lives);
	}
}
	glFlush();

}


int window;
void main(int argc, char** argr) {
	glutInit(&argc, argr);

	glutInitWindowSize(1500, 1200);
	glutInitWindowPosition(150, 150);
	window=glutCreateWindow("OpenGL - 2D Template");
	glutFullScreen();
	randomly();
	glutDisplayFunc(Display);
	glutKeyboardFunc(Key);
	glutTimerFunc(0, Timer, 0);
	glutSpecialFunc(spe);
	glutSpecialUpFunc(speUp);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, 1500, 0.0, 1200);

	glutMainLoop();
}

void Key(unsigned char key, int x, int y) {
	if (key == 27) {
		glutDestroyWindow(window);
		exit(0);
	}
	if (key == 13) {
		live = 2;
		l = 1500;

		 x1 = 600.0f;
		 x2 = 900.0f;
		 x3 = 700.0f;
		 x4 = 800.0f;
		 x5 = 750.0f;

		 playerbullet1 = 0.0f;
		 playerbullet2 = 0.0f;
		 playerbullet3 = 0.0f;
		 playerbullet4 = 0.0f;
		

		 playerbullet5 = 0.0f;
		 playerbullet6 = 0.0f;
		 playerbullet7 = 0.0f;
		 playerbullet8 = 0.0f;
		 


		 p1 = 0;  
		 p2 = 50;
		 p3 = 100;
		 p4 = 150;

		 z1 = 650;
		 z2 = 850;
		 z3 = 725;
		 z4 = 775;
		 z5 = 740;
		 z6 = 760; 
		
		
		
		 b1 = 740;
		 b2 = 760;
		 b3 = 1050;
		 b4 = 1030;


		 killed = false;
		 enemykilled = false;
		 abdo = true;
		 poweruptaken = false;



		glutPostRedisplay();






	}

	if (key == 'w' && p4 < 900) {
		p1 = p1 + 15;
		p2 = p2 + 15;
		p3 = p3 + 15;
		p4 = p4 + 15;

	}
	if (key == 's' && p1 > 0) {
		p1 = p1 - 15;
		p2 = p2 - 15;
		p3 = p3 - 15;
		p4 = p4 - 15;

	}
	if (key == 'd' && z2 < 1500) {
		z1 = z1 + 10;
		z2 = z2 + 10;
		z3 = z3 + 20;
		z4 = z4 + 20;
		z5 = z5 + 20;
		z6 = z6 + 20;
	}

	if (key == 'a' && z1 > 0) {
		z1 = z1 - 10;
		z2 = z2 - 10;
		z3 = z3 - 20;
		z4 = z4 - 20;
		z5 = z5 - 20;
		z6 = z6 - 20;
	}
	if (key == 32 && isshoted == false) {
		isshoted = true;
		playerbullet1 = z1+40;
		playerbullet2 = p4 + 20;
		playerbullet3 = z1+60;
		playerbullet4 = p4;

		playerbullet5 = z2 - 40;
		playerbullet6 = p4 + 20;
		playerbullet7 = z2 - 60;
		playerbullet8 = p4;
	}
}
void spe(int k, int x, int y)// keyboard special key function takes 3 parameters
							// int k: is the special key pressed such as the keyboard arrows the f1,2,3 and so on
{
	if (k == GLUT_KEY_RIGHT)//if the right arrow is pressed, then the object will be translated in the x axis by 10. (moving right)
		right = true;
	if (k == GLUT_KEY_LEFT)//if the left arrow is pressed, then the object will be translated in the x axis by -10. (moving left)
		left = true;
	if (k == GLUT_KEY_UP)//if the up arrow is pressed, then the object will be translated in the y axis by 10. (moving upwords)
		up = true;
	if (k == GLUT_KEY_DOWN)//if the down arrow is pressed, then the object will be translated in the y axis by -10. (moving downwords)
		down = true;
	
	glutPostRedisplay();//redisplay to update the screen with the changes
}

void speUp(int k, int x, int y)// keyboard special key function is called whenever the special key is released.
{
	if (k == GLUT_KEY_RIGHT)//if the right arrow is pressed, then the object will be translated in the x axis by 10. (moving right)
		right = false;
	if (k == GLUT_KEY_LEFT)//if the left arrow is pressed, then the object will be translated in the x axis by -10. (moving left)
		left = false;
	if (k == GLUT_KEY_UP)//if the up arrow is pressed, then the object will be translated in the y axis by 10. (moving upwords)
		up = false;
	if (k == GLUT_KEY_DOWN)//if the down arrow is pressed, then the object will be translated in the y axis by -10. (moving downwords)
		down = false;
	glutPostRedisplay();//redisplay to update the screen with the changes
}



