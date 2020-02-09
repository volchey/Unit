
def my_var():
    var_int     = 42
    var_str     = '42'
    var_str_2   = 'quarante-deux'
    var_float   = 42.0
    var_bool    = True
    var_list    = [42]
    var_dict    = {42:42}
    var_tuple   = 42,
    var_set     = set()
    
    print(str(var_int) + ' est de type ' + str(type(var_int)))
    print(str(var_str) + ' est de type ' + str(type(var_str)))
    print(str(var_str_2) + ' est de type ' + str(type(var_str_2)))
    print(str(var_float) + ' est de type ' + str(type(var_float)))
    print(str(var_bool) + ' est de type ' + str(type(var_bool)))
    print(str(var_list) + ' est de type ' + str(type(var_list)))
    print(str(var_dict) + ' est de type ' + str(type(var_dict)))
    print(str(var_tuple) + ' est de type ' + str(type(var_tuple)))
    print(str(var_set) + ' est de type ' + str(type(var_set)))

if __name__ == '__main__':
    my_var()