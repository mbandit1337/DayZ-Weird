#pragma once
#include <algorithm>
#include <cmath>
#include <d3dx10math.h>
#define PI 3.14159265358979323846f
namespace SDK
{
	namespace utils
	{
		namespace maths
		{
			namespace vectype2
			{
				struct FVector
				{
					float x;
					float y;
					float z;
				};

				struct FVector2D
				{
					float x;
					float y;
				};

				struct FRotator
				{
					float Pitch;
					float Yaw;
					float Roll;
				};

				FVector Subtract(FVector point1, FVector point2)
				{
					FVector vector{ 0, 0, 0 };
					vector.x = point1.x	- point2.x;
					vector.y = point1.y	- point2.y;
					vector.z = point1.z - point2.z;
					return vector;
				}
				class vector2
				{
				public:
					vector2( )
					{
						x = y = 0.f;
					}

					vector2( float fx, float fy )
					{
						x = fx;
						y = fy;
					}

					float x, y;

					vector2 operator+( const vector2& input ) const
					{
						return vector2{ x + input.x, y + input.y };
					}

					vector2 operator-( const vector2& input ) const
					{
						return vector2{ x - input.x, y - input.y };
					}

					vector2 operator/( float input ) const
					{
						return vector2{ x / input, y / input };
					}

					vector2 operator*( float input ) const
					{
						return vector2{ x * input, y * input };
					}

					vector2& operator-=( const vector2& v )
					{
						x -= v.x;
						y -= v.y;
						return *this;
					}

					vector2& operator/=( float input )
					{
						x /= input;
						y /= input;
						return *this;
					}

					vector2& operator*=( float input )
					{
						x *= input;
						y *= input;
						return *this;
					}

					float length( ) const
					{
						return std::sqrt( ( x * x ) + ( y * y ) );
					}

					vector2 normalized( ) const
					{
						return { x / length( ), y / length( ) };
					}

					float dot_product( vector2 input ) const
					{
						return ( x * input.x ) + ( y * input.y );
					}

					float distance( vector2 input ) const
					{
						return ( *this - input ).length( );
					}

					bool empty( ) const
					{
						return x == 0.f && y == 0.f;
					}
				};

				class vector3
				{
				public:
					vector3( )
					{
						x = y = z = 0.f;
					}

					vector3( float fx, float fy, float fz )
					{
						x = fx;
						y = fy;
						z = fz;
					}

					float x, y, z;

					vector3 operator+( const vector3& input ) const
					{
						return vector3{ x + input.x, y + input.y, z + input.z };
					}

					vector3 operator-( const vector3& input ) const
					{
						return vector3{ x - input.x, y - input.y, z - input.z };
					}

					vector3 operator/( float input ) const
					{
						return vector3{ x / input, y / input, z / input };
					}

					vector3 operator*( float input ) const
					{
						return vector3{ x * input, y * input, z * input };
					}

					vector3& operator-=( const vector3& v )
					{
						x -= v.x;
						y -= v.y;
						z -= v.z;

						return *this;
					}

					vector3& operator/=( float input )
					{
						x /= input;
						y /= input;
						z /= input;
						return *this;
					}

					vector3& operator*=( float input )
					{
						x *= input;
						y *= input;
						z *= input;
						return *this;
					}

					bool operator==( const vector3& input ) const
					{
						return x == input.x && y == input.y && z == input.z;
					}

					void make_absolute( )
					{
						x = std::abs( x );
						y = std::abs( y );
						z = std::abs( z );
					}

					float length_sqr( ) const
					{
						return ( x * x ) + ( y * y ) + ( z * z );
					}

					float length( ) const
					{
						return std::sqrt( length_sqr( ) );
					}

					float length_2d( ) const
					{
						return std::sqrt( ( x * x ) + ( y * y ) );
					}

					vector3 normalized( ) const
					{
						return { x / length( ), y / length( ), z / length( ) };
					}

					float dot_product( vector3 input ) const
					{
						return ( x * input.x ) + ( y * input.y ) + ( z * input.z );
					}

					float distance( vector3 input ) const
					{
						return ( *this - input ).length( );
					}

					float distance_2d( vector3 input ) const
					{
						return ( *this - input ).length_2d( );
					}

					void clamp( )
					{
						//std::clamp( x, -89.f, 89.f );
						//std::clamp( y, -180.f, 180.f );

						z = 0.f;
					}

					bool empty( ) const
					{
						return x == 0.f && y == 0.f && z == 0.f;
					}
				};

				class vector4
				{
				public:
					float x;
					float y;
					float z;
					float w;

					vector4( );
					vector4( float x, float y, float z, float w );

					vector4 operator+( const vector4& vector ) const;
					vector4 operator-( const vector4& vector ) const;
					vector4 operator-( ) const;
					vector4 operator*( float number ) const;
					vector4 operator/( float number ) const;

					vector4& operator+=( const vector4& vector );
					vector4& operator-=( const vector4& vector );
					vector4& operator*=( float number );
					vector4& operator/=( float number );

					bool operator==( const vector4& vector ) const;
					bool operator!=( const vector4& vector ) const;

					inline float Dot( const vector4& vector )
					{
						return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
					}

					inline float Distance( const vector4& vector )
					{
						return sqrt(
							( x - vector.x ) * ( x - vector.x ) +
							( y - vector.y ) * ( y - vector.y ) +
							( z - vector.z ) * ( z - vector.z ) +
							( w - vector.w ) * ( w - vector.w ) );
					}
				};

				inline bool vector4::operator==( const vector4& vector ) const
				{
					return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
				}

				inline bool vector4::operator!=( const vector4& vector ) const
				{
					return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
				}

				inline vector4 vector4::operator+( const vector4& vector ) const
				{
					return vector4( x + vector.x, y + vector.y, z + vector.z, w + vector.w );
				}

				inline vector4 vector4::operator-( const vector4& vector ) const
				{
					return vector4( x - vector.x, y - vector.y, z - vector.z, w - vector.w );
				}

				inline vector4 vector4::operator-( ) const
				{
					return vector4( -x, -y, -z, -w );
				}

				inline vector4 vector4::operator*( float number ) const
				{
					return vector4( x * number, y * number, z * number, w * number );
				}

				inline vector4 vector4::operator/( float number ) const
				{
					return vector4( x / number, y / number, z / number, w / number );
				}

				class matrix
				{
				public:
					inline float* operator[]( int i )
					{
						return m [ i ];
					}

					inline const float* operator[]( int i ) const
					{
						return m [ i ];
					}

					inline float* Base( )
					{
						return &m [ 0 ][ 0 ];
					}

					inline const float* Base( ) const
					{
						return &m [ 0 ][ 0 ];
					}
				public:

					inline matrix( )
					{
					}

					inline matrix(
						float m00, float m01, float m02, float m03,
						float m10, float m11, float m12, float m13,
						float m20, float m21, float m22, float m23,
						float m30, float m31, float m32, float m33 )
					{
						Init(
							m00, m01, m02, m03,
							m10, m11, m12, m13,
							m20, m21, m22, m23,
							m30, m31, m32, m33
						);
					}

					inline void Init(
						float m00, float m01, float m02, float m03,
						float m10, float m11, float m12, float m13,
						float m20, float m21, float m22, float m23,
						float m30, float m31, float m32, float m33
					)
					{
						m [ 0 ][ 0 ] = m00;
						m [ 0 ][ 1 ] = m01;
						m [ 0 ][ 2 ] = m02;
						m [ 0 ][ 3 ] = m03;

						m [ 1 ][ 0 ] = m10;
						m [ 1 ][ 1 ] = m11;
						m [ 1 ][ 2 ] = m12;
						m [ 1 ][ 3 ] = m13;

						m [ 2 ][ 0 ] = m20;
						m [ 2 ][ 1 ] = m21;
						m [ 2 ][ 2 ] = m22;
						m [ 2 ][ 3 ] = m23;

						m [ 3 ][ 0 ] = m30;
						m [ 3 ][ 1 ] = m31;
						m [ 3 ][ 2 ] = m32;
						m [ 3 ][ 3 ] = m33;
					}

					matrix transpose( ) const
					{
						return matrix(
							m [ 0 ][ 0 ], m [ 1 ][ 0 ], m [ 2 ][ 0 ], m [ 3 ][ 0 ],
							m [ 0 ][ 1 ], m [ 1 ][ 1 ], m [ 2 ][ 1 ], m [ 3 ][ 1 ],
							m [ 0 ][ 2 ], m [ 1 ][ 2 ], m [ 2 ][ 2 ], m [ 3 ][ 2 ],
							m [ 0 ][ 3 ], m [ 1 ][ 3 ], m [ 2 ][ 3 ], m [ 3 ][ 3 ] );
					}

					float m [ 4 ][ 4 ];
				};

				using vec2_t = vector2;
				using vec3_t = vector3;
				using vec4_t = vector4;
				using mat4x4_t = matrix;

				static inline vector3 FVectorToVector( FVector FVect )
				{
					return { FVect.x, FVect.y, FVect.z };
				}

				static inline FVector VectorToFVector( vector3 FVect )
				{
					return { FVect.x, FVect.y, FVect.z };
				}

				static inline vector3 FRotatorToVector( FRotator FRotatorInput )
				{
					return { FRotatorInput.Pitch, FRotatorInput.Yaw, FRotatorInput.Roll };
				}

				static inline FRotator VectorToFRotator( vector3 VectorInput )
				{
					FRotator FRotatorOut;
					FRotatorOut.Pitch = VectorInput.x;
					FRotatorOut.Yaw = VectorInput.y;
					FRotatorOut.Roll = VectorInput.z;
					return FRotatorOut;
				}

				static inline FRotator D3DXVectorToFRotator( D3DXVECTOR3 D3DXVectorInput )
				{
					FRotator FRotatorOut;
					FRotatorOut.Pitch = D3DXVectorInput.x;
					FRotatorOut.Roll = D3DXVectorInput.y;
					FRotatorOut.Yaw = D3DXVectorInput.z;
					return FRotatorOut;
				}

				struct TransformAccessReadOnly
				{
					uintptr_t pTransformData;
				};

				struct TransformData
				{
					uintptr_t pTransformArray;
					uintptr_t pTransformIndices;
				};

				struct Matrix34
				{
					vector4 vec0;
					vector4 vec1;
					vector4 vec2;
				};

				__forceinline utils::maths::vectype2::vec3_t calculate_angle(utils::maths::vectype2::vec3_t source, utils::maths::vectype2::vec3_t destination)
				{
					utils::maths::vectype2::vec3_t vecDelta = source - destination;
					float hyp = (float)sqrt(vecDelta.x * vecDelta.x + vecDelta.y * vecDelta.y);

					utils::maths::vectype2::vec3_t ViewAngles = utils::maths::vectype2::vec3_t();
					ViewAngles.x = -(float)atan(vecDelta.z / hyp) * (float)(180.f / PI);
					ViewAngles.y = (float)atan(vecDelta.y / vecDelta.x) * (float)(180.f / PI);
					ViewAngles.z = (float)0.f;

					if (vecDelta.x >= 0.f)
						ViewAngles.y += 180.0f;

					return ViewAngles;
				}
			}
		}
	}
}
