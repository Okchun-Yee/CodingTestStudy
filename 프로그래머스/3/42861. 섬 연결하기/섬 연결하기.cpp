#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> parent;

int find_parent(int node)
{
	return parent[node] == node ? 
        node : parent[node] = find_parent(parent[node]);
}

bool union_nodes(int node1, int node2)
{
	int p1 = find_parent(node1);
	int p2 = find_parent(node2);
	
	if(p1 == p2) return true;
    parent[p1] = p2; // root 통일
	return false;
}

void kruskal(int n, vector<vector<int>>& costs, int& answer){
    sort(costs.begin(), costs.end(), [](const auto& a, const auto& b){
        return a[2] < b[2];
    });
    
    for (auto c : costs){
        if(!union_nodes(c[0], c[1])){
            answer += c[2];
        }
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    parent.assign(n, 0);
    iota(parent.begin(), parent.end(), 0); // 0 to n-1 초기화
    
    kruskal(n, costs, answer);
    
    return answer;
}