// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math3d/Vector2.h>
#include <math3d/Vector3.h>
#include <math3d/Vector4.h>
#include <math3d/Matrix.h>
#include <math3d/Plane.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Vector4 v(1,2,3,4);
	v /= 3;

	Vector3 v3(2,3,4);
	Vector4 v4(v3,9);


	Matrix m;
	m.SetIdentity();
	m.SetTranslate(Vector3(1,2,3));

	Plane p(Vector3(1,1,1),Vector3(1,0,0));
	bool isFront = p.PointIsFront(Vector3());
	return 0;
}

