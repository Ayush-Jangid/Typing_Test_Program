#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int main(){
string b = "Sorry bro I am pro";
string a = "Sorry bro I a pr o"; cout<<endl<<"a[17]:- "<<a[16]<<endl;
string x=" "; int err=0; int crr=0; int u=0; int w=0; int no=0;

cout<<endl<<"B.size:- "<<b.size()<<endl;




while(u<b.size()){

   while(a[w] == x[0]){
if(a[w] == b[u]){crr++; u++;}
else{err++;}  
w++;
}

while(b[u] == x[0]){
if(b[u] == a[w]){crr++; w++;}
else{err++;}
u++;
}

// start 

while(b[u] != x[0] ){
if(u >= b.size()){break;}

if(a[w] != x[0]){
cout<<"U:- "<<u<<endl;

if(b[u] == a[w]){crr++; cout<<endl<<"Correct:- "<<b[u]<<endl;}
else if(b[u] != a[w]){err++; cout<<endl<<"Error at:- ("<<w<<"):- ("<<a[w]<<")"<<endl;}

u++; w++;
}

else if(a[w] == x[0]){
    while(b[u] != x[0]){
        u++;
        err++;  //cout<<endl<<"Error at:- ("<<u<<"):- ("<<a[u]<<")"<<endl;

        if(u >= b.size()){break;}
      //   no =1;
      }
              }
} 

// end


if(u >= b.size()){
   while( w < a.size()){
  err++;
  w++;
}
  break;
  }

else if(w >= a.size()){
   while(u < b.size()){err++; u++;}
   break;
   }

if(a[w] == x[0]){ // if(a[w] == x[0] && no == 0){
   
   crr++; cout<<endl<<"Correct"<<a[w]<<"tab(W):- "<<w<<endl;
} no =0;


while(a[w] != x[0] ){

  cout<<"W:- "<<a[w]<<endl;
    if(w >= a.size()){
   while(u < b.size()){err++; u++;}
   break;
   }
err++; 
w++;

}
u++; w++;
}





cout<<endl<<"Errors:- "<<err<<endl;
cout<<"Correction:- "<<crr<<endl<<endl;

} 