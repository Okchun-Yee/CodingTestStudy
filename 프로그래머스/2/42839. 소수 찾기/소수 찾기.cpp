#include <string>
#include <vector>
#include <set>

using namespace std;
vector<bool> visited(7, false);
set<int> primes;

bool isprime(int n){
    if(n < 2) return false;
    
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void dfs(string& numbers, string str){
    if(!str.empty()){
        int num = stoi(str);
        if(isprime(num)){
            primes.insert(num);
        }
    }
    for(int i =0;i<numbers.size();i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(numbers, str+numbers[i]);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    dfs(numbers, "");
    
    answer = primes.size();
    return answer;
}