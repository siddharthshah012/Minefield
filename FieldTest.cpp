/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"

class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, IsMineInBounds )
{
	Field minefield;

	//minefield.placeMine(4,5);
	ASSERT_FALSE( minefield.isSafe(6,7) );
}

TEST(FieldTest, IsMine)
{
	Field minefield;

	minefield.placeMine(4,2);
	ASSERT_TRUE (minefield.isSafe(4,2) );
}

TEST(FieldTest, outofbounds)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_TRUE( minefield.get(11,12) );
}

TEST(FieldTest, Isempty)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_TRUE( minefield.get(5,9) );
}

