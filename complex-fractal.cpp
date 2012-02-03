#include <iostream>
#include <complex>
#include <windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int fun1(double bound, int itlimit, double a, double b )
{

 int count = 0;

  complex<double> comp (a,b);


  while(count <= itlimit)
  {
      count++;
      comp = comp * (comp + 4.0);
      comp *= 5;
      comp += 5;
      if(comp.real() >= bound) break;
  }

  return count;
}






int main()
{

  //declair variables
  double ub = 0;
  int count=0;
  double a, b;
  const int iterationlimit = 100000;
  complex<double> comp;
  COORD maxwindowsize;
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






  //run program
  cout << "Welcome to the Complex Number lab.\n What is the upper bound?(any real number):";
  cin >> ub;
  cout << "Upper bound is "<< ub << endl;



  for(double y = -15; y <= 15; y+=1) //31 rows, 0 to 30
  {
      for(double x = -15; x <=15; x+=1) //31 collumns, 0 to 30
      {
          int j = fun1(ub, iterationlimit, x, y);


          cout << hex << j << ""; // hex makes the console show numbers in hexadecimal format instead of decimal


      }
      cout << endl;
  }


  return 0;


}
