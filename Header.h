#ifndef HEADER
#define HEADER

//Libraries

#include<iostream>
#include<set>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
#include<regex>

//Using'ai

using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::multiset;
using std::set;
using std::string;
using std::vector;
using std::setw;

//Typedef'ai


//Const values

const string symbols { " \t\r\n,.!?;:)(" };
const string file_name_1{ "test.txt" };
const string file_name_2{ "url_test.txt" };

//Class

class Base
{
protected:
	string word_;
public:
	virtual void fun() = 0;
	Base(const string& a = " ") : word_{a} {}
	Base(string&& a) : word_{a} {}
	inline string word() const { return word_; }
	~Base() {}
};

class All : public Base
{
private:
	size_t pos_;
public:
	void fun() {};
	All(const string& a = " ", const size_t& p = 0) : Base(a), pos_{p} {}
	All(const All& a) : Base(a.word_), pos_{a.pos_} {}
	All(All&& a) : Base(std::move(a.word_)), pos_{std::move(a.pos_)} {}
	inline size_t position() const { return pos_; }
	bool operator<(const All& t) const
	{
		return (this->word_ < t.word_);
	}
	~All() {}
};

class Unique : public Base
{
private:
	size_t count_;
	vector <size_t> pos_;
public:
	void fun() {};
	Unique() : Base(" "), count_{0}, pos_{0} {}
	Unique(const string& a, const size_t& b, const vector<size_t>& c) : Base(a), count_{b}, pos_{c} {}
	Unique(const Unique& a) : Base(a.word_), count_{a.count_}, pos_{a.pos_} {}
	Unique(Unique&& a) : Base(std::move(a.word_)), count_{std::move(a.count_)}, pos_{std::move(a.pos_)} {}
	inline size_t count() const { return count_; }
	inline size_t sz() const { return pos_.size(); }
	inline size_t word_sz() const { return word_.length(); }
	void Set_word(string a) { word_ = a; }
	void Set_count(int a) { count_ = a; }
	void Set_Position(set<size_t> a)
	{
		pos_.clear();
		set<size_t>::iterator it = a.begin();
		for (size_t i = 0; i < a.size(); i++)
		{
			pos_.push_back(*it);
			it++;
		}
	}
	bool operator<(const Unique& t) const
	{
		return (this->word_ < t.word_);
	}
	friend std::ostream& operator<<(std::ostream& out, Unique& duom)
	{
		for (int i = 0; i < duom.pos_.size(); i++)
		{
			out << duom.pos_[i] << " ";
		}
		out << endl;
	}
	~Unique() {}
};

//Functions

bool dydis(Unique, Unique);
bool zodis(Unique, Unique);
void skaitymas_all(multiset<All>&, string);
void skaiciavimas(multiset<All>&, vector<Unique>&);
void spausdinimas(vector<Unique>&);
void url_skaitymas(set<string>&, string);
void url_spausdinimas(set<string>&);
#endif
