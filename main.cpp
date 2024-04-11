#include <string>
#include <chrono>
#include <iostream>
#include <fstream>
#include <algorithm> 
using namespace std;

void clear();

void run();

int prompt(string question);

//int match (string expected, string answer);

int main() {
  run();
  
}

void run(){

  ifstream q;
  ifstream a;

  q.open("questions.txt");
  a.open("answers.txt");

  string question, answer, responce, junk;

  int i = 0;
   while(q){
      getline(q,question);
      getline(a,answer);
      cout << question << " (" <<  answer << ") :";
      getline(cin, responce);

      if (answer== responce){
        cout << " Correct!" << endl;

      }
      else {
	cout << " Wrong. " << endl;
      }
      getline(cin,junk);
      clear();
  }
  //prompt("tes");
  a.close();
  q.close();



}

int prompt(string question){

  using Clock = chrono::high_resolution_clock;                                                 cout << question;                                                              
  string name;                                                                               
  auto start = Clock::now();                                                                   cin >> name;
  auto end = Clock::now();                                                                     auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();                  cout << "Your input took " << ms << " milliseconds" << endl;                       

}


void clear(){
  int lines = 50;
  for (int i = 0; i < lines; i++){

    cout << endl;
  }


}
