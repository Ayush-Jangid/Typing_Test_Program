#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// Accuracy function Declared...
void accuracy(string &a, string &b, int &err, int &crr, float &ac);


//          __________Main_Function_________
int main()
{

  string b = "I created this program for you :)";
  string a;
  int errors = 0;
  int correct = 0;
  float acc = 0;

  time_t starttime;
  time_t endtime;

  cout << endl
       << "Enter and type:" << endl;
  cout << endl
       << "Type:- " << b << endl;

  cout << endl
       << "Press enter and type..." << endl;
  cin.get(); 
  time(&starttime);

  getline(cin, a);
  time(&endtime);

  accuracy(a, b, errors, correct, acc);

  float words = ((float)a.size() / 5);
  float time = ((float)(endtime - starttime)) / 60;
  int tsec = (endtime - starttime);
  float gross_wpm = (words / time);
  float net_wpm = gross_wpm - (((float)errors / 5) / time);

  cout.precision(2);
  cout << fixed;
  cout << endl
       << "Avg. Speed:- " << net_wpm << " Wpm" << endl;
  cout << "Gross Speed:- " << gross_wpm << " Wpm" << endl;
  cout << "Accuracy:- " << acc << "%" << endl;
  cout << "Errors:- " << errors << endl;

  if (tsec > 59)
  {
    cout << "Time:- " << time << " min" << endl;
  }
  else
  {
    cout << "Time:- " << tsec << " sec" << endl;
  }
  cout << endl;
  return 0;
}

//         __________ Defining_Accuracy_Function __________

void accuracy(string &a, string &b, int &err, int &crr, float &ac)
{
  int w = 0;
  int u = 0;
  string x = " ";

  while (u < b.size())
  {

    // __________(For_Blank_Spaces(" "))__________

    while (a[w] == x[0])
    {
      if (a[w] == b[u])
      {
        crr++;
        u++;
      }
      else
      {
        err++;
      }
      w++;
    }

    if (w >= a.size())
    {
      //  while(u < b.size()){err++; u++;}
      break;
    }

    while (b[u] == x[0])
    {
      if (b[u] == a[w])
      {
        crr++;
        w++;
      }
      else
      {
        err++;
      }
      u++;
    }
    // ________________________________




    // __________(For_Errors)__________

    while (b[u] != x[0])
    {
      if (u >= b.size())
      {
        break;
      }

      if (a[w] != x[0])
      {

        if (b[u] == a[w])
        {
          crr++;
        }
        else if (b[u] != a[w])
        {
          err++;
        }

        u++;
        w++;
      }

      else if (a[w] == x[0])
      {
        while (b[u] != x[0])
        {
          u++;
          err++;

          if (u >= b.size())
          {
            break;
          }
        }
      }
    }
    // _________________________________





    if (u >= b.size())
    {
      while (w < a.size())
      {
        err++;
        w++;
      }
      break;
    }

    else if (w >= a.size())
    {
      //  while(u < b.size()){err++; u++;}
      break;
    }

    if (a[w] == x[0])
    {
      crr++;
    }

    while (a[w] != x[0])
    {

      if (w >= a.size())
      {
        while (u < b.size())
        {
          err++;
          u++;
        }
        break;
      }
      err++;
      w++;
    }

    u++;
    w++;
  }

  ac = (float(crr) / float(a.size())) * 100;
}
