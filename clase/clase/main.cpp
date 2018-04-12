//      Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Guevara Chávez Marco Antonio//
//*************	Version: Visual Studio 2015						******//
//************************************************************//

//      Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Guevara Chávez Marco Antonio//
//*************	Version: Visual Studio 2015						******//
//************************************************************//

#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;
int luna = 0;
float camaraZ = 0.0;
float camaraX = 0.0;


GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat mercurioDiffuse[] = { 0.937, 0.286, 0.062, 1.0f };			//mercurio
GLfloat mercurioSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mercurioShininess[] = { 50.0 };

GLfloat venusDiffuse[] = { 0.952, 0.635, 0.203, 1.0f };			//venus
GLfloat venusSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat venusShininess[] = { 50.0 };

GLfloat jupiterDiffuse[] = { 0.517, 0.419, 0.13337, 1.0f };			//jupiter
GLfloat jupiterSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat jupiterShininess[] = { 50.0 };

GLfloat uranoDiffuse[] = { 0.133337, 0.9001, 0.713, 1.0f };			//urano
GLfloat uranoSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat uranoShininess[] = { 50.0 };

GLfloat neptunoDiffuse[] = { 0.145, 0.125, 0.835, 1.0f };			//neptuno
GLfloat neptunoSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat neptunoShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);


	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);//camara
											   //sol								   //sol
	glPushMatrix();
	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
	glDisable(GL_LIGHTING);
	glutSolidSphere(1.9, 30, 30);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//mercurio
	glPushMatrix();
	glRotatef(mercurio, 0, 1, 1);//Traslacion mercurio 
	glTranslatef(5, 0, 0);
	glRotatef(mercurio, 1, 0, 0);//rotacion mercurio 
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mercurioDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mercurioSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mercurioShininess);
	glutWireSphere(0.5, 20, 20);
	glPopMatrix();
	//Venus
	glPushMatrix();
	glRotatef(venus, 0, 1, 1);
	glTranslatef(8, 0, 0);
	glColor3f(0.952, 0.635, 0.203);
	glRotatef(venus, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, venusDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, venusSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, venusShininess);
	glutWireSphere(0.7, 30, 30);
	glPopMatrix();

	//tierra
	glPushMatrix();
	glRotatef(tierra, 0, 1, 1);
	glTranslatef(11, 0, 0);
	glColor3f(0.0705, 0.403, 0.945);
	//glRotatef(tierra, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
	glutWireSphere(0.9, 30, 30);
	glPushMatrix();
	glRotatef(tierra, 0, 1, 1);
	glTranslatef(2, 0, 0);
	glColor3f(1, 1, 1);
	glRotatef(luna, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.4, 30, 30);
	glPopMatrix();
	glPopMatrix();
	//marte
	glPushMatrix();
	glRotatef(marte, 0, 1, 1);
	glTranslatef(14, 0, 0);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(marte, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	//jupiter
	glPushMatrix();
	glRotatef(jupiter, 0, 1, 1);
	glTranslatef(17, 0, 0);
	glColor3f(0.517, 0.419, 0.13337);
	//glRotatef(jupiter, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jupiterDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, jupiterSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, jupiterShininess);
	glutWireSphere(1.3, 30, 30);
	//luna1
	glPushMatrix();
	glRotatef(jupiter, 0, 1, 1);
	glTranslatef(2, 0, 0);
	glColor3f(1, 1, 1);
	glRotatef(luna, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.4, 30, 30);
	glPopMatrix();
	//luna2
	glPushMatrix();
	glRotatef(jupiter, 0, 1, 1);
	glTranslatef(-2, 0, 0);
	glColor3f(1, 1, 1);
	glRotatef(luna, 0, 1, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.4, 30, 30);
	glPopMatrix();
	glPopMatrix();
	//saturno
	glPushMatrix();
	glRotatef(saturno, 0, 1, 1);
	glTranslatef(20, 0, 0);
	glColor3f(1.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	//glRotatef(saturno, 1, 0, 0);
	
	glutWireSphere(1, 30, 30);
	glPushMatrix();

	glColor3f(1, 1, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
	glutWireTorus(.3, 3, 20, 20);
	glRotatef(saturno, 1, 0, 0);
	glPopMatrix();
	glPopMatrix();
	//urano
	glPushMatrix();
	glRotatef(urano, 0, 1, 1);
	glTranslatef(22, 0, 0);
	glColor3f(0.133337, 0.9001, 0.713);
	glRotatef(urano, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, uranoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, uranoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, uranoShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	//neptuno
	glPushMatrix();
	glRotatef(neptuno, 0, 1, 1);
	glTranslatef(25, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, neptunoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, neptunoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, neptunoShininess);
	glRotatef(neptuno, 1, 0, 0);
	glutWireSphere(0.6, 30, 30);
	glPopMatrix();

	glPopMatrix();


	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 8) % 360;
		mercurio = (mercurio - 8) % 360;
		venus = (venus - 7) % 360;
		tierra = (tierra - 6) % 360;
		marte = (marte - 5) % 360;
		jupiter = (jupiter - 4) % 360;
		saturno = (saturno - 3) % 360;
		urano = (urano - 2) % 360;
		neptuno = (neptuno - 1) % 360;
		luna = (luna - 3) % 360;


		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}

