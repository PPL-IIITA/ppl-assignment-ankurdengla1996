#include<stdlib.h>
#include<math.h>

/*! Class to form couples, store attributes of each couple formed,
    calculate happiness and compatibility */

class couples {
	public:
		boy b[50]; /*!<array of boys*/
		girl g[50]; /*!<array of girls*/
		gift gif[200]; /*!<array of gifts*/
		int count; /*!<counter for no. of couples formed*/

		struct coup {
			char boy[100]; /*!<name of boy*/
			char girl[100]; /*!<name of girl*/
			char boy_type; /*!<geek, generous or miser*/
			char girl_type; /*!<desperate, normal or choosy*/
			int budget; /*!<budget of boy*/
			int maint; /*!<maintenance budget of girl*/
			int boy_hap; /*!<happiness of boy*/
			int girl_hap; /*!<happiness of girl*/
			int couple_hap; /*!<happiness of couple*/
			int compatibility; /*!<compatibility of couple*/
		}; /*!<structure to store details of each couple formed*/

		int calc_boy_hap(struct coup c, int intel);  /*!<function to calculate happiness of boy*/
		int calc_girl_hap( struct coup c ); /*!<function to calculate happiness of girl*/

		int calc_comp( struct coup c, int bintel, int gintel, int battract, int gattract ); /*!<function to calculate compatibility of couple*/


		void make_couples (); /*!<function to assign proper partners to boys and girls*/
		void print_couples (); /*!<function to print list of all couples formed*/

		int get_k_couples ( int k ); /*!<function to print k most compatible and happy couples*/
};
