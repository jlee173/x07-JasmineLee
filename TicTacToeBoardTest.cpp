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

TEST(TicTacToeBoardTest, checkPlacePieceO)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(2,0);
	actual = tttb.placePiece(2,2);
	actual = tttb.getPiece(2,2);
	ASSERT_EQ(actual, O);
}

TEST(TicTacToeBoardTest, checkPlacePieceX)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(0,0);
	ASSERT_EQ(actual, X);		
}

TEST(TicTacToeBoardTest, checkPlacePieceOnO)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(0,0);
	actual = tttb.placePiece(1,0);
	actual = tttb.placePiece(1,0);
	ASSERT_EQ(actual, O);		
}

TEST(TicTacToeBoardTest, checkPlacePieceOnX)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(0,0);
	actual = tttb.placePiece(0,0);
	ASSERT_EQ(actual, X);		
}

TEST(TicTacToeBoardTest, checkPieceO)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(2,1);
	actual = tttb.placePiece(1,2);
	actual = tttb.placePiece(0,1);
	actual = tttb.placePiece(0,0);
	ASSERT_EQ(actual, O);
}		

TEST(TicTacToeBoardTest, checkClear)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(0,2);
	actual = tttb.placePiece(2,2);
	actual = tttb.placePiece(1,0);
	tttb.clearBoard();
	actual = tttb.getPiece(1,0);
	ASSERT_EQ(actual, Blank);
}

TEST(TicTacToeBoardTest, checkGetPieceX)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(1,1);
	actual = tttb.placePiece(0,0);
	actual = tttb.placePiece(0,2);
	actual = tttb.getPiece(0,2);
	ASSERT_EQ(actual, X);
}	

TEST(TicTacToeBoardTest, checkGetPieceO)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(2,0);
	actual = tttb.placePiece(2,2);
	actual = tttb.getPiece(2,2);
	ASSERT_EQ(actual, O);
}

TEST(TicTacToeBoardTest, checkGetPieceBlank)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(2,0);
	actual = tttb.placePiece(2,2);
	actual = tttb.getPiece(0,1);
	ASSERT_EQ(actual, Blank);
}

TEST(TicTacToeBoardTest, checkGetPieceInvalid)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(2,0);
	actual = tttb.placePiece(2,2);
	actual = tttb.getPiece(3,2);
	ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, invalidRowGreater2)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(4,0);
	ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, invalidRowLess0)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(-3,1);
	ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, invalidColGreater2)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(2,3);
	ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, invalidColLess0)
{
	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(0,-1);
	ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, winnerRowX)
{	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(0,0);
	actual = tttb.placePiece(0,0);
	actual = tttb.placePiece(0,1);
	actual = tttb.placePiece(0,1);
	actual = tttb.placePiece(0,2);
	actual = tttb.placePiece(0,2);	
	actual = tttb.getWinner();
	ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoardTest, winnerRowO)
{	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(1,1);
	actual = tttb.placePiece(0,0);
	actual = tttb.placePiece(1,1);
	actual = tttb.placePiece(0,1);
	actual = tttb.placePiece(1,1);
	actual = tttb.placePiece(0,2);	
	actual = tttb.getWinner();
	ASSERT_EQ(actual, O);
}

TEST(TicTacToeBoardTest, winnerColX)
{	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(1,0);
	actual = tttb.placePiece(1,1);
	actual = tttb.placePiece(2,0);
	actual = tttb.placePiece(0,1);
	actual = tttb.placePiece(0,0);
	actual = tttb.placePiece(0,2);	
	actual = tttb.getWinner();
	ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoardTest, winnerColO)
{	TicTacToeBoard tttb;
	Piece actual;
	actual = tttb.placePiece(1,1);
	actual = tttb.placePiece(0,0);
	actual = tttb.placePiece(0,1);
	actual = tttb.placePiece(1,0);
	actual = tttb.placePiece(0,2);
	actual = tttb.placePiece(2,0);	
	actual = tttb.getWinner();
	ASSERT_EQ(actual, O);
}

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
