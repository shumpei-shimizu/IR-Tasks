function double_counter(num) {
	if (num <= 0) return 0;
	return double_counter(num - 1) + num ** 2;
}

console.log(double_counter(100));

