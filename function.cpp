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
	set<size_t> pos;
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
			pos.insert(a->position());
			temp++;
		}
		else if (i == all.size() - 1)
		{
			last.push_back(Unique());
			last[temp].Set_word(tem);
			last[temp].Set_count(count + 1);
			pos.insert(a->position());
			last[temp].Set_Position(pos);
		}
		else
		{
			count++;
			pos.insert(a->position());
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

bool dydis(Unique a, Unique b)
{
	return a.count() < b.count();
}

bool zodis(Unique a, Unique b)
{
	return a.word_sz() < b.word_sz();
}

void spausdinimas(vector<Unique>& last)
{
	cout << "Zodziu duomenys yra isvedami i tekstini faila." << endl;
	ofstream out;
	out.open("Zodziu_suvestine.txt");
	out << "Pasikartojimai abeceles tvarka: " << endl << endl;
	std::vector<Unique>::iterator temp = std::max_element(last.begin(), last.end(), dydis);
	for (int i = 2; i <= temp->count(); i++)
	{
		out << "Pasikartojo " << i << " kartu/us: " << endl;
		for (int w = 0; w < last.size(); w++)
		{
			if (last[w].count() == i)
			{
				out << last[w].word() << " ";
			}
		}
		out << endl;
	}
	out << "Zodziu pasikartojimu lentele: " << endl;
	temp = std::max_element(last.begin(), last.end(), zodis);
	for (int i = 0; i < last.size(); i++)
	{
		if (last[i].count() > 1)
		{
			out << setw(temp->word_sz()) << std::left << last[i].word() << std::left << last[i];
		}
	}
	out.close();
}