#include <iostream>
#include <complex>
#include <windows.h>


using namespace std;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


char fun1(double bound, int itlimit, double a, double b, double ca, double cb)
{

 char count = 0;

  complex<double> comp (a,b);


  while(count <= itlimit)
  {

      comp = comp * comp;
      comp +=  complex<double>(ca,cb);


      //comp = comp * (comp );
      //comp *= 8;

      if(comp.real() >= bound) break;
      count++;
  }

  return count;
}






int main()
{

  //declair variables
  double ub = 0, ca = 0, cb = 0;
  int count=0;
  double a, b;
  const int iterationlimit = 10000;
  complex<double> comp;
  /*COORD maxwindowsize;
  maxwindowsize.X = 0;
  maxwindowsize.Y = 0;
  SMALL_RECT windowrect = {0,0,0,0};
  _CONSOLE_SCREEN_BUFFER_INFO screeninfo;

  GetConsoleScreenBufferInfo(hConsole, &screeninfo);
  maxwindowsize = screeninfo.dwMaximumWindowSize;
  windowrect = {0,0,maxwindowsize.X -1, maxwindowsize.Y -1}; //obselete
  //get largest console window size
  //maxwindowsize = GetLargestConsoleWindowSize(hConsole); //DID NOT WORK
  //cout << maxwindowsize.X << "," << maxwindowsize.Y << endl; //test line


  if(!SetConsoleWindowInfo(hConsole, TRUE, &windowrect))
  {
      cout << endl<< "Error setting window dimensions."<< endl;
  }
*/




 while(1)
  {
  //run program
  cout << "Welcome to the Fractal Lab. /nFractals are generated with the formula Z = Z^2 + C, where C is the complex number (ca + cb * i)." << endl
       << "This program draws the complex plane by printing the number of iterations taken for each point to meet the bound." << endl;
  cout << "What is the bound?(any real number):";
  cin >> ub;
  cout << "What is ca?(any real number):";
  cin >> ca;
  cout << "What is cb?(any real number):";
  cin >> cb;



  for(double y = -5; y <= 5; y+=.02) //31 rows, -15 to 15
  {
      for(double x = -5; x <=5; x+=.02) //31 collumns, -15 to 15
      {
          char j = fun1(ub, iterationlimit, x, y,ca, cb);

          j = (j%25) + 'A';
          cout << hex << j << ""; // hex makes the console show numbers in hexadecimal format instead of decimal


      }
      cout << endl;
  }

  }
  return 0;


}
