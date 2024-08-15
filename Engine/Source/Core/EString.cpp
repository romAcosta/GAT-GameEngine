#include "EString.h"

std::string ToLower(const std::string& str)
{

	std::string lower;
	lower.resize(str.size());

	/*for (int i = 0; i < str.length(); i++) {
		lower[i] = std::tolower(str[i]);
	}*/

	std::transform(str.begin(), str.end(), lower.begin(), [](char c)
		{
			return std::tolower(c);
		});
	/*for (auto c : str) {
		lower.push_back(std::tolower(c));
	}*/

	return lower;

}

std::string ToUpper(const std::string& str)
{

	std::string upper;
	upper.resize(str.size());

	/*for (int i = 0; i < str.length(); i++) {
		lower[i] = std::tolower(str[i]);
	}*/

	std::transform(str.begin(), str.end(), upper.begin(), [](char c)
		{
			return std::toupper(c);
		});
	/*for (auto c : str) {
		lower.push_back(std::tolower(c));
	}*/

	return upper;

}

bool IsEqualIgnoreCase(const std::string& str1, const std::string& str2)
{
	if (str1.length() != str2.length()) return false;

	return std::equal(str1.begin(), str1.end(), str2.begin(),
		[](char c1, char c2)
		{
			return std::tolower(c1) == std::tolower(c2);

		});
	


	
}
