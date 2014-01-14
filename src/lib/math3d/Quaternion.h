#ifndef __QUATERNION__H__
#define __QUATERNION__H__
#include "math_type_base.h"

class Matrix;
class Vector3;

class Quaternion:public QuaternionBase
{
public:
	Quaternion();
	Quaternion(const Matrix& m);
	Quaternion(float x,float y,float z,float w);
	Quaternion(const Vector3& v,float w);

	void Zero();
	void Set(float x,float y,float z,float w);

	void FromAxis(const Vector3& v,float angle);
	void FromMatrix(const Matrix& m);
	void Normalize();

	void Invert();
	void Slerp(const Quaternion& q1,const Quaternion& q2,float t);

	void Multiply(const Quaternion& q1,const Quaternion& q2);
	void PreMultiply(const Quaternion& q);
	void PostMultiply(const Quaternion& q);

	float DotProduct(const Quaternion& q);
	Vector3 Xyz();
};

Quaternion  operator *( const Quaternion& q1, const Quaternion& q2 );
bool		operator ==( const Quaternion& q1, const Quaternion& q2 );



#endif //__QUATERNION__H__