#include "stdafx.h"
#include "Matrix.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"

Matrix Matrix::s_identity;

Matrix::Matrix()
{
	SetZero();
}

void Matrix::SetIdentity()
{
	D3DXMatrixIdentity(this);
}

void Matrix::SetZero()
{
	//no virtual function 
	memset(this,0,sizeof(*this));
}

void Matrix::SetScale(float x,float y,float z)
{
	D3DXMatrixScaling(this,x,y,z);
}

void Matrix::SetScale(const Vector3& v)
{
	D3DXMatrixScaling(this,v.x,v.y,v.z);
}

void Matrix::SetTranslate( const float x, const float y, const float z )
{
	D3DXMatrixTranslation(this,x,y,z);
}
void Matrix::SetTranslate( const Vector3 & pos )
{
	D3DXMatrixTranslation(this,pos.x,pos.y,pos.z);
}

void Matrix::SetRotateX(float angle)
{
	D3DXMatrixRotationX(this,angle);
}

void Matrix::SetRotateY(float angle)
{
	D3DXMatrixRotationY(this,angle);
}
void Matrix::SetRotateZ(float angle)
{
	D3DXMatrixRotationZ(this,angle);
}

void Matrix::SetRotateAxis(const Vector3& v,float angle)
{
	D3DXMatrixRotationAxis(this,&v,angle);
}
void Matrix::SetRotate(const Quaternion& quat)
{
	D3DXMatrixRotationQuaternion(this,&quat);
}
void Matrix::SetRotate(float yaw,float pitch,float roll)
{
	D3DXMatrixRotationYawPitchRoll(this,yaw,pitch,roll);
}

void Matrix::Multiply(const Matrix& m1,const Matrix& m2)
{
	D3DXMatrixMultiply(this,&m1,&m2);
}
void Matrix::PreMultiply(const Matrix& m)
{
	Multiply(m,*this);
}
void Matrix::PostMultiply(const Matrix& m)
{
	Multiply(*this,m);
}

void Matrix::Invert()
{
	D3DXMatrixInverse(this,NULL,this);
}

Vector3 Matrix::TransformPoint(const Vector3 v)
{
	Vector4 result;
	D3DXVec3Transform(&result,&v,this);
	return Vector3(result.x,result.y,result.z);
}
void Matrix::TransformPoint(Vector4& out,const Vector3& in)
{
	D3DXVec3Transform(&out,&in,this);
}
void Matrix::TransformPoint(Vector4& out,const Vector4& in)
{
	D3DXVec4Transform(&out,&in,this);
}

Vector3 & Matrix::operator []( int i )
{
	//ASSERT
	return (*(Vector3*)m[i]);
}
const Vector3 & Matrix::operator []( int i ) const
{
	//ASSERT
	return (*(Vector3*)m[i]);
}

Vector4 & Matrix::Row( int i )
{
	return (*(Vector4*)m[i]);
}
const Vector4 & Matrix::Row( int i ) const
{
	return (*(Vector4*)m[i]);
}

float Matrix::Yaw()
{
	const Vector3 & zdir = (*this)[2];
	return atan2f( zdir.x, zdir.z );	
}
float Matrix::Pitch()
{
	const Vector3 & zdir = (*this)[2];
	return -asinf( zdir.y );
}
float Matrix::Roll()
{
	float roll;
	const Vector3 & xdir = (*this)[0];
	const Vector3 & zdir = (*this)[2];

	const float zdirxzlen = sqrtf( zdir.z*zdir.z + zdir.x*zdir.x );
	const float acarg = (zdir.z * xdir.x - zdir.x * xdir.z) / zdirxzlen;
	if (zdirxzlen == 0.f || acarg > 1.f) return 0.f;
	roll = acosf( acarg );
	return xdir.y < 0.f ? -roll : roll;	
}

void Matrix::LookAt( const Vector3& position,const Vector3& direction, const Vector3& up )
{
	D3DXMatrixLookAtLH(this,&position,&direction,&up);
}

void Matrix::Ortho(float width,float height,float zn,float zf)
{
	D3DXMatrixOrthoLH(this,width,height,zn,zf);
}

void Matrix::PerspectiveFov(float fov,float ratioHW,float zn,float zf)
{
	D3DXMatrixPerspectiveFovLH(this,fov,ratioHW,zn,zf);
}

void Matrix::Perspective(float width,float height,float zn,float zf)
{
	D3DXMatrixPerspectiveLH(this,width,height,zn,zf);
}

