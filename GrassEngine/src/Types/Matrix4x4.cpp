#include "Matrix4x4.h"

namespace grs
{
	Matrix4x4 Matrix4x4::operator+(Matrix4x4 a)
	{
		Matrix4x4 m;
		for(int i = 0; i < 4; ++i) 
		{
			for (int j = 0; j < 4; ++j)
			{
				m.content[i][j] = this->content[i][j] + a.content[i][j];
			}
		}
		return m;
	}
	Matrix4x4& Matrix4x4::operator+=(Matrix4x4 a)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				this->content[i][j] += a.content[i][j];
			}
		}
		return *this;
	}
	Matrix4x4 Matrix4x4::operator-(Matrix4x4 a)
	{
		Matrix4x4 m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				m.content[i][j] = this->content[i][j] - a.content[i][j];
			}
		}
		return m;
	}
	Matrix4x4& Matrix4x4::operator-=(Matrix4x4 a)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				this->content[i][j] -= a.content[i][j];
			}
		}
		return *this;
	}
	Matrix4x4 Matrix4x4::operator*(Matrix4x4 a)
	{
		Matrix4x4 m;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				m.content[i][j] = 0;
				for (int k = 0; k < 4; ++k)
				{
					m.content[i][j] += this->content[i][k] * a.content[k][j];
				}
			}
		}
		return m;
	}
	Matrix4x4& Matrix4x4::operator*=(Matrix4x4 a)
	{
		Matrix4x4 m = *this;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				this->content[i][j] = 0;
				for (int k = 0; k < 4; ++k)
				{
					this->content[i][j] += m.content[i][k] * a.content[k][j];
				}
			}
		}
		return *this;
	}

	Matrix4x4 Matrix4x4::CreateScaleMatrix(Vector3f scale)
	{
		Matrix4x4 m;
		m.content[0][0] = scale.x;
		m.content[1][1] = scale.y;
		m.content[2][2] = scale.z;
		return m;
	}
	Matrix4x4 Matrix4x4::CreateTranslateMatrix(Vector3f translation)
	{
		Matrix4x4 m;
		m.content[0][3] = translation.x;
		m.content[1][3] = translation.y;
		m.content[2][3] = translation.z;
		return m;
	}
	Matrix4x4 Matrix4x4::CreateRotateMatrix(Quaternion rotation)
	{
		Matrix4x4 m;
		m.content[0][0] = 1 - 2 * pow(rotation.y, 2) - 2 * pow(rotation.z, 2);
		m.content[0][1] = 2 * rotation.x * rotation.y - 2 * rotation.w * rotation.z;
		m.content[0][2] = 2 * rotation.x * rotation.z - 2 * rotation.w * rotation.y;
		m.content[1][0] = 2 * rotation.x * rotation.y - 2 * rotation.w * rotation.z;
		m.content[1][1] = 1 - 2 * pow(rotation.x, 2) - 2 * pow(rotation.z, 2);
		m.content[1][2] = 2 * rotation.y * rotation.z - 2 * rotation.w * rotation.x;
		m.content[2][0] = 2 * rotation.x * rotation.z - 2 * rotation.w * rotation.y;
		m.content[2][1] = 2 * rotation.y * rotation.z - 2 * rotation.w * rotation.x;
		m.content[2][2] = 1 - 2 * pow(rotation.x, 2) - 2 * pow(rotation.y, 2);
		return m;
	}
	Matrix4x4 Matrix4x4::CreatePerspectiveMatrix(float FOV, float XYRatio, float nearCP, float farCP)
	{
		float D2R = 3.1415 / 180.0;
		float yScale = 1.0 / tan(D2R * FOV / 2);
		float xScale = yScale / XYRatio;
		float nearmfar = nearCP - farCP;
		float nearpfar = nearCP + farCP;

		Matrix4x4 m;
		m.content[0][0] = xScale;
		m.content[1][1] = yScale;
		m.content[2][2] = nearpfar / nearmfar;
		m.content[2][3] = -1;
		m.content[3][2] = (2 * farCP * nearCP) / nearmfar;
		m.content[3][3] = 0;

		return m;
	}
	Matrix4x4 Matrix4x4::CreateLookAtMatrix(Vector3f eye, Vector3f center, Vector3f up)
	{
		Vector3f zaxis = ((center - eye).Normalize()) * -1;
		Vector3f xaxis = (Vector3f::Cross(zaxis, up)).Normalize();
		Vector3f yaxis = Vector3f::Cross(xaxis, zaxis);

		Matrix4x4 m;
		m.content[0][0] = xaxis.x; m.content[0][1] = xaxis.y; m.content[0][2] = xaxis.z; m.content[0][3] = -Vector3f::Dot(xaxis, eye);
		m.content[1][0] = yaxis.x; m.content[1][1] = yaxis.y; m.content[1][2] = yaxis.z; m.content[1][3] = -Vector3f::Dot(yaxis, eye);
		m.content[2][0] = zaxis.x; m.content[2][1] = zaxis.y; m.content[2][2] = zaxis.z; m.content[2][3] = -Vector3f::Dot(zaxis, eye);
		
		return m;
	}
	
	std::ostream& operator<<(std::ostream& os, const Matrix4x4& mat)
	{
		os << mat.content[0][0] << " " << mat.content[0][1] << " " << mat.content[0][2] << " " << mat.content[0][3] << "\n"
			<< mat.content[1][0] << " " << mat.content[1][1] << " " << mat.content[1][2] << " " << mat.content[1][3] << "\n"
			<< mat.content[2][0] << " " << mat.content[2][1] << " " << mat.content[2][2] << " " << mat.content[2][3] << "\n"
			<< mat.content[3][0] << " " << mat.content[3][1] << " " << mat.content[3][2] << " " << mat.content[3][3] << "\n";
		return os;
	}
}