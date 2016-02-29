#include"APOBB.h"
#include<assert.h>



#include<cmath>

//Build
VECTOR4 MAKE_VECTOR4(float x, float y , float z, float w)
{
    VECTOR4 v ;
    v.x = x ; v.y = y ; v.z = z ; v.w = w ;
    return v ;
}// end for MAKE_VECTOR4

VECTOR3 MAKE_VECTOR3(float x, float y, float z)
{
    VECTOR3 v ;
    v.x = x ; v.y = y ; v.z = z ;
    return v ;
}// end for MAKE_VECTOR3

VECTOR2 MAKE_VECTOR2(float x, float y)
{
    VECTOR2 v ;
    v.x = x ; v.y = y ;
    return v ;
}// end for MAKE_VECTOR2

//Method
VECTOR4 Vec4Add(VECTOR4& pOut, VECTOR4& pV1, VECTOR4& pV2)
{
    pOut.x = pV1.x + pV2.x ;
    pOut.y = pV1.y + pV2.y ;
    pOut.z = pV1.z + pV2.z ;
    
    return pOut ;
}// end Vec4Add

VECTOR4 Vec4Sub(VECTOR4& pOut, VECTOR4& pV1, VECTOR4& pV2)
{
    pOut.x = pV1.x - pV2.x ;
    pOut.y = pV1.y - pV2.y ;
    pOut.z = pV1.z - pV2.z ;
    
    return pOut ;
}// end Vec4Sub

VECTOR4 Vec4Mul(VECTOR4& pOut, VECTOR4& pV1, float n)
{
    pOut.x = pV1.x * n ;
    pOut.y = pV1.y * n ;
    pOut.z = pV1.z * n ;
    
    return pOut ;
}// end Vec4Mul

VECTOR4 Vec4Div(VECTOR4& pOut, VECTOR4& pV1, float n)
{
    pOut.x = pV1.x / n ;
    pOut.y = pV1.y / n ;
    pOut.z = pV1.z / n ;
    
    return pOut ;
}// end Vec4Div

VECTOR4 Vec4Cross(VECTOR4& pOut, VECTOR4& pV1, VECTOR4& pV2)
{
    pOut.x = pV1.y * pV2.z - pV2.y * pV1.z ;
    pOut.y =  - (pV1.x * pV2.z - pV2.x * pV1.z );
    pOut.z = pV1.x * pV2.y - pV2.x * pV1.y ;
    
    return pOut ;
}//end Vec4Cross

float Vec4Dot(float& pOut, VECTOR4& pV1, VECTOR4& pV2)
{
    pOut = pV1.x * pV2.x + pV1.y * pV2.y + pV1.z * pV2.z ;
    
    return pOut ;
}// end Vec4Dot

float Vec4Length(float& pOut, VECTOR4& p)
{
    pOut = (float)sqrt(p.x*p.x+p.y*p.y+p.z*p.z) ;
    return pOut ;
}// end Vec4Length

VECTOR4 Vec4Normalize(VECTOR4& pOut, VECTOR4& p)
{
    float length ;
    Vec4Length(length , p);
    
    // test for zero length
    if(length <= EPSILON)
        return pOut;
    float length_inv = 1 / length ;
    pOut.x *= length_inv ;
    pOut.y *= length_inv ;
    pOut.z *= length_inv ;
    
    return pOut ;
}// end Vec4Normalize

VECTOR3 Vec3Add(VECTOR3& pOut, VECTOR3& pV1, VECTOR3& pV2)
{
    pOut.x = pV1.x + pV2.x ;
    pOut.y = pV1.y + pV2.y ;
    pOut.z = pV1.z + pV2.z ;
    
    return pOut ;
}// end Vec3Add

VECTOR3 Vec3Sub(VECTOR3& pOut, VECTOR3& pV1, VECTOR3& pV2)
{
    pOut.x = pV1.x - pV2.x ;
    pOut.y = pV1.y - pV2.y ;
    pOut.z = pV1.z - pV2.z ;
    
    return pOut ;
}// end Vec3Sub

VECTOR3 Vec3Mul(VECTOR3& pOut, VECTOR3& pV1,float n)
{
    pOut.x = pV1.x * n ;
    pOut.y = pV1.y * n ;
    pOut.z = pV1.z * n ;
    
    return pOut ;
}// end Vec3Mul

VECTOR3 Vec3Div(VECTOR3& pOut, VECTOR3& pV1,float n)
{
    pOut.x = pV1.x / n ;
    pOut.y = pV1.y / n ;
    pOut.z = pV1.z / n ;
    
    return pOut ;
}// end Vec3Div

VECTOR3 Vec3Cross(VECTOR3& pOut, VECTOR3& pV1, VECTOR3& pV2)
{
    pOut.x = pV1.y * pV2.z - pV2.y * pV1.z ;
    pOut.y = pV1.x * pV2.z - pV2.x * pV1.z ;
    pOut.z = pV1.x * pV2.y - pV2.x * pV1.y ;
    
    return pOut ;
}// end Vec3Cross

float Vec3Dot(float& pOut, VECTOR3& pV1, VECTOR3& pV2)
{
    pOut = pV1.x * pV2.x + pV1.y * pV2.y + pV1.z * pV2.z ;
    
    return pOut ;
}// end Vec3Dot

float Vec3Length(float& pOut, VECTOR3& p)
{
    int temp ;
    int x, y ,z ;
    
    x = fabs(p.x) * 1024 ;
    y = fabs(p.y) * 1024 ;
    z = fabs(p.z) * 1024 ;
    
    if(y < x)
    {
        temp = y ;
        y = x ;
        x = temp ;
    }// end if
    
    if(z < y)
    {
        temp = y ;
        y = z ;
        z = temp ;
    }// end if
    
    if(y < x)
    {
        temp = y ;
        y = x ;
        x = temp ;
    }// end if
    
    int dist = (z + 11 * (y >> 5) + (x >> 2)) ;
    
    return (float)(dist >> 10) ;
}// end Vec3Length

VECTOR3 Vec3Normalize(VECTOR3& pOut, VECTOR3& p)
{
    float length ;
    Vec3Length(length , p);
    Vec3Div(pOut , p , length);
    
    return pOut ;
}// end Vec3Normalize

VECTOR2 Vec2Add(VECTOR2& pOut, VECTOR2& pV1, VECTOR2& pV2)
{
    pOut.x = pV1.x + pV2.x ;
    pOut.y = pV1.y + pV2.y ;
    
    return pOut ;
}// end Vec2Add

VECTOR2 Vec2Sub(VECTOR2& pOut, VECTOR2& pV1, VECTOR2& pV2)
{
    pOut.x = pV1.x - pV2.x ;
    pOut.y = pV1.y - pV2.y ;
    
    return pOut ;
}// end Vec2Sub

VECTOR2 Vec2Mul(VECTOR2& pOut, VECTOR2& pV1,float n)
{
    pOut.x = pV1.x * n ;
    pOut.y = pV1.y * n ;
    
    return pOut ;
}// end Vec2Mul

VECTOR2 Vec2Div(VECTOR2& pOut, VECTOR2& pV1,float n)
{
    pOut.x = pV1.x / n ;
    pOut.y = pV1.y / n ;
    
    return pOut ;
}// end Vec2Mul

float Vec2Dot(float& pOut, VECTOR2& pV1, VECTOR2& pV2)
{
    pOut = pV1.x * pV2.x + pV1.y * pV2.y ;
    return pOut ;
}// end Vec2Dot


float Vec2Length(float& pOut, VECTOR2& p)
{
    pOut = sqrt(p.x*p.x + p.y * p.y);
    return pOut ;
}// end Vec2Length

VECTOR2 Vec2Normalize(VECTOR2& pOut, VECTOR2& p)
{
    float length ;
    Vec2Length(length,p);
    Vec2Div(pOut,p,length);
    
    return pOut ;
}// end Vec2Normalize


APProjection::APProjection(float _min, float _max)
	:min(_min),
	max(_max)
{

}

APProjection::~APProjection()
{

}

float APProjection::getMax() const
{
	return max ;
}

float APProjection::getMin() const
{
	return min ;
}

bool APProjection::overlap(APProjection* proj)
{
	if(min > proj->getMax()) return false ;
	if(max < proj->getMin()) return false ;

	return true ;
}

APOBB::APOBB()
{
    setVertex(0, 0, 0);
    setVertex(1, 0, 0);
    setVertex(2, 0, 0);
    setVertex(3, 0, 0);
}

APOBB::~APOBB()
{

}

VECTOR2 APOBB::getVertex(int index) const
{
	assert(0 <= index && index <=3 && "The index must be from 0 to 3");
	return vertex[index] ;
}

void APOBB::setVertex(int index , float x, float y)
{
	assert(0 <= index && index <=3 && "The index must be from 0 to 3");
	vertex[index].x = x ;
	vertex[index].y = y ;
}

void APOBB::setVertex(int index, VECTOR2 v)
{
	assert(0 <= index && index <=3 && "The index must be from 0 to 3");
	vertex[index].x = v.x ;
	vertex[index].y = v.y ;
}

void APOBB::getAxies(VECTOR2* axie)
{
	for(int i = 0 ; i < 4 ; i ++)
	{
		VECTOR2 s ;
		Vec2Sub(s,vertex[i],vertex[(i+1)%4]);
		Vec2Normalize(s, s);
		axie[i].x = -s.y ;
		axie[i].y = s.x ;
	}
}

APProjection APOBB::getAPProjection(VECTOR2 axie)
{
	float min = 0 ;
	Vec2Dot(min,vertex[0], axie);
	float max = min ;

	for(int i = 1 ; i < 4 ; i ++)
	{
		float temp = 0 ;
		Vec2Dot(temp, vertex[i], axie);
		if(temp > max)
			max = temp ;
		else if(temp < min)
			min = temp ;
	}// end for

	return APProjection(min, max);
}

bool APOBB::isCollidWithAPOBB(APOBB* APOBB)
{
	VECTOR2 * axie1 = new VECTOR2[4];
	VECTOR2 * axie2 = new VECTOR2[4];

	//Get the seperat axie
	getAxies(axie1);
	APOBB->getAxies(axie2);

	//Check for overlap for all of the axies
	for(int i = 0 ; i < 4 ; i ++)
	{
		APProjection p1 = getAPProjection(axie1[i]);
		APProjection p2 = APOBB->getAPProjection(axie1[i]);

		if(!p1.overlap(&p2))
			return false ;
	}

	for(int i = 0 ; i < 4 ; i ++)
	{
		APProjection p1 = getAPProjection(axie2[i]);
		APProjection p2 = APOBB->getAPProjection(axie2[i]);

		if(!p1.overlap(&p2))
			return false ;
	}

	delete[]axie1 ;
	delete[]axie2 ;

	return true ;
}