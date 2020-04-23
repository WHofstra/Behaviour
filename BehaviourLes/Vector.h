#pragma once
class Vector
{
	public:
		Vector(int x, int y, int z = 0);
		~Vector();

		int X(), Y(), Z();
		void SetVector(int x, int y, int z = 0);

	private:
		int *thisX, *thisY, *thisZ;
};

