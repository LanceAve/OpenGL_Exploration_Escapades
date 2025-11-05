# Preamble

> **Note:** This repo heavily relies on **branches** to demo milestones reached.  
> I highly recommend checking out the [Branches & Overview](#branches-and-overview) to see the full progression table. There's even a fancy one in there too!

Heya there! This is just my little personal sandbox in the large swath of the interwebs in order for me to learn **OpenGL** with **C++**, while mostly following the material from [LearnOpenGL](https://learnopengl.com/) and maybe more to come!  

The goal, you may ask? Well, mostly to sharpen my C++ fundamentals while also exploring some real-time rendering and the whatnot! Who knows? I might even swing my bat at **Vulkan** later (but that's a much steeper climb so don't hold your breathe, lest you faint!)

## External stuff
I'll mention any external libraries I used here so it's just left for future reference. Mostly for my eyes honestly because I'm sure I'll forget a year later.

Here's a fancy little table for yah! I will eventually add some more technical stuff (like IDE setups down to even running it on your toaster if you're into that kinda thing!)

|   | **Library** 	|     **What it was used for**     	|                **What it is**               	|           **URL**                   	    |
| - | -----------	| --------------------------------- | ---------------------------------------------	| ----------------------------------------- |
| 1 | stb_image.h 	| Loading texture onto mesh        	| Loads images from file/memory               	| [stb](https://github.com/nothings/stb)    |
| 2 | glew-2.1.0  	| Basically everything you see     	| Extension loader/manager                    	| [glew](https://github.com/nigels-com/glew)|
| 3 | glfw-3.3.4  	| Create window and set resolution 	| Cross platform window + GL Context creation 	| [glfw](https://github.com/glfw/glfw) 	    |

*more to come...*

## Buidling
**NOTE:** This project in its current form only supports **Windows x86/64**. 

If you wanna try and use it on other platforms, you're more than welcome to give it a shot, but you're on your own. It's on my to-do list to port it to other platforms though.

### Setup
1. When running the **Visual Studio Installer**, select:
   - **.NET desktop development**
   - **Desktop development with C++**
2. Under **Individual Components**, include:
   - **MSVC – Visual C++ compiler and libraries for x64/x86**

### Project Configuration
3. Enable **C++/CLI** support → set runtime to `/clr`
4. Make sure the following libraries are included:
   - `glew`
   - `glfw`
   - `stb`
5. Set your platform to **Win32 (x86)**
6. Profit??

This is roughly how I structure the project in Visual studio by the by. It's a filter only though, but you can use whatever method that tickles your fancy.

<img width="340" height="auto" alt="image" src="https://github.com/user-attachments/assets/8707b7da-715e-4ef6-9c02-9376f23eae3b" />

## Branches and Overview
This repository makes use of branches. Each branch builds from the previous one, so... as I further get through the material, you'll see things shuffling around and more stuff being added in. Nothing earth-shattering. Just me getting through the material and the such. 

You'll notice that there are some branches where I go off on a tangent. Some will be marked as `_junk` for experimental stuff that didn't work. The whole point of it is to just leave a breadcrumb of info when I come back to this months later so I know what the heck I was attempting. It'll still run just fine! I'll (try) to make sure of it. But like... expectations won't match reality. So the result I was aiming for won't match the reality. Who knows! If I manage to successfully make that "feature" works, I'll remove the junk and give it it's own branch. 

**Note:** Since the branches table has become fairly huge, I decided to make its own markdown file in here:  
📜 [**BRANCHES.md**](BRANCHES.md)

## License
License? Check [Here](LICENSE.md) if you're interested in that sort of thing.


