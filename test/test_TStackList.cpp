#include "Stack.h"
#include <gtest.h>

TEST(TStackList, can_create_StackList)
{
	ASSERT_NO_THROW(TStackList<int> S_INT);
	ASSERT_NO_THROW(TStackList<int> S_CHAR);
}

TEST(TStackList, create_empty_StackList)
{
	TStackList<int> s;

	EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStackList, create_isfull_StackList)
{
	TStackList<int> s;

	EXPECT_EQ(false, s.IsFull());
}

TEST(TStackList, can_push)
{
	TStackList<int> s;

	ASSERT_NO_THROW(s.Push(3));
}

TEST(TStackList, can_get_elem)
{
	TStackList<int> s;
	s.Push(4);

	EXPECT_EQ(4, s.Get());
}

TEST(TStackList, cant_get_if_empty)
{
	TStackList<int> s;

	ASSERT_ANY_THROW(s.Get());
}

TEST(TStackList, can_copy_StackList)
{
	TStackList<int> s;
	s.Push(1);

	ASSERT_NO_THROW(TStackList<int> s2(s));
}

TEST(TStackList, can_assing_StackList)
{
	TStackList<int> s1;
	s1.Push(1);
	TStackList<int> s2;
	s2 = s1;

	EXPECT_EQ(1, s2.Get());
}

TEST(TStackList, can_get_count)
{
	TStackList<int> s;
	s.Push(1);
	s.Push(2);
	EXPECT_EQ(2, s.GetCount());
}

TEST(TStackList, DOP_can_save_in_file_DOP)
{
	TStackList<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	ASSERT_NO_THROW(s.File());
}

TEST(TStackList, DOP_can_get_max_elem_DOP)
{
	TStackList<int> s;
	s.Push(1);
	s.Push(7);
	s.Push(3);
	s.Push(14);
	s.Push(61);
	s.Push(2);
	EXPECT_EQ(61, s.Max_elem());
}

TEST(TStackList, DOP_can_get_min_elem_DOP)
{
	TStackList<int> s;
	s.Push(1);
	s.Push(7);
	s.Push(3);
	s.Push(14);
	s.Push(61);
	s.Push(2);
	EXPECT_EQ(1, s.Min_elem());
}