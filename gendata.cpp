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



void generate::generate_boys ( boy b_array[]) {
      	int i, j, temp;
       	char name[100], type;
        int attr, intel, girl_req, budget, is_single = 1;
        srand(time(NULL));

        for(i=0;i<50;i++)
        {
         	for (  j = 0;j < 10;j++ ) {
     	              	name[j] =(rand()%26)+97;
                }
                name[j] = '\0';

               	attr = rand()%101;
                intel = rand()%101;
                girl_req = rand()%101;
                budget = rand()%20000;
	
                temp = rand()%3;

                switch (temp) {
                       	case 0:
                               	type = 'm';
                               	break;
                       	case 1:
                              	type = 'g';
                               	break;
                       	case 2:
                               	type = 'G';
                               	break;
                       	default:
                               	break;
                }


               	strcpy(b_array[i].name,name);
		b_array[i].attr = attr;
		b_array[i].intel = intel;
		b_array[i].girl_req =  girl_req;
		b_array[i].budget =  budget;
		b_array[i].is_single =  is_single;
		b_array[i].type = type;
        }	


}

void generate::generate_girls ( girl g_array[] ) {
	int i, j;
	char name[100];
	int attr, intel, maint, is_single = 1;
	char boy_type;
	char type;
	int temp;

	srand(time(NULL)+100);

	for(i=0;i<50;i++)
	{
		for (  j = 0;j < 10;j++ ) {
			name[j] =(rand()%26)+97;
		}
		name[j] = '\0';

		attr = rand()%101;
		intel = rand()%101;
		maint = rand()%20000;		

		temp = rand()%3;

		switch (temp) {
			case 0:
				boy_type = 'm';
				break;
			case 1:
				boy_type = 'r';
				break;
			case 2:
				boy_type = 'i';
				break;
			default:
				break;
		}	

		temp = rand()%3;

               	switch (temp) {
               	        case 0:
               	                type = 'c';
              	                break;
               	        case 1:
               	                type = 'n';
               	                break;
               	        case 2:
               	                type = 'd';
               	                break;
               	        default:
               	                break;
               	}
	
	
		strcpy(g_array[i].name,name);
                g_array[i].attr = attr;
                g_array[i].intel = intel;
                g_array[i].boy_type =  boy_type;
                g_array[i].maint =  maint;
                g_array[i].is_single =  is_single;
                g_array[i].type = type;

	  }
}

void generate::generate_gifts( gift g[] ) {
	int i, temp;
	char type;
	int prev_price = 0;
	int price_diff = 0;
	int price, value;
	int lux_rate = 0, lux_diff = 0, util_val = 0, util_class = 0;

	srand(time(NULL));

	for(i=0;i<200;i++)
   	{
		temp = rand()%3;
		lux_rate = 0, lux_diff = 0, util_val = 0, util_class = 0;

               	switch (temp) {
                       	case 0:
                               	type = 'e';
                               	break;
                       	case 1:
                               	type = 'l';
                               	break;
                       	case 2:
                               	type = 'u';
                               	break;
                       	default:
                               	break;

		}	

		price_diff = rand()%200;
		g[i].id = price_diff;
			
		price = prev_price + price_diff;
		prev_price = price;
		value = rand()%200;
			
		if ( type == 'l' ) {
			lux_rate = rand()%101;
			lux_diff = rand()%101;		
		} else if ( type == 'u' ) {
			util_val = rand()%101;
			util_class = rand()%101;
		}
         		
		g[i].type = type;
		g[i].price = price;
		g[i].value = value;
		g[i].lux_rate = lux_rate;
		g[i].lux_diff = lux_diff;
		g[i].util_val = util_val;
		g[i].util_class = util_class;
	}	
}

