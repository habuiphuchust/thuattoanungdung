#include <bits/stdc++.h>
using namespace std;
vector<string> dates;
map<string, int> idx;
void input() {
	int i = 0;
	while(1) {
		string date;
		cin >> date;
		if (date == "*")
			break;
		dates.push_back(date);
		idx[date] = i;
		i++;
	}
	while(1) {
		string date, time;
		int duration;
		cin >> date;
		if (date == "***")
			break;
		cin >> time >> duration;
		
		int time_second;
		time_second = 3600*(10*(time[0] - '0') + (time[1] - '0')) +
		60* (10*(time[3] - '0') + (time[4] - '0')) +
		(10*(time[6] - '0') + (time[7] - '0'));
		int nextday;
		nextday = (duration + time_second) / 86400;
		time_second = (duration + time_second) % 86400;
		string newtime;
		int hour, minute, second;
		hour = time_second / 3600;
		minute = (time_second % 3600) / 60;
		second = time_second % 60;
		newtime.push_back(hour/10 + '0');
		newtime.push_back(hour%10 + '0');
		newtime.push_back(':');
		newtime.push_back(minute/10 + '0');
		newtime.push_back(minute%10 + '0');	
		newtime.push_back(':');	
		newtime.push_back(second/10 + '0');
		newtime.push_back(second%10 + '0');

		date = dates[idx[date] + nextday];
		cout << date <<" "<<newtime<<endl;
//		cout << date <<" "<<setw(2)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minute<<":"<<setw(2)<<setfill('0')<<second<<endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	return 0;
}