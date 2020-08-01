#pragma once

#include <iostream>
#include <cassert>

#include "Lawn.h"
#include "IFenceable.h"
#include "RectangleLawn.h"
#include "CircleLawn.h"
#include "SquareLawn.h"
#include "EquilateralTriangleLawn.h"

namespace lab5
{
	void TestBarney()
	{
		Lawn* lawn1 = new RectangleLawn(10, 20);
		unsigned int area1 = lawn1->GetArea();
		unsigned int grassPrice1 = lawn1->GetGrassPrice(BERMUDA);
		unsigned int sodRollsCount1 = lawn1->GetMinimumSodRollsCount();

		assert(area1 == 200);
		assert(grassPrice1 == 1600);
		assert(sodRollsCount1 == 667);

		RectangleLawn* rectangleLawn = (RectangleLawn*)lawn1;
		unsigned int fencePrice1 = rectangleLawn->GetFencePrice(RED_CEDAR);
		unsigned int fencesCount1 = rectangleLawn->GetMinimumFencesCount();

		assert(fencePrice1 == 360);
		assert(fencesCount1 == 240);
			
		delete lawn1;
		delete rectangleLawn;
		///////////////////////////////////////////

		Lawn* lawn2 = new SquareLawn(10);
		unsigned int area2 = lawn2->GetArea();
		unsigned int grassPrice2 = lawn2->GetGrassPrice(BERMUDA);
		unsigned int sodRollsCount2 = lawn2->GetMinimumSodRollsCount();

		assert(area2 == 100);
		assert(grassPrice2 == 800);
		assert(sodRollsCount2 == 334);

		SquareLawn* squareLawn = (SquareLawn*)lawn2;
		unsigned int fencePrice2 = squareLawn->GetFencePrice(RED_CEDAR);
		unsigned int fencesCount2 = squareLawn->GetMinimumFencesCount();

		assert(fencePrice2 == 240);
		assert(fencesCount2 == 160);

		delete lawn2;
		delete squareLawn;
		/////////////////////////////////////////////

		Lawn* lawn3 = new CircleLawn(10);
		unsigned int area3 = lawn3->GetArea();
		unsigned int grassPrice3 = lawn3->GetGrassPrice(BERMUDA);
		unsigned int sodRollsCount3 = lawn3->GetMinimumSodRollsCount();

		assert(area3 == 314);
		assert(grassPrice3 == 2512);
		assert(sodRollsCount3 == 1047);

		CircleLawn* circleLawn = (CircleLawn*)lawn3;
		unsigned int fencePrice3 = circleLawn->GetFencePrice(RED_CEDAR);
		unsigned int fencesCount3 = circleLawn->GetMinimumFencesCount();

		assert(fencePrice3 == 0);
		assert(fencesCount3 == 0);

		delete lawn3;
		delete circleLawn;
		/////////////////////////////////////////////

		Lawn* lawn4 = new EquilateralTriangleLawn(10);
		unsigned int area4 = lawn4->GetArea();
		unsigned int grassPrice4 = lawn4->GetGrassPrice(BERMUDA);
		unsigned int sodRollsCount4 = lawn4->GetMinimumSodRollsCount();

		assert(area4 == 44);
		assert(grassPrice4 == 352);
		assert(sodRollsCount4 == 147);

		EquilateralTriangleLawn* triangleLawn = (EquilateralTriangleLawn*)lawn4;
		unsigned int fencePrice4 = triangleLawn->GetFencePrice(RED_CEDAR);
		unsigned int fencesCount4 = triangleLawn->GetMinimumFencesCount();

		assert(fencePrice4 == 180);
		assert(fencesCount4 == 120);

		delete lawn4;
		delete triangleLawn;

		//std::cout << "area: " << area << std::endl;
		//std::cout << "grassPrice: " << grassPrice << std::endl;
		//std::cout << "sodRollsCount: " << sodRollsCount << std::endl;
		//std::cout << "fencePrice: " << fencePrice << std::endl;
		//std::cout << "fencesCount: " << fencesCount << std::endl;
	}
} // namespace lab5