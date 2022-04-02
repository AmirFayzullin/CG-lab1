#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <cstdio>
using namespace std;

GLuint VBO;

void render() {
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_POINTS, 0, 1);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

void prepareVertices() {
	using namespace glm;
	tvec3<float> vertices[1];
	vertices[0] = tvec3<float>(0.0f, 0.0f, 0.0f);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void initializeGlut(int argc, char **argv, void (*render)()) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Amir");
	glutDisplayFunc(render);
}


bool initializeGlew() {
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		throw "error";
	}
}

int main(int argc, char** argv) {
	initializeGlut(argc, argv, render);
	try {
		initializeGlew();
	}
	catch (char* e) {
		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	prepareVertices();
	glutMainLoop();
}
