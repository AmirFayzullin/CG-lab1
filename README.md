# CG-lab1

#### glutInit(&argc, argv)
Initializes the glut, which is used to interact with windows system

#### glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA)
Sets some options to glut. GLUT_DOUBLE means double buffering, rendering into the back buffer and displaying frame buffer

#### glutInitWindowSize(1024, 768)
Sets size of the window 

#### glutInitWindowPosition(50, 50);
Sets the position of the window

#### glutCreateWindow("Amir");
Creates the window with specitfied title

#### glutDisplayFunc(render);
As the glut takes control over the windows system, the major part of actions with the program are produced via callbacks. 
In this function we pass the callback, which will be called by glut to render 1 frame

#### glewInit();
Initializes glew to provide extensions for OpenGL that are available. This function seraches available extensions, dynamically
uploads them and provides access to them.

#### glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
Here we specify the color, which will be used, when frame buffer is cleared. 4 parameters: red, green, blue, alfa-channel. 
Allowed values from 0.0 to 1.0

#### glGenBuffers(1, &VBO)
Generates 1 buffer object names(that are actually unused as objects names integers) to the buffer VBO

#### glBindBuffer(GL_ARRAY_BUFFER, VBO)
This function binds a buffer object to the specified buffer binding point. As OpenGL has unusual method of pointers usage, we bind 
the pointer to the name of the target, and then we start the action on the target

#### glBufferData(GL_ARRAY_BUFFER, sizeof(vectors), vectors, GL_STATIC_DRAW)
Creates a new data store for the buffer object, which has already been bound to the target name. Parameters (target name, size in bytes, data, usage). 
GL_STATIC_DRAW says that we won't change the data.

#### glEnableVertexAttribArray(0)
As the attributes of the vertex are matched by the index, we have to have to specify the index of coordinates, so they will be available 
in a producion line.

#### glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0) 
This function call says to the production line how it should see the data inside the buffer. Parameters (attribute index, number of the components, data type, 
normalization, step between 2 instances of the attribute, structure shift)

#### glClear(GL_COLOR_BUFFER_BIT)
Clearing frame buffer. GL_COLOR_BUFFER_BIT indicates the buffers currently enabled for color writing

#### glDrawArrays(GL_TRIANGLES, 0, 3)
Draws vertices in some mode. Parameters (mode, first, count), GL_TRIANGLES says that vertices shoud be drawn in triangle mode, they will be connected with lines.
0 - index of the first vertex, 3 - count of vertices.


#### glDisableVertexAttribArray(0)
Disables the generic vertex attribute array specified by parameter.

#### glutSwapBuffers()
Swaps back buffer and frame buffer. It means that in the next call rendering will be in the current frame buffer and back buffer will be displayed.

#### glutMainLoop()
Gives control to the glut, which will start its own cycle, where it will be waiting for events from windows system. When they comes, it will pass them to 
callbacks. In this case, only one callback is defined, it renders one frame.
