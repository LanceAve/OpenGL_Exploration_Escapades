# Preamble
**_Note: This is just the "landing page." This repo heavily relies on branches to demo milestones reached. I would highly recommend that you go [here](#branches-and-overview) to see the branches and all the info surrounding them. There's even a little table there. Ooohh._**

Heya. This is my exploration of using C++ to learn how to use OpenGL. It makes use of the material found in:

1. https://learnopengl.com/
2. Maybe more??
   
Alongside other sources and the whatnot. Just trying to harden my skills in C++, but also learning a graphics library for the heck of it. Might move on to Vulkan later on, but I wager it's gonna be a bit of a difficulty curve, so... 

## External stuff
I'll mention any external libraries I used here so it's just left for future reference. Here's a fancy little table for yah! I will eventually add some more technical stuff (like IDE setups down to even running it on your toaster if you're into that kinda thing!)

|   | **Library** 	|     **What it was used for**     	|                **What it is**               	|           **URL**                   	    |
| - | -----------	| --------------------------------- | ---------------------------------------------	| ----------------------------------------- |
| 1 | stb_image.h 	| Loading texture onto mesh        	| Loads images from file/memory               	| [stb](https://github.com/nothings/stb)    |
| 2 | glew-2.1.0  	| Basically everything you see     	| Extension loader/manager                    	| [glew](https://github.com/nigels-com/glew)|
| 3 | glfw-3.3.4  	| Create window and set resolution 	| Cross platform window + GL Context creation 	| [glfw](https://github.com/glfw/glfw) 	    |

more to come...

## Buidling
**NOTE: This project in it's current form only supports Windows, x86/64 platforms. If you want to try and use it on others, you're more than welcome to give it a shot, but I can't help you in that regard. I am planning to figure out how to port it eventually, but that's not the focus of this at the minute.** 

Anyhow, with that out of the way. Building is fairly straightforward you see:

<img width="340" height="auto" alt="image" src="https://github.com/user-attachments/assets/8707b7da-715e-4ef6-9c02-9376f23eae3b" />

This is how I structure the project in Visual Studio. This doesn't really mean a whole lot, since it's mostly just a filter. But you'll definitely need to do a few preliminary things before it builds successfully. For starters:
1. When running the Visual Studio Installer, make sure that you select .NET desktop Development and Desktop Development with C++ 

<img width="876" height="auto" alt="image" src="https://github.com/user-attachments/assets/502459a3-7cb3-4163-8d0b-a0111f80cb4c" />

2. Make sure that you include "MSVC - Visual C++ compiler and libraries for x64/x86" from Individual Components (latest version)

## These parts should already be in the project settings if you fork the project. In case you're having issues, I'll mention them anyhow.
3. Include the C++/CLI support component too (will be needed for the debug window that pops up.) 
4. Ensure that in your project properties, you have the C++/CLI properties set to .NET Framework Runtime Support (/clr)
5. Make sure that you include glew, glfw and stb into your project, otherwise you'll get compilation errors (trust, I've seen that one too many times.)
6. Set platform to Win32 (or x86)
7. Profit?

## Branches and Overview
This repository makes use of branches. Each branch builds from the previous one, so... as I further get through the material, you'll see things shuffling around and more stuff being added in. Nothing earth-shattering. Just me getting through the material and the such. 

You'll notice that there are some branches where I go off on a tangent. Some will be marked as `_junk` for experimental stuff that didn't work. The whole point of it is to just leave a breadcrumb of info when I come back to this months later so I know what the heck I was attempting. It'll still run just fine! I'll (try) to make sure of it. But like... expectations won't match reality. So the result I was aiming for won't match the reality. Who knows! If I manage to successfully make that "feature" works, I'll remove the junk and give it it's own branch. 

Anyhow. With that ramble out of the way, stuff that did work will be given an abbreviation with the readme updated to reflect what was achieved. You'll see what I mean later, don't worry.

**Note that, considering how large the branches table has become, I decided to move it to it's own [markdown file](Branches.md) called Branches.md. You can check it out at your own leisure if you feel like it. Just thought I'd let you know.**

## License
License? Check [Here](LICENSE.md) if you're interested in that sort of thing.


