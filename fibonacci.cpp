// By recursion
int fibonacci(n) {
	f(0);
	if(n > 0) f = fibonacci(n-1) + fibonacci(n-2);
	return f;
}

// By iteration
int fibonacci(n) {
	fib1 = 0;
	fib2 = 1;
	for(int i(-1), i < n, i++) {
		fib1 + fib2 = fib;
		fib1 = fib2;
		fib2 = fib;
	}
	return fib2;
}