#include <iostream>
#include <time.h>
#include <string>
using namespace std;

string select; // Global Variable...

//            _______________ Functions Declaration _______________
void selection(string &sen, string &cpy);
void accuracy(string &, string &, int &, int &, float &);
void PrintRes(float time, float net, float gross, float ac, int err, string sentence, int ts);

//                _______________ Main Function _______________
int main()
{
  string cpy;
  string sen;
  selection(sen, cpy);
  string sentence;

  time_t starttime;
  time_t endtime;

  cout << endl
       << endl
       << endl
       << "\t\t__________ Enter_This_Text __________" << endl;
  cout << endl
       << "Type:- " << cpy << endl;

  cout << endl
       << "Press enter and type..." << endl;
  cin.get();
  time(&starttime);

  getline(cin, sentence);
  time(&endtime);

  float words = ((float)sentence.size() / 5);
  float time = ((float)(endtime - starttime)) / 60;
  int tsec = (endtime - starttime);
  float acc = 0;
  int err = 0;
  int crr = 0;

  accuracy(sentence, sen, err, crr, acc); // Accuracy function Called

  float gross_wpm = (words / time);
  float net_wpm = gross_wpm - (((float)err / 5) / time);
  if (net_wpm < 1)
  {
    net_wpm = 0;
  }
  PrintRes(time, net_wpm, gross_wpm, acc, err, sentence, tsec);

  return 0;
}

//           ____________________ Functions_Area ____________________

//                __________ Defining_Accuracy_Function __________
void accuracy(string &a, string &b, int &err, int &crr, float &ac)
{
  int w=0; int u=0; string x = " ";

while(u<b.size()){

// __________(For_Spaces)__________
   while(a[w] == x[0]){
if(a[w] == b[u]){crr++; u++;}
else{err++;}  
w++;
}

if(w >= a.size()){
  //  while(u < b.size()){err++; u++;}
   break;
   }

while(b[u] == x[0]){
if(b[u] == a[w]){crr++; w++;}
else{err++;}
u++; }
// ________________________________



// __________(For_Errors)__________
while(b[u] != x[0] ){
if(u >= b.size()){break;}

if(a[w] != x[0]){

if(b[u] == a[w]) {crr++;}
else if(b[u] != a[w]) {err++; }

u++; w++;
} 

else if(a[w] == x[0]){
    while(b[u] != x[0]){
        u++;
        err++;  

        if(u >= b.size()){break;}
        }}
        } 
// _________________________________



if(u >= b.size()){
   while( w < a.size()){
  err++;
  w++;
}
  break;
  }

else if(w >= a.size()){
  //  while(u < b.size()){err++; u++;}
   break;
   }

if(a[w] == x[0]){
   crr++; 
}




while(a[w] != x[0] ){

    if(w >= a.size()){
   while(u < b.size()){err++; u++;}
   break;
   }
err++; 
w++;
}

u++; w++;
}

ac = (float(crr) / float(a.size())) *100;
}



//       _______________ Defining_Selection_Function() _______________

void selection(string &sen, string &cpy)
{
  cout << endl
       << "Select Mode:"
       << endl
       << "For Random Words (Type:- words)"
       << endl
       << "For quote (Type:- quote)" 
       << endl
       << "For custom (Type:- custom)"
       << endl;
  getline(cin, select);
  int error = 0;

  //                  ______________ If for Words (Main) ______________
  if (select == "words" || select == "words " || select == " words" || select == " words " || select == "Words" || select == "Words " || select == " Words" || select == " Words ")
  {
    cout << endl
         << "Select No. Of Words:"
         << endl
         << "Type:- 10, 25 or 50" << endl;
    getline(cin, select);

    //                   ______________ If for 10 (Words) ______________
    if (select == "10" || select == "10 " || select == " 10" || select == " 10 ")
    {
      sen = "work school show these feel such need before eye early";
      cpy = "work school show these feel such need before eye early";
    }

    //                 ______________ Else If for 25 (Words) ______________
    else if (select == "25" || select == "25 " || select == " 25" || select == " 25 ")
    {
      sen = "hand now between plan can stand you while increase tell lead down "
            "must real own facts because person might then this plan end "
            "interest while";

      cpy = "hand now between plan can stand you while increase tell lead down \n"
            "must real own facts because person might then this plan end \n"
            "interest while";
    }

    //                 ______________ Else If for 50 (Words) ______________
    else if (select == "50" || select == "50 " || select == " 50" || select == " 50 ")
    {
      sen = "interest right in real during by begin leave write could all "
            "program line very those hold part down first turn still the on "
            "there will say another get would house leave day write after will "
            "so life present as we need say new feel how person call may each find";

      cpy = "interest right in real during by begin leave write could all \n"
            "program line very those hold part down first turn still the on \n"
            "there will say another get would house leave day write after will \n"
            "so life present as we need say new feel how person call may each find";
    }

    //                   ______________ Else (Words) ______________
    else
    {
      error++;
      cout << endl
           << endl
           << "!Invalid, Enter a valid choice..." << endl;

      //                  ______________ While (Words) ______________
      while (error != 0)
      {
        error = 0;
        cout << endl
             << "Select No. Of Words:"
             << endl
             << "Type:- 10, 25 or 50" << endl;
        getline(cin, select);

        //                  ______________ If for 10 (While-Words) ______________
        if (select == "10" || select == "10 " || select == " 10" || select == " 10 ")
        {
          sen = "work school show these feel such need before eye early";
          cpy = "work school show these feel such need before eye early";
        }

        //                  ______________ Else If for 25 (While-Words) ______________
        else if (select == "25" || select == "25 " || select == " 25" || select == " 25 ")
        {
          sen = "hand now between plan can stand you while increase tell lead down "
                "must real own facts because person might then this plan end "
                "interest while";

          cpy = "hand now between plan can stand you while increase tell lead down \n"
                "must real own facts because person might then this plan end \n"
                "interest while";
        }

        //                  ______________ Else If for 50 (While-Words) ______________
        else if (select == "50" || select == "50 " || select == " 50" || select == " 50 ")
        {
          sen = "interest right in real during by begin leave write could all "
                "program line very those hold part down first turn still the on "
                "there will say another get would house leave day write after will "
                "so life present as we need say new feel how person call may each find";

          cpy = "interest right in real during by begin leave write could all \n"
                "program line very those hold part down first turn still the on \n"
                "there will say another get would house leave day write after will \n"
                "so life present as we need say new feel how person call may each find";
        }

        //                 ______________ Else (While-Words) ______________
        else
        {
          error++;
        }
      }
    }
  }





  //                   ______________ Else If for quote(Main) ______________
  else if (select == "quote" || select == "quote " || select == " quote" || select == " quote " ||
           select == "Quote" || select == "Quote " || select == " Quote" || select == " Quote ")
  {
    cout << endl
         << "Select quote size:"
         << endl
         << "Type:- short, medium or long" << endl;
    getline(cin, select);

    //                  ______________ If for Short (Quote) ______________
    if (select == "short" || select == "short " || select == " short" || select == " short " ||
        select == "Short" || select == "Short " || select == " Short" || select == " Short ")
    {
      sen = "The past is history, future is a mystery, now is a gift, "
            "They call it the present...";

      cpy = "The past is history, future is a mystery, now is a gift, \n"
            "They call it the present...";
    }

    //              ______________ Else If for Medium (Quote) ______________
    else if (select == "medium" || select == "medium " || select == " medium" || select == " medium " ||
             select == "Medium" || select == "Medium " || select == " Medium" || select == " Medium ")
    {
      sen = "Not only do we come into fairly regular contact with people who "
            "want to know what our family looks like, but we also navigate "
            "a vast array of organizations and agencies that have their own "
            "definitions of family and may, at times, impose them on us...";

      cpy = "Not only do we come into fairly regular contact with people who \n"
            "want to know what our family looks like, but we also navigate \n"
            "a vast array of organizations and agencies that have their own \n"
            "definitions of family and may, at times, impose them on us...";
    }

    //              ______________ Else If for Long (Quote) ______________
    else if (select == "long" || select == "long " || select == " long" || select == " long " ||
             select == "long" || select == "long " || select == " long" || select == " long ")
    {
      sen = "The road may be long, tortuous and wearied."
            " But the resulting success is enduring, sure and sweet."
            " The fool abandons hope in the wearied journey of life."
            " The wise gets going - holding firmly to the promise of a better tomorrow."
            " He that gives up too soon fails to understand that life rewards with"
            " success only those who cling on to hope against hope."
            " Those who hope when it is unfashionable to hope.";

      cpy = "The road may be long, tortuous and wearied. \n"
            "But the resulting success is enduring, sure and sweet. \n"
            "The fool abandons hope in the wearied journey of life. \n"
            "The wise gets going - holding firmly to the promise of a better tomorrow. \n"
            "He that gives up too soon fails to understand that life rewards with \n"
            "success only those who cling on to hope against hope. \n"
            "Those who hope when it is unfashionable to hope.";
    }

    //                  ______________ Else (Quote) ______________
    else
    {
      error++;
      cout << endl
           << endl
           << "!Invalid, Enter a valid choice..." << endl;

      //                  ______________ While (Quote) ______________
      while (error != 0)
      {
        error = 0;
        cout << endl
             << "Select quote size:"
             << endl
             << "Type:- short, medium or long" << endl;
        getline(cin, select);

        //                  ______________ If for Short (While-Quote) ______________
    if (select == "short" || select == "short " || select == " short" || select == " short " ||
        select == "Short" || select == "Short " || select == " Short" || select == " Short ")
        {
          sen = "The past is history, future is a mystery, now is a gift, "
                "They call it the present...";

          cpy = "The past is history, future is a mystery, now is a gift, \n"
                "They call it the present...";
        }

        //                  ______________ If for Medium (While-Quote) ______________
    else if (select == "medium" || select == "medium " || select == " medium" || select == " medium " ||
             select == "Medium" || select == "Medium " || select == " Medium" || select == " Medium ")
        {
          sen = "Not only do we come into fairly regular contact with people who "
                "want to know what our family looks like, but we also navigate "
                "a vast array of organizations and agencies that have their own "
                "definitions of family and may, at times, impose them on us...";

          cpy = "Not only do we come into fairly regular contact with people who \n"
                "want to know what our family looks like, but we also navigate \n"
                "a vast array of organizations and agencies that have their own \n"
                "definitions of family and may, at times, impose them on us...";
        }

        //                  ______________ If for Long (While-Quote) ______________
    else if (select == "long" || select == "long " || select == " long" || select == " long " ||
             select == "long" || select == "long " || select == " long" || select == " long ")
        {
          sen = "The road may be long, tortuous and wearied."
                " But the resulting success is enduring, sure and sweet."
                " The fool abandons hope in the wearied journey of life."
                " The wise gets going - holding firmly to the promise of a better tomorrow."
                " He that gives up too soon fails to understand that life rewards with"
                " success only those who cling on to hope against hope."
                " Those who hope when it is unfashionable to hope.";

          cpy = "The road may be long, tortuous and wearied. \n"
                "But the resulting success is enduring, sure and sweet. \n"
                "The fool abandons hope in the wearied journey of life. \n"
                "The wise gets going - holding firmly to the promise of a better tomorrow. \n"
                "He that gives up too soon fails to understand that life rewards with \n"
                "success only those who cling on to hope against hope. \n"
                "Those who hope when it is unfashionable to hope.";
        }

        //                  ______________ Else (While-Quote) ______________
        else
        {
          error++;
        }
      }
    }
  }



        //                  ______________ Else If for Custom (Main) ______________

    else if (select == "custom" || select == "custom " || select == " custom" || select == " custom " ||
             select == "Custom" || select == "Custom " || select == " Custom" || select == " Custom ")
             {
             cout<<endl<<"Enter The Text That You Wanna Type:"<<endl;
             getline(cin,cpy);
             sen = cpy;
             }




  //                  ______________ Else (Main) ______________

  else
  {
    error++;
    cout << endl
         << endl
         << "!Invalid, Enter a valid choice..." << endl;
    //                  ______________ While (Else) ______________
    while (error != 0)
    {
      error = 0;

  cout << endl
       << "Select Mode:"
       << endl
       << "For Random Words (Type:- words)"
       << endl
       << "For quote (Type:- quote)" 
       << endl
       << "For custom (Type:- custom)"
       << endl;
      getline(cin, select);

      //                  ______________ If for Words (Main) ______________
      if (select == "words" || select == "words " || select == " words" || select == " words " ||
          select == "Words" || select == "Words " || select == " Words" || select == " Words ")
      {
        cout << endl
             << "Select No. Of Words:"
             << endl
             << "Type:- 10, 25 or 50" << endl;
        getline(cin, select);

        //                   ______________ If for 10 (Words) ______________
        if (select == "10" || select == "10 " || select == " 10" || select == " 10 ")
        {
          sen = "work school show these feel such need before eye early";
          cpy = "work school show these feel such need before eye early";
        }

        //                 ______________ Else If for 25 (Words) ______________
        else if (select == "25" || select == "25 " || select == " 25" || select == " 25 ")
        {
          sen = "hand now between plan can stand you while increase tell lead down "
                "must real own facts because person might then this plan end "
                "interest while";

          cpy = "hand now between plan can stand you while increase tell lead down \n"
                "must real own facts because person might then this plan end \n"
                "interest while";
        }

        //                 ______________ Else If for 50 (Words) ______________
        else if (select == "50" || select == "50 " || select == " 50" || select == " 50 ")
        {
          sen = "interest right in real during by begin leave write could all "
                "program line very those hold part down first turn still the on "
                "there will say another get would house leave day write after will "
                "so life present as we need say new feel how person call may each find";

          cpy = "interest right in real during by begin leave write could all \n"
                "program line very those hold part down first turn still the on \n"
                "there will say another get would house leave day write after will \n"
                "so life present as we need say new feel how person call may each find";
        }

        //                   ______________ Else (Words) ______________
        else
        {
          error++;
          cout << endl
               << endl
               << "!Invalid, Enter a valid choice..." << endl;

          //                  ______________ While (Words) ______________
          while (error != 0)
          {
            error = 0;
            cout << endl
                 << "Select No. Of Words:"
                 << endl
                 << "Type:- 10, 25 or 50" << endl;
            getline(cin, select);

            //                  ______________ If for 10 (While-Words) ______________
            if (select == "10" || select == "10 " || select == " 10" || select == " 10 ")
            {
              sen = "work school show these feel such need before eye early";
              cpy = "work school show these feel such need before eye early";
            }

            //                  ______________ Else If for 25 (While-Words) ______________
            else if (select == "25" || select == "25 " || select == " 25" || select == " 25 ")
            {
              sen = "hand now between plan can stand you while increase tell lead down "
                    "must real own facts because person might then this plan end "
                    "interest while";

              cpy = "hand now between plan can stand you while increase tell lead down \n"
                    "must real own facts because person might then this plan end \n"
                    "interest while";
            }

            //                  ______________ Else If for 50 (While-Words) ______________
            else if (select == "50" || select == "50 " || select == " 50" || select == " 50 ")
            {
              sen = "interest right in real during by begin leave write could all "
                    "program line very those hold part down first turn still the on "
                    "there will say another get would house leave day write after will "
                    "so life present as we need say new feel how person call may each find";

              cpy = "interest right in real during by begin leave write could all \n"
                    "program line very those hold part down first turn still the on \n"
                    "there will say another get would house leave day write after will \n"
                    "so life present as we need say new feel how person call may each find";
            }

            //                 ______________ Else (While-Words) ______________
            else
            {
              error++;
            }
          }
        }
      }

      //                   ______________ Else If for quote(Main) ______________
      else if (select == "quote" || select == "quote " || select == " quote" || select == " quote " ||
               select == "Quote" || select == "Quote " || select == " Quote" || select == " Quote ")
      {
        cout << endl
             << "Select quote size:"
             << endl
             << "Type:- short, medium or long" << endl;
        getline(cin, select);

        //                  ______________ If for Short (Quote) ______________
        if (select == "short" || select == "short " || select == " short" || select == " short " ||
            select == "Short" || select == "Short " || select == " Short" || select == " Short ")
        {
          sen = "The past is history, future is a mystery, now is a gift, "
                "They call it the present...";

          cpy = "The past is history, future is a mystery, now is a gift, \n"
                "They call it the present...";
        }

        //              ______________ Else If for Medium (Quote) ______________
        else if (select == "medium" || select == "medium " || select == " medium" || select == " medium " ||
                 select == "Medium" || select == "Medium " || select == " Medium" || select == " Medium ")
        {
          sen = "Not only do we come into fairly regular contact with people who "
                "want to know what our family looks like, but we also navigate "
                "a vast array of organizations and agencies that have their own "
                "definitions of family and may, at times, impose them on us...";

          cpy = "Not only do we come into fairly regular contact with people who \n"
                "want to know what our family looks like, but we also navigate \n"
                "a vast array of organizations and agencies that have their own \n"
                "definitions of family and may, at times, impose them on us...";
        }
        //           ______________ If for Long (Quote) ______________
        else if (select == "long" || select == "long " || select == " long" || select == " long " ||
                 select == "Long" || select == "Long " || select == " Long" || select == " Long ")
        {
          sen = "The road may be long, tortuous and wearied."
                " But the resulting success is enduring, sure and sweet."
                " The fool abandons hope in the wearied journey of life."
                " The wise gets going - holding firmly to the promise of a better tomorrow."
                " He that gives up too soon fails to understand that life rewards with"
                " success only those who cling on to hope against hope."
                " Those who hope when it is unfashionable to hope.";

          cpy = "The road may be long, tortuous and wearied. \n"
                "But the resulting success is enduring, sure and sweet. \n"
                "The fool abandons hope in the wearied journey of life. \n"
                "The wise gets going - holding firmly to the promise of a better tomorrow. \n"
                "He that gives up too soon fails to understand that life rewards with \n"
                "success only those who cling on to hope against hope. \n"
                "Those who hope when it is unfashionable to hope.";
        }

        //                  ______________ Else (Quote) ______________
        else
        {
          error++;
          cout << endl
               << endl
               << "!Invalid, Enter a valid choice..." << endl;

          //                  ______________ While (Quote) ______________
          while (error != 0)
          {
            error = 0;
            cout << endl
                 << "Select quote size:"
                 << endl
                 << "Type:- short, medium or long" << endl;
            getline(cin, select);

            //                  ______________ If for Short (While-Quote) ______________
            if (select == "short" || select == "short " || select == " short" || select == " short " ||
                select == "Short" || select == "Short " || select == " Short" || select == " Short ")
            {
              sen = "The past is history, future is a mystery, now is a gift, "
                    "They call it the present...";

              cpy = "The past is history, future is a mystery, now is a gift, \n"
                    "They call it the present...";
            }

            //                  ______________ If for Medium (While-Quote) ______________
        else if (select == "medium" || select == "medium " || select == " medium" || select == " medium " ||
                 select == "Medium" || select == "Medium " || select == " Medium" || select == " Medium ")
            {
              sen = "Not only do we come into fairly regular contact with people who "
                    "want to know what our family looks like, but we also navigate "
                    "a vast array of organizations and agencies that have their own "
                    "definitions of family and may, at times, impose them on us...";

              cpy = "Not only do we come into fairly regular contact with people who \n"
                    "want to know what our family looks like, but we also navigate \n"
                    "a vast array of organizations and agencies that have their own \n"
                    "definitions of family and may, at times, impose them on us...";
            }

            //                  ______________ If for Long (While-Quote) ______________
        else if (select == "long" || select == "long " || select == " long" || select == " long " ||
                 select == "Long" || select == "Long " || select == " Long" || select == " Long ")
            {
              sen = "The road may be long, tortuous and wearied."
                    " But the resulting success is enduring, sure and sweet."
                    " The fool abandons hope in the wearied journey of life."
                    " The wise gets going - holding firmly to the promise of a better tomorrow."
                    " He that gives up too soon fails to understand that life rewards with"
                    " success only those who cling on to hope against hope."
                    " Those who hope when it is unfashionable to hope.";

              cpy = "The road may be long, tortuous and wearied. \n"
                    "But the resulting success is enduring, sure and sweet. \n"
                    "The fool abandons hope in the wearied journey of life. \n"
                    "The wise gets going - holding firmly to the promise of a better tomorrow. \n"
                    "He that gives up too soon fails to understand that life rewards with \n"
                    "success only those who cling on to hope against hope. \n"
                    "Those who hope when it is unfashionable to hope.";
            }

            //                  ______________ Else (While-Quote) ______________
            else
            {
              error++;
            }
          }
        }
      }


        //                  ______________ Else If for Custom (Main) ______________

    else if (select == "custom" || select == "custom " || select == " custom" || select == " custom " ||
             select == "Custom" || select == "Custom " || select == " Custom" || select == " Custom ")
             {
             cout<<endl<<"Enter The Text That You Wanna Type:"<<endl;
             getline(cin,cpy);
             sen = cpy;
             }


      //                  ______________ Else (Main) ______________
      else
      {
        error++;
      }
    }
  }
}







//       _______________ Defining_PrintRes_Function() _______________
void PrintRes(float time, float net, float gross, float ac, int err, string sentence, int ts)
{

  cout << endl
       << endl
       << endl
       << "\t\t___________________ Result _____________________" << endl;
  cout.precision(2);
  cout << fixed;
  cout << endl
       << "\t\tGROSS SPEED"
       << "\t\t\t\tACCURACY"
       << endl
       << "\t\t" << gross << " Wpm "
       << "\t\t\t\t" << ac << "%" << endl;

  cout << endl
       << "\t\tAVERAGE SPEED"
       << "\t\t\t\tTIME"
       << endl
       << "\t\t" << net << " Wpm ";

  if (ts > 59)
  {
    cout << "\t\t\t\t" << time << " min" << endl
         << endl;
  }

  else
  {
    cout << "\t\t\t\t" << (ts) << " sec" << endl
         << endl;
  }
  cout << "\t\tKEYSTROKES"
       << "\t\t\t\tERRORS"
       << endl
       << "\t\t" << sentence.size() << " Char "
       << "\t\t\t\t" << err << " Err" << endl
       << "\t\t________________________________________________" << endl
       << endl
       << endl;
}
