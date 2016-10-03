#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

void initFunc();
void funReshape(int w, int h);
void funDisplay();
void funKeyboard(unsigned char key, int x, int y);
void funIdle();
void destroyFunc();

// Variables globales
bool dibujar = true;

int main(int argc, char** argv) {
    
 // Inicializamos GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Sesion 1");
    
 // Inicializamos GLEW
    GLenum err = glewInit();
    if(GLEW_OK != err) printf("Error: %s\n", glewGetErrorString(err));
    printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    const GLubyte *oglVersion = glGetString(GL_VERSION);
    printf("This system supports OpenGL Version: %s\n", oglVersion);
    
 // Inicializaciones específicas
    initFunc();
    
 // Configuración CallBacks
    glutReshapeFunc(funReshape);
    glutDisplayFunc(funDisplay);
    glutKeyboardFunc(funKeyboard);
    glutIdleFunc(funIdle);
    
 // Bucle principal
    glutMainLoop();
    
 // Destrucción de objetos
    destroyFunc();
    
    return(0);
}


void initFunc() {
    
}

void destroyFunc() {
    
}

void funReshape(int w, int h) {
    
    printf("Dimensiones %dx%d pixeles\n", w, h);
    
}

void funDisplay() {
    
 // Borramos el buffer de color
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
 // Dibujamos una tetera con modelo de alambre
    //glColor3f(1.0f, 1.0f, 0.0f);
    glutWireTeapot(1.0f);
    
 // Intercambiamos los buffers
    glutSwapBuffers();
    
}

void funKeyboard(unsigned char key, int x, int y) {
   
    switch(key) {
        case 'r':
            glColor3f(1.0f, 0.0f, 0.0f); 
            break;
        case 'g':
            glColor3f(0.0f, 1.0f, 0.0f);
            break;
        case 'b':
            glColor3f(0.0f, 0.0f, 1.0f);
            break;
        default:
            glColor3f(1.0f, 1.0f, 1.0f); 
    }
    
    glutPostRedisplay();
        
}

void funIdle() {
    
    if(dibujar) {
        glColor3f(1.0f, 1.0f, 1.0f);
        dibujar = false;
    }
    else {
        glColor3f(0.0f, 0.0f, 0.0f);
        dibujar = true;  
    }
    
    Sleep(500);
    
    glutPostRedisplay();
    
}
