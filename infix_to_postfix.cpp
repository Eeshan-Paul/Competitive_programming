//code by Eeshan Paul
#include<bits/stdc++.h>
using namespace std;

int precedence(char a){  // to check precedence of operator
	if (a=='^')
		return 3;
	else if (a=='*' || a=='/')
		return 2;
	return 1;
}
bool isoperator(char a){  // for identifying whether the character is a operator or not
	return (a=='^' || a=='*' || a=='/' || a=='+' || a=='-');
}
void infix_to_postfix(string s){
	stack<char> st;
	string postfix="";
	for (int i=0;i<s.length();i++){
		if (s[i] >= 'a' && s[i] <= 'z')
			postfix+=s[i];
		else if (s[i]=='(')
			st.push(s[i]);
		else if (s[i]==')'){
			while (!st.empty() && st.top()!='('){
				postfix+=st.top();
				st.pop();
			}
			if (st.top()=='(')
			    st.pop();
		}
		else{
			if (st.empty())
				st.push(s[i]);
			else if (precedence(s[i])>precedence(st.top()))
				st.push(s[i]);
			else if (precedence(s[i])<=precedence(st.top())){
				while (!st.empty() && (precedence(s[i])<precedence(st.top()))){
					postfix+=st.top();
					st.pop();
				}
				st.push(s[i]);
			}
	}
}
	while (!st.empty()){
	    postfix+=st.top();
	    st.pop();
	}
	for (int i=0;i<postfix.length();i++)
		cout<<postfix[i]<<"";
}
int main()
{
	string s="(a+((b*c)/d)+e)";//sample case
	infix_to_postfix(s);// we can also return the value instead of void
	return 0;
}
