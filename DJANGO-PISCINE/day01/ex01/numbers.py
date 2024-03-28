#!/usr/bin/python3

def my_func():
    f = open("numbers.txt", "r")
    str_arr = f.read()
    str_arr = str_arr.rstrip("\n")
    str_arr = str_arr.split(",")
    for item in str_arr:
        print(item)
    f.close()

if __name__ == '__main__':
	my_func()
