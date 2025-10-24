# Preamble
Heya. This is my exploration of using C++ to learn how to use OpenGL. It makes use of the material found in:

1. https://learnopengl.com/
2. Maybe more??
   
Alongside other sources and the whatnot. Just trying to harden my skills in C++, but also learning a graphics library for the heck of it. Might move on to Vulkan later on, but I wager it's gonna be a bit of a difficulty curve, so... 

# External stuff
I'll mention any external libraries I used here so it's just left for future reference. Here's a fancy table (which will be mostly empty for now, but will be populated as time goes by.)

|   	| **Library** 	|     **What it was used for**     	|                **What it is**               	|           **URL of Tool**          	|
|:-:	|:-----------:	|:--------------------------------:	|:-------------------------------------------:	|:----------------------------------:	|
| 1 	| stb_image.h 	| Loading texture onto mesh        	| Loads images from file/memory               	| https://github.com/nothings/stb    	|
| 2 	| glew-2.1.0  	| Basically everything you see     	| Extension loader/manager                    	| https://github.com/nigels-com/glew 	|
| 3 	| glfw-3.3.4  	| Create window and set resolution 	| Cross platform window + GL Context creation 	| https://github.com/nigels-com/glew 	|

more to come...

# Buidling

Fairly simple, you see:

<img width="340" height="525" alt="image" src="https://github.com/user-attachments/assets/8707b7da-715e-4ef6-9c02-9376f23eae3b" />

This is how I structure the project in Visual Studio. This doesn't really mean a whole lot, since it's mostly just a filter. But you'll definitely need to do a few prelimiary things before it builds successfully. For starters:
1. When running the Visual Studio Installer, make sure that you select .NET desktop Developement and Desktop Development with C++ 

<img width="876" height="331" alt="image" src="https://github.com/user-attachments/assets/502459a3-7cb3-4163-8d0b-a0111f80cb4c" />

2. Make sure that you include "MSVC - Visual C++ compiler and libraries for x64/x86" from Individual Components (latest version)

## These parts should already be in the project settings if you fork the project. In case you're having issues, I'll mention them anyhow.
3. Include the C++/CLI support component too (will be needed for the debug window that pops up.) 
4. Ensure that in your project properties, you have the C++/CLI properties set to .NET Framework Runtime Support (/clr)
5. Make sure that you include glew, glfw and stb into your project, otherwise you'll get compilation errors (trust, I've seen that one too many times.)
6. Set platform to Win32 (or x86)
7. Profit?

# Branches
This repository makes use of branches. Each branch builds from the previous one, so... as I further get through the material, you'll see things shuffling around and more stuff being added in. Nothing earth-shattering. Just me getting through the material and the such. 

You'll notice that there are some branches were I go off on a tangent. Some will be marked as `_junk` for experimental stuff that didn't work. Stuff that did work will be given an abreviation with the readme updated to reflect what was acheived. You'll see what I mean later, don't worry.

# License
License? Check [Here](LICENSE.md) if you're interested in that sort of thing.


