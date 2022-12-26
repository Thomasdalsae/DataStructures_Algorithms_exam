* OpenGL Extension Wrangler
* Interface for OpenGL verson
* Load OPenGL extenstion
* Some extensions are platform specific, GLEW can checkc if they exist on that platform
* Alternattives: GL3W, glLoadGen,glad, glsdk,glbinding,libepoxy, Glee
* Best to use GLEW. Most people do.


# Using GLEW
* #indclude <GL/glew.h>
* after initialisation OPenGL context:
	* glewExperimental = GL_TRUE;
* glewInit();
* shour return GlEW_OK. if it fails, i return the error.
* can read error with glewGetErrorString(resutl);
* Check extension exist:
	* if(!GLEW_EXT_framebuffer_object){}
	* this is to check if this extension exist.
* wglew.h for windows only functions.


# GLFW
* OpenGL FrameWork(...probably)
* Handles windows creation and control
* Pick up and process input from the keyboard,mouse,joystick and gamepad.
* Even allows multiple monitor support!


# SDL

* Simple DirectMedia Layer
* Can do almost everthing GLFW can do.
* and more!(Audio, Threading,FIlesystems,etc.)
* Very popular, especially for Indie developers
* used in FTL, Amensia, Starbound and Dying Light
* Even used in level editors for Source Engine and Cryengine!


# ALternatives


* SFML(Simple and Fast Multimedia Library): Like SDL but with even more features
* but the OpenGL context is very weak. Based on 2D only graphics.
* GLUT(OpenGL Utility Toolkit): Is no longer maintainted. Try to avoit it.
* Win32 API: For the purists. Lowest level for window creation. Only attemt if you know what you're doing!


# TLDR DERP
* GLEW(OpenGL Extension Wrangler) lets us interface with modern OpenGL and handle platform-specific extensions safely
* GLFW lets us create windows and OPenGL contexts, as well as handle user input.
* SDL does all that GLFW does, and more.
* The additional features of SDL are beyond the scope of this course , so we will be using GLFW