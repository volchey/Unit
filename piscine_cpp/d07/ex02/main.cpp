#include "Array.hpp"
#include <string>

int main()
{
	char	str[5] = "Wow!";
	Array<char*> array(5);
	array[0] = str;
	array[1] = str;
	array[2] = str;
	array[3] = str;
	array[4] = str;
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;

	/*************************************************/

	Array<char*> charArr(5);
	charArr = array;
	for (unsigned int i = 0; i < charArr.size(); i++)
		std::cout << charArr[i] << std::endl;
	
	/*************************************************/

	Array<int> intArr(5);
	for (int i = 0; i < 5; i++)
		intArr[i] = i;
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << std::endl;

	/*************************************************/

	Array<std::string> strArr(5);
	for (int i = 0; i < 5; i++)
		strArr[i] = "100";
	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << std::endl;

	/*************************************************/

	try
	{
		Array<int> arr(5);
		arr[6] = 6;
	}
	catch (std::exception &e)
	{
		std::cout << "access to a non allocated memory" << std::endl;
	}
}