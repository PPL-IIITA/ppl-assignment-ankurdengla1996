/*!Class to assign gifts to girlfriends
    according to specific type of boyfriend*/

class give{
	public:
	int miser_give ( gift g[], int budget, int maintenance ); /*!<function for miser boyfriend*/
	int generous_give ( gift g[], int budget, int maintenance ); /*!<function for generous boyfriend*/
	int geek_give  ( gift g[], int budget, int maintenance ); /*!<function for geek boyfriend*/
};
