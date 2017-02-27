/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, checkFirstSquare)
{
	TicTacToeBoard tttb;
	tttb.clearBoard();
	ASSERT_FALSE(tttb.placePiece(0,0) != Blank);		
}

TEST(TicTacToeBoardTest, checkClear)
{
	TicTacToeBoard tttb;
	tttb.clearBoard();
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			ASSERT_FALSE(tttb.placePiece(row, col) != Blank);	
		}
	}
}		


TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
