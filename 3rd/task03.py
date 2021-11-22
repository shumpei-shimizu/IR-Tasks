def double_counter(num) :
    if (num == 0) : return 0
    return double_counter(num - 1) + num ** 2

print(double_counter(100))

