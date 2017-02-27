##Ankur Dengla
##Roll No. - IIT2015510

The provided source code is the solution for Questions 1 and 2 of the given PPL assignment.

The solution for question 1 is file q1.cpp and similarly for question 2 is q2.cpp.



##The header files are: 

boy.hpp

girl.hpp

couples.hpp

gift.hpp

gendata.hpp

givegifts.hpp



##The library can be generated by using files couples.cpp, gendata.cpp and givegifts.cpp.



##The steps to generate library and execute code are (Type the following commands in the linu terminal) :-

1) g++ -c gendata.cpp

2) g++ -c givegifts.cpp

3) g++ -c couples.cpp

4) ar rvs lib.a gendata.o givegifts.o couples.o



( Now to compile and run q1 )



5) g++ q1.cpp lib.a

6) ./a.out ( This will display the list of couples formed and also enter the data in a file called couples.txt )



( To compile and run q2 )

( NOTE: q2 is designed to operate on the data generated by q1 so it is advised to run q2 after q1. Though a pre-defined data file is also there to test q2 first. )



7) g++ q2.pp lib.a
 
8) ./a.out ( This will display the list of 'k' most happy and compatible couples. 'k' is generated randomly by the program itself. )



##Appropriate documentation has also been provided in various formats in the folder "Documentation".

##To access the documentation, simply go to path "Documentation/html/index.html".

The class diagram is in the file "Class Diagram.pdf".
