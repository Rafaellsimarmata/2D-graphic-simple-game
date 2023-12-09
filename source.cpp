#include <glut.h>

int x = 0;
int y = 0;
int x1 = 0;
int y1 = 0;

int checkPointYellow_up = 300;
int checkPointYellow_down = 200;
int checkPointYellow_left = 190;
int checkPointYellow_right = 290;


int checkPointGreen_up = 300;
int checkPointGreen_down = 200;
int checkPointGreen_left = 360;
int checkPointGreen_right = 460;

int upperYellow = 492;
int lowerYellow = 432;
int leftYellow = 9;
int rightYellow = 69;

int upperGreen = 62;
int lowerGreen = 2;
int leftGreen = 580;
int rightGreen = 640;

bool done = false;
bool doneYellow = false;
bool doneGreen = false;

void write(float x, float y, float z, void* font, const char* string) {
    const char* c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void oktagonYellow() {
    glColor3ub(255, 255, 0);
    glBegin(GL_POLYGON);
    glVertex2f(9 + x, 475 + y);
    glVertex2f(9 + x, 450 + y);
    glVertex2f(26 + x, 432 + y);
    glVertex2f(52 + x, 432 + y);
    glVertex2f(69 + x, 450 + y);
    glVertex2f(69 + x, 475 + y);
    glVertex2f(52 + x, 492 + y);
    glVertex2f(26 + x, 492 + y);
    glEnd();
}

void oktagonGreen() {
    glColor3ub(0, 255, 0);
    glBegin(GL_POLYGON);
    glVertex2f(580 + x1, 45 + y1);
    glVertex2f(580 + x1, 20 + y1);
    glVertex2f(598 + x1, 2 + y1);
    glVertex2f(622 + x1, 2 + y1);
    glVertex2f(640 + x1, 20 + y1);
    glVertex2f(640 + x1, 45 + y1);
    glVertex2f(622 + x1, 62 + y1);
    glVertex2f(598 + x1, 62 + y1);
    glEnd();
}

void userdraw() {
    glColor3ub(120, 120, 0);
    glBegin(GL_LINES);
    glVertex2f(0, 240);
    glVertex2f(640, 240);
    glEnd();

    glColor3ub(120, 120, 0);
    glBegin(GL_LINES);
    glVertex2f(320, 0);
    glVertex2f(320, 480);
    glEnd();

    // BOX A
    glColor3ub(255, 255, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(190, 200);
    glVertex2f(290, 200);
    glVertex2f(290, 300);
    glVertex2f(190, 300);
    glEnd();
    // BOX A

    // BOX B
    glColor3ub(0, 255, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(360, 200);
    glVertex2f(460, 200);
    glVertex2f(460, 300);
    glVertex2f(360, 300);
    glEnd();
    // BOX B
    oktagonYellow();
    oktagonGreen();

    if (!doneGreen || !doneYellow) write(0.0f, 2.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Place Octagon Inside Square");

    if (upperYellow < checkPointYellow_up && lowerYellow > checkPointYellow_down && leftYellow > checkPointYellow_left && rightYellow < checkPointYellow_right) {
        doneYellow = true;
        write(0.0f, 18.0f, 1.0f, GLUT_BITMAP_HELVETICA_18, "Done Yellow");
    }

    if (upperGreen < checkPointGreen_up && lowerGreen > checkPointGreen_down && leftGreen > checkPointGreen_left && rightGreen < checkPointGreen_right) {
        doneGreen = true;
        write(150.0f, 18.0f, 1.0f, GLUT_BITMAP_HELVETICA_18, "Done Green");
    }

    if (doneGreen && doneYellow) {
        done = true;
        write(320.0f, 450.0f, 1.0f, GLUT_BITMAP_HELVETICA_18, "You Win");
        write(400.0f, 18.0f, 1.0f, GLUT_BITMAP_HELVETICA_18, "Press Space to Reset");
    }

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    userdraw();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int, int) {
    switch (key) {
    case 'w': if (upperYellow + 2 >= 0 && upperYellow + 2 <= 500) {
        upperYellow += 2;
        lowerYellow += 2;
        y += 2; // Move oktagon yellow up
        break;
    } break;
    case 'a': if (leftYellow - 2 >= 0 && leftYellow - 2 <= 650) {
        leftYellow -= 2;
        rightYellow -= 2;
        x -= 2;
        break; // Move oktagon yellow left
    }break;
    case 's': if (lowerYellow - 2 >= 0 && lowerYellow - 2 <= 500) {
        lowerYellow -= 2;
        upperYellow -= 2;
        y -= 2;
        break; // Move oktagon yellow down
    }break;
    case 'd': if (rightYellow + 2 >= 0 && rightYellow + 2 <= 650) {
        rightYellow += 2;
        leftYellow += 2;
        x += 2;
        break; // Move oktagon yellow right
    }break;
    case 32: if (done) {
        x = 0;
        y = 0;
        x1 = 0;
        y1 = 0;

        upperYellow = 492;
        lowerYellow = 432;
        leftYellow = 9;
        rightYellow = 69;

        upperGreen = 62;
        lowerGreen = 2;
        leftGreen = 580;
        rightGreen = 640;

        done = false;
        doneYellow = false;
        doneGreen = false;
        break; // Move oktagon yellow right
    }break;
    }


    glutPostRedisplay(); // Redraw the scene
}

void specialKeyboard(int key, int, int) {
    switch (key) {
    case GLUT_KEY_UP: if (upperGreen + 2 >= 0 && upperGreen + 2 <= 500) {
        upperGreen += 2;
        lowerGreen += 2;
        y1 += 2; // Move oktagon yellow up
        break;
    } break;
    case GLUT_KEY_LEFT: if (leftGreen - 2 >= 0 && leftGreen - 2 <= 650) {
        leftGreen -= 2;
        rightGreen -= 2;
        x1 -= 2;
        break; // Move oktagon yellow left
    }break;
    case GLUT_KEY_DOWN: if (lowerGreen - 2 >= 0 && lowerGreen - 2 <= 500) {
        lowerGreen -= 2;
        upperGreen -= 2;
        y1 -= 2;
        break; // Move oktagon yellow down
    }break;
    case GLUT_KEY_RIGHT: if (rightGreen + 2 >= 0 && rightGreen + 2 <= 650) {
        rightGreen += 2;
        leftGreen += 2;
        x1 += 2;
        break; // Move oktagon yellow right
    }break;
    }

    glutPostRedisplay(); // Redraw the scene
}




int main() {
    glutInit(&__argc, __argv);
    glutInitWindowSize(650, 500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Project Pertama Lab Grafika Komputer");
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(0, 650, 0, 500);

    glutIdleFunc(display);
    glutDisplayFunc(display);
    if (!doneYellow) glutKeyboardFunc(keyboard);
    if (!doneGreen) glutSpecialFunc(specialKeyboard);
    glutMainLoop();
}