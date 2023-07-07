#ifndef SEARCHIDEXCEPTION_H
#define SEARCHIDEXCEPTION_H


class searchIdException: public exception{
public:
	const char* what() const throw()
	{
		return "not found this id";
	}
        /*searchIdException() {}
        virtual ~searchIdException() {}*/

    protected:

    private:
};

#endif // SEARCHIDEXCEPTION_H
