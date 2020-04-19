/**
 * problem : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
 */

#include<iostream>
#include<vector>
#define NOT_YET -1
#define SAME_INDEX 1
#define DIFFERENT_INDEX 0
using namespace std;


bool question(int ind) {
	cout << ind + 1 << endl;
	bool ans;
	cin >> ans;
	return ans;
}
void questionAny() { question(0); }

char respond(vector<bool>& bitArray) {
	for (int i = 0; i < bitArray.size(); i++) {
		cout << bitArray[i];
	}
	cout << endl;
	char ans;
	cin >> ans;
	return ans;
}

// quesion twice
void QuantumFluctuation(vector<bool>& bitArray, int sameIndex, int differentIndex) {
	int b = bitArray.size();
	if (sameIndex != NOT_YET) {
		// check complemented
		if (bitArray[sameIndex] != question(sameIndex)) {
			// complemented
			for (int i = 0; i < b; i++) bitArray[i] = !bitArray[i];
		}
	}
	else 
		questionAny();

	if (differentIndex != NOT_YET) {
		// check reversed
		if (bitArray[differentIndex] != question(differentIndex)) {
			// reversed
			for (int i = 0; i < b / 2; i++) {
				int tmp = bitArray[i];
				bitArray[i] = bitArray[b - 1 - i];
				bitArray[b - 1 - i] = tmp;
			}
		}
	}
	else
		questionAny();
}

int main() {

	int t, b;
	cin >> t >> b;
	while (t--) {
		vector<bool> bitArray(b);
		int bitIndex[] = { NOT_YET, NOT_YET }; // [0] = different index, [1] = same index

		for (int ind = 0; ind < b/2; ind++) {
			bitArray[ind] = question(ind);
			bitArray[b - 1 - ind] = question(b - 1 - ind);
			bitIndex[bitArray[ind] == bitArray[b - 1 - ind]] = ind;

			if (ind != 0 && ind % 4 == 0) 
				QuantumFluctuation(bitArray, bitIndex[SAME_INDEX], bitIndex[DIFFERENT_INDEX]);
		}
		char ans = respond(bitArray);
		if (ans == 'N') return 0; // fail
	}
	return 0;
}
