# Solar-System-Cpp
Since our project consists of an animation of the solar system we have used graphic.h
header file and for the implementation of our code we have used DEV C++ IDE.
Line 13,14,15 and 16 are header file, In C language, header files contain the set of
predefined standard library functions. Your request to use a header file in your program by
including it with the C preprocessing directive “#include”. All the header file have a ‘.h’ an
extension. By including a header file, we can use its contents in our program.
So in that manner as u can see we have used stdio,conio,graphic and math header files
stdio. h is a header file which has the necessary information to include the
input/output related functions in our program (Example printf, scanf etc. If we want to
use printf or scanf function in our program, we should include the stdio. h header file
in our source code.) (extra information).
conio.h is a C header file used mostly by MS-DOS compilers to provide console
input/output.It stands for console input output header file. It is used for following g
functions : clrscr, getch, delline, getche, kbhit, gotoxy, wherex, wherey, textcolor,
textbackground.
graphics.h header file. The graphics. h header file provides access to a simple
graphics library that makes it possible to draw lines, rectangles, ovals, arcs,
polygons, images, and strings on a graphical window.
math.h is a header file in the standard library of the C programming language
designed for basic mathematical operations. Most of the functions involve the
use of floating point numbers. …( Mathematical library functions that operate on
integers, such as abs , labs , div , and ldiv , are instead specified in the stdlib.)
Now in the main function, the command int gdrive r= DETECT, gmode requests auto
detection then we are declaring all the variables that we would be using in this
program
int xrad[9], yrad[9], x[9][60], y[9][60];
9 is the 9 planets and 60 is the plane divided in 60 parts
initgraph is to initialize graphic mode.
midx and midy variables are used to store mid points of x and y axis respectively.
(Function getmaxx returns the maximum X coordinate for current graphics mode
and driver.
Function getmaxy returns the maximum Y coordinate for current graphics mode and
driver.)
Planet array stores the radius of each planet. Positions of each planet are set
randomly (why?) (so that they don’t spiral) (and if u want them to be consecutive
then we can put in a for loop)
(initialising the offset position of each planet. Offset position means the initial position
that they would be in when the animation starts or the graphics start. We have given
them random positions so that they are not in a specific pattern or are not as a spiral)
Orbits for all nine planets are initialized. Radius as per x axis is increased on the
major axis by 30 px and radius as per y axis is increased on the minor axis by 15 px.
The corresponding for loop defines positions of planets on their corresponding orbits.
while(!kbhit()) denotes that while no key is hit, it performs the further code, that is to
draw the nine ellipse orbits. In other words the while loop will run until a key on the
keyboard is hit.
setcolor() is the function used to set the current drawing colour to the desired colour
wanted in this case its white.
The Sun is set to the center of the orbit.Each planet is filled with different colours
using the function setcolor().
outtextxy() is used to display the text or string at a specified point (x,y) on the screen
and we are adding a small value to each so that the they dont overlap each other
setfillstyle() sets the current fill pattern and fill color and we have used solid fill (fills
an area with the required colour)
floodfill() is used to fill an enclosed area.
pieslice() draws and fills a pie slice with center at(x,y) and a given radius r. The slice
travels from starting angle 0° to an ending angle 360°.
(small values are added to the x and y coordinate, 4 and 7 so that the text doesn’t
overlap with the planet figure.)
The for loop is written to check for one complete rotation of the planets and if yes it
sets the position variable to it's starting value
delay(150) function is used to pause the program for 150 milli-seconds,(if we didn't
use what would have happened?) (the program would start going too fast )
cleardevice() clears the screen in graphic mode and sets the current position to (0,0)
and closegraph() function deallocates the memory allocated for the graphic screen.
This is the end of the main function.
The function planetMotion() reads integer arguments for the radius and mid-point of
the orbits and hence manipulates the positions of each planet.
In the for loop, counter ‘i’ is set to follow a 360° rotation. x[j] and y[j++] sets the
positions of each planet in their corresponding orbits.
The formula is the conversion from degree to radian
