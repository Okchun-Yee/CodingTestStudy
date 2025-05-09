#include <string>
#include <sstream>
#include <vector>
#include <iostream> 
#include <unordered_map>

using namespace std;

struct Entry {
	string cmd;
	string id_ref;
};

vector<string> solution(vector<string> record) {
	const string message[] = { "Enter", "Leave", "Change" };
	unordered_map<string, string> idToname;
	vector<string> answer;
	vector<Entry> e;

	int cnt = 0;
	for (const string& line : record) {
		string temp_id, temp_name, command;
		stringstream ss(line);
		ss >> command
			>> temp_id
			>> temp_name;
		if (command == message[0] || command == message[2]) {
			idToname[temp_id] = temp_name;
		}
		else if (command == message[1]) {
			temp_name = idToname[temp_id];
		}
		if(command != message[2])
			e.push_back({ command, temp_id});
	}

	for (int i = 0; i < e.size(); i++) {
		if (e[i].cmd == message[0]) {
			answer.push_back(idToname[e[i].id_ref] + string("님이 들어왔습니다."));
		}
		else if (e[i].cmd == message[1])
			answer.push_back(idToname[e[i].id_ref] + string("님이 나갔습니다."));
	}
	return answer;
}