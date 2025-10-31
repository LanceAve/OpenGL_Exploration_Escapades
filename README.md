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

# Branches and Overview
This repository makes use of branches. Each branch builds from the previous one, so... as I further get through the material, you'll see things shuffling around and more stuff being added in. Nothing earth-shattering. Just me getting through the material and the such. 

You'll notice that there are some branches where I go off on a tangent. Some will be marked as `_junk` for experimental stuff that didn't work. Stuff that did work will be given an abbreviation with the readme updated to reflect what was achieved. You'll see what I mean later, don't worry.

While I have you here, you might as well take a look at what each branch is all about. If you want to, at least. Here's a little table that shows them off. It's gonna get updated as more shows up. You get a little link to follow too. Isn't that nice?

**_FYI: I noticed a bunch of them shouldn't really have their own branches. I'll do some housekeeping at some point and merge them into each other. That won't happen anytime soon though._**

| **Branch Name**                                           | **Where is that?**                                                                  | **What is that?**                                                            
| --------------------------------------------------------- | ----------------------------------------------------------------------------------- | -----------------------------------------------------------------------------
| 1.0_project_setup                                         | [View Branch](../../tree/1.0_project_setup)                                         | Setting up the project. Just the very rough skeleton.                        
| 2.1_triangle_draw                                         | [View Branch](../../tree/2.1_triangle_draw)                                         | First mesh drawn and it's a triangle using OpenGL! Very cool!                
| 2.2_tool_window                                           | [View Branch](../../tree/2.2_tool_window)                                           | Added ToolWindow for use in debugging and the whatnot.                       
| 2.3_color_channel                                         | [View Branch](../../tree/2.3_color_channel)                                         | Added color channels that use tool window sliders.                           
| 3.0_camera_projection                                     | [View Branch](../../tree/3.0_camera_projection)                                     | First time making of camera projection (world space, object space, etc.).    
| 4.0_triangle_double_colored                               | [View Branch](../../tree/4.0_triangle_double_colored)                               | Rendering two angled triangles with a fancy color gradient.                  
| 4.1_triangle_double_LINES                                 | [View Branch](../../tree/4.1_triangle_double_LINES)                                 | Rendering the triangle but by using the `LINES` primitive.                   
| 4.2_triangle_double_LINE_STRIP                            | [View Branch](../../tree/4.2_triangle_double_LINE_STRIP)                            | Rendering the same triangle but with `LINE_STRIP`this time.                  
| ~~4.2.1_triangle_double_default~~                         | [View Branch](../../tree/4.2.1_triangle_double_default)                             | Most probably a duplicate of 4.0. Gonna keep it for now.                     
| 4.3_triangle_double_STRIP                                 | [View Branch](../../tree/4.3_triangle_double_STRIP)                                 | Uses the `STRIP` primitive to render the triangle this time.                 
| 4.3.1_triangle_double_POINTS                              | [View Branch](../../tree/4.3.1_triangle_double_POINTS)                              | Rendering with `POINTS` now. Very hard to see. Caution advised.              
| 4.3.2_triangle_double_LINE_LOOP                           | [View Branch](../../tree/4.3.2_triangle_double_LINE_LOOP)                           | Rendering the triangle using `LINE_LOOP`! Shape closed automatically.        
| 4.3.3_triangle_double_FAN                                 | [View Branch](../../tree/4.3.3_triangle_double_FAN)                                 | Exact same triangles by is drawn using `FAN` primitive.                      
| 4.4_icosahedron_rotate                                    | [View Branch](../../tree/4.4_icosahedron_rotate)                                    | Big achievement! rotating colored icosahedron. Very manual vertex data.      
| 5.0_square_texture_rotate                                 | [View Branch](../../tree/5.0_square_texture_rotate)                                 | Rotating a square that's textured with a wood png.                           
| ~~5.1_square_texture_duplicate~~                          | [View Branch](../../tree/5.1_square_texture_duplicate)                              | Most probably a duplicate of 5.0. Will be merged eventually.                 
| 5.2_square_texture_rotate_color                           | [View Branch](../../tree/5.2_square_texture_rotate_color)                           | Adds color blending on a rotating textured square.                           
| 5.3_square_layered_texture_rotate_color                   | [View Branch](../../tree/5.3_square_layered_texture_rotate_color)                   | Layered two textures on each other! Emoji and wood. Nifty!                   
| 5.3.1_square_layered_flipped_texture_rotate_color         | [View Branch](../../tree/5.3.1_square_layered_flipped_texture_rotate_color)         | Micro commit that just flips the emoji texture orientation. Merge probably.  
| 5.3.2_square_layered_flipped_texture_rotate_color_channel | [View Branch](../../tree/5.3.2_square_layered_flipped_texture_rotate_color_channel) | Same square but now has flipped layered textures with color-channels!        
| ~~5.3.2.1_icosahedron_UV_junk~~                           | [View Branch](../../tree/5.3.2.1_icosahedron_UV_junk)                               | Failed experimental UV-mapping that was meant to wrap an icosahedron;        
| 5.4_square_texture_RGB_to_YUV                             | [View Branch](../../tree/5.4_square_texture_RGB_to_YUV)                             | RGB to YUV converter that worked like a charm! Uses tool window with a slider
| 6.1_lighting_diffuse_setup                                | [View Branch](../../tree/6.1_lighting_diffuse_setup)                                | Initial setup for lighting. Currently contains just Diffuse lighting so far. 
| 6.2_lighting_phong_diffuse_specular                       | [View Branch](../../tree/6.2_lighting_phong_diffuse_specular)                       | Modification of 6.1 that includes specular and phong lighting.               

# License
License? Check [Here](LICENSE.md) if you're interested in that sort of thing.


