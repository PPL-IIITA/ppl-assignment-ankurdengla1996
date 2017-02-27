#include<math.h>
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
#include"couples.hpp"

int couples::calc_boy_hap(struct coup c, int intel) {	
		
	int hap = 0;
	give giv;

	if ( c.boy_type == 'm' ) {
		hap = c.budget - giv.miser_give ( gif, c.budget, c.maint );
	} else if ( c.boy_type == 'g' ) {
		hap = c.girl_hap;
	} else if ( c.boy_type == 'G' ) {
		hap = intel;
	}

	return hap;
}

int couples::calc_girl_hap( struct coup c ) {
	int temp, hap = 0;
	give giv;

	if ( c.boy_type == 'm' ) {
        	temp = giv.miser_give ( gif, c.budget, c.maint );
        } else if ( c.boy_type == 'g' ) {
                temp = giv.generous_give ( gif, c.budget, c.maint );
        } else if ( c.boy_type == 'G' ) {
                temp = giv.geek_give ( gif, c.budget, c.maint );
        }
	
	if ( c.girl_type == 'c' ) {
		hap = log10(temp);
	} else if ( c.girl_type == 'n' ) {
		hap = temp;
	} else if ( c.girl_type == 'd' ) {	
		hap = (int)(exp(temp%21));
	}

	return hap;
}

int couples::calc_comp( struct coup c, int bintel, int gintel, int battract, int gattract ) {
	int comp = 0;
  	comp = (c.budget - c.maint) + (abs(bintel - gintel)) + (abs(battract - gattract));
	return comp;
}

		
void couples::make_couples () {
	
	generate gen;
	gen.generate_boys(b);
	gen.generate_girls(g);
	gen.generate_gifts(gif);
			
	FILE *fp;

	fp = fopen ( "couples.txt", "w" );

	struct coup c;
        int i,j;
	count = 0;

        for ( i = 0;i < 50;i++ ) {
		
		for (j = 0;j < 50;j++ ) {

                	if ( b[j].is_single == 1 ) {
                        	if ( (g[i].maint <= b[j].budget) && (g[i].attr >= b[j].girl_req ) ) {
                                        g[i].is_single = 0;
                                        b[j].is_single = 0;
                                        strcpy(c.boy, b[j].name);
                                        strcpy(c.girl, g[i].name);
                                        c.boy_type = b[j].type;
                                        c.girl_type = g[i].type;
					c.budget = b[j].budget;
					c.maint = g[i].maint;

                                        c.girl_hap = calc_girl_hap(c);
                                        c.boy_hap = calc_boy_hap( c,g[i].intel );
                                        c.couple_hap = c.boy_hap + c.girl_hap;
					c.compatibility = calc_comp(c,b[j].intel,g[i].intel,b[j].attr,g[i].attr);

					fprintf ( fp,"%s %s %c %c %d %d %d %d %d %d\n", c.boy, c.girl, c.boy_type, c.girl_type, c.budget, c.maint, c.boy_hap, c.girl_hap, c.couple_hap, c.compatibility );
					count++;
					break;
                                 }
                        }
		}
        }      

	fclose(fp);
}
		
void couples::print_couples () {
	FILE *fp;
	struct coup c;
	fp = fopen( "couples.txt", "r" );

	printf ( "There were %d couples formed out of 50 boys and 50 girls. These couples are :-\n", count );

	while ( !feof(fp) ) {
		fscanf ( fp,"%s %s %c %c %d %d %d %d %d %d\n", c.boy, c.girl, &c.boy_type, &c.girl_type, &c.budget, &c.maint, &c.boy_hap, &c.girl_hap, &c.couple_hap, &c.compatibility );
		printf ( "Boy-> %s, Girl-> %s\n",c.boy, c.girl );
	}

	fclose(fp);
}

int couples::get_k_couples ( int k ) {
	FILE *fp;
        struct coup c[50], temp;
	int i = 0;
        fp = fopen( "couples.txt", "r" );

        while ( !feof(fp) ) {
        	fscanf ( fp,"%s %s %c %c %d %d %d %d %d %d\n", c[i].boy, c[i].girl, &c[i].boy_type, &c[i].girl_type, &c[i].budget, &c[i].maint, &c[i].boy_hap, &c[i].girl_hap, &c[i].couple_hap, &c[i].compatibility );
                i++;
        }

        fclose(fp);

	for ( int x = 0;x < i;x++ ) {
		for ( int y = 0;y < i;y++ ) {
			if ( c[x].couple_hap > c[y].couple_hap ) {
				temp = c[x];
				c[x] = c[y];
				c[y] = temp;
			}
		}
	}

	printf ( "The %d happiest couples are :-\n", k );
	for ( int x = 0;x < k;x++ ) {
		printf ( "Boy-> %s, Girl-> %s, Happiness-> %d\n", c[x].boy, c[x].girl, c[x].couple_hap );
	}

	for ( int x = 0;x < i;x++ ) {
                for ( int y = 0;y < i;y++ ) {
	                if ( c[x].compatibility > c[y].compatibility ) {
        	                temp = c[x];
                                c[x] = c[y];
                                c[y] = temp;
                        }
                }
         }

         printf ( "The %d most compatible couples are :-\n", k );
         for ( int x = 0;x < k;x++ ) {
         	printf ( "Boy-> %s, Girl-> %s, Compatibility-> %d\n", c[x].boy, c[x].girl, c[x].compatibility );
         }

}

