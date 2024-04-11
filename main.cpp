#include <string>
#include <chrono>
#include <iostream>
#include <fstream>
using namespace std;

void clear();

int run();

void popUp();

int prompt(string question, string answer);

//int match (string expected, string answer);

int main() {

  popUp();
 int score = run();
 clear();
 cout << "Your score is: " << score/100.00 << "(the lower the better)" << endl;
}

int run(){
  int time = 0;
  ifstream q;
  ifstream a;

  q.open("questions.txt");
  a.open("answers.txt");

  string question, answer;
   while(q){
      getline(q,question);
      getline(a,answer);

      time += prompt(question, answer);
      cout << time << endl;
  }
  //prompt("tes");
  a.close();
  q.close();


  return time;
}

int prompt(string question, string answer){
  using Clock = chrono::high_resolution_clock;
  cout << question << " (" <<  answer << ") :";                                                              
  string responce, junk;
  auto start = Clock::now();
  getline(cin, responce);
  auto end = Clock::now();
  auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
  if (answer == responce){
        cout << "Correct!" << endl;
        cout << "Your input took " << ms << " milliseconds" << endl;                       
      }
      else {
	cout << "Wrong. 50 second penality" << endl;
	ms += 50000;
	cout << "Your input took " << ms << " milliseconds" << endl;                       
      }
      getline(cin,junk);
      clear();
  return ms;
}


void clear(){
  int lines = 35;
  for (int i = 0; i < lines; i++){

    cout << endl;
  }


}

void popUp(){

cout << "*****************************************************" << endl;
cout << "*                                                   *" << endl;
cout << "*                     WELCOME                       *" << endl;
cout << "*         A SIMULATION OF THE BASELINE TEST         *" << endl;
cout << "*               FROM BLADERUNNER 2049               *" << endl;
cout << "*          Created for DevHawks Game Jam #2         *" << endl;
cout << "*                                                   *" << endl;
cout << "*                  BrainRotter 2049                 *" << endl;
cout << "*                 By Dylan Daniels                  *" << endl;
cout << "*                                                   *" << endl;
cout << "*                                                   *" << endl;
cout << "*                Press enter to start               *" << endl;
cout << "*        (A simulation of the perfect world)        *" << endl;
cout << "*    https://www.youtube.com/watch?v=vrP-_T-h9YM    *" << endl;
cout << "*               REFRENCE TO THIS CLIP               *" << endl;
cout << "*    https://www.youtube.com/watch?v=cX345EE2pis    *" << endl;
cout << "*****************************************************" << endl;

string junk;
 getline(cin, junk);
 clear();

}
