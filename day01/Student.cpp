#include "Student.h"
#include<QtDebug>

Student::Student()
{

}

Student::~Student()
{
    qDebug()<<"学生被释放";
}
