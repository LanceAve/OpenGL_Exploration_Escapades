# Branch Overview

This repository uses branches to isolate milestones and experiments. Each branch represents a discrete feature or learning checkpoint.

Notes:
- Some branches are intentionally incremental and may be consolidated later.
- Branches marked as duplicates or `_junk` are retained for reference and are not guaranteed to be stable.

Stable milestones are progressively merged into main, though experimental branches may not build. 

| **Branch Name**                                           | **Link**                                                                     | **Summary**                                                            
| --------------------------------------------------------- | :--------------------------------------------------------------------------: | -----------------------------------------------------------------------------
| 1.0_project_setup                                         | [View](../../tree/1.0_project_setup)                                         | Initial project foundation.                        
| 2.1_triangle_draw                                         | [View](../../tree/2.1_triangle_draw)                                         | First rendered mesh (triangle).               
| 2.2_tool_window                                           | [View](../../tree/2.2_tool_window)                                           | Tool window added for debugging and parameter control.                        
| 2.3_color_channel                                         | [View](../../tree/2.3_color_channel)                                         | Color channel controls via tool window sliders.                           
| 3.0_camera_projection                                     | [View](../../tree/3.0_camera_projection)                                     | Camera projection setup (world/object space).    
| 4.0_triangle_double_colored                               | [View](../../tree/4.0_triangle_double_colored)                               | Two angled triangles with a color gradient.                 
| 4.1_triangle_double_LINES                                 | [View](../../tree/4.1_triangle_double_LINES)                                 | Triangle rendering using LINES.                   
| 4.2_triangle_double_LINE_STRIP                            | [View](../../tree/4.2_triangle_double_LINE_STRIP)                            | Triangle rendering using LINE_STRIP.                  
| ~~4.2.1_triangle_double_default~~                         | [View](../../tree/4.2.1_triangle_double_default)                             | Likely duplicate of 4.0 (retained for reference).                    
| 4.3_triangle_double_STRIP                                 | [View](../../tree/4.3_triangle_double_STRIP)                                 | Triangle rendering using STRIP.                 
| 4.3.1_triangle_double_POINTS                              | [View](../../tree/4.3.1_triangle_double_POINTS)                              | Triangle rendering using POINTS.            
| 4.3.2_triangle_double_LINE_LOOP                           | [View](../../tree/4.3.2_triangle_double_LINE_LOOP)                           | Triangle rendering using LINE_LOOP.       
| 4.3.3_triangle_double_FAN                                 | [View](../../tree/4.3.3_triangle_double_FAN)                                 | Triangle rendering using FAN.                
| 4.4_icosahedron_rotate                                    | [View](../../tree/4.4_icosahedron_rotate)                                    | Rotating colored icosahedron (manual vertex data).      
| 5.0_square_texture_rotate                                 | [View](../../tree/5.0_square_texture_rotate)                                 | Textured rotating square.                          
| ~~5.1_square_texture_duplicate~~                          | [View](../../tree/5.1_square_texture_duplicate)                              | Likely duplicate of 5.0 (candidate for merge).                 
| 5.2_square_texture_rotate_color                           | [View](../../tree/5.2_square_texture_rotate_color)                           | Textured square with color blending.                           
| 5.3_square_layered_texture_rotate_color                   | [View](../../tree/5.3_square_layered_texture_rotate_color)                   | Layered textures.                   
| 5.3.1_square_layered_flipped_texture_rotate_color         | [View](../../tree/5.3.1_square_layered_flipped_texture_rotate_color)         | Texture orientation adjustment.  
| 5.3.2_square_layered_flipped_texture_rotate_color_channel | [View](../../tree/5.3.2_square_layered_flipped_texture_rotate_color_channel) | Layered textures with color-channel controls.       
| ~~5.3.2.1_icosahedron_UV_junk~~                           | [View](../../tree/5.3.2.1_icosahedron_UV_junk)                               | Failed UV-mapping experiment with icosahedron (retained).        
| 5.4_square_texture_RGB_to_YUV                             | [View](../../tree/5.4_square_texture_RGB_to_YUV)                             | RGB to YUV conversion controlled via tool window.
| 6.1_lighting_diffuse_setup                                | [View](../../tree/6.1_lighting_diffuse_setup)                                | Initial diffuse lighting setup. 
| 6.2_lighting_phong_diffuse_specular                       | [View](../../tree/6.2_lighting_phong_diffuse_specular)                       | Phong lighting (diffuse + specular).             
| 8.0_lighting_specular_texture_reflection                  | [View](../../tree/8.0_lighting_specular_texture_reflection)                  | Specular texture reflections.
| 8.1_lighting_multi_rotating_cubes                         | [View](../../tree/8.1_lighting_multi_rotating_cubes)                         | Multiple light sources with rotating cubes.    
| 8.2_lighting_directional_multi_rotating_cubes_debug       | [View](../../tree/8.2_lighting_directional_multi_rotating_cubes_debug)       | Directional lighting (debug branch)
| 8.3_lighting_point_multi_rotating_cubes                   | [View](../../tree/8.3_lighting_point_multi_rotating_cubes)                   | Point lighting with radial falloff.
| 8.4_lighting_spotlight_rotating_wall_cubes                | [View](../../tree/8.4_lighting_spotlight_rotating_wall_cubes)                | Spotlight lighting on rotating cube wall.  
| 8.5_lighting_spotlight_attenuation_rotating_wall_cubes    | [View](../../tree/8.5_lighting_spotlight_attenuation_rotating_wall_cubes)    | Spotlight attenuation.
| 8.6_lighting_multi_spotlight_rotating_wall_cubes          | [View](../../tree/8.6_lighting_multi_spotlight_rotating_wall_cubes)          | Multiple spotlights with attenuation. 
