from urllib import request

class FileUpperSimple(object):
    def __init__(self, fname): #fname to url
        print("Init")
        self.fname = fname
        self.__f = None
    def read(self):
        print("Read")
        return self.__f.read()
    def __enter__(self):
        print("enter")
        self.__f = request.urlopen(self.fname) #otwieranie strony zamiast pliku
        return self
    def __exit__(self, exc_type, exc_val, exc_tb):
        print("exit")
        self.__f.close()
        return False

def main():
    with FileUpperSimple("http://python.org") as link:
        print(link.read())

if __name__=="__main__":
    main()