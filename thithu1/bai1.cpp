#include <bits/stdc++.h>
using namespace std;

struct Person
{
	string code;
	string birth;
	string father;
	string mother;
	string alive;
	string region;
};

//vector<Person> persons;
//map<string, vector<string>> persons; 
map<string, Person> people;

int numpeople = 0;
int unrelated = 0;

int countDate(string date) 
{
	int count = 0;
	for (auto p : people)
	{
		if (p.second.birth == date)
		{
			count++;
		}
	}
	return count;
}

int betweenDate(string low, string high)
{	
	int count = 0;
	for (auto p : people)
	{
		if(p.second.birth >= low && p.second.birth <= high)
			count++;
	}	
	return count;
}

int findancestor(string code, int count) 
{	
//	if(persons.find(code) == persons.end())	
//		return count;
//	string father = persons[code][2];
//	string mother = persons[code][3];
//	if (father != "0000000" || mother != "0000000")
//	{
//		count++;
//		count = max(findancestor(father, count), findancestor(mother, count));
//		
//	}
	return count;
}

void input() 
{	
	string type;
	do 
	{
		cin >> type;
		if (type == "*") continue;
		numpeople++;
		string birth, father, mother, alive, region;
		cin >> birth >> father >> mother >> alive >> region;
		if (father == "0000000" || mother == "0000000")
			unrelated++;
//		vector<string> person;
//		person.push_back(type);
//		person.push_back(birth);
//		person.push_back(father);
//		person.push_back(mother);
//		person.push_back(alive);
//		person.push_back(resion);
		struct Person person;// = 
		person.code = type;
		person.birth = birth;
		person.father = father;
		person.mother = mother;
		person.alive = alive;
		person.region = region;
//		people.insert(make_pair(type, person));
//		persons[type] = Person(type, birth, father, mother, alive, region);
		people[person.code] = person;
		
	} while (type != "*");
}
void solve() {
	string type;
	do
	{
		cin >> type;
//		cout << " "<<type << endl;
		if (type == "***") continue;
		if (type == "NUMBER_PEOPLE")
			cout << numpeople << endl;
		if (type == "MAX_UNRELATED_PEOPLE")
			cout << unrelated << endl;
		if (type == "NUMBER_PEOPLE_BORN_AT")
		{
			string date;
			cin >> date;
			cout << countDate(date)<<endl;
		}
		if (type == "NUMBER_PEOPLE_BORN_BETWEEN")
		{
			string low, high;
			cin >> low>> high;
			cout << betweenDate(low, high) << endl;
		}
		if (type == "MOST_ALIVE_ANCESTOR")
		{
			string code;
			cin >> code;
			cout << findancestor(code, 0) << endl;
		}
	}while (type != "***");
} 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	solve();
	return 0;
}