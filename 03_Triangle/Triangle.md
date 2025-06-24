The process of transforming 3D coordinated to 2D pixels is managed by the graphics pipeline of OpenGL. 
It can be divided into two large parts:
- The first transforms your 3D coordinated into 2D coordinates
- The second part transforms the 2D coordinated into actual coloured pixels

Graphics pipeline can be divided into several steps where each step requires the output of the previous step as its input. All these steps are highly specialized and can be easily executed in parallel. 
Graphics cards have thousands of small processing cores to quickly process the data within the graphics pipeline. The processing cores run small programs on the GPU for each step of the pipeline. 
These small programs are called shaders. 

Some shaders are configurable -- allow us to write our own shaders to replace the existing default shaders.
This gives us fine-grained control over specific parts of the pipeline and as they run on GPU, they can also save us CPU time. 

Shaders -- written in OpenGL Shading Language (GLSL)

![[Pasted image 20250622210704.png]]

Vertex Data -- we pass in a list of three 3D coordinates that should form a triangle in an array (it's a collection of vertices)
Vertex -- collection of data per 3D coordinate
Vertex data is represented using vertex attributes (for now, let's say, it's 3D position and some colour value)

Vertex Shader -- takes as input a single vertex (transforms 3D coordinate into different 3D coordinates and allow us to do some basic processing on the vertex attributes)
Output of vertex shader is optionally passed to the geometry shader. 
Geometry Shader -- takes as input a collection of vertices that form a primitive and has the ability to generate other shapes by emitting new vertices to form new (or other) primitives (in example, it generates a second triangle out of the given shape)

Primitive Assembly -- takes as input all the vertices (or vertex) from the vertex (or geometry) shader that form one or more primitives and assembles all the points in the primitive shape given (in this case two triangles)

Output of the primitive assembly stage is passed on to the rasterization stage

Rasterization stage -- maps the resulting primitives to the corresponding pixels on the final screen, resulting in fragments for the fragment shader to use. 
Before the fragment shaders run, clipping is performed. 
Clipping -- discards all fragments that are outside your view, increasing performance. 

A fragment in OpenGL is all the data required to OpenGL to render a single pixel.

Fragment Shader -- main purpose is to calculate the final colour of a pixel and this is usually the stage where all the advanced OpenGL effects occur. 
Fragment shader contains data about the 3D scene that it can use to calculate the final pixel colour (like lights, shadows, colour of the light and so on)

After all the corresponding colour values have been determined, the final object will then pass through one more stage that we call the alpha test and blending stage. 
This stage checks the corresponding depth (and stencil) value of the fragment and uses those to check if the resulting fragment is in front or behind other objects and should be discarded accordingly. 
This stage also checks for alpha values (alpha values define the opacity of an object) and blends the object accordingly. 
So even if a pixel output colour is calculated in the fragment shader, the final pixel colour could still be something entirely different when rendering multiple triangles. 