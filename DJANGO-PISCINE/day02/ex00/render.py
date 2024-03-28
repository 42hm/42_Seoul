#!/usr/bin/python3
import sys, os, re, settings


def main():
	if len(sys.argv) != 2:
		return print("argv count error")
	elif not os.path.isfile(sys.argv[1]):
		return print("file not here")
	elif os.path.splitext(sys.argv[1])[1] != ".template":
		return print("not template file")
	else:
		with open(sys.argv[1], "r") as f:
			template = "".join(f.readlines())
		file = template.format(
			name=settings.name, surname=settings.surname, title=settings.title,
			age=settings.age, profession=settings.profession)
		path = str(os.path.splitext(sys.argv[1])[0]) + ".html"
		if file:
			html = open(path,"w")
			html.write(file)
			html.close()


if __name__ == '__main__':
    main()