#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i = 1; i <= sqrt(yellow); i++) {
        if (yellow % i == 0) {
            if ((i + yellow / i + 2) * 2 == brown) {
                answer.push_back(yellow / i + 2);
                answer.push_back(i + 2);
            }
        }
    }
    return answer;
}
