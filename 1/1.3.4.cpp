#include <ctime>
#include <iostream>

using namespace std;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }
char menu() {
  char choice;
  cout << "1) add two number\n";
  cout << "2) sub two number\n";
  cout << "3) multiply two number\n";
  cout << "4) divide two number\n";
  cout << "0) quit\n";
  cout << "Enter your choice:\n";
  cin >> choice;
  return choice;
}
bool answerQuestion(int num1, int num2, int (*f)(int, int), int answer) {
  return f(num1, num2) == answer; //???
}
int main() {
  int cntque = 0, cntcor = 0;
  while (true) {
    char choice = menu();
    if (choice == '0')
      break;
    else
      cntque++;
    int num1, num2;
    num1 = rand() % 90 + 10;
    num2 = rand() % 90 + 10;
    int *pf; //???
    char op;
    switch (choice) {
    case '1':
      pf = add;
      op = '+';
      break;
    case '2':
      pf = sub;
      op = '-';
      break;
    case '3':
      pf = multiply;
      op = '*';
      break;
    case '4': {
      pf = divide;
      op = '/';
      num2 = rand() % 10 + 10;
      num1 = num2 * (rand() % 4 + 2);
      break;
    }
    default:
      continue;
    }
    int answer;
    cout << num1 << op << num2 << "=?\n";

    int cnt = 0;
    while (cnt < 3) {
      cin >> answer;
      if (answerQuestion(num1, num2, pf, answer) == true) {
        cout << "Correct!" << endl;
        cntcor++;
        break;
      } else {
        cout << "Wrong!" << endl;
        switch (cnt) {
        case 0:
          cout << "Two chances left.Please enter another answer:\n";
          break;
        case 1:
          cout << "One chance left.Please enter another answer:\n";
          break;
        case 2:
          cout << "Game over.\nYour stupid is beyond my imagination......\n";
          break;
        }
        cnt++;
      }
    }
  }
  
  cout << "You have answered "<< cntque ;
  if (cntque<=1) cout<<" question\n";
  else cout<<" question\n";
  if (cntque!=0) cout << "Your accuracy is " << (double)cntcor / (double)cntque *100 <<"\%" << endl;
  return 0;
}