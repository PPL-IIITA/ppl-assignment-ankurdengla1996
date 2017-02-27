/*! Class to store attributes of each boy namely
    attractiveness, intelligence, girl requirement, name,
    type, budget, is single */

class boy {
	public:
		int attr; /*!<from 0 to 100*/
		int intel; /*!<from 0 to 100*/
		int girl_req; /*!<girl attractiveness from 0 to 100*/

		char name[100]; /*!<name*/
		char type;  /*!< 'm' for miser, 'g' for generous, 'G' for geek*/
		int budget; /*!< from 0 to 10000*/
		int is_single; /*!<1 for single, 0 for not*/

};
