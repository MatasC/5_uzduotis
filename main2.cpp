#include"Header.h"

int main()
{
	multiset<All> test;
	vector<Unique> last;
	set<string> url;
	skaitymas_all(test, file_name_1);
	skaiciavimas(test, last);
	spausdinimas(last);
	url_skaitymas(url, file_name_2);
	url_spausdinimas(url);
	cout << "Darbas baigtas." << endl;
}


// std::regex r(R"([^\W_]+(?:['_-][^\W_]+)*)");
// std::string s = "Hello, world! Aren't you clever? 'Later', she said. Maybe 5 o'clock?' In the year 2017 ... G2g, cya l8r hello_world.h Hermione's time-turner. Good mor~+%g. Hi' Testing_ Bye- The kids' toys";
// for (std::sregex_iterator i = std::sregex_iterator(s.begin(), s.end(), r);
//         i != std::sregex_iterator();
//         ++i)
// {
// 	std::smatch m = *i;
// 	std::cout << m.str() << '\n';
// }