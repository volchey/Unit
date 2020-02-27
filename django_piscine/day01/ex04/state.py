import sys

def capital_city():
    
    if len(sys.argv) != 2:
        return

    states = {
    "Oregon" : "OR",
    "Alabama" : "AL",
    "New Jersey": "NJ",
    "Colorado" : "CO"
    }
    capital_cities = {
    "OR": "Salem",
    "AL": "Montgomery",
    "NJ": "Trenton",
    "CO": "Denver"
    }

    city = ''
    for key, value in capital_cities.items():
        if value == sys.argv[1]:
            city = key
            break
        
    if city == '':
        print("Unknown capital city")
        return

    for key, value in states.items():
        if value == city:
            print(key)
            return

if __name__ == '__main__':
    capital_city()