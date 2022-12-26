
# What is the Rendering Pipeline?
* The Rendering Pipeline is a series of stages that take place in oorder to render an imgae to the screen.
* Four stages are programmable via "Shaders".
* Shaders are pieces of code written is GLSL(OpenGL Shading Language), or HLSL(High-Level Shading Language) if you're using Direct3D
* GLSL is BSed on C.
# The redendering Pipeline Stages
1. Vertex Specification
	* A vertex(plural: vertices) is a point in space, usually defined with x,y and z co-ordinates.
	* A primitive is a simple shape defined using one or more vertices.
	* Usually we used triangles , but we can also use points, lines and quads.
	* Vertex Specification: Setting up the data of the vertices for the primitives we want to render.
	* Done in the application iteself.
* Vertex Specification: creating VAO/VBO
	* 1. Generate a VAO ID
	* 2. Bind the VAO with that ID.
	* 3.Generate a VBO ID.
	* 4.Bind the VBO with that ID(Now you're working o the chosen VBO attached to the chosen VAO).
	* 5.Attach the vertex data to that VBO
	* 6.Define the Attribute Poijnter formatting
	* 7.Enable the Attribute Pointer
	* 8.Unbind the VAO and VBO, ready for the next object to be bound
* Vertex Specification: Initiating Draw
	* 1. Activate Shader Program you want to use.
	* 2.Bind VAO of object you want to draw.
	* 3.Call glDrawArrays.which initiates the rest of the pipeline.


2. Vertex Shaders(programmable)
	*  Uses VAOs(Vertex Array Objects) and VBOs(Vertex Buffer Objects). (You can have multiple VBOs attached to VAOS)
	* VAO defines WHAT data a vertex has (Position, colour, texture, normals,etc).
	* VBO defines the data iteself.
	* Attribute POinters define where and how shaders can access vertex data.
		* Defines where and how shaders can access the vertex data.
	* example (VAO can say this object has a position VBO has a color,VBO has a Texture, VBO has a Normal and a VBO will have all those individual X,Y,Z positions,RGB colors and so on iteself.) all of that gets stored on the ram of the graphics card. this way the graphic card dosen't ahve to keep doing the slow process.
* Vertex Shader(pipeline?)
	* Handles vertices individually.
	* NOT optional
	* Must store something in gl_posiiton as it is used by later stages.
	* Can specify additonal outputs that can be picked up and used by user-defined shaders later in pipeline.
	* inputs consist of the vertex data itself.
* Vertex Shader: Simple Example
![[Pasted image 20221226205720.png]]
3. Tessellation(programmable)
4. Geomety Shader(programmable)
2,3,4 if you don't program them they will use the default on way , will just pass the data trough without doing anything to it.
5. Vertex POst-Processing
6. Primitive Assembly(handling of groups of vertices,racialization, which is the conversion to fragments, the frament shader itself and then per sample operatins , which are both a operations performed on the fragments just before it renders to the screen.)
7. Rasterization
8. Fragment Shader(programmable)
9. Per-Sample Operations