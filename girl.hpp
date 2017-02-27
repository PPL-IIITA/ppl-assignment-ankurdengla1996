/*! Class to store attributes of each girl namely
    attractiveness, intelligence, boy type requirement, name,
    type, maintenance, is single */

class girl {
        public:
            int attr;  /*!<from 0 to 100*/
            int intel; /*!<from 0 to 100*/
            char boy_type; /*!<'r' for rich, 'a' for attractive, 'i' for intelligent*/

            char name[100]; /*!<name of girl*/
            char type; /*!< 'c' for choosy, 'd' for desperate, 'n' for normal*/
            int maint; /*!< maintenance from 0 to 10000*/
            int is_single;  /*!<1 for single, 0 for not*/
};

