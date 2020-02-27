
def parse_file():
    
    try:
        f = open("numbers.txt", "r")

        content = f.read()

        content_list = content.split(',')
        
        for i in content_list:
            if i:
                print(i)
    except IOError:
        print("File not found")

if __name__ == '__main__':
    parse_file()