/*! Class to store gifts and their attributes like id, price, value, type */


class gift {
	public:
		int id;    /*!<gift id*/
		char type;  /*!< 'e' for essential, 'l' for luxury, 'u' for utility*/
		int price;   /*!< price of gift */
		int value;   /*!< value of gift */

		int lux_rate; /*!< luxury rate (only for luxury gifts) */
		int lux_diff; /*!< difficulty in obtaining (only for luxury gifts) */

		int util_val;   /*!< utility value (only for utility gifts) */
		int util_class;	/*!< utility class (only for utility gifts) */
};
