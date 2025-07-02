To compile and run ```main.cpp``` the file:

```
// To compile
g++ main.cpp -I ~/glfw/include -L ~/glfw/build/src -lglfw3 -lGL -lX11 -lXrandr -lXi -lXcursor -lm -ldl -pthread -o test_glfw

// To run
export DISPLAY=$(ip route | awk '/default/ {print $3}'):0
// Following opens a window
./test_glfw
```

If window isn't seen due to any reason, or the terminal get's stuck, Confirm X Server is running on Windows
https://sourceforge.net/projects/vcxsrv/

Inside XLaunch, once downloaded and installed:
- Run XLaunch and choose:
  - Multiple Windows
  - Start no client
  - Check the 'Disable access control'
  - Finish and leave it running

And finally rerun all the compilation and initialization steps on the terminal given above. 

```

g++ --> use G++ compiler
main.cpp --> compile this source file
-o rotate --> output binary should be named rotate

// to this base, we are adding OpenGL, GLFW, and GLAD support

glad_src/glad.c --> GLAD is a loader for OpenGL functions
glad.c --> contains the actual OpenGL function pointers' loading code
GLAD = glue between your C++ code and OpenGL

-Iglad/include --> when we write #include <glad/glad.h> in the code, it says, look inside glad/include/

-lglfw --> link the GLFW library (creates the window, handles user input, sets up OpenGL context)

-lGL --> links the core OpenGL library on Linux

-ldl --> dynamic loader library (Required on Linux and WSL systems)
GLAD uses dlopen() and dlsym() under the hood to load OpenGL functions at runtime

-lpthread --> GLFW uses multithreading internally, so we need to link POSIX threads (pthread)

-lX11, -lXrandr, -lXi, -lXcursor --> these are X11-related libraries required by GLFW to (create and manage windows, handle window resizing, input events, mouse interaction, etc.)


// -I, -L, -l flags -- standard g++ and gcc options that control how the compiler finds and links things

-I --> include path
-I<directory> --> add this folder to the list of directories to search for header files during compilation

-l --> link library
-l<library> --> add this library when creating the final executable
-lglfw --> link the library called libglfw.so or libglfw.a from system paths (it auto-prefixes with lib and suffixes .so(shared) or .a(static))

-L --> library path
-L<library> --> search for libraries in this folder
-L~/glfw/build/src --> when we aren't using system-installed libraries, but have built our own somewhere, we use -L to point the linker

POSIX --> Portable Operating System Interface -- defines how operating systems like Linux, Unix, and macOS should behave at the system-call and API level - so that software written for one can work on the others.

thread --> like a mini-program inside your main program
It runs at the same time as the main code - like doing two things in parallel.
(Threads let different parts of your program run at the same time - often on different CPU cores)


// Running from windows terminal (git bash)

-I"C:/opencv/opencv/build/include" --> when you see #include <opencv2/opencv.hpp>, go look inside this folder
inside this include folder, you'll find -- opencv2/core.hpp, opencv2/highgui.hpp, and opencv2/imgproc.hpp, etc.

-L"C:/opencv/opencv/build/x64/mingw/lib" --> this is the folder where compiled OpenCV .lib and .dll.a libraries live
We don't build these ourselves -- since we installed OpenCV using prebuilt binaries (which many devs do), CMake already placed the readymade .lib files here.
(Basically saying, "when I link to a library like -lopencv_core4110, go look there to find the corresponding .lib or .dll.a file)

-lopencv_core4110 --> tells the linker to look for libopencv_core4110.a (mingw), or opencv_core4110.lib (msvc)
4110 -- means opencv version 4.1.1.0 (these suffix helps distinguish between versions)

-lopencv_core4110 --> core opencv functionality (matrices, math, utils)
-lopencv_highgui4110 --> window handling, imshow(), GUI interactions
-lopencv_videoio4110 --> camera input, video reading/writing
-lopencv_imgproc4110 --> image processing: filters, contours, histograms
-lopencv_imgcodecs4110 --> reading/writing images from disk (e.g., imread)

```

