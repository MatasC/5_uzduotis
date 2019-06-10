#include"Header.h"

void skaitymas_all(multiset<All>& cont, string file_name)
{
	cout << "Nuskaitomi duomenys nuo tekstinio failo." << endl;
	std::regex r(R"([^\W_]+(?:['_-][^\W_]+)*)");
	ifstream in;
	in.open(file_name);
	string line;
	int pos = 0;
	while (getline (in, line))
	{
		++pos;
		for (std::sregex_iterator i = std::sregex_iterator(line.begin(), line.end(), r);
		        i != std::sregex_iterator();
		        ++i)
		{
			std::smatch m = *i;
			cont.emplace(m.str(), pos);
		}
	}
	in.close();
}

void url_skaitymas(set<string>& url, string file_name)
{
	cout << "Nuskaitomi duomenys is url failo." << endl;
	std::regex r(R"((http(s)?://)?([\w-]+\.)+[\w-]+[.com]+([\w\-\.,@?^=%&amp;:/~\+#]*[\w\-\@?^=%&amp;/~\+#])?)");
	ifstream in;
	in.open(file_name);
	string line;
	while (getline(in, line))
	{
		for (std::sregex_iterator i = std::sregex_iterator(line.begin(), line.end(), r);
		        i != std::sregex_iterator();
		        ++i)
		{
			std::smatch m = *i;
			url.insert(m.str());
		}
	}
	in.close();
}

void skaiciavimas(multiset<All>& all, vector<Unique>& last)
{
	cout << "Apskaiciuojami zodziu pasikartojimai ir issaugomos pasikartojimu eilutes." << endl;
	std::multiset<All>::iterator a = all.begin();
	int temp = 0, count = 0;
	vector<size_t> pos;
	string tem = a->word();
	for (int i = 0; i < all.size(); i++)
	{
		if (tem != a->word())
		{
			last.push_back(Unique());
			last[temp].Set_word(tem);
			last[temp].Set_count(count);
			last[temp].Set_Position(pos);
			tem = a->word();
			count = 1;
			pos.clear();
			pos.push_back(a->position());
			temp++;
		}
		else if (i == all.size() - 1)
		{
			last.push_back(Unique());
			last[temp].Set_word(tem);
			last[temp].Set_count(count + 1);
			pos.push_back(a->position());
			last[temp].Set_Position(pos);
		}
		else
		{
			count++;
			pos.push_back(a->position());
		}
		a++;
	}
}

void url_spausdinimas(set<string>& url)
{
	cout << "Spausdinami url adresai." << endl;
	ofstream out;
	out.open("URL_suvestine.txt");
	for (auto i : url)
		out << i << endl;
	out.close();
}

void spausdinimas(vector<Unique>& last)
{
	cout << "Zodziu duomenys yra isvedami i tekstini faila." << endl;
	ofstream out;
	out.open("Zodziu_suvestine.txt");
	for (int i = 0; i < last.size(); i++)
	{
		if (last[i].count() > 1)
		{
			out << "Zodis: " << last[i].word() << endl;
			out << "Eilutes: ";
			out << last[i];
		}
	}
	out.close();
}