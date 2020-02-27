import settings
import sys, os, re

def render():

    if len(sys.argv) != 2:
        return

    file_name = sys.argv[1]

    module = globals().get('settings', None)

    if file_name.endswith('.template') == False:
        print("Incorrect file extantion")
        return
    
    try:
        f = open(file_name, "r")

        file_content = f.read()

        new_content = file_content

        for key, value in module.__dict__.items():
            if not (key.startswith('__') or key.startswith('_')):
                new_content = re.sub("\{" + key + "\}", value, new_content)

        new_file_name = file_name.replace('.template', '') + '.html'
        new_file = open(new_file_name, 'w')
        new_file.write(new_content)
        new_file.close()

    except IOError:
        print("File not found")


if __name__ == '__main__':
    render()