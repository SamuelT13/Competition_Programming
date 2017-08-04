#include <iostream>
#include <cmath>
using namespace std;

//*** nums[] is of size limit + 1 ***//
//1-based indexing//

void sieve(bool nums[], long long int limit){
	for (long long int m = 2; m <= sqrt(limit); m++)
		if (!nums[m])
			for (long long int k = m*m; k <= limit; k += m)
				nums[k] = true;
}
