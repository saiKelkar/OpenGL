- Inside WSL:
```
  sudo apt update
  sudo apt install cmake xorg-dev libgl1-mesa-dev libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev build-essential
```

- Clone or copy glfw-3.4 into WSL:
```
cd ~
git clone https://github.com/glfw/glfw.git
cd glfw
mkdir build && cd build
cmake ..
make
```

The above may give errors as it tries to enable Wayland support by default and isn't able to find the xkbcommon development headers. But since it's not actually needed, we can ask CMake to skip the Wayland entirely, like follows:
```
cd ~/glfw/build
cmake .. -DGLFW_BUILD_WAYLAND=OFF
make
```

The above code helps bypass the xkbcommon check, so CMake will succeed with only X11 support. 
```make``` compiles GLFW and leaves ```libglfw3.a``` in ```~/glfw/build/src``` 

- We can check files in the folder as follows:
```
// Standard command
ls

// Detailed info including file sizes
ls -lh

// To see everything, including the hidden files and organized output
ls -lah
```
