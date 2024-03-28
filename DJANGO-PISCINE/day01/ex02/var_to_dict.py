#!/usr/bin/python3

def my_var():
	d = [
	('Hendrix' , '1942'),
	('Allman' , '1946'),
	('King' , '1925'),
	('Clapton' , '1945'),
	('Johnson' , '1911'),
	('Berry' , '1926'),
	('Vaughan' , '1954'),
	('Cooder' , '1947'),
	('Page' , '1944'),
	('Richards' , '1943'),
	('Hammett' , '1962'),
	('Cobain' , '1967'),
	('Garcia' , '1942'),
	('Beck' , '1944'),
	('Santana' , '1947'),
	('Ramone' , '1948'),
	('White' , '1975'),
	('Frusciante', '1970'),
	('Thompson' , '1949'),
	('Burton' , '1939')
	]
	ret = {} #빈 딕셔너리를 만듬
	for i in d: #d에 앞의 값을 뒤로 옮김 그거를 ret 담아줌
		ret[i[1]] = i[0]
	print(ret)
	print(type(ret))
	for key, value in ret.items():
		print(key, ":", value)

if __name__ == '__main__':
	my_var()
