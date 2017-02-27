#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

#include "boy.hpp"
#include "girl.hpp"
#include "gift.hpp"
#include "givegifts.hpp"
#include "gendata.hpp"
#include "couples.hpp"

	
int give::miser_give ( gift g[], int budget, int maintenance ) {
	int cost = 0;
	int i = 0;
	
	while ( (cost <= maintenance) &&(i<200) ) {
		if ( g[i].price <= budget ) {
			cost += g[i].price;
			i++;
		} else {
			break;
		}

		if ( cost > budget ) {
			cost -= g[i].price;
		}
	}

	return cost;
}

int give::generous_give ( gift g[], int budget, int maintenance ) {
	int cost = 0;
	int i = 99;

	while ( (cost <= budget) && (i >=0) ) {
		if ( g[i].price <= budget ) {
			cost += g[i].price;
		} else {
			return cost;
		}
	}

	cost -= g[i].price;

	return cost;
}

int give::geek_give  ( gift g[], int budget, int maintenance ) {
        int cost = 0;
        int i = 199;

        while ( (cost <= maintenance) &&(i<200) ) {
                if ( g[i].price <= budget ) {
                        cost += g[i].price;
                        i++;
                } else {
        	        return cost;
	        }
        }

        for ( i = 0;i < 200;i++ ) {
		if ( g[i].type == 'l' ) {
			if ( g[i].price <= (budget - cost ) ) {
				cost += g[i].price;
				break;
			}
		}	
	}		

        return cost;
}

