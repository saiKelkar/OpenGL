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