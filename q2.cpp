using namespace std;
#include <time.h>
#include <stdlib.h>
#include "boy.hpp"
#include "girl.hpp"
#include "gift.hpp"
#include "couples.hpp"

int main()
{
	couples c;
	int k;
	
	srand(time(NULL));
	k = (rand() % 10) + 5;
	
	c.get_k_couples(k);

	return 0;
}
