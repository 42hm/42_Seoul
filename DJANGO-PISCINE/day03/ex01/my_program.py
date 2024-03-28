#!/usr/bin/env python

from path import Path

def main():
    try:
        Path.makedirs('pathtest')
    except FileExistsError as e:
        print(e)
    Path.touch('pathtest/test')
    f = Path('pathtest/test')
    f.write_lines(['hello world!'])
    print(f.read_text())


if __name__ == '__main__':
    main()