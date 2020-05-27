#include <iostream>
#include <vector>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

typedef unsigned int uint;

hash_map<uint, int> maxDollars;


int getValueInMap(uint bc)
{
    if (maxDollars.find(bc) == maxDollars.end()) {
		return -1;
    }
    else {
		return maxDollars[bc];
    }
}

uint getMaxDollars(uint bc)
{
    if (bc <= 1) {
		return bc;
    }

    if (getValueInMap(bc) != -1) {
		return getValueInMap(bc);
    }

    uint f1, f2, f3;
    f1 = bc/2;
    f2 = bc/3;
    f3 = bc/4;

    f1 = getMaxDollars(f1);
    f2 = getMaxDollars(f2);
    f3 = getMaxDollars(f3);

    uint maxValue = std::max(f1 + f2 + f3, bc);
    maxDollars[bc] = maxValue;

    return maxValue;
}

int main(){
    uint in;
    while (cin >> in) {
	cout << getMaxDollars(in)<<endl;
    }

}
