#include "CppUnitTest.h"
#include "Connect_Four.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//Note: To run this unit test, go to Test > Test Settings > and make sure Default Processor Architecture is X64
namespace UnitTest1
{
	TEST_CLASS(Connect_Four_Unit_Test)
	{
	public:

		//Create an empty grid and check to see it cannot satisfy a win condition
		TEST_METHOD(Check_Empty_Grid)
		{
			int connections = 4;
			char **grid = BuildGameBoard(connections);
			Assert::IsFalse(CheckRowWin(grid, connections) ||
				CheckColumnWin(grid, connections) ||
				CheckLeftDiagonalWin(grid, connections) ||
				CheckRightDiagonalWin(grid, connections), L"Default grid should not be a winning condition");
		}
	};
}
