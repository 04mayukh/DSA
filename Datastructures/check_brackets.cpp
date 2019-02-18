#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char ttype, int pposition){
        type = ttype;
        position = pposition;
    }

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    int flag = 0;
    for (int position = 0; position < (int)text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            struct Bracket t(next,position);
            opening_brackets_stack.push(t);
        }

        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.empty()){
				cout<<position+1;
				flag = 1;
				break;
			}
            Bracket t = opening_brackets_stack.top();
            
            if(t.Matchc(next))
			opening_brackets_stack.pop();
			else{
				flag = 1;
				cout<<(position+1);
				break;
			}
        }
    }
    
    if(!opening_brackets_stack.empty() && flag == 0){
		flag = 1;
		while(opening_brackets_stack.size()>1)
		opening_brackets_stack.pop();
	
		Bracket t = opening_brackets_stack.top();
		cout<<(t.position+1);
	}
	if(flag==0)
	cout<<"Success";

    // Printing answer, write your code here

    return 0;
}
