#include <iostream>
#include <string>
using namespace std;

//Grammar Parser
/*
  EXPR:   TERM | TERM + EXPR | TERM - EXPR
  TERM:   FACTOR | FACTOR * TERM | FACTOR / TERM
  FACTOR: NUM | (EXPR)
  
  assume one-digit numbers, for simplicity
*/

int pos(0);
string input;
int expr();
int term();
int factor();

int expr(){
	int res = term();
	
	while (pos < input.size() && (input[pos] == '+' || input[pos] == '-')){
		int sign = (input[pos++] == '+') ? 1 : -1;
		
		res += sign*expr();
	}
	
	return res;
}

int term(){
	int res = factor();
	
	while (pos < input.size() && (input[pos] == '*' || input[pos] == '/'))
		if (input[pos++] == '*') res *= term();
		else res /= term();
	
	return res;
}

int factor(){
	int res;
	
	if (input[pos] == '('){
		pos++;
		res = expr();
		pos++; // ')'
	}
	
	else res = input[pos++]-'0';
	
	return res;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> input;
	
	cout << expr() << "\n";
	return 0;
}
