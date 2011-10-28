for(int i=0; i < string.size(); i++) {
	q.push(input[i]);
}

string temp;
bool palindrome(true);
for(int i=0; i < q.size(); i++) {
	temp += q.front();
	s.push(q.front());
	q.pop();
}

for(int i=0; i < s.size(); i++) {
	if(s.top != string[i]) palindrome = false;
	s.pop();
}

if(palindrome == true) {
	cout << "It's a palindrome";
} else {
	cout << "It's not a palindrome";
}