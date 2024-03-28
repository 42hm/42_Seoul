#!/usr/bin/python3


class Intern:
    def __init__(self, Name = "My name? I'm nobody, an intern, I have no name."):
        self.Name = Name
    class Coffee:
        def __str__(self):
            return "This is the worst coffee you ever tasted."
    def __str__(self):
        return self.Name
    def work(self):
        raise Exception("I'm just an intern, I can't do that...")
    def make_coffee(self):
        return Intern.Coffee()


def main():
    intern = Intern()
    mark = Intern("Mark")
    print(intern)
    print(mark)
    print(mark.make_coffee())
    try:
        intern.work()
    except Exception as e:
        print(e)

if __name__ == '__main__':
    main()