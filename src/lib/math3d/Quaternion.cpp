#include "stdafx.h"
#include "Quaternion.h"
#include "Vector3.h"

Quaternion::Quaternion():QuaternionBase(0.f,0.f,0.f,0.f)
{
}

Quaternion::Quaternion(float a,float b,float c,float d):QuaternionBase(a,b,c,d)
{
}

Quaternion::Quaternion(const Vector3& v,float w):QuaternionBase(v.x,v.y,v.z,w)
{
}

void Quaternion::Zero()
{
	x = 0.f; y = 0.f; z = 0.f; w = 0.f;
}

void Quaternion::Set(float a,float b,float c,float d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

void Quaternion::FromAxis(const Vector3& v,float angle)
{
	D3DXQuaternionRotationAxis(this,&v,angle);
}

void Quaternion::Normalize()
{
	float ls = x*x + y*y + z*z + w*w;
	ls = 1.f/sqrtf(ls);
	x *= ls;
	y *= ls;
	z *= ls;
	w *= ls;
}

void Quaternion::Invert()
{
	D3DXQuaternionInverse(this,this);
}

void Quaternion::Slerp(const Quaternion& q1,const Quaternion& q2,float t)
{
	D3DXQuaternionSlerp(this,&q1,&q2,t);
}

void Quaternion::Multiply(const Quaternion& q1,const Quaternion& q2)
{
	D3DXQuaternionMultiply(this,&q1,&q2);
}
void Quaternion::PreMultiply(const Quaternion& q)
{
	D3DXQuaternionMultiply(this,&q,this);
}
void Quaternion::PostMultiply(const Quaternion& q)
{
	D3DXQuaternionMultiply(this,this,&q);
}

float Quaternion::DotProduct(const Quaternion& q)
{
	return x*q.x + y*q.y + z*q.z + w*q.w;
}

Vector3 Quaternion::Xyz()
{
	return Vector3(x,y,z);
}
Quaternion  operator *( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion result;
	result.Multiply(q1,q2);
	return result;
}
bool operator ==( const Quaternion& q1, const Quaternion& q2 )
{
	return (q1.x==q2.x && q1.y==q2.y && q1.z== q2.z && q1.w==q2.w);
}


