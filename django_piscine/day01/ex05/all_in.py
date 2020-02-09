import sys

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

def findStateByCode(state):
    for key, value in states.items():
        if (state.lower() == value.lower()):
            return value, key

    return '', ''

def findCityByName(city):
    for key, value in capital_cities.items():
        if (city.lower() == value.lower()):
            return key, value

    return '', ''

def findStateByName(state):
    for key, value in states.items():
        if (state.lower() == key.lower()):
            return value, key

    return '', ''

def capital_city():
    
    if len(sys.argv) != 2:
        return

    content_list = sys.argv[1].split(',')

    for i in content_list:        
        if i == '':
            continue
        
        i = i.strip()

        if (i == ''):
            continue

        state_code, state_name = findStateByName(i)
        if state_code != '' and state_name != '':
            print(capital_cities[state_code], "is the capital of", state_name)
        else:
            city_code, city_name = findCityByName(i)
            if (city_code != '' and city_name != ''):
                state_in_city_code, state_in_city_name = findStateByCode(city_code)
                print(city_name, "is the capital of", state_in_city_name)
            else:
                print(i, "is neither a capital city nor a state")

if __name__ == '__main__':
    capital_city()