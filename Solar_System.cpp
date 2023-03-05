/*_______________________________________________________________________________________
    CG PROJECT BY TEAM TECHNO 404 (SEM 3, SE AI-DS, Fr. CRCE, 2021-22)
    MENTOR: Dr Nilesh Patil
    NAMES:
    Edryn Shajan Eazhakadan      9368
    Mohit Sunil Pansare          9391
    Gladys Gince Skariah         9409
    Sia Viji Puthusseri          9414
	PROJECT NAME: Animation of the SOLAR SYSTEM in C with graphics.h library
_________________________________________________________________________________________
*/

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// manipulates the position of planets on the orbit 
void planetMotion(int xrad, int yrad, int midx, int midy, int x[60], int y[60]) 
{
  int i, j = 0;
  // positions of planets in their corresponding orbits 
  for (i = 360; i > 0; i = i - 6) 
  {
    x[j] = midx - (xrad * cos((i * 3.14) / 180));
    y[j++] = midy - (yrad * sin((i * 3.14) / 180));
  }
  return;
}

int main() 
{
  // request auto detection 
  int gdriver = DETECT, gmode; // err;
  int i = 0, midx, midy;
  int xrad[9], yrad[9], x[9][60], y[9][60];
  int pos[9], tmp;

  // initialize graphic mode
  initgraph( & gdriver, & gmode, (char * )"C://tc//BGI");

  // mid positions at x and y-axis 
  midx = getmaxx() / 2;
  midy = getmaxy() / 2;

  //radius of planets
  int planet[] = {7, 10, 10, 7, 16, 13, 12, 11, 7};

  // offset position for the planets on their corresponding orbit 
  pos[0] = 0, pos[1] = 12, pos[2] = 34, pos[3] = 6, pos[4] = 89, pos[5] = 55, 
  pos[6] = 42, pos[7] = 77, pos[8] = 23;

  // orbits for all 9 planets 
  xrad[0] = 60, yrad[0] = 30;
  for (i = 1; i < 9; i++) {
    xrad[i] = xrad[i - 1] + 30;	//increase major axis by 30 px
    yrad[i] = yrad[i - 1] + 15; //increase minor axis by 15 px
  }

  // positions of planets on their corresponding orbits 
  for (i = 0; i < 9; i++) {
    planetMotion(xrad[i], yrad[i], midx, midy, x[i], y[i]);
  }

  while (!kbhit()) { //while no key isn't hit, do the following code
    // drawing 9 orbits
    setcolor(WHITE);
    for (i = 0; i < 9; i++) {
      ellipse(midx, midy, 0, 360, xrad[i], yrad[i]);
    }

    // sun at the mid of the solar system 
    outtextxy(midx + 15, midy + 15, "\nSUN"	);
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(midx, midy, 25);
    floodfill(midx, midy, YELLOW);

    // mercury in first orbit 
    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    outtextxy(x[0][pos[0]] + 4, y[0][pos[0]] + 4, "	MERCURY"); //adding the 4 so that the name does not 
    pieslice(x[0][pos[0]], y[0][pos[0]], 0, 360, planet[0]);   //overlap with the planet 

    // venus in second orbit
    setcolor(LIGHTRED);
    setfillstyle(SOLID_FILL, LIGHTRED);
    outtextxy(x[1][pos[1]] + 4, y[1][pos[1]] + 4, " VENUS");
    pieslice(x[1][pos[1]], y[1][pos[1]], 0, 360, planet[1]);

    // earth in third orbit 
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    outtextxy(x[2][pos[2]] + 4, y[2][pos[2]] + 4, " EARTH");
    pieslice(x[2][pos[2]], y[2][pos[2]], 0, 360, planet[2]);

    // mars in fourth orbit 
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    outtextxy(x[3][pos[3]] + 4, y[3][pos[3]] + 4, " MARS");
    pieslice(x[3][pos[3]], y[3][pos[3]], 0, 360, planet[3]);

    // jupiter in fifth orbit
    setcolor(LIGHTMAGENTA);
    setfillstyle(SOLID_FILL, LIGHTMAGENTA);
    outtextxy(x[4][pos[4]] + 7, y[4][pos[4]] + 7, " JUPITER"); //adding the 7 so that the name does not
    pieslice(x[4][pos[4]], y[4][pos[4]], 0, 360, planet[4]); //overlap with the planet 

    // saturn in sixth orbit
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    outtextxy(x[5][pos[5]] + 7, y[5][pos[5]] + 7, " SATURN");
    pieslice(x[5][pos[5]], y[5][pos[5]], 0, 360, planet[5]);

    // uranus in sevth orbit
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    outtextxy(x[6][pos[6]] + 7, y[6][pos[6]] + 7, "URANUS");
    pieslice(x[6][pos[6]], y[6][pos[6]], 0, 360, planet[6]);

    // neptune in eigth orbit
    setcolor(LIGHTCYAN);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    outtextxy(x[7][pos[7]] + 7, y[7][pos[7]] + 7, "NEPTUNE");
    pieslice(x[7][pos[7]], y[7][pos[7]], 0, 360, planet[7]);

    // pluto in ninth orbit
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    outtextxy(x[8][pos[8]]+7, y[8][pos[8]] + 7, "PLUTO");
    pieslice(x[8][pos[8]], y[8][pos[8]], 0, 360, planet[8]);

    // checking for one complete rotation 
    for (i = 0; i < 9; i++) {
      if (pos[i] <= 0) {
        pos[i] = 59;
      } 
	  else {
        pos[i] = pos[i] - 1;
      }
    }

    // sleep for 150 milliseconds
    delay(150);

    // clears graphic screen
    cleardevice();
  }

  // deallocate memory allocated for graphic screen
  closegraph();
  return 0;
}
