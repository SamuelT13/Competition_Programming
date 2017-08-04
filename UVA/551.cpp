#include <iostream>
#include <stack>
using namespace std;

int main(){
	string l;
	stack<char> c;
	int i, count;
	
	while (getline(cin, l)){
		count = 0;

		for (i = 0; i < l.length(); i++){
			count++;

			if (l[i] == '(' || l[i] == '[' || l[i] == '{' || l[i] == '<'){
				if (l[i] == '(' && (i+1 < l.length() && l.at(i+1) == '*')){
					i++;
					c.push('*');					
				}
				else
					c.push(l[i]);
			}
			else if (l[i] == ')' || l[i] == ']' || l[i] == '}' || l[i] == '>' || (l[i] == '*' && (i+1 < l.length() && l.at(i+1) == ')'))){
				if (c.empty())
					break;
				if (l[i] == ')'){
					if (c.top() != '(')
						break;
					c.pop();
				}
				else if (l[i] == ']'){
					if (c.top() != '[')
						break;
					c.pop();
				}
				else if (l[i] == '}'){
					if (c.top() != '{')
						break;
					c.pop();
				}
				else if (l[i] == '>'){
					if (c.top() != '<')
						break;
					c.pop();
				}
				else if (l[i] == '*'){
					if (c.top() != '*')
						break;
					i++;
					c.pop();
				}
			}
		}
		
		if (!c.empty() || i < l.length()){
			if (!c.empty() && i >= l.length()) count++;
			
			cout << "NO " << count << endl;
		}
		else
			cout << "YES" << endl;
		
		while (!c.empty()) c.pop();
	}
	
	return 0;
}
