This is the repo for Seng 475 project by Sam Kosman

--- Overview ---
The program simulates the rigid body dynamics of spheres, specially the collision detection and response for spheres.
It works by opening up a window and simulating various spheres moving through a space defined by a box.
Some text will print to the terminal to welcome you to the program and provide you with information on actions you can take.
Since it is rigid dynamics, the spheres are considered solid, frictionless, inflexible objects, so momentum will be conserved through collisions.
In addition, there is no gravity to pull the sphere's down or loss of velocity due to kinetic energy as elastic collisions are used.
Therefore, the spheres will continuously travel through the box, never stopping. 

Within this box, there can be 1 and up to 10 spheres that collide with the box's walls and each other. 
The user is able to add and remove spheres, as well as resize the window and the simulation will adjust.
This was done to showcase the physics behind sphere collisions. 

Please note: sphere and sphere collision is quite buggy, more debudding and testing is needed to fix the sphere to sphere collision.
If you find that a collision has caused a bug, it is recommended to just remove the spheres using the down arrow indicated below.

--- Running the Program ---
To build and this program, run the following commands from the top directory.

First create the tmp folder to build the code by running the command:
> cmake -H. -Btmp

Then build the code using the command:
> cmake --build tmp

Once the program has been built, there are two ways to run. Just as is:
> ./tmp/sphere_collision
This will open the program and generate a single sphere.

Or with the -f flag and filename to indicate a config file
> ./tmp/sphere_collision -f input.txt
This will open the program and generate spheres based on the config file.

To stop running the program, exit click the exit button on the window or in the terminal type ctrl c.

--- Out-of-source Build ---
To do an out of source build, follow the following commands from the top directory.

Set the install directory variables
> export INSTALL_DIR=<path-to-directory>

Build and install the software 
> cmake -H. -Btmp_cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR
> cmake --build tmp_cmake --clean-first --target install

Run the demo program (this runs the program without the -f flag)
> $INSTALL_DIR/bin/demo


--- User Input ---
Two user inputs are accepted during the program. It is the up arrow key and down arrow key.

- up arrow: Sphere Creation
will create a sphere with random radius, initial position and velocity. Can create up to 10 spheres.
- down arrow: Sphere Removal
will remove the last sphere added. Cannot remove all spheres as one sphere will always be on screen. 

If the user attempts to add or remove more than the set number of spheres, the terminal will print a message letting them know they cannot perform more actions until a sphere is either removed or added.

--- Config Files ---
If you would like to configure your starting spheres, use the -f flag to indicate to the program that you have a configuration file.

If you choose to run the program using the -f flag, a text file will be required and the name of the file must be passed as a command line argument following the -f flag.
Each line in the config file corresponds to a sphere. A maxmimum of 10 spheres can be initialized. 
The data in the line is first the radius of the sphere, the x, y and z position coordinates, and then the x, y, and z, velocity coordinaties. It is all of type float.
Using this data a sphere will be created upon the creation of the program's window. 

The contents of the text file must be as follows:
  <radius> <x-pos> <y-pos> <x-pos> <x-vel> <y-vel> <z-vel>

Example from input.txt
  0.12 1.0 1.0 1.0 -0.01 0.01 0.00
  0.2 1.5 -1.0 1.0 -0.02 -0.01 0.00

Radius must be between
  0.1 and 0.3
Position coordinates must be between
  -2.0 and 2.0
Velocity coordiantes must be between
  -0.04 and 0.04

If data is missing or the wrong data type is given, the file will not be accepted. See bad.txt for an example of an unacceptable config file.

--- References ---
This code was developed using the following resources as references:
https://www3.ntu.edu.sg/home/ehchua/programming/opengl/CG_Examples.html
https://studiofreya.com/3d-math-and-physics/simple-sphere-sphere-collision-detection-and-collision-response/
http://www.songho.ca/opengl/gl_sphere.html
http://www.csce.uark.edu/~jgauch/4813/src/
https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html